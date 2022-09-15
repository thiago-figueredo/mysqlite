#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "string.h"

bool str_equals(char *s1, char *s2)
{
    return strcmp(s1, s2) == 0;
}

char* str_to_upper(char* s)
{
    size_t length = strlen(s);

    for (size_t i = 0; i < length; i++) {
        s[i] = toupper(s[i]);
    }

    return s;
}