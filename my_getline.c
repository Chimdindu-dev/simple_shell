#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>


ssize_t fgets(FILE *stream, char *buf, size_t size)
{
  if (size == 0)
    return 0;

  size_t count;
  int c = 0;
  for (count = 0; c != '\n' && count < size - 1; count++) 
  {
    c = getc(stream);

    if (c == EOF) {
      if (count == 0)
        return -1;
      break;
    }

    buf[count] = (char) c;
  }

  buf[count] = '\0';
  return (ssize_t) count;
}

