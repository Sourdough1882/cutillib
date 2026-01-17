#ifndef CUTILLIB_H
#define CUTILLIB_H

#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int str_cap(char* input);
int str_upper(char* input);
int str_lower(char* input);
int str_split(char* input, char delim, char*** output);
int str_reverse(char* input);
int str_trim(char* input);
int str_ltrim(char* input);
int str_rtrim(char* input);

#endif