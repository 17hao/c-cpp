#include "csapp.h"

#define MAXARGS 128
#define MAXLINE 128

/* Function prototypes */
static void eval(char *cmdline);
static int builtin_cmd(char **argv);
static int parseline(char *buf, char **argv);

int main() {
  char cmdline[MAXLINE];

  while (1) {
    // Read
    printf("> ");
    fgets(cmdline, MAXLINE, stdin);
    if (feof(stdin)) {
      exit(0);
    }

    // Evaluate
    eval(cmdline);
  }
}

static void eval(char *cmdline) {
  char *argv[MAXARGS]; // Argument list execve()
  char buf[MAXLINE];   // Holds modified command line
  int bg;              // Should the job run in bg or fg?
  pid_t pid;           // Process id

  strcpy(buf, cmdline);
  bg = parseline(buf, argv);
  if (argv[0] == NULL) {
    return; // Ignore empty lines
  }

  if (!builtin_cmd(argv)) {
    if ((pid == Fork()) == 0) { // Child process
      if (execve(argv[0], argv, environ) < 0) {
        printf("%s: Command not found.\n", argv[0]);
        exit(0);
      }
    }

    // Parent waits for forgeground job to terminate
    if (!bg) {
      int status;
      if (waitpid(pid, &status, 0) < 0) {
        unixError("waitFg: waitpid error");
      }
    } else {
      printf("%d %s", pid, cmdline);
    }
  }
  return;
}

/* If the first arg is a builtin command, runt it and return true */
static int builtin_cmd(char **argv) {
  if (!strcmp(argv[0], "quit")) { // quit command
    exit(0);
  }
  if (!strcmp(argv[0], "&")) { // Ignore singleton &
    return 1;
  }
  return 0;
}

/* Parse the command lien and build the argv array */
static int parseline(char *buf, char **argv) {
  char *delim; // Points to first space delimiter
  int argc;    // Number of args
  int bg;      // Background job?

  buf[strlen(buf) - 1] = ' ';     // Replace trailing '\n' with space
  while (*buf && (*buf == ' ')) { // Ignore leading spaces
    buf++;
  }

  // Build the argv list
  argc = 0;
  while ((delim = strchr(buf, ' '))) {
    argv[argc++] = buf;
    *delim = '\0';
    buf = delim + 1;
    while (*buf && (*buf == ' ')) {
      buf++;
    }
  }
  argv[argc] = NULL;

  if (argc == 0) { // Ignore blank line
    return 1;
  }

  if ((bg = (*argv[argc - 1] == '&')) != 0) {
    argv[argc--] = NULL;
  }

  return bg;
}