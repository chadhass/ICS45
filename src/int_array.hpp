#ifndef INT_ARRAY_HPP 
#define INT_ARRAY_HPP 

#include <iomanip> 
#include <iostream> 
#include <sstream> 
#include <utility> 

class Array{ 
public: 
//Construct zero-length array. 
    Array():len{0}, buf{nullptr}{}
//construct array of given length. 
    explicit Array(int len) : len{len}, buf{new int[len]}{}
//copy & move constuctors(TODO impliment these). 
    Array(const Array& other):buf(new int[other.len]){
        for(int i =0; i<other.len; ++i){ 
            buf[i] = other.buf[i]; 
         }
        len = other.len; 
    }
    Array(Array&& other){
        buf = other.buf 
        other.buf= nullptr; 
        len = other.len; 
        other.len = 0; 
    }
//Swap two arrays (without allocations)
//Note: now a friend function, which is the more common way to do it. 
friend void swap(Array& lhs, Array& rhs) noexcept{ 
    std::swap(lhs.len, rhs.len); 
    std::swap(lhs.buf, rhs.buf); 
}

Array& operator=(const Array& other){
    if(this != &other){
        delete[] buf; 
        int *dat =  new int[other.len]; 
        for(int i=0; i<other.len; ++i){
             dat[i] = other.buf[i]; 
        }
        this-> buf = dat; 
        this->len = other.len; 
        }
        return *this; 
}
    
Array& operator=(Array&& other) noexcept{
    if(this!=&other){
        delete[] buf; 
        this->buf = other.buf; 
        this->len = other.len; 

        other.len =0; 
        other.buf = nullptr;
    }
    return *this 
    }

//Destructor
~Array(){
    delete[] buf; 
}
//get length of the array. 
int length() const{
    return len; 
}
//Get a particular element of the array//TODO add bounds check). 
int& operator[](int index){
 if(!in_bounds(index)){
 throw "Excption operator[](" + std::to_string(index); + ") Out Of Range"; 
   }
   return buf[index];
}
//Get a particular element of the array TODO: add bounds check
const int& operator[](int index) const{
if(!in_bounds(index)){ 
    throw "Exception operator[](" + std::to_string(index) + ") Out Of Range";
    }
    return buf[index]; 
}

//Set every element of the array to val TODO impliment this. 
void fill(int val){
    for(int i = 0; i < len; ++i){
        buf[i] = val;
    }
}
private: 
    int len; 
    int* buf; 

    bool in_bounds(int index) const{
        return index >=0 && index <len; 
    }
}; 
//Print array to out in a single line 
inline std::ostream& operator<<(std::ostream& out, const Array& array){ 
    std::stringstream temp; 
    //We don't want to set formatting flags globally
    temp << std::setprecision(2) << std::fixed << std::right; 

    for(int i =0; i <array.length(); ++i){
        temp <<std::stew(8) << array[i]; 
    }
    out << temp.str(); 
    return out;
}
inline std::istream& operator>>(std::istream& in, Array& array){
    for(int i =0; i <array.length(); ++i){
        in >>array[i]; 
    }
    return in; 
}
#endif
