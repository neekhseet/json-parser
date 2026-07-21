#include "../includes/json.h"

Token get_token(const char *value)
{
    Token new;
    new.type = get_token_type(value);
    new.value = value;
    return new;
}

JsonTokens get_token_type(const char *value)
{
    switch(*value)
    {
        case '{':
            return JSON_BEGIN_OBJECT;
            break;
        case '}':
            return JSON_END_OBJECT;
            break;
        case '[':
            return JSON_BEGIN_ARRAY;
            break;
        case ']':
            return JSON_END_ARRAY;
            break;
        case ':':
            return JSON_COLON;
            break;
        case ',':
            return JSON_COMMA;
            break;
        case '"':
            return JSON_STRING;
            break;
    };

    return JSON_EOF;
}