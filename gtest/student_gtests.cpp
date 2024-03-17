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

TEST(StringFunction, strdup){ 
    char src[] = "World"; 
    char *p = src; 
    EXPECT_STREQ(strdup(p),p); 
    EXPECT_NE(strdup(p),p); 
}

TEST(StringFunction, strncpy) {
int MAXLEN = 1024; 
char res[10]; 
    EXPECT_EQ(String::strcpy(res, "hi", res); 
    EXPECT_STREQ(result, "hi"); 
}

TEST(StringFunction, strcat) {
    char src[] = "World"; 
    char dest[] ="Hi"; 
    EXPECT_STREQ(String::strncpy(res, dest,src,MAXLEN), "HiWorld"); 
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
