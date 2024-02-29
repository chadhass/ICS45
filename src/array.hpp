#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iomanip>
#include <iostream>
#include <sstream>
#include <utility> 

template <typename T>
class Array{
public: 
//impliment all methods from int_array.hpp here 
Array(): len(0),buf(nullptr){}
//construct array 
explicit Array(int len): len(len), buf(new T[len]){}
// copy + move constructors
Array(const Array& other):buf(new T[other.len]){ 
    for(int i =0; i<other.len; ++i){
        buf[i] = other.buf[i]; 
    }
    len = other.len; 
}
Array(Array&& other){ 
    buf = other.buf; 
    other.buf = nullptr; 

    len = other.len;
    other.len = 0; 
}
friend void swap(Array& lhs, Array& rhs) noexcept{ 
    std::swap(lhs.len, rhs.len); 
    std::swap(lhs.buf, rhs.buf); 
}
Array& operator=(const Array other){ 
    if(this!= &other){ 
    delete[] buf;
    len = other.len; 
    buf = newT[len];
    for(int i = 0; i<other.len; ++i){
        buf[i] = other.buf[i]; 
    }
    }
    return *this; 
}
Array& operator=(Array&& other) noexcept{
    if(this != &other){
    delete[] buf; 
    len = other.len; 
    buf = other.buf; 
    other.buf = nullptr;
    other.len =0; 
    }
    return *this;
}
~Array(){delete[] buf; }
int length() const{ return len;}
T& operator[](int index){ 
if(!in_bounds(index)){
throw "Exception operator[](" + std::to_string(index) +") Out Of Range"; 
}
return buf[index]; 
}
const T& operator[](int index) const{ 
if(!in_bounds(index)){ 
throw"Exception operator[](" + std::to_string(index)+") Out Of Range"; 
}
return buf[index]; 
}
void fill(T f){ 
    for(int i =0; i <len; ++i){
        buf[i] =f;
    }
}

//Fill array by the setting ever i to fn(i). 
template <typename Fn> 
void fill_with_fn(Fn fn){
    for(int i =0; i<len; ++i){
        buf[i] = fn(i); 
    }
}
private: 
    int len; 
    T* buf; 
    
    bool in_bounds(int index) const {
        return index >= 0 && index <len; 
    }
};

std::ostream& operator<<(std::ostream& out, const Array<auto>& array){ 
    std::stringstream prt; 
    prt<<std::setprecision(2) << std::fixed << std::right; 
    for(int i =0; i<array.length(); ++i){
        prt<<std::setw(8) <<array[i]; 
    }
    out<< prt.str(); 
    return out; 
}

std::istream& operator>>(std::istream& in, Array<auto>& array){ 
    for(int i =0; i<array.length(); ++i){ 
        in>>array[i]; 
    } 
    return in; 
 }

#endif
