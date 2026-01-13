#include "cutillib.h"

int str_cap(char* input) {
    if (input == 0 || *input == '\0') {
        return -1;
    }

    if (islower((unsigned char)*input)) {
        *input = (char)toupper((unsigned char)*input);
        return 1;
    }

    return 0;
}

int str_upper(char* input) {
    if (input == 0 || *input == '\0') {
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

int str_lower(char* input) {
    if (input == 0 || *input == '\0') {
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

int str_split(char* input, char delim, char*** output) {
    if (!input || !output) return -1;

    int count = 1;
    for (int i = 0; input[i]; i++) {
        if (input[i] == delim) count++;
    }

    *output = malloc(count * sizeof(char*));
    if (!*output) return -1;

    int idx = 0;
    int start = 0;

    for (int i = 0; input[i]; i++) {
        if (input[i] == delim || input[i + 1] == '\0') {
            int end = (input[i] == delim) ? i : i + 1;
            int len = end - start;

            if (len > 0) {
                (*output)[idx] = malloc(len + 1);
                if (!(*output)[idx]) return -1;

                strncpy((*output)[idx], &input[start], len);
                (*output)[idx][len] = '\0';

                idx++;
            }

            start = i + 1;
        }
    }

    return idx;
}