#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int i;
    for (i = 1; i < argc; i++) {
        FILE *fp;
        int c;
        int line_number = 1;
        int should_number_lines = 0;

        // Check for -n option
        if (argv[i][0] == '-' && strcmp(argv[i], "-n") == 0) {
            should_number_lines = 1;
            continue;
        }

        // Open the file
        fp = fopen(argv[i], "r");
        if (fp == NULL) {
            fprintf(stderr, "Cannot open file: %s\n", argv[i]);
            continue;
        }

        // Read and output the file content
        c = getc(fp);
        while (c != EOF) {
            if (should_number_lines) {
                printf("%d: ", line_number);
            }
            putc(c, stdout);

            if (c == '\n') {
                line_number++;
            }

            c = getc(fp);
        }

        fclose(fp);
    }

    return 0;
}
