/**
  
  * Dictionary (associative containers)
  * An alternative is to write your own hash table. This will require writing a hash function and handling collisions, and lots of testing to make sure you got it right.
  *Internally, the elements in a map are always sorted by its key following a specific strict weak ordering criterion indicated by its internal comparison object (of type Compare).
  * map containers are generally slower than unordered_map containers to access individual elements by their key, but they allow the direct iteration on subsets based on their order
  * Maps are typically implemented as BSTs.




*/


  map<char,int> first;
  first['a']=10;
  first['b']=30;
  first['c']=50;
  first['d']=70;

  map<char,int> second (first.begin(),first.end());

  map<char,int> third (second);

  map<char,int,classcomp> fourth;                 // class as Compare
/* (Defined outside main)
  struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
}; */

  bool(*fn_pt)(char,char) = fncomp;
  /* (defined outside main) bool fncomp (char lhs, char rhs) {return lhs<rhs;} */
  map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

  second=first;                // second now contains 4 ints
  first=std::map<char,int>();  // and first is now empty
  
  cout << "Size of first: " << first.size() << '\n'; //length
  
  /* insertion -1 */
  mymap.insert ( pair<char,int>('a',100) );  
  
  /* insertion -2 (using return value)  */
  pair<map<char,int>::iterator, bool> ret;  //map<char,int>::iterator means iterator to data tyep: map<char,int>
  ret = mymap.insert ( pair<char,int>('z',500) );
  if (ret.second==false) {
    cout << "element 'z' already existed";
    cout << " with a value of " << ret.first->second << '\n';
  }
  
    // second insert function version (with hint position):
  map<char,int>::iterator it = mymap.begin();
  mymap.insert (it, pair<char,int>('b',300));  // max efficiency inserting
  mymap.insert (it, pair<char,int>('c',400));  // no max efficiency inserting

  // third insert function version (range insertion):
  map<char,int> anothermap;
  anothermap.insert(mymap.begin(), mymap.find('c'));

  // showing contents:
  cout << "mymap contains:\n";
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    cout << it->first << " => " << it->second << '\n';
  
  myMap.empty() //check empty
  
  /*  Erasing */
  it=mymap.find('b');
  mymap.erase (it);                   // erasing by iterator

  mymap.erase ('c');                  // erasing by key

  it=mymap.find ('e');
  mymap.erase ( it, mymap.end() );    // erasing by range

  
