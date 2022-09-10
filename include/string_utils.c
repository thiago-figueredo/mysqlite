#include <string.h>
#include "string.h"
#include <stdbool.h>

bool str_equals(char *s1, char *s2)
{
    return strcmp(s1, s2) == 0;
}