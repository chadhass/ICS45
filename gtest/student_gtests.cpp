#include <gtest/gtest.h>
#include <string.h>

#include <algorithm>

#include "string.hpp"
#include "alloc.hpp"

TEST(StringFunction, strlen) {
    EXPECT_EQ(String::strlen(""), 0);
    EXPECT_EQ(String::strlen("foo"), 3);
}

TEST(StringFunction, strcpy) {
    char result[10];
    EXPECT_EQ(String::strcpy(result, "foo"), result);
    EXPECT_STREQ(result, "foo");

    EXPECT_EQ(String::strcpy(result, "a"), result);
    EXPECT_STREQ(result, "a");

    EXPECT_EQ(String::strcpy(result, ""), result);
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strdup) {
    EXPECT_EQ(String::strlen(""), 0); 
    EXPECT_EQ(String::strlen("hello",5); 
    EXPECT_EQ(Strng::strlen("s"), 1); 
}

TEST(StringFunction, strncpy) {
char res[10]; 
    EXPECT_EQ(String::strcpy(res, "hi", res); 
    EXPECT_STREQ(result, "hi"); 
}

TEST(StringFunction, strcat) {
    int MAXLEN 1024; 
    char res = "res"; 
    EXPECT_STREQ(String::strncpy(res, "hi", MAXLEN), "hi"); 
}

TEST(StringFunction, strncat) {
    EXPECT_TRUE(false);
}

TEST(StringFunction, strcmp) {
    EXPECT_TRUE(false);
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
