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

/*Convert char to int in C and C++ */
char a = '4';
int ia = a - '0';

/*  read the value as an ascii code */
char a = 'a';
int ia = (int)a;  // note that the int cast is not necessary -- int ia = a would suffice

/*  Check if character is a digit */
#include <ctype.h>
int main ()
{
  char str[]="1776ad";
  int year;
  if (isdigit(str[0]))
  {
    year = atoi (str);  //see below how atoi(str) works
    printf ("The year that followed %d was %d.\n",year,year+1);
  }
}`

/*  atoi(string)  */
//Parses the C-string str interpreting its content as an integral number, which is returned as a value of type int.
//The function first discards as many whitespace characters (as in isspace) as necessary until the first non-whitespace character is found. 
//Then, starting from this character, takes an optional initial plus or minus sign followed by as many base-10 digits as possible, and interprets them as a numerical value.
//The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
char buffer[256] = "73bc";
i = atoi (buffer);
printf ("The value entered is %d. Its double is %d.\n",i,i*2);  //73 and 146 ("bc" is ignored)




