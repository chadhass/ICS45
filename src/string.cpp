#include <iostream>
#include "string.hpp"


String::String(list::Node*head){ //default empty string 
    this->head = head; 
}

String::String(const char *s){
    head = list::from_string(s); 
}

//construct the string as a copy s 
String::String(const String &s){
    head = list::copy(s.head); 
}

String::String(String &&s){ 
    head = s.head; 
    s.head = nullptr;  
}

void String::swap(String &s){
    list::Node* sw = s.head; 
    s.head = head; 
    head = sw; 
}

//assignment operator for strings 
String &String::operator= (const String &s){
if( list::compare(head, s.head) != 0){ 
    list::free(head); 
    head = list::copy(s.head); 
}
return *this; 
}

//assign by moving 
String &String::operator=(String &&s){
    if(head != s.head){ 
    list::free(head); 
    head = s.head; 
    s.head = nullptr; 
}
return *this; 
}

bool String::in_bounds(int index) const { 
    return(index < list::length(head)); 
}

char String::operator[](int index) const{
    if(in_bounds(index)){
        return list::nth(head, index)-> data; 
    }
    else{
    return '\0'; 
    }
}

int String::size() const{
    return list::length(this->head); 
}

String String::reverse() const{
    String rev; 
    rev.head = list::reverse(this->head); 
    return rev; 
}

int String::indexOf(char c) const {
    return list::index(this-> head, list::find_char(this->head,c));
}

int String::indexOf(const String &s) const{ 
    return list::index(this->head,list::find_list(this->head,s.head)); 
}

//compare string(NOT assign) 
bool String::operator==(const String &s) const{ 
    return list::compare(this->head, s.head) ==0; 
}


std::strong_ordering String::operator<=>(const String &s) const{
    return list::compare(head, s.head) <=> 0; 
} 

String String::operator+(const String &s) const{ 
    String add; 
    add.head = list::append(this->head, s.head); 
    list::free(head); 
    return add; 
}

String &String::operator+=(const String &s){
    head = list::append(this->head, s.head); 
    return *this; 
} 

void String::print(std::ostream &out) const{
    list::print(out, head); 
}

void String::read(std::istream &in){ 
    char Input[1000000]; 
    in >> Input; 
    list::free(head); 
    head = list::from_string(Input); 
}

String::~String(){
    list::free(this->head); 
} 

std::ostream &operator<<(std::ostream &out, const String &s){
    s.print(out); 
    return out; 
}

std::istream &operator>>(std::istream &in, String &s){
    s.read(in); 
    return in; 
}

