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
    for(int i = 0; i <len-subStr; ++i)
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
    int len 1 = size(); 
    int len2 = s.size(); 
    int minLen = len1 < len ? len1 :len2; 
    for(int i = 0; i<minLen; ++i){
    if(buf[i] > s[i]){
    return true; 
    }
    else if(buf[i] <s[i])
    {
    return false; 
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
    int len1 = size(); 
    int len2 = s.size(); 
    String result(len1+len2); 
    for(int i =0; i<len1; ++i){
    result.buf[i] = buf[i]; 
    }
    for(int i = 0; i<len2; ++i){
    result.buf[len1 +i] = s.buf;
    }
    result.buf[len1 + len2] = '\0'; 
    return result; 
}

String &String::operator+=(String s){ 
    *this = *this + s; 
    return *this; 
}

void String::print(std::ostream &out) const{ 
    out << buf; 
}

void String::read(std::istream &in){
    in >>buf; 
}

char *String::strdup(const char *src) {
    int len = 0; 
    while(src[len] != '\0') {
    len++
    }
    char *dup = new char[len +1]; 
    for(int i =0; i<len; ++i){
    dup[i] = src[i];
    }
    dup[len] = '\0'; 
    return dup;
}

const char *String::strchr(const char *str, char c){
    while(*str != '\0'{
        if(*str == c){
            return str; 
            }
            ++str; 
             }
        return nullptr; 
}

const chat *String::strstr(const char *haystack, const char *needle){
    int needlelEN = 0;  
    while(needle[needleLen] != '\0'){
    ++needleLen; 
    }

    int haystackLen = 0; 
    while(haystack[haystackLen] != '\0' {
        int i = 0; 
        while(haystack[haystackLen +i]  == needle[i]){
        ++i 
        if(needle[i] == '\0'){
        return haystack + haystackLen; 
        }
        }
       ++ haystackLen
    }
return nullptr; 
}

String::String(int length) {
    buf = new char[length +1]; 
    buf[0] = '\0'; 
}
