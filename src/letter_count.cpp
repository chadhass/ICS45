#include <iostream>
using namespace std; 
#include "letter_count.hpp"

constexpr int N_CHARS = ('Z' - 'A' +1); 

int main ()
{
int counters[N_CHARS] = {0};

    std::string input_line;
    while (std::getline(std::cin, input_line)) {
        count(input_line, counters);
    }

    print_counts(counters, N_CHARS);

    return 0; 
}
