#include <gtest/gtest.h>

#include "list.hpp"

using namespace std;
using list::Node;

TEST(ListTests, FromStringBasic) {
    Node* const foo_list_head = list::from_string("foo");
    Node* foo_list = foo_list_head;

    EXPECT_EQ(foo_list->data, 'f');
    // ASSERT instead of EXPECT means: end the test here if this fails, do not try to continue
    // running. This is useful to prevent early crashes.
    ASSERT_NE(foo_list->next, nullptr);
    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    ASSERT_NE(foo_list->next, nullptr);

    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    ASSERT_EQ(foo_list->next, nullptr);

    list::free(foo_list_head);
}

TEST(ListTests, Length) {
    Node* const head = list::from_string("foo");
    EXPECT_EQ(list::length(head), 3);
    list::free(head);
}

// Add remaining tests below. All tests should follow
// the format of `TEST(ListTests, <TestName>){}`.

TEST(ListTests, Compare) {
    Node* hie = list::from_string("hie");
    Node* hit = list::from_string("hit"); 
    Node* hip = list::from_string("hip"); 

    EXPECT_EQ(list::compare(hie, hie), 0); 
    EXPECT_EQ(list::compare(hie,hit), -1); 
    EXPECT_EQ(list::compare(hip, hip), 1); 

    list::free(hie); 
    list::free(hit); 
    list::free(hip); 
}

TEST(ListTests, Compare2){

    Node* hello = list::from_string("hello"); 
    Node* helli = list::from_string("helli"); 
    Node* hella = list::from_string("hella"); 

    EXPECT_EQ(list::compare(hello, hello, 4), 0); 
    EXPECT_EQ(list::compare(hello, helli, 5), -1); 
    EXPECT_EQ(list::compare(hello, hella, 5), 3); 

    list::free(hello); 
    list::free(helli); 
    list::free(hella); 

}

TEST(ListTests, Copy) {
    Node* const head = list::from_string("foo"); 
    Node* myNode = list::copy(head); 

    EXPECT_EQ(list::compare(head, myNode, 0); 

    Node* const hi = list::from_string(""); 
    Node* secondhi = list::copy(hi); 
    EXPECT_EQ(list::compare(hi, secondhi), 0); 

    list::free(head); 
    list::free(myNode); 
    list::free(hi); 
    list::free(secondhi); 
}

TEST(ListTests, Last){
    Node* hi = list::from_string("hi"); 
    Node* myNode = list::from_string("i"); 

    EXPECT(list::compare(last(hi), myNode),0);  

    Node* hey = list::from_string("hey"); 
    Node* end = list::from_string("ey"); 
    EXPECT_NE(list::compare(last(hey), end), 0); 

    list::free(hi); 
    list::free(myNode); 
    list::free(hey);
    list::free(end);
}

Test(ListsTests, Copy){

Node* const head = list::from_string("hi"); 
Node* myNode = list::copy(head); 
EXPECT_EQ(list::compare(head, myNode),0);

Node* const empty = list::from_string("");
Node* newNodes = list::copy(empty);
EXPECT_EQ(list::compare(empty, newNodes),0);

list::free(head);
list::free(myNode);
list::free(empty);
list::free(newNodes);
}

TEST(ListTests, Append){
Node* hi = list::from_string("hi");
Node* hey = list::from_string("hey");
Node* hihey = list::append(hi, hey);
Node* hh = list::from_String("hihey");
EXPECT_EQ(lost::compare(hihey,hh),0);

list::free(hi);
list::free(hey);
list::free(hihey);
list::free(hh);
}

TEST(ListTests, Nth){
Node* hw = list::from_string("HelloWorld");
Node* three = list::nth(hw, 3);
EXPECT_EQ(three-> data, 'l');

Node* five = list::nth(hw,5);
EXPECT_EQ(five->data, 'W');
list::free(hw);
}

TEST(ListTests,Index){
Node* hw = list::from_string("HelloWorld");
Node* w = list::from_string(World);
EXPECT_EQ(list::index(hw,w),5);

Node* w = list::from_string("d");
EXPECT_EQ(list::index(hw,w)9);

Node* empty = list::from_string("");
Node* empty2 = list::from_string("");

EXPECT_EQ(list::index(empty, empty2),0);

list::free(hw);
list::free(w);
}

TEST(ListTests, FindChar){
Node* hw = list::from_string("HelloWorld");
char w = 'W';
Node* world  = list::find_char(hw, w);
Node* findW = list::from_string("World"); 
EXPECT_EQ(list::compare(world, findW),0);

list::free(hw);
list::free(findW);
}

TEST(ListTests, FindList){
Node* sen = list::from_string("have a good day");
Node* good = list::from_string("good");
Node* lf = list::find_list(sen, good);
EXPECT_EQ(list::compare(lf, list::from_string("good day")), 0);
list::free(lf);
list::free(sen);
}

TEST(ListTests, Reverse){
Node* hw = list::from_string("HelloWorld");
Node* rev = list::from_string("dlroWolleH");
Node* revTest = list::reverse(hw);
EXPECT_EQ(list::compare(revTest, rev),0);
Node* empty = list::from_string("");
Node* rev2 = list::from_string("");
Node revTest2 = list::reverse(empty);
EXPECT_EQ(list::compare(rev2, revTest2), 0);

list::free(hw);
list::free(rev);
list::free(revTest); 
list::free(empty);
list::free(rev2);
list::free(revTest2);
}

