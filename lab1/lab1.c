#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  printf("Plz enter some text: ");

  char *lineptr = NULL;
  size_t n = 0;
  ssize_t size_char = getline(&lineptr, &n, stdin);

  if (size_char < 0) {
    perror("get line is failed");
    exit(EXIT_FAILURE);
    free(lineptr);
    return 0;
  }
  char *token = NULL;
  printf("Tokens: \n");
  char *temp = NULL;
  token = strtok_r(lineptr, " ", &temp);

  do {
    printf("%s\n", token);
    token = strtok_r(NULL, " ", &temp);
  } while (token != NULL);

  free(lineptr);

  return 0;
}
