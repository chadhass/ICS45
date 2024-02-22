#include "circle.hpp"
#include <iostream>
#include <numbers>

Circle::Circle(Point center, std::name, int radius): Shape(center,name), radius(raidus){
} 
double Circle::area() const{
    return std::numbers::pi * radius * radius; 
} 

void Circle::draw(Std::ostream& out) const{ 
    for(int y=-radius; y<=raiuds; y+=2){ 
        for(int x = -radius; x<=radius; ++x){ 
            out <<(x*x+y*y<=radius*radius ? '*' : ' ');
            }
        out<<'\n'; 
    }
}
Circle* Circle::clone() const{ 
    return new Circle(*this); 
}