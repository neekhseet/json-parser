#include "../includes/utils.h"

#include <stdlib.h>
#include <string.h>

char *copy_range(const char *begin, size_t len)
{
    char *res = malloc(len + 1);
    if (res == NULL)
        return NULL;

    memcpy(res, begin, len);
    res[len] = '\0';

    return res;
}