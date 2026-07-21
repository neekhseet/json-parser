#include "../includes/json.h"
#include <gtest/gtest.h>

TEST(ProjTest, TokenizeRightBrace) 
{
    Token tok = get_token("{");
    EXPECT_EQ(tok.type, JSON_BEGIN_OBJECT);
    EXPECT_STREQ(tok.t, "{");
};

TEST(ProjTest, TokenizeLeftBrace)
{
    Token tok = get_token("}");
    EXPECT_EQ(tok.type, JSON_END_OBJECT);
    EXPECT_STREQ(tok.t, "}");
}


TEST(ProjTest, TokenizeLeftBracketSymbol)
{
    Token tok = get_token("[");
    EXPECT_EQ(tok.type, JSON_BEGIN_ARRAY);
    EXPECT_STREQ(tok.t, "[");
}

TEST(ProjTest, TokenizeRightBracketSymbol)
{
    Token tok = get_token("]");
    EXPECT_EQ(tok.type, JSON_BEGIN_ARRAY);
    EXPECT_STREQ(tok.t, "]");
}