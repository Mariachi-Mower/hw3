#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************



void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  head = split(head, smaller, larger, pivot);
}



Node* split(Node *&head, Node *&smaller, Node*&larger, int pivot){
  if(head == nullptr){
    smaller = nullptr;
    larger = nullptr;
    return nullptr;
  }
  if(head->val > pivot){//if the number is larger.
    larger = head;
    return split(head->next, smaller, larger->next, pivot);
  }
  else{//if number is smaller(head->val <= pivot)
  //if number is equal to pivot also added.
    smaller = head;
    return split(head->next, smaller->next, larger, pivot);
  }
}

