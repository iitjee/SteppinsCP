/*
  Unless you have a specific, compelling reason to use C-style strings, use string (defined in the <string> header) instead. std::string is easier, safer, and more flexible.
  
  no need of importing <string> to use strings
  to use functions like strcpy() etc. on c-style arrays, you need to import <cstring>


*/

string s;
s.length(); /*or*/ s.size(); //to get length of string. strlen works only for c-style strings





//C Style String
char myword[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
char myword[] = "Hello";  //string-literal style (\0 will be autom added)
cout << myword << " has " << sizeof(myword) << " characters.\n"; //(5+1) counts null character also
//If array size is given in declaration, sizeof() returns the size of the entire array regardless of what’s in it.
cout << myword << " has " << strlen(myword) << " letters.\n"; //prints the number of characters before the null terminator

char *t = "hello world";  //also a c-style array

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

char animal[20] = “bear”; 
cout << animal; //animal == animal[0] == address of first character.
//when you pass address of first character to cout, The cout object assumes that the address of a char is the address of a string, so it prints the character 
//at that address and then continues printing characters until it runs into the null character (\0)


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


/*  Pointers and Character Array  */

const char * bird = “wren”;  // bird holds address of string
cout << bird; //"wren"

char animal[20] = “bear”; 
char * ps; // uninitialized
// cout << ps << “\n”; //may display garbage, may cause a crash
// cin >> ps; Too horrible a blunder to try; ps doesn’t  point to allocated space
ps = animal; // set ps to point to string
cout << ps ; //ps == animal[0]== animal. same as cout<<animal;
(int *) animal,  (int *) ps //both will have same address

  //To get a copy of a string, you need to do more. First, you need to allocate memory to hold the string
  ps = new char[strlen(animal) + 1]; // gets new storage. 1 is added to accomodate null character
  strcpy(ps, animal); // copy string to new storage
  (int *) animal,  (int *) ps //now both will have different addresses
    
/*  Note: why did we type cast into (int *) ?
Normally, if you give cout a pointer, it prints an address. But if the pointer is type char *,
cout displays the pointed-to string. If you want to see the address of the string, you have to
type cast the pointer to another pointer type, such as (int *)

Note: How to Copy: Difference between strcpy() and strncpy()
The strcpy() function takes two arguments. The first is the destination address, and the second
is the address of the string to be copied. It’s up to you to make certain that the destination
really is allocated and has sufficient space to hold the copy. 

Note that by using new and strcpy(), you get two separate copies of “fox”.
Also note that something like this:
      strcpy(food, “a picnic basket filled with many goodies”);
can cause problems because the food array is smaller than the string. In this case, the function
copies the rest of the string into the memory bytes immediately following the array, which can
overwrite other memory the program is using. To avoid that problem, you should use
strncpy() instead. It takes a third argument: the maximum number of characters to be
copied. Be aware, however, that if this function runs out of space before it reaches the end of
the string, it doesn’t add the null character. Thus, you should use the function like this:
    strncpy(food, “a picnic basket filled with many goodies”, 19);
    food[19] = ‘\0’;
This copies up to 19 characters into the array and then sets the last element to the null character.
If the string is shorter than 19 characters, strncpy() adds a null character earlier to mark
the true end of the string
*/



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


/* char* vs char[]  */
 // char* and char[] are different types, but it's not immediately apparent in all cases. 
  //This is because arrays decay into pointers, meaning that if an expression of type char[] is provided where one of
  //type char* is expected, the compiler automatically converts the array into a pointer to its first element.
  
  void printSomething(char *p)  //or it can be printSomething(char p[])
{    printf("p: %s",p); }

  //Your example function printSomething expects a pointer, so if you try to pass an array to it like this:
  char s[10] = "hello";
  printSomething(s);
  The compiler pretends that you wrote this:

  char s[10] = "hello";
  printSomething(&s[0]);



