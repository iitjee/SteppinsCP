/*

1. In a set, key = value and each value must be unique. (**i.e even if you add same elements, the final result don't have any 
dupliactes and will be sorted :) )
2. The value of the elements in a set cannot be modified once in the container (the elements are always const),
   but they can be inserted or removed from the container.
3. By default, all elements are ordered lexicographically. (We can override the default behavior though! ;) )
4. Internally uses BST


PROBLEMS: 
https://www.codechef.com/problems/STONES/ 
https://discuss.codechef.com/questions/3616/stones-editorial
*/



/* Initialization */
//1 creates a set of integers, named first
set<int> first; 

//2(1) Range based
  int myints[]= {10,20,30,40,50};
  set<int> second (myints,myints+5);
  
//2(2) Range based
  set<int> fourth (second.begin(), second.end()); //begin() and end() are iterators pointing to first and last elems
  
   string s = "Hello World";
   set<char> S(s.begin(),s.end());

//3  Copy constructor
  set<int> third (second); 

//Note: actually we've to write std::set. It's assumed we've declared 'using namespace std;'


//4 Overriding DEFAULT CONSTRUCTOR. eg: Here we are overriding the default comparator with that which sorts by the length rather than 
alphabet
  set<int, myCustomComparator> fifth; //myCustomComparator is basically a struct
  
  struct myCustomComparator { 
  bool operator() (const string &first, const string &second) //should define operator in a struct
  {
  int length1 = first.length();
  int length2 = second.length();
  
  if(length1 != length2) return length1<length2;
  return (first<second);
  }
  };
  

//5 Iterating through elements of a set.
for (set<char>::iterator i = mySet.begin(); i != mySet.end(); i++) {//we declare iterator to a set element like this only set<char>::iterator
   char element = *i;
   cout<<element;
}

//6 Searching for an element in a set
mySet.count(valueYouAreSearchingFor); 
//this returns the count of values in the set matching with your value. But since all elements are unique, 
// the result will be either 1 or 0! ;)


// Insertion and Deletion
