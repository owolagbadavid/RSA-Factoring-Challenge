#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h> // Include this header for PRIu64 macro
#include <unistd.h>

int factorize(char *buffer);

int main(int argc, char *argv[]) {
    FILE *fptr;
    size_t count;
    ssize_t line;
    char *buffer = NULL;

    if (argc != 2) {
        fprintf(stderr, "Usage: factor <filename>\n");
        exit(EXIT_FAILURE);
    }
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        fprintf(stderr, "Error: can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while ((line = getline(&buffer, &count, fptr)) != -1) {
        factorize(buffer);
    }

    return 0;
}

int factorize(char *buffer) {
    uint64_t num;

    sscanf(buffer, "%" SCNu64, &num);  // Read the number as a 64-bit unsigned integer

    for (uint64_t i = 2; i <= num; i++) {
        if (num % i == 0) {
            printf("%" PRIu64 "=%" PRIu64 "*%" PRIu64 "\n", num, num / i, i);
            break;
        }
    }

    return 0;
}

