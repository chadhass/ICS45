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

String &String::operator=(const String &s){
    if(this != &s)
    { buf = strdup(s.buf); }
    return *this; 
}

String &String::operator==(String &&s){
if(this != &s){
buf = s.buf; 
s.buf= nullpetr;
}
return *this; 
}

String::~String(){
    delete[] buf; 
}
char &String::operator[](int index){
    return buf[index]; 
}

const char &String::operator[](int index) const{
    return buf[index];
    }



int String::size() const{
    return strlen(buf); 
}

String String::reverse() const{
    int len = strlen(buf); 
    String rev(len);
    for(int i=0; i <len; ++i)
    {
    rev.buf[i]=buf[len-i-1];
    }
    rev.buf[len] = '\0'; 
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
    return(strcmp(buf, s.buf)==0); 
}

bool String::operator>(String s) const{
    return(strcmp(buf,s.buf)>0); 
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

String&String::operator+=(String s){ 
    *this = *this + s; 
    return *this; 
}


char *String::strdup(const char *src) {
    int len = strlen(src) +1; 
    char* str = new char[len]; 

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

const char *String::strchr(const char *str, char c){
    while(*str != '\0'){
        if(*str == c){
            return str; 
            }
            ++str; 
        }
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

void Sring::print(strd::ostream &out) const{ out <<buf; }

void String::read(std::istream &in){
    buf = stdup[2048]; }

char stdup(const char *src) {
    int length = strlen(src) + 1; 
    char * str = new char[length]; 

    strcpy(str,src)

    return str; 
}


