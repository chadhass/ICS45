#include "shape.hpp"
#ifndef CIRCLE_HPP 
#define CIRCLE_HPP
// class Circle 

class Circle : public Shape{
public:
    Circle(Point center, std::string name, int radius);
    void draw(std::ostream& out) const override; 
    double area() const override; 
    Circle* clone() const override; 
protected: 
    Circle(const Circle& other) = default; 
private:
    int radius; 
}; 
#endif
