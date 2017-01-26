/*


Stacks are a type of 'container adaptor', specifically designed to operate in a LIFO context 

*/


stack.empty()
stack.size()  //number of elements
stack.top()   //Returns a reference to the top element in the stack. You can also 'modify' top element
stack.push(elem)
stack.pop() //Removes the element on top of the stack, effectively reducing its size by one.


#include <iostream>       
#include <stack>       

int main ()
{
  stack<int> mystack;
  int sum (0);

  for (int i=1;i<=10;i++) mystack.push(i);

  while (!mystack.empty())
  {
     sum += mystack.top();
     mystack.pop();
  }

  std::cout << "total: " << sum << '\n';

  return 0;
}




