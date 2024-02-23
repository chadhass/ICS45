#include "rectangle.hpp"

// class Square 
class Square: public Rectangle{ 
    public: 
    using Rectangle::Recangle; 
    Square(Point center, std::string name, int side); 
    private:
    int side; 
}; 
