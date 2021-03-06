/*
//Initialization of Vectors

  std::vector<int> first;                                // empty vector of ints
  std::vector<int> vi1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  std::vector<int> second (4,100);                       // four ints with value 100
  
  std::vector<int> third (second.begin(),second.end());  // iterating through second vector
  
  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::vector<int> fourth (third);                       // a copy of third





*/


/* DEMO */
#include <iostream>
#include <vector>
using namespace std;

int main( int argc, char ** argv ) {
    cout << "vector from initializer list: " << endl;
    vector<int> vi1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    
    cout << "size: " << vi1.size() << endl;
    cout << "front: " << vi1.front() << endl;
    cout << "back: " << vi1.back() << endl;
    
    // iterator and iterating through vector
    vector<int>::iterator itbegin = vi1.begin(); /*(or)*/ auto itbegin = vi1.begin();
    vector<int>::iterator itend = vi1.end();
    for (auto it = itbegin; it < itend; ++it) {
        cout << *it << ' ';
    }

  //Note: begin() returns an iterator that can be used to iterate through the collection, 
  //while front() just returns a reference to the first element of the collection  
  
    cout << "element at 5: " << vi1[5] << endl;
    cout << "element at 5: " << vi1.at(5) << endl;
    
    cout << "range-based for loop:" << endl;
    for (int & i : vi1) {
        cout << i << ' ';
    }

    
    cout << "insert 42 at begin + 5: " << endl;
    vi1.insert(vi1.begin() + 5, 42);
    cout << "size: " << vi1.size() << endl;
    cout << "vi1[5]: " << vi1[5] << endl;
    
    cout << "erase at begin + 5: " << endl;
    vi1.erase(vi1.begin() + 5);
    cout << "size: " << vi1.size() << endl;
    cout << "vi1[5]: " << vi1[5] << endl;
    
    cout << "push_back 47: " << endl;
    vi1.push_back(47);  //pop_back() is opposite
    cout << "size: " << vi1.size() << endl;
    cout << "vi1.back() " << vi1.back() << endl;
    
    cout << "range-based for loop: " << endl;
    for(int & v : vi1) {
        cout << v << ' ';
    }
    cout << endl << endl;
    
    // from C-array - Old Style of making vectors
    int ia[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << "vector from C-array: " << endl;
    vector<int> vi2(ia, ia + + sizeof(ia)/sizeof(int) ));
    for( int & i : vi2 ) {
        cout << i << ' ';
    }
    cout << endl << endl;
    
    // vector of strings
    cout << "vector of strings:" << endl;
    vector<string> vs = { "one", "two", "three", "four", "five" };
    for(string & v : vs) {
        cout << v << endl;
    }
    
    return 0;
}


