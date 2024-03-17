#include <gtest/gtest.h>

#include "string.hpp"

TEST(StringFunction, strlen) {
    EXPECT_EQ(String::strlen(""), 0);
    EXPECT_EQ(String::strlen("foo"), 3);
}

TEST(StringFunction, strcpy) {
    char result[10];
    EXPECT_EQ(String::strcpy(result, "foo"), result);
    EXPECT_STREQ(result, "foo");

    EXPECT_EQ(String::strcpy(result, "c"), result);
    EXPECT_STREQ(result, "c");

    EXPECT_EQ(String::strcpy(result, ""), result);
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strncpy) {
    char result[MAXLEN]; 
    EXPECT_STREQ(String::strncpy(result, "code", MAXLEN), "code"); 
    EXPECT_STREQ(String::strncpy(result, "hello", MAXLEN), "hello"); 
}

TEST(StringFunction, strcat) {
    char src[MAXLEN] = "assign"; 
    char dest[MAXLEN] = "ment";
    EXPECT_STREQ(String::strcat(dest, src), "assignment"); 
}

TEST(StringFunction, strncat) {
    char src[MAXLEN] = "assign"; 
    char dest[MAXLEN] = "ment"; 
    EXPECT_STREQ(String::strncat(dest, src, MAXLEN), "assignment"); 
    EXPECT_STREQ(String::strncat(dest, src, 2) "assignmentme"); 
}

TEST(StringFunction, strcmp) {
    char res[10]; 
    char cmp[10]; 

    String::strcpy(res, "hello"); 
    String::strcpy(cmp, "hallo"); 
    int res1 = String::strcmp(res, cmp); 
    EXPECT_EQ(res1, 1); 

    String::strcpy(compare, "hello"); 
    int res2 = String::strcmp(res, cmp); 
    EXPECT_EQ(result2, 0); 

    String::strcpy(compare, "holly"); 
    int res3 = String::strcmp(result, compare); 
    EXPECT_EQ(res3,-8); 
}

TEST(StringFunction, strncmp) {
    EXPECT_TRUE(false);
}

TEST(StringFunction, reverse_cpy) {
    EXPECT_TRUE(false);
}

TEST(StringFunction, strchr) {
    EXPECT_TRUE(false);
}

TEST(StringFunction, strstr) {
    EXPECT_TRUE(false);
}
