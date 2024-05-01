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
//Класс узла списка
template <typename T>
class Node  {
public:
    T data;
    Node <T>* next;
    Node(T value) : data(value), next(nullptr) {}
};
// Адаптируемый класс "Связный список"
template <typename T>
class List {
private:
    Node<T>* head;
public:
    List() : head(nullptr) {}
    void addToEnd(T element) {
        Node<T>* newNode = new Node<T>(element);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node<T >* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    T removeFromEnd() {
        if (head != nullptr) {
            if (head->next == nullptr) {
                T tmp = head->data;
                delete head;
                head = nullptr;
                return tmp;
            }
            else {
                Node<T>* current = head;
                while (current->next->next != nullptr) {
                    current = current->next;
                }
                T tmp = current->next->data;
                delete current->next;
                current->next = nullptr;
                return tmp;
            }
        }
    }
    bool isEmpty() const {
        return head == nullptr;
    }
    ~List() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
    }
};



