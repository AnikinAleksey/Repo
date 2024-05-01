#include <iostream>
#include <string>
using namespace std;
//Целевой класс "Стек"
template <typename T>
class Stack {
public:
    Stack() {};
    virtual void push(T element) = 0;
    virtual T pop() = 0;
    virtual bool isEmpty() const = 0;
    virtual ~Stack() {}
};




