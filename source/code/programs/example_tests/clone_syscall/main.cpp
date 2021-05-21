#include <cstdlib>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstring>
#include <memory>
#include <signal.h>
#include <sys/wait.h>

static int child_func(void* arg) {
  char* buf = (char*)arg;
  printf("Child sees buf = \"%s\"\n", buf);
  strcpy(buf, "hello from child");
  return 0;
}

int main(int argc, char** argv) {
  const int STACK_SIZE = 65536;
  char* stack = (char*)malloc(STACK_SIZE);
  if (!stack) {
    perror("malloc");
    exit(1);
  }

  unsigned long flags = 0;
  if (argc > 1 && !strcmp(argv[1], "vm")) {
    flags |= CLONE_VM;
  }

  char buf[100];
  strcpy(buf, "hello from parent");
  if (clone(child_func, stack + STACK_SIZE, flags | SIGCHLD, buf) == -1) {
    perror("clone");
    exit(1);
  }

  int status;
  if (wait(&status) == -1) {
    perror("wait");
    exit(1);
  }

  printf("Child exited with status %d. buf = \"%s\"\n", status, buf);
  return 0;
}