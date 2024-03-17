#include <iostream>

using namespace std; 

#include "string.hpp"

String::String(const char *s){
    strncpy(buf, s, MAXLEN-1); 
}

String::String(const String &s){
    if(strlen(s.buf)<MAXLEN){
    strncpy(buf, s.buf, MAXLEN-1); 
    }
}

String &String::operator=(const String &s){
    if(this != &s){
    strncpy(buf, s.buf, MAXLEN); 
    }
    buf[MAXLEN-1];
    return *this; 
}

char &String::operator[](int index){
    return (index < strlen(buf)) ? buf[index] : buf[0]; 
}

int String::strlen(const char *s){
    int i  = 0; 
    for(i=0; s[i] != '\0'; ++i){
    } 
    return i; 
}

char *String::strcpy(char *dest, const char *src){
    int i = 0; 
    for(i=0; src[i] != '\0'; ++i){
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest; 
}

char *String::strncpy(char *dest, const char *src, int n){
    int i = 0; 
    for(;src[i] != '\0' && i <n; ++i){
        dest[i] = src[i];
    }
    dest[i] = '\0'; 
    return dest; 
}

char *String::strcat(char *dest, const char *src){
    int i = strlen(dest); 
    int s = 0;
    for(s = 0; src[s] != '\0'; ++s){
        dest[i] = src[s]; 
        ++i;
        }
    dest[i] = '\0'; 
    return dest; 
}

char *String::strncat(char *dest,const char *src, int n){
    int i = strlen(dest); 
    int s = 0; 
    for(s = 0; src[s] != '\0' && s<n; ++s){
        dest[i] = src[s]; 
        ++i; 
    }

    dest[i] = '\0'; 
    return dest; 
}

int String::strcmp(const char *left, const char *right){
    int i =0; 
    for(i = 0;(left[i]!= '\0' || right[i] != '\0'); ++i){
    if(left[i] != right[i]) {
             int result = left[i]-right[i]; 
             return result; 
        }
    }
    return 0; 
}

int String::strncmp(const char *left, const char *right, int n){
    int i = 0; 
    while(left[i] == right[i] && left[i] != '\0' && right[i] != '\0' && i<n)
    { 
        ++i; 
    }
    if(i==n){
    return 0; 
    }
    return left[i] - right[i]; 
}

void String::reverse_cpy(char *dest, const char *src){
    int rev = String::strlen(src)-1; 
    int i =0; 

    for(rev = String::strlen(src)-1; rev>=0; rev--){
        dest[i] = src[rev]; 
        ++i; 
        }
    dest[i] = '\0'; 
}

const char *String::strchr(const char *str, char c){ 
    if(str==nullptr){
    return nullptr;
    }

    do{ 
        if(*str == c){ 
            return str; 
        } 
    }
    while(*str++); 

    return nullptr;
}

const char *String::strstr(const char *haystack, const char *needle){

    if(!needle || !*needle){ 
        return haystack; 
    }

    while(*haystack){
        const char *hay = haystack;  
        const char *n = needle; 

        while(*n && *hay && *hay == *n){ 
            ++hay;
            ++n; 
        } 

        if(!*n){ 
            return haystack;
        }

        ++haystack; 
    }
    return nullptr;
}

int String::size() const{ 
    int result  = strlen(buf); 
    return result; 

}

String String::reverse() const{
    char *str = new char[MAXLEN]; 
    reverse_cpy(str, buf); 
    String rev(str); 
    delete[] str; 
    return rev; 
}

int String::indexOf(char s) const {

    const char *num = strchr(buf, s); 
    if(num != nullptr)
    {
        return num-buf; 
    }
    else{ 
        return -1; 
    }
}

int String::indexOf(const String &s) const {
    const char *num = strstr(buf, s.buf); 
    if(num != nullptr){
        return num-buf;
    }
    else{ 
        return -1; 
    }
    
}

bool String::operator==(const String &s) const { 
    return(strcmp(buf, s.buf) ==0) ? true: false; 
}

bool String::operator!=(const String &s) const {
    return(strcmp(buf,s.buf) != 0) ? true: false; 
}

bool String::operator>(const String &s) const {
    return(strcmp(buf, s.buf) > 0) ? true:false; 
}

bool String::operator<(const String &s) const {
    return(strcmp(buf, s.buf) <0) ? true :false; 
}

bool String::operator<=(const String &s) const{
    return(strcmp(buf,s.buf) <= 0) ? true: false; 
}

bool String::operator >=(const String &s) const{
    return(strcmp(buf, s.buf) >= 0) ? true: false;

}

String String::operator+(const String &s) const{
    String p; 
    int len = strlen(buf) + strlen(s.buf); 

    if(len > MAXLEN -1){ 
        strncpy(p.buf, buf, MAXLEN-1); 

        p.buf[MAXLEN-1] = '0'; 
    } else{ 
        strcpy(p.buf, buf); 
        strcat(p.buf, s.buf); 
    }

    return p; 
}

String &String::operator+=(const String &s) {
    strncat(buf, s.buf, MAXLEN-1); 
    if(strlen(buf) > MAXLEN){
    buf[MAXLEN] = '\0'; 
    }
        
    return *this; 
}

void String::print(std::ostream &out) const{
    out << buf; 
}

void String::read(std::istream &in){
    in >>buf; 
}

String::~String()
{
}
std::ostream &operator<<(std::ostream &out, const String &s){
    s.print(out); 
    return out; 
}

std::istream &operator>>(std::istream &in, String &s){
    s.read(in); 
    return in;
}
