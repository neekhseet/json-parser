#include "../includes/json.h"

Token get_token(const char *value)
{
    /*  
    JsonTokens type = get_token_type()
    */
    return new;
}

TokenType get_token_type(const char *value)
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
        default:
            if (*value == 't' || *value == 'f') 
                return JSON_BOOLEAN;
            if (isdigit(*value) || *value == '-') return JSON_NUMBER;
            if (*value == 'n') return JSON_NULL;
            if (*value == '\0') return JSON_EOF;
    };

    return JSON_UNKNOWN;
}