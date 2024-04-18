/* See LICENSE file for copyright and license details. */
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "util.h"

void
die(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);

	if (fmt[0] && fmt[strlen(fmt)-1] == ':') {
		fputc(' ', stderr);
		perror(NULL);
	} else {
		fputc('\n', stderr);
	}

	exit(1);
}

void *
ecalloc(size_t nmemb, size_t size)
{
	void *p;

	if (!(p = calloc(nmemb, size)))
		die("calloc:");
	return p;
}

void
logmsg(const char *message)
{
  FILE *fptr;
  fptr = fopen("/home/gergedan/repos/github/dwm/log", "a");
  fprintf(fptr, "%s", message);
  fclose(fptr);
}

char*
timestamp()
{
  time_t ltime;
  ltime = time(NULL);
  return asctime(localtime(&ltime));
}
