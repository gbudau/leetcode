#include <string.h>
#include <stdbool.h>

bool is_repeated(char *s, size_t n, size_t len)
{
    size_t i = 0;
    for (; i + n <= len; i += n)
        if (memcmp(s, &s[i], n))
            return false;
    return i == len;
}

bool repeatedSubstringPattern(char * s){
    if (!s || !*s || !*(s + 1))
        return false;
    size_t len = strlen(s);
    size_t max_len_pattern = len / 2 + len % 2;
    for (size_t i = 1; i <= max_len_pattern; i++)
        if (is_repeated(s, i, len))
            return true;
    return false;
}
