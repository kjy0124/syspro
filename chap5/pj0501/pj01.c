#include <stdio.h>
#include <stdlib.h>

int main() {
    char savedText[10][100];  // 2차원 배열로 텍스트 저장
    FILE *file;
    char filename[100];
    int line_count = 0;

    scanf("%s", filename);

    file = fopen(filename, "r");


    char ch;
    int row = 0, col = 0;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            savedText[row][col] = '\0';
            row++;
            col = 0;
            line_count++;
        } else {
            savedText[row][col] = ch;
            col++;
        }
        if (row >= 10 || col >= 100) {
            printf("err\n");
            return 1;
        }
    }

    fclose(file);

    int line_number;
    printf("You can choose 1 ~ 3 Line\n ");
    print("pls 'Enter' the line to select : ");
    scanf("%d", &line_number);

    if (line_number < 1 || line_number > line_count) {
        printf("err\n");
    } else {
        printf("%s\n", savedText[line_number - 1]);
    }

    return 0;
}
