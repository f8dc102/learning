#pragma once

#include "preimplemented.h"

/* Trie 삽입 함수 */
TrieNode *insert_trie(char key[], Trie *Tr) {
  /*
          INPUT:
                  char key[]: 삽입할 단어
                  Trie* Tr: 트라이

          OUTPUT:
                  TrieNode*: 삽입된 단어의 마지막 노드
  */

  int i;
  TrieNode *tn, *curr, *prev;
  TrieNode *last = NULL;

  /* ==================== FILL YOUR CODE ==================== */
  // if root is NULL 첫번째 노드 삽입 후 hang_down
  if (Tr->root == NULL) {
    Tr->root = (TrieNode *)malloc(sizeof(TrieNode));
    Tr->root->character = key[0];
    Tr->root->below = NULL;
    Tr->root->right = NULL;
    tn = hang_down(key, Tr->root, 1);
    Tr->count++;
    return tn;
  }

  // find_node_trie로 삽입할 위치 찾기 (true가 반환된 경우 이미 존재하는 단어)
  if (find_node_trie(key, Tr, &curr, &prev, &i)) {
    // Key already exists
    return NULL;
  }

  // 각 case에 따라 삽입
  if (prev == NULL) {
    // Insert at root level
    tn = (TrieNode *)malloc(sizeof(TrieNode));
    tn->character = key[i];
    tn->below = hang_down(key, tn, i + 1);
    tn->right = Tr->root;
    Tr->root = tn;
  } else {
    // Insert after `prev`
    tn = (TrieNode *)malloc(sizeof(TrieNode));
    tn->character = key[i];
    tn->below = hang_down(key, tn, i + 1);
    tn->right = curr;
    prev->right = tn;
  }

  /* ================= YOUR CODE ENDS HERE ================== */

  Tr->count++;
  return last;
}

/* spell correction 진행 함수 */
void find_with_spell_correction(TrieNode *root_sub_trie, char key[],
                                char corrected_key[], int ki, int ci, int ns,
                                int nd, int ni, int nt,
                                CorrectionResults *results) {
  /*
          INPUT:
                  TrieNode* root_sub_trie: 현재 노드
                  char key[]: 입력된 단어
                  char corrected_key[]: 수정된 단어
                  int ki: key의 index
                  int ci: corrected_key의 index
                  int ns: substitution 횟수
                  int nd: deletion 횟수
                  int ni: insertion 횟수
                  int nt: transposition 횟수
                  CorrectionResults* results: 수정 결과
  */

  TrieNode *curr = root_sub_trie;
  // 어따쓰냐 ㅠㅠ
  // char c, new_corrected_key[MAX_WORD_LENGTH];

  if (!curr)
    return;

  /* ==================== FILL YOUR CODE ==================== */

  // key와 corrected_key가 모두 끝에 도달한 경우
  if (key[ki] == '\0' && curr->character == '\0') {
    corrected_key[ci] = '\0'; // 수정된 키 종료
    copy2results(results, corrected_key, ns, nd, ni, nt); // 결과 복사
    if (ns + nd + ni + nt == 0) { // 완벽히 일치할 경우
      results->found_perfect_match = true;
    }
    return;
  }

  // key의 문자와 현재 노드의 문자가 같을 때까지 오른쪽으로 이동
  while (curr && curr->character != key[ki] && curr->character != '\0') {
    curr = curr->right;
  }

  // key의 문자와 현재 노드의 문자가 같을 때 재귀 호출
  if (curr && curr->character == key[ki]) {
    corrected_key[ci] = curr->character; // 현재 문자를 수정된 키에 추가
    find_with_spell_correction(curr->below, key, corrected_key, ki + 1, ci + 1,
                               ns, nd, ni, nt, results);
  }

  // perfect match가 아니고, 교정 횟수가 MAX_CORRECTIONS보다 작을 때
  if (!results->found_perfect_match && (ns + nd + ni + nt) < MAX_CORRECTIONS) {
    // substitution
    substitution(root_sub_trie, key, corrected_key, ki, ci, ns + 1, nd, ni, nt,
                 results);

    // deletion
    deletion(root_sub_trie, key, corrected_key, ki + 1, ci, ns, nd + 1, ni, nt,
             results);

    // insertion
    insertion(root_sub_trie, key, corrected_key, ki, ci + 1, ns, nd, ni + 1, nt,
              results);

    // transposition
    if (key[ki + 1] != '\0') {
      transposition(root_sub_trie, key, corrected_key, ki, ci, ns, nd, ni,
                    nt + 1, results);
    }
  }
  /* ================= YOUR CODE ENDS HERE ================== */

  return;
}

/* substitution 수행 함수 */
void substitution(TrieNode *leftmost, char key[], char corrected_key[], int ki,
                  int ci, int ns, int nd, int ni, int nt,
                  CorrectionResults *results) {
  /*
          INPUT:
                  TrieNode* root_sub_trie: 현재 노드
                  char key[]: 입력된 단어
                  char corrected_key[]: 수정된 단어
                  int ki: key의 index
                  int ci: corrected_key의 index
                  int ns: substitution 횟수
                  int nd: deletion 횟수
                  int ni: insertion 횟수
                  int nt: transposition 횟수
                  CorrectionResults* results: 수정 결과
  */

  char new_corrected_key[MAX_WORD_LENGTH];
  strcpy(new_corrected_key, corrected_key);

  /* ==================== FILL YOUR CODE ==================== */
  TrieNode *curr = leftmost;

  // 현재 노드의 아래로 이동하면서 corrected_key에 문자 추가
  while (curr) {
    new_corrected_key[ci] = curr->character;
    find_with_spell_correction(curr->below, key, new_corrected_key, ki + 1,
                               ci + 1, ns, nd, ni, nt, results);
    curr = curr->right;
  }
  /* ================= YOUR CODE ENDS HERE ================== */
}

/* deletion 수행 함수 */
void deletion(TrieNode *leftmost, char key[], char corrected_key[], int ki,
              int ci, int ns, int nd, int ni, int nt,
              CorrectionResults *results) {
  /*
          INPUT:
                  TrieNode* root_sub_trie: 현재 노드
                  char key[]: 입력된 단어
                  char corrected_key[]: 수정된 단어
                  int ki: key의 index
                  int ci: corrected_key의 index
                  int ns: substitution 횟수
                  int nd: deletion 횟수
                  int ni: insertion 횟수
                  int nt: transposition 횟수
                  CorrectionResults* results: 수정 결과
  */

  char new_corrected_key[MAX_WORD_LENGTH];
  strcpy(new_corrected_key, corrected_key);

  /* ==================== FILL YOUR CODE ==================== */

  // 현재 문자 삭제 (corrected_key는 기존 상태 유지)
  find_with_spell_correction(leftmost, key, corrected_key, ki + 1, ci, ns,
                             nd + 1, ni, nt, results);

  /* ================= YOUR CODE ENDS HERE ================== */
}

/* insertion 수행 함수 */
void insertion(TrieNode *leftmost, char key[], char corrected_key[], int ki,
               int ci, int ns, int nd, int ni, int nt,
               CorrectionResults *results) {
  /*
          INPUT:
                  TrieNode* root_sub_trie: 현재 노드
                  char key[]: 입력된 단어
                  char corrected_key[]: 수정된 단어
                  int ki: key의 index
                  int ci: corrected_key의 index
                  int ns: substitution 횟수
                  int nd: deletion 횟수
                  int ni: insertion 횟수
                  int nt: transposition 횟수
                  CorrectionResults* results: 수정 결과
  */

  char new_corrected_key[MAX_WORD_LENGTH];
  strcpy(new_corrected_key, corrected_key);

  /* ==================== FILL YOUR CODE ==================== */

  TrieNode *curr = leftmost;

  // 현재 노드의 아래로 이동하면서 corrected_key에 문자 추가
  while (curr) {
    new_corrected_key[ci] = curr->character;
    find_with_spell_correction(curr->below, key, new_corrected_key, ki, ci + 1,
                               ns, nd, ni + 1, nt, results);
    curr = curr->right;
  }

  /* ================= YOUR CODE ENDS HERE ================== */
}

/* transposition 수행 함수 */
void transposition(TrieNode *leftmost, char key[], char corrected_key[], int ki,
                   int ci, int ns, int nd, int ni, int nt,
                   CorrectionResults *results) {
  /*
          INPUT:
                  TrieNode* root_sub_trie: 현재 노드
                  char key[]: 입력된 단어
                  char corrected_key[]: 수정된 단어
                  int ki: key의 index
                  int ci: corrected_key의 index
                  int ns: substitution 횟수
                  int nd: deletion 횟수
                  int ni: insertion 횟수
                  int nt: transposition 횟수
                  CorrectionResults* results: 수정 결과
  */

  char new_corrected_key[MAX_WORD_LENGTH];
  strcpy(new_corrected_key, corrected_key);

  /* ==================== FILL YOUR CODE ==================== */

  if (key[ki + 1] == '\0') {
    return; // 더 이상 교환할 문자가 없음
  }

  // key의 문자를 두 개 바꾸어 corrected_key에 저장
  strcpy(new_corrected_key, key); // key 복사
  char temp = new_corrected_key[ki];
  new_corrected_key[ki] = new_corrected_key[ki + 1];
  new_corrected_key[ki + 1] = temp;

  // find_with_spell_correction 호출
  find_with_spell_correction(leftmost, new_corrected_key, corrected_key, ki + 1,
                             ci + 1, ns, nd, ni, nt + 1, results);

  /* ================= YOUR CODE ENDS HERE ================== */
}
