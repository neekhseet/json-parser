#include "../includes/json.h"

Token get_token(const char *text)
{
    const char *cursor = text;
    return next_token(&cursor);
}

Token next_token(const char **cursor)
{
    Token t;
    t.type = get_token_type(**cursor);
    
    // switch (t.type)
    // {
    //     case JSON_BEGIN_OBJECT:
    //         t.value[0] = '{';
    //         // (*cursor)++;
    //         break;
    //     default:
    //         t.value[0] = '{';
    //         break;
    // }
    
    t.value[0] = '{';
    t.value[1] = '\0';
    return t;
}

TokenType get_token_type(const char value)
{
    switch(value)
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
            if (value == 't' || value == 'f') 
                return JSON_BOOLEAN;
            if (isdigit(value) || value == '-') return JSON_NUMBER;
            if (value == 'n') return JSON_NULL;
            if (value == '\0') return JSON_EOF;
    };

    return JSON_UNKNOWN;
}