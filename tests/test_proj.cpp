#include "../includes/json.h"
#include <gtest/gtest.h>

const char *t = "{";

TEST(ProjTest, TokenizeRightBrace) 
{
    Token tok = get_token(t);
    EXPECT_EQ(tok.type, JSON_BEGIN_OBJECT);
    EXPECT_STREQ(tok.t, "{");
};