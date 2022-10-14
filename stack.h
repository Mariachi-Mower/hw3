#ifndef STACK_H
#define STACK_H
#include <vector>
#include <stdexcept>


// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    //remember all you are doing is just creating the stack behavior on a vector.
    //push and pop back only
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

template<typename T>
Stack<T>::Stack(){
}

template <typename T>
Stack<T>::~Stack(){
}

template<typename T>
bool Stack<T>::empty() const{
  return (std::vector<T>::empty());
}

template<typename T>
size_t Stack<T>::size() const{
  return size_t(std::vector<T>::size());
}

template<typename T>
void Stack<T>::push(const T& item){
  this->push_back(item);
}

template<typename T>
void Stack<T>::pop(){
  if(Stack<T>::empty()){
    throw std::underflow_error("Error stack is empty");
  }
  else{
    this->pop_back();
  }
  //throws std::underflow_error if empty;
}

template<typename T>
const T& Stack<T>::top() const{
  //throws std::underflow_error if empty.
  if(this->empty()){
    throw std::underflow_error("Error stack is empty");
  }
  else{
    return this->back();
  }
}
#endif