#include <iostream> 
#include <fstream> 
#include <vector> 
#include <algorithm> 
#include <iterator> 
#include "process_numbers.hpp"

void split_odd_even(std::istream& numbers, std::ostream& odds, std::ostream& evens){ 

std::vector<int> nums{
    std::istream_iterator<int>(numbers), std::istream_iterator<int>()}; 
} 

std::sort(nums.begin(), nums.end()); 

std::copy_if(nums.begin(), nums.end(),std::ostream_interator<int>(odds," "),[](int num)
{ 
    n = num%2 != 0;
    return n; 
}); 

std::copy_if(nums.begin(),nums.end(),std::ostream_iterator<int>(evens, " ")[](int num){ 
    n = num%2 ==0; 
    return n; 
}); 

} 
