#include <stdio.h>
#include <unistd.h>

int main() {

  for (int i = 0; i < 20; i++) {
    printf("Sleeping\n");
    sleep(1);
    fork();
    printf("after fork num %d\n", i);
  }

  printf("Done\n");
  return 0;
}
