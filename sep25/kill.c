#define _POSIX_C_SOURCE 200809

#include <signal.h>
#include <unistd.h>

void handle_sigint(int signum) {
  const char msg[] = "CTRL + C pressed \n";
  write(STDOUT_FILENO, msg, sizeof(msg) - 1);
}

int main() {

  pid_t pid = fork();

  if (pid > 0) {
    // parent
    struct sigaction handler;

    handler.sa_handler = handle_sigint;
    handler.sa_flags = 0;
    sigemptyset(&handler.sa_mask);

    sigaction(SIGINT, &handler, NULL);

    while (1) {
      sleep(5);
    }

  } else if (pid == 0) {
    // child
    while (1) {
      sleep(5);
      kill(getppid(), SIGINT);
    }
  }

  return 0;
}
