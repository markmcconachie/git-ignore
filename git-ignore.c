#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ignore-file.h"

int arg_matches(char *arg, char *opt) {
  return (strcmp(arg, opt) == 0);
}

void display_usage() {
  printf("usage: git ignore list\n"
         "   or: git ignore add <rule>...\n\n");
}

int main(int argc, char *argv[]) {
  if(!argv[1]) {
    printf("error: no option given.\n");
    display_usage();
    exit(1);
  }

  if(arg_matches(argv[1], "list")) {
    print_ignore_file();
  } else if(arg_matches(argv[1], "add")) {
    int i;
    if(!argv[2]) {
      printf("error: no rules given.\n");
      display_usage();
      exit(1);
    }
    for(i = 2; i < argc; i++) {
      append_to_ignore_file(argv[i]);
    }
  } else {
    printf("error: unknown option `%s'.\n", argv[1]);
    display_usage();
    exit(1);
  }

  return 0;
}