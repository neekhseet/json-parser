#include "../includes/json.h"

Token get_token(const char *t)
{
    Token new;
    new.type = JSON_BEGIN_OBJECT;
    new.t = t;
    return new;
}