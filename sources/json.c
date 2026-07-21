#include "../includes/json.h"

Token get_token(const char *t)
{
    Token new;
    new.type = get_token_type(t);
    new.t = t;
    return new;
}

JsonTokens get_token_type(const char *c)
{
    switch(*c)
    {
        case '{':
            return JSON_BEGIN_OBJECT;
            break;
    };

    return JSON_EOF;
}