#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:


  int M;
	//the number of children that each node in the heap can have.
	//needed for indexing.


  PComparator c;
	
	//function called to maintain heap property after inserting and removing
	//called by pop and by push. not by user
	void heapify(int index);

	//function called by push(). not by user. 
	void trickleUp(int index);

	//vector list of items.
	std::vector<T> items;
};

// Add implementation of member functions here

template<typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : M(m), c(c){
}

template<typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){
}


template<typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
	return size_t(items.size());
}

template<typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int index){
	//recursive call to trickledown after popping.
	size_t best = M * index + 1;//start with leftmost child.
	if(best > this->size()){
		return;
	//check if the index of its left-most child is valid by
	//if it is greater than the size var, than it isn't valid.
	}
	size_t dum = best;
	//compare best to all existing children.
	for(int x = 1; x < M; x++){//for every child of index.
		if(dum + x > this->size()){
			//if the child does not exist, then the loop breaks;
			break;
		}
		int other = dum + x;
		if(Heap<T, PComparator>::c(items[other], items[best])){
			best = other;
		}
	}

	if(!(Heap<T, PComparator>::c(items[index], items[best]))){
		T temp = items[index];
		items[index] = items[best];
		items[best] = temp;
		heapify(best);
	}
	//if the child is better than the parent, then swap them.
	//call heapify on the node.
}


template<typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int index){
	int parent = (index - 1)/ M;
	while(parent >= 0 && Heap<T,PComparator>::c(items[index], items[parent])){
		//while top is not reached AND child is better than the parent.
		//inside will happen if child is better than parent.
		T temp = items[parent];
		items[parent] = items[index];
		items[index] = temp;
		//the values of the child and parent are swapped.
		index = parent;
		parent = (parent - 1) / M;
		//the loop moves on the level above.
	}
}

template<typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
	//should work for an empty heap.
	//should work for a full heap.
	//should work for a partially full heap.
	items.push_back(item);
	trickleUp(size() - 1);
	//trickle up called ONCE
}

template<typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
	return (this->size() == 0);
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("Error: Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
	return items.front();
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("Error: Heap is empty");
  }
	//set the first index = to the back node.
	items[0] = items.back();
	items.pop_back();
	heapify(0);
}



#endif