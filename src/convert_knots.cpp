#include <iostream>
using namespace std; 
#include "convert_knots.hpp"

int main()
{
int knots = 0; 
cout << "Enter interger speed in knots: ";
cin >> knots; 
cout << "Speed in miles per miniute is" <<knots_to_miles_perminute(knots)
<<endl; 

return 0; 
}
