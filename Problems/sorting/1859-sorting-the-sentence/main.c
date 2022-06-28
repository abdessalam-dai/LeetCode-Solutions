#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* sortSentence(char *s) {
    int len = strlen(s);
    char *result = malloc(sizeof(char) * len);

    char *word = malloc(sizeof(char) * len);
    int j = 0;

    for (int i=0; i<len; i++) {
        if (atoi(s+i) != 0 || s[i] == ' ') {
            printf("%s\n", word);
            memset(word, '\0', sizeof word);
            j = 0;
        } else {
            word[j] = s[i];
            j++;
        }
    }

    return result;
}

int main() {
    char s[] = "sentence4 a3 is2 This1";
    printf("%s\n", s);
    printf("%s\n", sortSentence(s));

    return 0;
}
