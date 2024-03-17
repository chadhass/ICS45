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
    EXPECT_STREQ(String::strncat(dest, src, 2), "mentassignas"); 
}

TEST(StringFunction, strcmp) {
    char res[10]; 
    char cmp[10]; 

    String::strcpy(res, "foo"); 
    String::strcpy(cmp, "fob"); 
    int res1 = String::strcmp(res, cmp); 
    EXPECT_EQ(res1, 13); 

    String::strcpy(res, "hello"); 
    String::strcpy(cmp, "hello"); 
    int res2 = String::strcmp(res, cmp); 
    EXPECT_EQ(res2, 0); 

}

TEST(StringFunction, strncmp) {
    char res[10]; 
    char cmp[10]; 

    String::strncpy(res, "foo", MAXLEN); 
    String::strncpy(cmp, "fob", MAXLEN); 

    int res1 = String::strncmp(res, cmp, 4); 
    EXPECT_EQ(res1, 13); 

    res1 = String::strncmp(res, cmp, 2); 
    EXPECT_EQ(res1, 0); 

    char lres[10]  = "test"; 
    char l[10] = "testl"; 

    res1 = String::strncmp(1res, l, 5); 
    EXPECT_LT(res2,0); 
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
    const char haystack[20] = "Hello, World"; 
    const char needle[20] = "Wor"; 

    const char* res = String::strstr(haystack, needle); 

    ASSERT_NE(res-haystack, 0); 
    EXPECT_EQ(res-haystack, 7); 

    res = String::strstr(haystack, "needle"); 
    EXPECT_EQ(res, nullptr);

    res = String::strstr(haystack,""); 
    ASSERT_NE(res-haystack, 12); 
    EXPECT_EQ(res-haystack,0); 
}
