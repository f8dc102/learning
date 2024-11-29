#include "implementation.h"
#include "preimplemented.h"

/* main 함수 */
int main() {

  // 트라이 생성
  Trie *Tr = create_trie();

  FILE *fp1 = fopen("data.csv", "r"), *fp2 = fopen("records.bin", "wb");
  insert_from_file(fp1, fp2, Tr);
  fclose(fp1);
  fclose(fp2);

  printf("Trie created.\n");
  printf("Number of words: %d\n", Tr->count);

  char key[MAX_WORD_LENGTH], corr_key[MAX_WORD_LENGTH];
  CorrectionResults *cr =
      (CorrectionResults *)malloc(sizeof(CorrectionResults));

  // spell_correction
  while (true) {
    printf("\n\nType a key: ");

    // @WARNING: gets 함수는 사용하지 않도록..! (dreplicated)
    // gets(key);
    // sscanf(key, "%s", key);

    fgets(key, MAX_WORD_LENGTH, stdin); // fgets로 입력 받기
    key[strcspn(key, "\n")] = '\0'; // 입력 문자열에서 개행 문자 제거

    if (strcmp(key, "$exit") == 0)
      break;

    corr_key[0] = '\0';
    cr->n_results = 0;
    cr->found_perfect_match = false;
    find_with_spell_correction(Tr->root, key, corr_key, 0, 0, 0, 0, 0, 0, cr);
    sort_results(cr);
    print_results(cr);
  }

  return 0;
}
