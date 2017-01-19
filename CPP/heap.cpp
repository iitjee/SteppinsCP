/*
Depending on your language you may be familiar with the term heap as an area of memory where you allocate objects…but that's not what we're talking about here.
…A heap is a specific data structure we can use for our own purposes mainly to pick out the largest/smallest element.(=> useful in making priority queues)
…They're often used in sorting algorithms you may…have even heard of something called a heap sort.
…But they're also a way of implementing other abstract data types like the priority queue.
…Heaps are usually implemented as a binary tree, not…a binary search tree but still, a binary tree.…

A collection of parent child nodes with a…maximum of two children under any one parent.
…But there's a different, simple rule that we use to give…a heap a totally different internal structure to a binary search tree.
…So the basics, heaps are a collection of objects.
***As we add items to this heap, they are always add top to bottom, left to right.*** (better see lyn video)
…We completely fill out any level before moving on to the next.
…So we don't have to worry about the…tree becoming unbalanced like a binary search tree can.…

Min Heap vs Max Heap:



*/



//operations:
//***Remember these are certain 'functions' operating on iterators***
make_heap(startingIter, EndingIter)
sort_heap(startingITer, EndingITer)
push_heap(startingIter, EndingIter)
pop_heap(startingIter, EndingIter)



// range heap example
#include <iostream>     // std::cout
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector
using namespace std;
int main () {
  int myints[] = {10,20,30,5,15};
  vector<int> v(myints,myints+5);

  make_heap (v.begin(),v.end());
  cout << "initial max heap   : " << v.front() << '\n';

  pop_heap (v.begin(),v.end()); 
  v.pop_back();
  cout << "max heap after pop : " << v.front() << '\n';

  v.push_back(99); 
  push_heap (v.begin(),v.end());
  cout << "max heap after push: " << v.front() << '\n';

  sort_heap (v.begin(),v.end());

  cout << "final sorted range :";
  for (unsigned i=0; i<v.size(); i++)
    cout << ' ' << v[i];

  return 0;
}
