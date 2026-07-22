#include "../includes/json.h"
#include <gtest/gtest.h>

TEST(ProjTest, TokenizeRightBrace) 
{
    Token tok = get_token("{");
    EXPECT_EQ(tok.type, JSON_BEGIN_OBJECT);
    EXPECT_STREQ(tok.value, "{");
};

TEST(ProjTest, TokenizeLeftBrace)
{
    Token tok = get_token("}");
    EXPECT_EQ(tok.type, JSON_END_OBJECT);
    EXPECT_STREQ(tok.value, "}");
}


TEST(ProjTest, TokenizeLeftBracketSymbol)
{
    Token tok = get_token("[");
    EXPECT_EQ(tok.type, JSON_BEGIN_ARRAY);
    EXPECT_STREQ(tok.value, "[");
}

TEST(ProjTest, TokenizeRightBracketSymbol)
{
    Token tok = get_token("]");
    EXPECT_EQ(tok.type, JSON_END_ARRAY);
    EXPECT_STREQ(tok.value, "]");
}

TEST(ProjTest, TokenizeColonSymbol)
{
    Token tok = get_token(":");
    EXPECT_EQ(tok.type, JSON_COLON);
    EXPECT_STREQ(tok.value, ":");
}


TEST(ProjTest, TokenizeCommaSymbol)
{
    Token tok = get_token(",");
    EXPECT_EQ(tok.type, JSON_COMMA);
    EXPECT_STREQ(tok.value, ",");
}

TEST(ProjTest, TokenizeString)
{
    Token tok = get_token("\"string\"");
    EXPECT_EQ(tok.type, JSON_STRING);
    EXPECT_STREQ(tok.value, "\"string\"");
}

TEST(ProjTest, TokenizeBoolean)
{
    Token tok = get_token("true");
    EXPECT_EQ(tok.type, JSON_BOOLEAN);
    EXPECT_STREQ(tok.value, "true");
}

TEST(ProjTest, TokenizeNumber)
{
    Token tok = get_token("1");
    EXPECT_EQ(tok.type, JSON_NUMBER);
    EXPECT_STREQ(tok.value, "1");
}