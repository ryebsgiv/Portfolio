#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

// Function to print the last n lines of a file
void tail(int fd, int n, int start) {
    char buffer[256];
    off_t file_size = lseek(fd, 0, SEEK_END);
    off_t pos = file_size;
    int newlines = 0;

    if (pos == -1) {
        perror("lseek");
        exit(1);
    }

    while (pos > 0) {
        pos--;
        lseek(fd, pos, SEEK_SET);
        if (read(fd, buffer, 1) != 1) {
            perror("read");
            exit(1);
        }
        if (buffer[0] == '\n') {
            newlines++;
            if (newlines == n + 1) {
                break;
            }
        }
    }

    if (newlines < n + 1) {
        pos = 0;
    }

    lseek(fd, pos, SEEK_SET);
    while (pos < file_size) {
        if (read(fd, buffer, 1) != 1) {
            perror("read");
            exit(1);
        }
        if (write(STDOUT_FILENO, buffer, 1) != 1) {
            perror("write");
            exit(1);
        }
        pos++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2 && argc != 4) {
        fprintf(stderr, "Usage: %s -n NUM_OF_LINES [FILENAME]\n", argv[0]);
        return 1;
    }

    int n, start = 0;
    if (argc == 2) {
        n = atoi(argv[1]);
    } else if (argc == 4) {
        if (strcmp(argv[1], "-n") != 0 || strcmp(argv[3], "+") != 0) {
            fprintf(stderr, "Usage: %s -n NUM_OF_LINES [FILENAME]\n", argv[0]);
            return 1;
        }
        n = atoi(argv[2]);
        start = 1;
    }

    int fd;
    if (start) {
        fd = open(argv[4], O_RDONLY);
    } else {
        fd = open(argv[1], O_RDONLY);
    }

    if (fd == -1) {
        perror("open");
        return 1;
    }

    tail(fd, n, start);

    close(fd);
    return 0;
}
