/**

https://github.com/cacophonix/SPOJ/blob/master/SHPATH.cpp

  * priority_queue is just like a normal queue except the element removed from the queue is always the greatest among all the elements in the queue, thus this container is usually used to replicate Max Heap in C++.
  * or in other words, such that its first element is always the greatest of the elements it contains, according to some strict weak ordering criterion.
  * This context is similar to a heap, where elements can be inserted at any moment, and only the max heap element can be retrieved (the one at the top in the priority queue).
  
  *Elements are popped from the "back" of the specific container, which is known as the top of the priority queue.
  



*/


  priority_queue<int> pq1;

 //other constructors
 int myints[]= {10,60,50,20};
 priority_queue<int> second (myints,myints+4); //contains the four ints defined for myints, with 60 (the highest) at its top.
 priority_queue<int, vector<int>, greater<int> > third (myints,myints+4); //Third has the same four ints, but because it uses greater instead of the default (which is less), it has 10 as its top element.
//'greater' is an operator

  pq1.push(30);  // inserts 30 to pq1 , now top = 30
  pq1.push(40);  // inserts 40 to pq1 , now top = 40 ( maxinmum element)
  pq1.push(90);  // inserts 90 to pq1 , now top = 90  
  pq1.push(60);	// inserts 60 to pq1 , top still is 90	
  
  pq1.pop();  // removes 90 (greatest element in the queue)
  pq1.top();
  pq1.empty();
  pq1.size();
  
/* custom comparison operator */
class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const int& lhs, const int& rhs) const
  {
    if (reverse) return (lhs>rhs);
    else return (lhs<rhs);
  }
};

  mypq_type fourth;                       // less-than comparison
  mypq_type fifth (mycomparison(true));   // greater-than comparison
//Fourth and fifth are very similar to first: they are both empty, except that these use mycomparison for comparisons,
//which is a special stateful comparison function that behaves differently depending on a flag set on construction.


