/* Dem rulz: */
/* - pure functions if possible */
/* - small functions */
/* - avoid dynamic memory */

#include <errno.h>
#include <ncurses.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

typedef struct {
  uint8_t day;
  uint8_t month;
  uint32_t year;
  uint8_t hour;
  uint8_t minute;
} day;

int main(int argc, char **argv) {
  (void)argc;
  char *program = *argv++;
  char *filepath = *argv++;
  FILE *fp = fopen(filepath, "r");
  if (fp == NULL) {
    printf("ERROR: could not open file: %s %s\n", filepath, strerror(errno));
    exit(1);
  }
  struct stat fileinfo;
  if (stat(filepath, &fileinfo) != 0) {
    printf("ERROR: could not get file info: %\n", strerror(errno));
  }
  size_t fsize = (size_t)fileinfo.st_size;
  size_t lines = 0;
  char c;
  size_t offset = 0;
  while ((c = (char)fgetc(fp)) != EOF) {
    // printf("%c", c);
    offset += 1;
    if (c == ';') {
      printf("found ; %d\n", offset);
    } else if (c == '\n') {
      lines++;
    }
  }
  day days[lines - 1];
  days[0].day = 1;
  days[0].month = 1;
  days[0].year = 1900;
  days[0].hour = 12;
  days[0].minute = 0;
  if (fclose(fp) != 0) {
    printf("ERROR: could not close file %s\n", strerror(errno));
  }
  return 0;
}
