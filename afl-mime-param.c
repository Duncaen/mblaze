#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#include "blaze822.h"

int
main(int argc, char *argv[])
{
	if (argc != 2)
		return 111;

	off_t len;
	char *buf;
	if (slurp(argv[1], &buf, &len) != 0) {
		perror(argv[1]);
		return 123;
	}

	char *s, *e;
	blaze822_mime_parameter(buf, "foo", &s, &e);
	free(buf);
	return 0;
}
