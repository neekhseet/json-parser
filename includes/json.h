#pragma once

#ifdef __cplusplus
extern "C" 
{
#endif
#include <stddef.h>
#include <ctype.h>

typedef enum {
    JSON_BEGIN_OBJECT,
    JSON_END_OBJECT,
    JSON_BEGIN_ARRAY,
    JSON_END_ARRAY,
    JSON_COLON,
    JSON_COMMA,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOLEAN,
    JSON_NULL,
    JSON_EOF,
    JSON_UNKNOWN
} TokenType;


typedef struct Token
{
    TokenType type; 
    char *value;
} Token;

typedef struct TokenStream 
{
    Token *tokens;

    size_t capacity;
    size_t size;
} TokenStream;

Token next_token(const char **cursor);
Token get_token(const char *value);
TokenType get_token_type(const char value);

char *parse_string(const char **cursor);
char *parse_number(const char **cursor);

#ifdef __cplusplus
}
#endif