#include "shape.hpp"
#include <iostream>

Shape::Shape(Point center, std::string name): center(center), name(std::move(name)){}
void Shape::print(std::ostream& out) const{
out<< this->name << " at(" << this->center.x <<", " << this-> center.y << ") area = " << this.area()<<'\n';
Shape& Shape::operator=(const Shape& other) = delete{ 
    if(this!=other){ 
    this->name = other.name; 
    this->center = other.center; 
    } 
    return *this; 
}

double Shape::area() const{ 
}

void Shape::draw(std::ostream& out) const{ 
}
Shape* Shape::clone const{ 
}
Shape::Shape(const Shape& other):center(other.center,name(other.name){
}

