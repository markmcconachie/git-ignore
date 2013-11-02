#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <git2.h>

#include "ignore-file.h"

char *get_ignore_path_from_workdir(char *workdir) {
  char *ignore_path = NULL;
  ignore_path = malloc(MAX_LENGTH * sizeof(char));
  strncpy(ignore_path, workdir, MAX_LENGTH);
  strcat(ignore_path, ".gitignore");
  return ignore_path;
}

git_repository *current_repo() {
  git_repository *repo = NULL;
  char *cwd = NULL;

  cwd = getcwd(0,0);
  char git_repo_path[MAX_LENGTH];
  git_repository_discover(git_repo_path, sizeof(git_repo_path), cwd, 0, NULL);
  git_repository_open(&repo, git_repo_path);

  if (!repo) {
    printf("fatal: Not a git repository (or any of the parent directories): .git\n");
    exit(1);
  }
  
  return repo;
}

char *get_ignore_path() {
  git_repository *repo = current_repo();
  char *workdir = (char *)git_repository_workdir(repo);

  git_repository_free(repo);
  return get_ignore_path_from_workdir(workdir);
}

FILE *open_ignore_file(char *mode) {
  char *ignore_path = NULL;
  FILE *fp; 

  ignore_path = get_ignore_path();
  fp=fopen(ignore_path, mode);

  free(ignore_path);
  return fp;
}

void print_ignore_file() {
  FILE *ignore_file = NULL;

  ignore_file = open_ignore_file("r");

  printf("# Rules in ignore file:\n"
         "#   (use \"git ignore add <rule>...\" to add more)\n#\n" );

  if(ignore_file) {
    char line[MAX_LENGTH];
    while (fgets(line, sizeof(line), ignore_file) != NULL) {
        printf("#\t%s", line);
    }

    fclose(ignore_file);
  }
}

void append_to_ignore_file(char *ignore_rule) {
    FILE *ignore_file = NULL;
    ignore_file = open_ignore_file("a");
    printf("added ignore rule: %s\n", ignore_rule);
    fprintf(ignore_file, "%s\n", ignore_rule);
    fclose(ignore_file); 
}
