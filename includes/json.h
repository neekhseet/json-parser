#pragma once

#ifdef __cplusplus
extern "C" 
{
#endif

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

typedef struct Token Token;
typedef struct TokenStream TokenStream;

struct Token
{
    JsonTokens type; 
    char *t;
};

struct TokenStream 
{
    Token *tokens;

    size_t capacity;
    size_t size;
}

#ifdef __cplusplus
}
#endif