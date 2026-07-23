#include "../includes/json.h"
#include <gtest/gtest.h>

TEST(ProjTest, TokenizeLeftBraceType) 
{
    Token tok = get_token("{");
    EXPECT_EQ(tok.type, JSON_BEGIN_OBJECT);
    EXPECT_STREQ(tok.value, "{");
};

TEST(ProjTest, TokenizeRightBraceType)
{
    Token tok = get_token("}");
    EXPECT_EQ(tok.type, JSON_END_OBJECT);
    EXPECT_STREQ(tok.value, "}");
}


TEST(ProjTest, TokenizeLeftBracketType)
{
    Token tok = get_token("[");
    EXPECT_EQ(tok.type, JSON_BEGIN_ARRAY);
    EXPECT_STREQ(tok.value, "[");
}

TEST(ProjTest, TokenizeRightBracketType)
{
    Token tok = get_token("]");
    EXPECT_EQ(tok.type, JSON_END_ARRAY);
    EXPECT_STREQ(tok.value, "]");
}

TEST(ProjTest, TokenizeColonType)
{
    Token tok = get_token(":");
    EXPECT_EQ(tok.type, JSON_COLON);
    EXPECT_STREQ(tok.value, ":");
}


TEST(ProjTest, TokenizeCommaType)
{
    Token tok = get_token(",");
    EXPECT_EQ(tok.type, JSON_COMMA);
    EXPECT_STREQ(tok.value, ",");
}

TEST(ProjTest, TokenizeStringType)
{
    Token tok = get_token("\"string\"");
    EXPECT_EQ(tok.type, JSON_STRING);
    EXPECT_STREQ(tok.value, "string");
}

TEST(ProjTest, TokenizeBooleanType)
{
    Token tok = get_token("true");
    EXPECT_EQ(tok.type, JSON_BOOLEAN);
    EXPECT_STREQ(tok.value, "true");
}

TEST(ProjTest, TokenizeNumberType)
{
    Token tok = get_token("1");
    EXPECT_EQ(tok.type, JSON_NUMBER);
    EXPECT_STREQ(tok.value, "1");
}


TEST(ProjTest, TokenizeNegativeNumberType)
{
    Token tok = get_token("-1");
    EXPECT_EQ(tok.type, JSON_NUMBER);
    EXPECT_STREQ(tok.value, "-1");
}

TEST(ProjTest, TokenizeNullType)
{
    Token tok = get_token("null");
    EXPECT_EQ(tok.type, JSON_NULL);
    EXPECT_STREQ(tok.value, "null");
}

TEST(ProjTest, TokenizeEndOfFileType)
{
    Token tok = get_token("\0");
    EXPECT_EQ(tok.type, JSON_EOF);
    EXPECT_STREQ(tok.value, "\0");
}

TEST(ProjTest, TokenizeUnknownType)
{
    Token tok = get_token(" ");
    EXPECT_EQ(tok.type, JSON_UNKNOWN);
    EXPECT_STREQ(tok.value, " ");
}