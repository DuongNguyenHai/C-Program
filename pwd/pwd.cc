/* For printf. */
#include <stdio.h>
/* For realpath. */
#include <stdlib.h>
/* For PATH_MAX (the maximum length of a path). */
#include <sys/param.h>
/* For strerror. */
#include <string.h>
/* For errno. */
#include <errno.h>

static void call_realpath (char * argv0) {
    char resolved_path[PATH_MAX];

    if (realpath (argv0, resolved_path) == 0) { 
		fprintf (stderr, "realpath failed: %s\n", strerror (errno));
    }
    else {
		printf ("Program's full path is '%s'\n", resolved_path);
    }
}

int main (int argc, char ** argv) {
    // printf ("Program called as '%s'\n", argv[0]);
    call_realpath (argv[0]);
    return 0;
}