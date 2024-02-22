#include "picture.hpp"
#include <iostream>
#include <utility>

Picture::Picture():head(nullptr), tail(nullptr){
}

//copy and move constructors 
Picture::Picture(const Picture& other): head(nullptr), tail(nullptr){
    ListNode* p = other.head; 
    while(p != nullptr){
    this->add(*(p->shape)); 
    p = p->next;
    }
}
Picture::Picture(Picture&& other): head(other.head), tail(other.tail){
    other.head = nullptr; 
    other.tail=nullptr; 
}

void Picture::swap(Picture& other){
    std::swap(head, other.head); 
    std::swap(tail,other.tail); 
}

Picture& Picture::operator=(const Picture& other)
{
    Picture p(other); 
    swap(p); 
    return *this; 
}

Picture& Picture::operator=(Picture&& other){
    if(this != &other){
        ListNode* temp = head; 
        while(temp != nullptr){
        ListNode* del = temp; 
        temp = temp-> next; 
        delete del->shape; 
        delete del; 
    }

this->head = other.head; 
this-> tail = other.tail; 

other.head = nullptr; 
other.tail = nullptr; 
}
return *this; 
}

void Picture::add(const Shape& shape){
    Shape* newShape = shape.clone(); 
    ListNode* n = new ListNode; 
    
    n->shape = newShape; 
    n->next = nullptr; 
    if(!head){
        head = n; 
        tail = n; 
    }
    else{
        tail->next = n; 
        tail =n; 
    }
}

void Picture::print_all(std::ostream& out) const{
    ListNode* n = head; 
    while(n!=nullptr){
        Shape* currentShape = n->shape; 
        pShape->prnt(out); 
        pShape->draw(out); 
        n = n->next; 
    }
}

void Picture::draw_all(std::ostream& out) const{
    ListNode*  n = head;    
    while(n!=nullptr){
    Shape* pShape = n->shape; 
    pShape->print(out); 
    pShape->draw(out); 
    n = n->next; 
    }
}

double Picture::total_area() const{
    ListNode* n = head; 
    double area = 0.0; 
    while(n!=nullptr){
        Shape* pShape = n->shape; 
        area += pShape->area(); 
        n = n->next; 
    }
    return area; 
}

Picture~Picture(){
    ListNode* n = head; 
    while(current != nullptr){
        ListNode* del = cur; 
        cur = cur->next; 
        delete del->shape; 
        del del; 
    }
    head=nullptr; 
    tail=nullptr; 
}
