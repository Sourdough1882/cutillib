#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int strcap(char* input) {
    if (input == NULL || *input == '\0') {
        return -1;
    }

    if (islower((unsigned char)*input)) {
        *input = (char)toupper((unsigned char)*input);
        return 1;
    }

    return 0;
}

int strupper(char* input) {
    if (input == NULL || *input == '\0') {
        return -1;
    }

    while(*input) {
        if(islower((unsigned char)*input)) {
            *input = (char)toupper((unsigned char)*input);
        }
        input++;
    }

    return 0;
}

int strlower(char* input) {
    if (input == NULL || *input == '\0') {
        return -1;
    }

    while(*input) {
        if(isupper((unsigned char)*input)) {
            *input = (char)tolower((unsigned char)*input);
        }
        input++;
    }

    return 0;
}

#define BUFFER 255

int main(void) {
    char line[BUFFER];

    while ((fgets(line, sizeof(line), stdin)) != NULL) {
        strlower(line);
        printf("%s", line);
    }

    return 0;
}