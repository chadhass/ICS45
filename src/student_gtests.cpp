#include <iostream>
#include "string.hpp"

TEST(StringTest, Constructor)
{
String str; 
EXPECT_EQ(0,str.size()); 

String str2("Hi"); 
EXPECT_EQ(2,str2.sitze()); 
EXPECT_STREQ("Hi".str2.c_str()); 
}

TEST(StringTest, ReverseCopy){

onst char *org = "Hi";
char reversed[strlen(original)+1]; 

String::reverse_cpy(reversed, original); 

EXPECT_STREQ("iH", reversed);
}
