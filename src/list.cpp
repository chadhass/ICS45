#include <iostream>
#include "list.hpp"

namespace list{

Node* from_string(const char* s){
    if(!s || s[0] == '\0') { 
    return nullptr; 
    }

    Node* head = new Node{.data = *s, .next = nullptr}; 
    Node* p = head; 
    ++s; 

while(*s != '\0'){ 
    p->next = new Node{.data = *s, .next = nullptr}; 
    p = p->next; 
    ++s; 
 }
    return head; 
}

void free(Node* head){ //delete linked list nodes
    while(head!=nullptr){
        Node* nextDel = head->next; 
        delete head; 
        head = nextDel; 
    }
}

void print(std::ostream& out, Node*head){
    for(Node* h = head; h!= nullptr; h=h->next){
    out << h->data; 
    }
}

Node* copy(Node* head){
    if(head != nullptr){
    Node * cHead = new Node{.data = head ->data, .next = nullptr}; 
    Node *p = cHead; 
    for(Node* loopP = head->next; loopP != nullptr; loopP = loopP->next){
         cHead-> next = new Node{.data = p->data, .next = nullptr}; 
        cHead = cHead-> next; 
         }
    return p; 
    }
    else { return nullptr; }
}

int compare(Node* lhs, Node* rhs){
     Node* l = lhs; 
     Node* r = rhs; 
     while(l != nullptr && r != nullptr){
        if(l->data != r-> data){
        return l->data - r->data;
        }
    l = l->next; 
    r = r->next; 

}
    if(l == nullptr && r == nullptr){
    return 0; 
    }
    else if(l == nullptr){
        return -1; 
    }else{
    return 1; 
    }
}

int compare(Node* lhs, Node* rhs, int n){
    Node* l = lhs; 
    Node* r = rhs; 

    for(int i = 0; i <n; i++){
    if(!l && !r){
    return 0; 
    }
    else if(!l){
    return -1; 
    }
    else if(!r){
    return 1;
    }
    else if(l->data !=  r->data){ 
    return l->data - r->data; 
    }
    l = l-> next; 
    r = r -> next; 
    }
    return 0; 
}

int length(Node* head){ 
    if(head == nullptr) { return 0; }
    int len = 0;
    for(Node* loopP = head; loopP != nullptr; loopP = loopP ->next){
        ++len; 
    }
    return len; 
}

Node* reverse(Node*head){
    Node* rev = copy(head); 
    Node* prev = nullptr; 
    Node* rprev = rev; 
    Node* next = nullptr; 

    while(rprev != nullptr && rprev->data != '\0'){
        next = rprev->next; 
        rprev->next = prev; 
        prev = rprev; 
        rprev = next; 
    }
    return prev; 
}

Node* append(Node* lhs, Node* rhs){
    if(lhs == nullptr){
    return copy(rhs); 
    }

    Node* l = copy(lhs); 
    
    Node* end = last(l); 

    end->next = copy(rhs); 
    
    return l; 
}

int index(Node* head, Node* node){
    Node* h = head; 
    int index = 0; 
    while(h!=nullptr){
    if(compare(h, node) ==0){
        return index; 
    }
    h = h->next; 
    ++index; 
    }
    return -1; 
}

Node* find_char(Node*head, char c){
    Node *h = head; 
    while(h != nullptr){
        if(h->data != c){
            h  = h->next; 
        }
        else{
            return h; 
        }
    }
    return h; 
}

Node* find_list(Node* haystack, Node* needle){
    if(haystack ==nullptr){ return nullptr; }
    Node* h = haystack; 
    Node* n = needle; 
    const int needleLen =  length(needle); 
    Node* find = nth(haystack, length(needle)-1); 
    bool Nfound = false; 
    while(find != nullptr && !Nfound)
    {
        if(compare(n,h, needleLen) == 0)
        {
            return h; 
        } else{
        h = h->next; 
        find = find->next; 
        }
     }
    return nullptr; 
}

Node* nth(Node* head, int n){
    Node* h = head; 
    
    for(int i = 0; i<n && h != nullptr; ++i){
        h = h->next; 
    }
    return h; 
}

Node* last(Node* head){
    if(head == nullptr) { return nullptr;}
    Node* last = head; 
    while( last -> next != nullptr){
        last = last->next; 
    }
    return last; 
}
}

