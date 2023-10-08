#include <stdio.h>
#include <string.h>
#include "copy.h"
char lines[MAXLINES][MAXLINE]; //입력줄
char longest[MAXLINE];
int line_lengths[MAXLINES];
int line_count = 0;

void copy(char from[], char to[]);

int main()
{
	int len;
        int max_lengths[MAXLINES];

	while (fgets(lines[line_count],MAXLINE,stdin) != NULL) {
		len = strlen(lines[line_count]);
		line_lengths[line_count] = len;
		line_count++;

		if (line_count >= MAXLINES) {
			return 1;
		}
	}
	for(int i = 0; i < line_count; i++) {
		max_lengths[i] = line_lengths[i];
	}

	for(int i = 0; i < line_count - 1; i++) {
		for(int j = i + 1; j < line_count; j++) {
			if(max_lengths[i] < max_lengths[j]) {
					int temp_len = max_lengths[i];
					max_lengths[i] = max_lengths[j];
					max_lengths[j] = temp_len;
			}
		}
	}

	for(int i = 0; i < line_count; i++) {
		for(int j = 0; j < line_count; j++){
			if(max_lengths[i] == line_lengths[j]) {
					printf("%s", line[j]);
					break;
			}
		}
	}

	return 0;
}	

