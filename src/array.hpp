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
//Fill array by the setting ever i to fn(i). 
template<typename Fn> 
void fill_with_fn(Fn, fn); 
private: 
    int len; 
    T* buf; 
    
    bool in_bounds(int index) const {
        return index >= 0 && index <len; 
    }
};

#endifi
