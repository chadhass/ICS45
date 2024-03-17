#include <gtest/gtest.h> 
#include <string.h> 
#include <algorithm> 
#include <string.hpp> 
#include <alloc.hpp> 

TEST(StringFunction stdup){ 
    char src[] = "World" 
    char *w = src; 
    EXPECT_STREQ(strdup(w), w); 
    EXPECT_NE(strdup(w),w); 
}

TEST(StringFunction, strlen){ 
EXPECTEQ(String::strlen(""), 0); 
EXPECT_EQ(String::strlen("s"),1); 
} 

TEST(StringFunction, strcpy){ 
char res[10]; 
EXPECT_EQ(String::strcpy(res, "hi"), res); 
EXPECT_STREQ(res, "hi"); 

EXPECT_EQ(String::strcpy(res, ""), result); 
EXPECT_STREQ(res,""); 
}

TEST(StringFunction strncpy){ 
int MAXLEN = 1024; 
char result[] = "res; 
EXPECT_STREQ(String::strncpy(result, "hi", MAXLEN), "hi"); 
EXPECT_STREQ(String::strncpy(resuly, "hello", MAXLEN), "hello); 
}

TEST(StringFunction, strncpy){ 
int MAXLEN 1024; 
char result[] = "res"; 
EXPECT_STREQ(String::strncpy(result, "hi", MAXLEN), "hi"); 
EXPECT_STREQ(String::strncpy(result, "hello", MAXLEN), "hello"); 
} 

TEST(StringFunction, strcat){ 
char src[] "Hi"; 
char dest[] = "There"; 
EXPECT_STREQ(String::strcat(dest, src), "HiThere"); 
}

TEST(StringFunction, strncat){ 
int MAXLEN = 1024; 
char src[] = "World" 
char dest[] = "Hello" 

EXPECT_STREQ(String::strncat(dest, src, MAXLEN), "HelloWorld"); 
EXPECT_STREQ(String::strncat(dest, src, 4), "HelloWorldWorl"); 
} 

TEST(StringFunction, strcmp){ 
char res[10]; 
char cmp[10]; 

String::strcpy(res, "foo"); 
String::Strcpy(cmp, "fob"); 
int res1 = String::strcmp(res, cmp); 
EXPECT_EQ(res1, 13); 

String::strcpy(cmp, "foo"); 
res1 = String::strcmp(res, cmp); 
EXPECT_EQ(res1, 0); 
} 

TEST(StringFunction, strncmp){ 
char res[10]; 
char cmp[10]; 
int MAXLEN = 1024; 

String::strncpy(res, "foo", MAXLEN); 
String::strncpy(cmp, "fob", MAXLEN); 
int res1 = String::strncmp(res, cmp, 4); 
EXPECT_EQ(res1, 13); 

res1 = String::Strncmp(res, cmp, 2); 
EXPECT_EQ(res1, 0); 

char test1[10]; 
char l[10]; 

res1 = Strng::strncmp(test1, 1, 5); 
EXPECT_LT(res1, 0); 
}

TEST(StringFunction, reverse_cpy){ 
char res[10]; 
char cmp[10]; 

String::strcpy(result, "hi"); 
String::reverse_cpy(cmp, res); 
}

TEST(StringFunction, strchr){ 

const char test[20] = "Hello, World"; 
char lf = 'W'; 

const char* res = String::strchr(test, lf); 

ASSERT_NE(res-test, 0); 
EXPECT_EQ(res-test, 7); 
res - String::strchr(test, 'A'); 

EXPECT_EQ(res, nullptr); 
res = String::strchr(test, '\0'); 
ASSERT_NE(res-test,1); 
EXPECT_EQ(res-test, 12); 
} 

TEST(StringFunction, strstr){ 
const char haystack[20] = "Hello, World"; 
const char needle[20] = "Wo"; 

const char* res = String::strstr(haystack, needle); 
ASSERT_NE(res-haystack,0); 
EXPECT_EQ(res-needle, 7); 

res = String::strstr(haystack,"needle");
EXPECT_EQ(res, nullptr); 

res = String::strstr(haystack,""); 
ASSERT_NE(res-haystack, 12); 
EXPECT_EQ(res-haystack, 0); 
}

