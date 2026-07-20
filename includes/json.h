#pragma once

#ifdef __cplusplus
extern "C" 
{
#endif
#include <stddef.h>

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
    JSON_NULL
} JsonTokens;


typedef struct Token
{
    JsonTokens type; 
    char *t;
} Token;

struct TokenStream 
{
    Token *tokens;

    size_t capacity;
    size_t size;
} TokenStream;

Token get_token(const char *t);

#ifdef __cplusplus
}
#endif