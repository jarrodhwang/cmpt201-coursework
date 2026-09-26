#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main() {
  char *line = NULL;
  size_t n = 0;

  while (1) {
    printf("----- Please enter a command\n");
    ssize_t len = getline(&line, &n, stdin);
    if (len == -1) {
      perror("Failed to read line\n");
      break;
    }
    if (len > 0 && line[len - 1] == '\n') {
      line[len - 1] = '\0';
    }

    pid_t cpid = fork();

    if (cpid < 0) {
    } else if (cpid > 0) {
    } else {
    }

    free(line);
  }
  return 0;
}
