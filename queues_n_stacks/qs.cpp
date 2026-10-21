#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// Abstract Class function definitions

// Abstract Class

template <typename T> class SimpleList {
private:
  class Node {
    Node *next;
    T data;
  };
  Node *head;
  Node *tail;
  std::string name;

protected:
  void insertAtStart(T data) {
    Node *n = new Node;
    assert(n != nullptr);
    n->data = data;

    /* If the linked list is empty, we just point both tail
     * and head pointers to the same Node (which is now in a single element
     * list) */
    if (head == nullptr) {
      head = (tail = n);
      n->next = nullptr;
    }

    else {
      n->next = head;
      head = n;
    }
  }
  void insertAtEnd(T data) {
    Node *n = new Node;
    assert(n != nullptr);

    n->data = data;
    n->next = nullptr;

    /* We can paste the same function above into this if statement, but
     I feel this is nicer for symmetry reasons, they have the same logic
     though */
    if (tail == nullptr) {
      tail = (head = n);
    }

    else {
      tail->next = n;
      tail = n;
    }
  }
  T removeHeadNode() {
    T data = head->data;
    Node *n = head;
    head = head->next;
    delete n;
    return data;
  }

public:
  SimpleList(std::string n) : name(n) {}

  virtual void push(T data);
  virtual T pop();
};

// Subclass implementations of our abstract fella

template <typename T> class Stack : public SimpleList<T> {
public:
  Stack(std::string name) : SimpleList<T>(name) {}
  void push(T data) { this->insertAtStart(data); }
  T pop() { return this->removeHeadNode(); }
};

template <typename T> class Queue : public SimpleList<T> {
public:
  Queue(std::string name) : SimpleList<T>(name) {}
  void push(T data) { this->insertAtEnd(data); }
  T pop() { return this->removeHeadNode(); }
};

int main(int argc, char *argv[]) {}
