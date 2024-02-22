#include "shape.hpp"
#include <iostream>

Shape::Shape(Point center, std::string name): center(center),name(std::move(name))
{
}
void Shape::print(std::ostream& out) const{
out<< this->name << " at(" << this->center.x <<", " << this-> center.y << ") area = " <<
this->area()<<'\n';
}

double Shape::area() const
{
return 0.0; 
}

Shape* Shape::clone() const{ 
return nullptr; 
}

