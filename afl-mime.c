#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#include "blaze822.h"

static blaze822_mime_action
cb(int depth, struct message *msg, char *body, size_t bodylen)
{
	(void) depth;
	(void) msg;
	(void) body;
	(void) bodylen;
	return MIME_CONTINUE;
}

int
main(int argc, char *argv[])
{
	if (argc != 2)
		return 111;

	struct message *msg = blaze822_mmap(argv[1]);
	if (!msg)
		return 123;

	blaze822_walk_mime(msg, 0, cb);
	blaze822_free(msg);
	return 0;
}
