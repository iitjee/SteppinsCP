
/* Look @last for istringstream and ostrinstream variants

stringstream is a stream class to operate on strings.

Objects of this class use a string buffer that contains a sequence of characters. 
This sequence of characters can be accessed directly as a string object, using member str 

One common use of this class is to parse comma-separated(aka CSV files) integers from a string


*/

#include <sstream>
stringstream ss("23,4,56"); //(or) stringstream ss; ss.str("23,4,56");
char ch;
int a, b, c;
ss >> a >> ch >> b >> ch >> c;  // a = 23, b = 4, c = 56


#include <sstream>
stringstream ss;

ss << myString;
ss << myCstring;
ss << myInt;  //or flot or double

ss >> myChar; 
ss >> myCstring; 
ss >> myInt; //This is also an easy way to convert strings of digits into ints, floats or doubles

string s = ss.str(); //similar to cin>> .You can get the entire contents of the stringstream as a single C++ string:

  ss.str ("Example string");
  string s = ss.str();
  cout << s << '\n';

//note that str() has two forms:
//ss.str() with no arguments => cin (getting)
//ss.str("someContent") => setting


//


/*  Converting string of digits into individual ints  */
//this is input string (file)
1,3,10,3,1
1,10,10,3,10
1,,,,
0,0,0,1,10
1,1,0,2,2
10,1,0,1,10


// when we try to strore this in 6*5 int array we get
1 3 10 3 1
1 10 10 3 10
1 0 0 0 0
0 0 0 1 10
1 1 0 2 2
10 1 0 1 10

//Code for that:
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

const int ROWS = 6;
const int COLS = 5;
const int BUFFSIZE = 80;

int main() {
  int array[ROWS][COLS];
  char buff[BUFFSIZE]; // a buffer to temporarily park the data
  ifstream infile("input.txt");
  stringstream ss;
  for( int row = 0; row < ROWS; ++row ) {
	// read a full line of input into the buffer (newline is
	//  automatically discarded)
	infile.getline( buff,  BUFFSIZE );
	// copy the entire line into the stringstream
	ss << buff;
	for( int col = 0; col < COLS; ++col ) {
	  // Read from ss back into the buffer.  Here, ',' is
	  //  specified as the delimiter so it reads only until
	  //  it reaches a comma (which is automatically
	  //  discarded) or reaches the 'eof', but of course
	  //  this 'eof' is really just the end of a line of the
	  //  original input.  The "6" is because I figured
	  //  the input numbers would be 5 digits or less.
	  ss.getline( buff, 6, ',' );
	  // Next, use the stdlib atoi function to convert the
	  //  input value that was just read from ss to an int,
	  //  and copy it into the array.
	  array[row][col] = atoi( buff );
	}
	// This copies an empty string into ss, erasing the
	//  previous contents.
	ss << ""; 
	// This clears the 'eof' flag.  Otherwise, even after 
	//  writing new data to ss we wouldn't be able to
	//  read from it.
	ss.clear();
  }
  // Now print the array to see the result
  for( int row = 0; row < ROWS; ++row ) {
	for( int col = 0; col < COLS; ++col ) {
	  cout << array[row][col] << " ";
	}
	cout << endl;
  }
  infile.close();
}

/* The above code was set up explicitly to load data into a 6x5 array because that's what a particular application required, but it can be easily modified to read an entire input file of indeterminate length using a while loop, i.e.
while( infile.getline( buff, 50 ) ) , containing lines with any number of comma-separated values (as long as a big enough buffer is provided). 
(for that more generalized code, see @below http://www.dreamincode.net/forums/topic/95826-stringstream-tutorial/
*/


/* istringstream and ostringstream
Personally I find it very rare that I want to preform streaming into and out of the same string stream. (the case of stringstream)
Usually I want to either initialize a stream from a string and then parse it; or stream things too a string stream and
then extract the result and store it.

If you're streaming to and from the same stream you have to be very careful with the stream state and stream positions.

Using 'just' istringstream or ostringstream better expresses your intent and gives you some checking against silly mistakes
such as accidental use of << vs >>.

There might be some performance improvement but I wouldn't be looking at that first.

*/

