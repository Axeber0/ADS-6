// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <stdexcept>

struct SYM {
  char ch;
  int prior;
};
template <typename T>
class TPQueue {
private:
  struct Node {
    T data;
    explicit Node(const T& data) : data(data), next(nullptr) {}
    Node* next;
  };
  Node* head;
public:
  TPQueue() : head(nullptr) {}
  bool isEmpty() const {
    return head == nullptr;
  }
  void push(const T& arg) {
    Node* temp = new Node(arg);
    if (!head || head->data.prior < arg.prior) {
      temp->next = head;
      head = temp;
    }
    else {
      Node* cur = head;
      while (cur->next && cur->next->data.prior >= arg.prior) {
        cur = cur->next;
      }
      temp->next = cur->next;
      cur->next = temp;
    }
  }
  T pop() {
    if (!head) {
      throw std::underflow_error("Stack is empty");
    }
    Node* cur2 = head;
    T val = head->data;
    head = head->next;
    delete cur2;
    return val;
    }
  }
};
#endif  // INCLUDE_TPQUEUE_H_
