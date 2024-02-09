#include "string.hpp"

String::String(const char *s){
    buf = strdup(s);
}

String::String(const String &s){
    buf = strdup(s.buf); 
}

void String::swap(String &s){
    char *temp = buf; 
    buf = s.buf; 
    s.buf = temp; 
}

String &String::operator=(String s){
    swap(s); 
    return *this; 
}

String::~String(){
    delete[] buf; 
}
char &String::operator[](int index){
    return buf[index]; 
}

int String::size() const{
    int count =0; 
    while(buf[count] != '\0')
    {   
        count++; 
    }
    return count; 
}

String String::reverse() const{
    int len = size();
    String rev(len);
    for(int i=0; i <len; ++i)
    {
    rev.buf[i]=buf[len-i-1];
    }
    return rev; 
}

int String::indexOf(char c) const {
    int len = size(); 
    for(int i = 0; i <len; ++i)
    {
        if(buf[i]==c){
            return i;
            }
    }
    return -1; 
}

int String::indexOf(String s) const{
    int len = size(); 
    int subStr = s.size();
    for(int i = 0; i <len-subStr; ++i){
    int j; 
    for(int j = 0; j < subStr; ++j)
    { 
        if(buf[i+j] != s[j]){
        break;
        }
    }
    if(j ==subStr){ return i;}
    }
    return -1; 
}

bool String::operator ==(String s) const {
    int len1 = size(); 
    int len2 = s.size();
    if(len1 != len2){return false;}
    for(int i =0; i <len1; ++i) {
        if(buf[i] != s[i]){ return false; }
    }
    return true; 
}

bool String::operator>(String s) const{
    int len1 = size(); 
    int len2 = s.size(); 
    int minLen = len1 < len2 ? len1 :len2; 
    for(int i = 0; i<minLen; ++i){
    if(buf[i] > s[i]){
    return true; 
    }
    else if(buf[i] <s[i]) {
    return false; 
    }
    }
    return len1 > len2; 
 }

bool String::operator<(String s) const { 
    return !(*this==s || *this >s); 
}

bool String::operator<=(String s) const {
    return *this < s || *this ==s; 
}

bool String::operator>=(String s) const {
    return *this > s || *this ==s; 
}

String String::operator+(String s) const{
    int length = this-> size();
    int length2 = s.size();
    char *newStr = new char[length +length2 +1]; 

    for(int i = 0; i <length; ++i){
    newStr[i] = this->buf[i]; 
    }
    for(int i = 0; i < length2; ++i){
    newStr[length +i] = s.buf[i];
    }

    newStr[length + length2] = '\0';

    String newString(newStr); 

    return newString; 
}

String &String::operator+=(String s){ 
    *this = *this + s; 
    return *this; 
}


char *String::strdup(const char *src) {
    int len = strlen(src) +1; 
    char str = new char[length]; 

    strcpy(str,src);

    return str; 
}
int String::Strlen(const char *s){
int i =0; 
while(s[i] != '\0'){
i++
}
return i; 
} 

const char *String::strchr(const char *str, char c){
    while(*str != '\0'){
        if(*str == c){
            return str; 
            }
            ++str; 
 :            }
        return nullptr; 
}

const char  *String::strstr(const char *haystack, const char *needle){
    int needleLen = 0;  
    while(needle[needleLen] != '\0'){
    ++needleLen; 
    }

    int haystackLen = 0; 
    while(haystack[haystackLen] != '\0') {
        int i = 0; 
        while(haystack[haystackLen +i]  == needle[i]){
        ++i; 
        if(needle[i] == '\0'){
        return haystack + haystackLen; 
        }
        }
       ++haystackLen;
    }
return nullptr; 
}

String::String(int length) {
    buf = new char[length +1]; 
    buf[0] = '\0'; 
}
