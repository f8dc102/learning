#pragma once

/* scanf 및 fscanf 등의 사용을 위한 보안 경고 무시 */
#define _CRT_SECURE_NO_WARNINGS

/* 라이브러리 및 헤더파일 포함 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 상수 정의 */
#define MAX_WORD_LENGTH 100
#define MAX_RESULTS 50000
#define MAX_CORRECTIONS 3
#define MAX_LINE 1024

/* 레코드 구조체 */
typedef struct Record {
  char lemma[MAX_WORD_LENGTH]; // 단어

  char PoS;     // 품사
  int freq;     // 빈도
  float perMil; // 백만분율
  float caps;   // 대문자 비율
} Record;

/* 트라이 노드 구조체 */
typedef struct TrieNode {
  char character; // 문자 하나

  long int bp;            // 파일에서의 byte position
  struct TrieNode *below; // 아래쪽 자식 노드
  struct TrieNode *right; // 오른쪽 형제 노드
} TrieNode;

/* 트라이 구조체 */
typedef struct Trie {
  TrieNode *root; // 루트 노드
  int count;      // 단어 개수
} Trie;

/* 교정 결과 구조체 (하나의 샘플) */
typedef struct CorrectionResult {
  char word[MAX_WORD_LENGTH]; // 교정된 단어
  int ns, nd, ni, nt;         // 대체, 삭제, 삽입, 전치 횟수
  float penalty;              // 벌점 점수
} CorrectionResult;

/* 교정 결과 구조체 (배열) */
typedef struct CorrectionResults {
  CorrectionResult corrections[MAX_RESULTS]; // 교정 결과 배열
  int n_results;                             // 교정 결과 개수
  bool found_perfect_match;                  // 완벽한 일치 여부
} CorrectionResults;

/* 함수 프로토타입 선언 */
TrieNode *insert_trie(char key[], Trie *Tr);
void substitution(TrieNode *leftmost, char key[], char corrected_key[], int ki,
                  int ci, int ns, int nd, int ni, int nt,
                  CorrectionResults *results);
void deletion(TrieNode *leftmost, char key[], char corrected_key[], int ki,
              int ci, int ns, int nd, int ni, int nt,
              CorrectionResults *results);
void insertion(TrieNode *leftmost, char key[], char corrected_key[], int ki,
               int ci, int ns, int nd, int ni, int nt,
               CorrectionResults *results);
void transposition(TrieNode *leftmost, char key[], char corrected_key[], int ki,
                   int ci, int ns, int nd, int ni, int nt,
                   CorrectionResults *results);
void find_with_spell_correction(TrieNode *root_sub_trie, char key[],
                                char corrected_key[], int ki, int ci, int ns,
                                int nd, int ni, int nt,
                                CorrectionResults *results);

/* 결과 비교 함수(qsort를 위한 함수) */
int compare_results(const void *a, const void *b) {
  const CorrectionResult *c1 = (const CorrectionResult *)a;
  const CorrectionResult *c2 = (const CorrectionResult *)b;

  if (c1->penalty < c2->penalty)
    return -1;
  if (c1->penalty > c2->penalty)
    return 1;

  int suma = c1->ns + c1->nd + c1->ni + c1->nt;
  int sumb = c2->ns + c2->nd + c2->ni + c2->nt;
  if (suma != sumb)
    return suma - sumb;

  if (c1->ns != c2->ns)
    return c1->ns - c2->ns;
  if (c1->nd != c2->nd)
    return c1->nd - c2->nd;
  if (c1->ni != c2->ni)
    return c1->ni - c2->ni;
  if (c1->nt != c2->nt)
    return c1->nt - c2->nt;

  return strcmp(c1->word, c2->word);
}

/* 결과 정렬 함수 */
void sort_results(CorrectionResults *res) {
  qsort(res->corrections, res->n_results, sizeof(CorrectionResult),
        compare_results);
}

/* 결과 출력 함수 */
void print_results(CorrectionResults *res) {
  if (res->n_results == 0) {
    printf("No results found.\n");
    return;
  }
  if (res->found_perfect_match) {
    printf("Perfect match found.\n");
    printf("Word: %s\n", res->corrections[0].word);
    return;
  }
  printf("Total %d results found.\n", res->n_results);
  printf("Top 10 results:\n");
  for (int i = 0; i < res->n_results && i < 10; i++) {
    printf("%02d. %s\t(ns=%d, nd=%d, ni=%d, nt=%d, penalty=%.1f)\n", i + 1,
           res->corrections[i].word, res->corrections[i].ns,
           res->corrections[i].nd, res->corrections[i].ni,
           res->corrections[i].nt, res->corrections[i].penalty);
  }
}

/* Trie 생성 함수 */
Trie *create_trie() {
  Trie *Tr = (Trie *)malloc(sizeof(Trie));
  Tr->root = NULL;
  Tr->count = 0;
  return Tr;
}

/* insert를 위한 fine_node_trie 함수 */
bool find_node_trie(char key[], Trie *Tr, TrieNode **curr, TrieNode **prev,
                    int *val_i) {
  int i = 0;
  *prev = NULL;
  *curr = Tr->root;

  do {
    while (key[i] != '\0' && (*curr)->character == key[i]) {
      (*prev) = (*curr);
      (*curr) = (*curr)->below;
      i++;
    }

    if ((*curr)->character == '\0' && key[i] == '\0')
      return true;

    while (*curr != NULL && (*curr)->character < key[i]) {
      (*prev) = (*curr);
      (*curr) = (*curr)->right;
    }

    if ((*curr) == NULL || (*curr)->character > key[i]) {
      *val_i = i;
      return false;
    }
  } while (1);
}

/* insert를 위한 hang_down 함수 */
TrieNode *hang_down(char key[], TrieNode *tn, int i) {

  TrieNode *newn;
  while (key[i] != '\0') {
    newn = (TrieNode *)malloc(sizeof(TrieNode));
    newn->character = key[i++];
    newn->right = NULL;
    tn->below = newn;
    tn = newn;
  }

  newn = (TrieNode *)malloc(sizeof(TrieNode));
  newn->character = '\0';
  newn->bp = 0;
  newn->right = NULL;
  newn->below = NULL;
  tn->below = newn;

  return newn;
}

/* File로부터 Trie 구축하는 함수 */
void insert_from_file(FILE *insertFP, FILE *recordFP, Trie *T) {
  char line[MAX_LINE];

  Record rec;
  char key[MAX_WORD_LENGTH];
  TrieNode *last;

  while (fgets(line, MAX_LINE, insertFP)) {
    sscanf(line, "%[^,],%c,%d,%f,%f", rec.lemma, &rec.PoS, &rec.freq,
           &rec.perMil, &rec.caps);
    strcpy(key, rec.lemma);
    last = insert_trie(key, T);
    if (last) {
      last->bp = ftell(recordFP);
      fwrite(&rec, sizeof(Record), 1, recordFP);
      fflush(recordFP);
    }
  }
}

/* 패널티 계산 함수 */
float get_penalty(int ns, int nd, int ni, int nt) {
  return ns * 1.1 + nd * 1.3 + ni * 1.6 + nt * 1.9;
}

/* 교정 결과를 CorrectionResults에서 찾는 함수 */
int find_in_results(CorrectionResults *results, char corrected_key[]) {
  for (int i = 0; i < results->n_results; i++)
    if (strcmp(results->corrections[i].word, corrected_key) == 0)
      return i;
  return -1;
}

/* result에 word, ns, nd, ni, nt, panalty 복사하는 함수 */
void copy2results(CorrectionResults *results, char corrected_key[], int ns,
                  int nd, int ni, int nt) {

  if (results->n_results >= MAX_RESULTS)
    return;
  int idx = find_in_results(results, corrected_key);

  float penalty = get_penalty(ns, nd, ni, nt);
  if (idx != -1) {
    if (results->corrections[idx].penalty > penalty) {
      results->corrections[idx].ns = ns;
      results->corrections[idx].nd = nd;
      results->corrections[idx].ni = ni;
      results->corrections[idx].nt = nt;
      results->corrections[idx].penalty = penalty;
    }
    return;
  }

  int nres = results->n_results;
  strcpy(results->corrections[nres].word, corrected_key);
  results->corrections[nres].ns = ns;
  results->corrections[nres].nd = nd;
  results->corrections[nres].ni = ni;
  results->corrections[nres].nt = nt;
  results->corrections[nres].penalty = penalty;
  results->n_results++;
}
