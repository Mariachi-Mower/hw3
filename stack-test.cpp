#include "stack.h"
#include "llrec.h"
#include <iostream>

using namespace std;

int main(){
  Stack<Node*> mystack;
  Node* third = new Node(3, NULL);
  Node* second = new Node(2, third);
  Node* first = new Node(1, second);
  mystack.push(first);
  mystack.push(second);
  mystack.push(third);
  for(int x = 0; x < 3; x++){
    Node* temp = mystack.top();
    cout << "top is " << temp->val << endl;
    bool werk = mystack.empty();
    cout << "Empty == " << werk << endl;
    mystack.pop();
  }
  bool werk = mystack.empty();
  cout << "Empty == " << werk << endl;
  mystack.pop();
  return 0;
}