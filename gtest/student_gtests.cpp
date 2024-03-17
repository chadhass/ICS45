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
    EXPECT_STREQ(String::strcat(dest, src), "mentassign"); 
}

TEST(StringFunction, strncat) {
    char src[MAXLEN] = "assign"; 
    char dest[MAXLEN] = "ment"; 
    EXPECT_STREQ(String::strncat(dest, src, MAXLEN), "mentassign"); 
    EXPECT_STREQ(String::strncat(dest, src, 2), "meantassignas"); 
}

TEST(StringFunction, strcmp) {
    char res[10]; 
    char cmp[10]; 

    String::strcpy(res, "hello"); 
    String::strcpy(cmp, "hallo"); 
    int res1 = String::strcmp(res, cmp); 
    EXPECT_EQ(res1, 1); 

    String::strcpy(cmp, "hello"); 
    int res2 = String::strcmp(res, cmp); 
    EXPECT_EQ(res2, 0); 

    String::strcpy(cmp, "holly"); 
    int res3 = String::strcmp(res, cmp); 
    EXPECT_EQ(res3,-8); 
}

TEST(StringFunction, strncmp) {
    char res[10]; 
    char cmp[10]; 

    String::strncpy(res, "apple",  MAXLEN); 
    String::strncpy(cmp, "apply",  MAXLEN); 
    int res1 = String::strncmp(res, cmp, 5); 
    EXPECT_EQ(res1, 10); 
}

TEST(StringFunction, reverse_cpy) {
    char res[10]; 
    char rev[10]; 

    String::strcpy(res, "hi"); 
    String::reverse_cpy(rev, res); 
    EXPECT_STREQ(rev, "ih"); 
}

TEST(StringFunction, strchr) {
    const char test[20] =  "Hello World"; 
    char lf = 'W'; 

    const char* res = String::strchr(test, lf); 

    ASSERT_NE(res-test,0); 
    EXPECT_EQ(res-test,6);  

    res = String::strchr(test, 'A'); 

    EXPECT_EQ(res, nullptr); 

    res = String::strchr(test, '\0'); 
    ASSERT_NE(res-test, 1); 
    EXPECT_EQ(res-test, 11); 

}

TEST(StringFunction, strstr) {
    const char haystack[20] = "Hello World"; 
    const char needle[20] = "Wor"; 

    const char* res = String::strstr(haystack, needle); 

    ASSERT_NE(res-haystack, 0); 
    EXPECT_EQ(res-haystack, 6); 

    res = String::strstr(haystack, "haystack"); 
    EXPECT_EQ(res, nullptr); 
}
