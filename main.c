#include <stdio.h>
#include <ctype.h>

int capitalize(char* input) {
    if (input == NULL || *input == '\0') {
        return -1;
    }

    if (islower((unsigned char)*input)) {
        *input = (char)toupper((unsigned char)*input);
        return 1;
    }

    return 0;
}

#define BUFFER 255

int main(void) {
    char line[BUFFER];

    while ((fgets(line, sizeof(line), stdin)) != NULL) {
        capitalize(line);
        printf("%s", line);
    }

    return 0;
}