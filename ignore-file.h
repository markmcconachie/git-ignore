#ifndef _ignore_file_h
#define _ignore_file_h

#define MAX_LENGTH 256

FILE *open_ignore_file(char *mode);
void print_ignore_file();
void append_to_ignore_file(char *ignore_rule);

#endif