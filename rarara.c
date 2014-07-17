#define _GNU_SOURCE
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s FILENAME [OFFSET [COUNT]]\n", argv[0]);
        return 1;
    }
    size_t count = 1073741824; // cache 1G from offset on by default
    off64_t offset = 0;
    if (argc == 3) {
        if (sscanf (argv[2], "%zu", &offset) != 1) {
            fprintf (stderr, "OFFSET must be an integer");
            return 1;
        }
    }   
    if (argc == 4) {
        if (sscanf (argv[3], "%zu", &count) != 1) {
            fprintf (stderr, "COUNT must be an integer");
            return 1;
        }
    }
    int fd = open(argv[1], O_RDONLY);
    fprintf(stderr, "readahead [%zu:%zu]\n", offset, offset + count);
    int err = readahead(fd, offset, count);
    if (!err == 0) {
        fprintf(stderr, "readahead failed\n");
        return 1;
    }
    return 0;
}
