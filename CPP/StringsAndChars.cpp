/*
  no need of importing <string>


*/

string s;
s.length(); /*or*/ s.size(); //to get length of string. strlen works only for c-style strings






char myword[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
char myword[] = "Hello";  //string-literal style

//Expressions (once myword has already been declared as above), such as below are NOT Valie:
myword = "Bye";   //NOT VALID
myword[] = "Bye"; //NOT valid
myword = { 'B', 'y', 'e', '\0' }; //NOT valid

//This is because arrays cannot be assigned values. 
//Note, though, that each of its elements can be assigned a value individually.
myword[0] = 'B';
myword[1] = 'y';
myword[2] = 'e';
myword[3] = '\0';

  char question1[] = "What is your name? ";
  string question2 = "Where do you live? ";
  char answer1 [80];
  string answer2;

/* Note that strings and char arrays are quite interchangeable in their use with cin and cout */
  cout << question1;
  cin >> answer1;
  cout << question2;
  cin >> answer2;

  cout << "Hello, " << answer1;
  cout << " from " << answer2 << "!\n";

//Note that char arrays are of fixed size specified implicitly or explicitly
//However, strings have a dynamic size determined during runtime, while the size of arrays is determined on compilation, before the program runs.


/*  In any case, null-terminated character sequences and strings are easily transformed from one another: */
char myntcs[] = "some text";
string mystring = myntcs;  // convert c-string to string
cout << mystring;          // printed as a library string
cout << mystring.c_str();  // printed as a c-string 
cout << mystring.data();   //same as c_str()

