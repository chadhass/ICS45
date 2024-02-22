#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iosfwd>
#include <string>

// class Shape 

struct Point{
    int x; 
    int y; 
}; 

class Shape{
public:
    //construct this Shape with given center and name 
    Shape(Point center, std::string name); 
    //prints shapes name and cordinate in this format followed by a newline
    void print(std::ostream& out) const; 
    //delete assignment to prevent accidental slicing 
    Shape& operator=(const Shape& other); 
    //computes and returns the area of this Shape 
    virtual double area() const = 0; 
    //draws this Shape using graphics 
    virtual void draw(std::ostream& out) const =0; 
    //creates a new duplicate of this Shape, allocated from the free store 
    //must be overriden by each concrete class 
    virtual Shape* clone() const = 0; 
    //clean up any sub-storage owned by this Shape object 
    virtual ~Shape() = default; 
    protected:
    Shape(const Shape& other) = default; 
    //protect the copy constructor to be used by clone()
    private: 
    //position coordinares, used to illustrate inheritance 
    Point center; 
    std::string name; //name of this string 
}; 
#endif 
