#include "string.hpp"
#include <iostream> 
using namespace std; 

String::String(const char *s){
    if(s==nullptr || *s == '\0'){ 
        buf = new char [1]; 
        buf[0] = '\0'; 
    } 
    else { 
        buf = strdup(s); 
    }
}

String::String(const String &s){
    buf = strdup(s.buf); 
}

String::String(String && s) : buf(s.buf){ 
    s.buf = nullptr; 
}

String::String(int length): buf(new char [length+1]){ 
    buf[0] = '\0'; 
}

void String::swap(String &s){
    std::swap(buf, s.buf); 
}

String &String::operator=(const String &s){
    if(this != &s)
    { 
    delete[] buf; 
    buf = strdup(s.buf); 
    }
    return *this; 
}

String &String::operator=(String &&s){
    if(this != &s){
    delete [] buf; 
    buf = s.buf; 
    s.buf= nullptr;
}
return *this; 
}

char &String::operator[](int index){
    if(in_bounds(index)){ 
        return buf[index]; 
    }
    else{ 
        return buf[0]; 
    }
}

const char &String::operator[](int index) const{
    if(in_bounds(index)){ 
        return buf[index]; 
    }
    else{ 
        return buf[0]; 
    }
}

int String::size() const{
    return strlen(buf); 
}

String String::reverse() const{
    int len = strlen(buf); 
    String reved(len);
    for(int i=0; i <len; ++i)
    {
        reved.buf[i]=buf[len-i-1];
    }
    reved.buf[len] = '\0'; 
    return reved; 
}

int String::indexOf(char c) const {
    for(int i = 0; buf[i] != '\0'; i++)
    {
        if(buf[i] == c){ 
            return i; 
        }
    }
    return -1; 
}

int String::indexOf(const String &s) const{
    int len = this->size(); 
    int subStr = s.size();
    for(int i = 0; i <len-subStr; i++){ 
        bool ifound = true; 
            for(int j = 0; j < subStr; j++){ 
                if(buf[i+j] !=s.buf[j]){ 
                    ifound = false; 
                    break;
                }
            if(ifound){ 
                return i; 
            }
        }
    }
    return -1; 
}

bool String::operator ==(String s) const {
    return(strcmp(buf, s.buf)==0); 
}

bool String::operator!=(String s) const{ 
    return(strcmp(buf, s.buf) != 0); 
}
bool String::operator>(String s) const{
    return(strcmp(buf,s.buf) >0); 
 }

bool String::operator<(String s) const { 
    return(strcmp(buf, s.buf)<0); 
}

bool String::operator<=(String s) const {
    return(strcmp(buf,s.buf) <= 0);
}

bool String::operator>=(String s) const {
    return(strcmp(buf, s.buf) >= 0); 
}

String String::operator+(String s) const{
    int length = this->size() + s.size(); 
    String res(length); 
    
    res.strcpy(res.buf, this->buf); 
    res.strcat(res.buf +this->size(), s.buf); 

    return res; 
}

String&String::operator+=(String s){ 
    int len = strlen(buf) + strlen(s.buf); 
    char *p = new char[len+1]; 

    strcpy(p, buf); 
    strcat(p, s.buf); 

    delete[] buf; 
    buf = p; 
    return *this; 
}

void String::print(std::ostream & out) const{ 
    out <<buf; 
}
void String::read(std::istream &in){ 
    char store[2048]; 
    in >> store; 
    delete[] buf; 
    buf = strdup(store); 
}

char *String::strdup(const char *src) {
    int len = strlen(src) +1; 
    char *str = new char[len]; 

    strcpy(str,src);

    return str; 
}
int String::strlen(const char *s){
    int i =0; 
    while(s[i] != '\0'){
    i++;
    }
    return i; 
} 
char *String::strcpy(char *dest, const char *src){ 
    int i = 0; 
    while((dest[i]=src[i])!='\0'){ 
        i++;
        }
        return dest; 
}

char *String::strcat(char *dest, const char *src){ 
    int l = strlen(dest); 
    strcpy(dest+l, src); 
    return dest; 
}

char *String::strncat(char *dest, const char *src, int n){ 
    char *i = dest +strlen(dest); 
    while(n-- > 0 && src != '\0'){ 
        *i++ = *src++; 
    }
    *i = '\0'; 
    return dest; 
}

int String::strcmp(const char *left, const char *right){ 
    int i = 0; 
    for(i=0; (left[i] != '\0'&&  right[i] != '\0'); ++i){ 
        if(left[i] != right[i]){ 
            int res = left[i] - right[i]; 
            return res; 
        }
    }
    return 0; 
}

void String::reverse_cpy(char *dest, const char *src) {
    int i =0; 
    int s = String::strlen(src)-1; 
    for(s = String::strlen(src)-1; s >= 0; s--){ 
        dest[i] = src[s]; 
        i++; 
    }

    dest[i] = '\0'; 
}

const char *String::strchr(const char *str, char c){
    if(str == nullptr){ 
        return nullptr; 
    }
    do{ 
        if(*str == c){ 
            return str; 
        { 
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

String::~String(){ 
    delete[] buf;
}

std::istream &operator>>(std::istream &in, String &s){ 
    s.read(in); 
    return in; 
}

std::ostream &operator<<(std::ostream &out, String s){ 
    s.print(out); 
    return out; 
}
