#include "../includes/json.h"
#include "../includes/utils.h"

Token get_token(const char *text)
{
    const char *cursor = text;
    return next_token(&cursor);
}
    
Token next_token(const char **cursor)
{
    Token t;
    t.type = get_token_type(**cursor);
    
    switch (t.type)
    {
        case JSON_STRING:
            t.value = parse_string(cursor);
            break;
        case JSON_NUMBER:
            t.value = parse_number(cursor);
            break;
        case JSON_BOOLEAN:
            t.value = parse_boolean(cursor);
            break;
        case JSON_NULL:
            t.value = parse_null(cursor);
            break;
        default:
            t.value = copy_range(*cursor, 1);
            break;
    }
    
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


char *parse_string(const char **cursor)
{
    const char *begin = *cursor;
    
    (*cursor)++;
    begin = *cursor;

    while (**cursor != '"' && **cursor != '\0')
    {
        (*cursor)++;
    }

    size_t len = *cursor - begin;
    char *res = copy_range(begin, len);

    if (**cursor == '"')
        (*cursor)++;

    return res;
}

char *parse_number(const char **cursor)
{
    const char *begin = *cursor;

    while(**cursor == '-' || isdigit(**cursor))
    {
        (*cursor)++;
    }

    size_t len = *cursor - begin;
    char *res = copy_range(begin, len);

    if(isdigit(**cursor)) (*cursor)++;
    return res;
}

char *parse_boolean(const char **cursor)
{
    const char *begin = *cursor;

    while(**cursor != 'e')
    {
        (*cursor)++;
    }
    size_t len = *cursor - begin;
    char *res = copy_range(begin, len + 1);
    if (**cursor == 'e') (*cursor)++;
    return res;
}


char *parse_null(const char **cursor)
{
    const char *begin = *cursor;

    while(**cursor != 'l')
    {
        (*cursor)++;
    }
    size_t len = *cursor - begin;
    char *res = copy_range(begin, len + 2);
    if (**cursor == 'l') (*cursor)++;
    return res;
}