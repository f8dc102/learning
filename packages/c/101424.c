#include <stdio.h>

// Declare the function
int HWOne();

// Call the function yourself
int main() {
  HWOne();

  return 0;
}

// Declare for HWOne
void display_diary(char filepath[100]);
void append_to_diary(char filepath[100]);

// Homework 1
int HWOne() {
  // Initalise the variables
  char date[9];
  char filepath[100];

  // Get the date from the user
  printf("날짜를 입력하세요 (YYYYMMDD 형식): ");
  scanf("%s", date);
  getchar();

  // Get the file path from the user
  sprintf(filepath, "%s/%s.txt",
          "/home/f8dc193/devel/learning/packages/c/diary", date);

  // Print the original file contents
  display_diary(filepath);

  // Add a new entry to the file
  append_to_diary(filepath);

  return 0;
}

void display_diary(char filepath[100]) {
  // Initalise the variables
  FILE *file;
  char line[100];

  // Open the file
  // In this case, we are opening the file in read mode
  file = fopen(filepath, "r");

  // Check if the file exists
  if (file == NULL) {
    printf("해당 날짜의 일기가 존재하지 않습니다. 새로 작성하세요.\n");

    // Close the file
    // Prevent the resource leak
    fclose(file);

    // Call the append_to_diary function
    append_to_diary(filepath);

    return;
  }

  // Print the file contents
  while (fgets(line, 100, file) != NULL) {
    printf("%s", line);
  }

  // Close the file
  fclose(file);
}

void append_to_diary(char filepath[100]) {
  // Initalise the variables
  FILE *file;
  char entry[100];

  // Open the file
  // In this case, we are opening the file in append mode
  file = fopen(filepath, "a");

  // Get the entry from the user
  printf("Enter your entry: ");
  fgets(entry, 100, stdin);

  // Append the entry to the file
  fprintf(file, "%s", entry);

  // Close the file
  fclose(file);

  // End process
  printf("\n다이어리 저장 !!!!\n");
}
