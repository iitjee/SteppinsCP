/*
  1. A single pointer can point to several different objects over its lifetime.
  2. Unlike a reference, a pointer need not be initialized at the time.
  3. int *ptr; //ptr is a pointer to any variable, which is of INT type.
  4. Pointers store the address of variables.
  5. ptr = &myIntVariable; (or) *ptr = myIntVariable
  6.  Because references are not objects, they don’t have addresses. Hence, we may not define a pointer to a reference.
  
  
  The value stored in a pointer (which is the address) can be in one of four states:
1. It can point to an object.
2. It can point to the location just immediately past the end of an object.
3. It can be a null pointer, indicating that it is not bound to any object.
4. It can be invalid; values other than the above three are invalid
*/ 

//  NULL pointer (3 ways of declaring)
int *p1 = nullptr; // nullptr is a literal
int *p2 = 0; // directly initializes p2 from the literal constant 0 (must #include cstdlib)
int *p3 = NULL; // equivalent to int *p3 = 0; (NULL is a preprocessor variable(that #DEFINE wala))
//( ModernC++ programs generally should avoid using NULL and use nullptr instead.)
/*
Gentle Note:  The preprocessor is a program that runs before the compiler.
Preprocessor variables are managed by the preprocessor, and are not part of the std
namespace. As a result, we refer to them directly without the std:: prefix. :)
CAUTION: It is illegal to assign an int variable to a pointer, even if the variable’s value happens to be 0.
int zero = 0;
pi = zero; // error: cannot assign an int to a pointer WRONG!!!
Advice: Initialize all Pointers!!
Uninitialized pointers are a common source of run-time errors.
As with any other uninitialized variable, what happens when we use an uninitialized pointer is undefined.
Using an uninitialized pointer almost always results in a run-time crash. 
*/



/*  Compound Type Declarations */
// i is an int; p is a pointer to int; r is a reference to int (not the address operator)
int i = 1024, *p = &i, &r = i;

int *p, *q; //both p and q are pointers
int *r, s; //only r is pointer

int *p = &i; (or) int *p; (or) int *p;   
                  p = &i;      *p = i;
 
char * ps; // uninitialized
cout << ps << “\n”; //may display garbage, may cause a crash
cin >> ps; //Too horrible a blunder to try; ps doesn’t  point to allocated space

double wages[3] = {10000.0, 20000.0, 30000.0};
short stacks[3] = {3, 2, 1};
// Here are two ways to get the address of an array
double * pw = wages; // name of an array = address
short * ps = &stacks[0]; // or use address operator

stacks[0], stacks[1], stacks[2] //3, 2, 1
*stacks,  *(stacks + 1), *(stacks+2) //3, 2, 1
//arrayname[i] == *(arrayname + i)
  
sizeof(wages), sizeof(pw) //24, 4
//IMP NOTE: both pw and wages refer to the same array. But applying the sizeof operator to them produces the above results.
//This is one case in which C++ doesn’t interpret the array name as an address.

  
/*  New Operator  */
double * pn; // pn can point to a double value
double * pa; // so can pa
char * pc; // pc can point to a char value
double bubble = 3.2;
pn = &bubble; // assign address of bubble to pn
pc = new char; // assign address of newly allocated char memory to pc
pa = new double[30]; // assign address of array of 30 double to pa
  
  
/*  Dynamic Binding and Static Binding for Arrays */
int tacos[10]; // static binding, size fixed at compile time
int size;
cin >> size;
int * pz = new int [size]; // dynamic binding, size set at run time
...
delete [] pz; // free memory when finished


/*  Pointers and Strings  */
//The special relationship between arrays and pointers extends to C-style strings.
  char flower[10] = “rose”;
  cout << flower << “s are red\n”;
//Ofcourse, 'flower' == flower[0] is the address of the char element containing the character r.
//However, The cout object assumes that the address of a char is the address of a string, so it prints the character 
//at that address and then continues printing characters until it runs into the null character (\0)

// This implies that you can use a pointer-to-char variable as an argument to cout, also, because it, too, is the address of a char. 





/*  Pointers for user-defined types like Structs  */
struct temp {
    int i;
    float f;
};
    temp sampleTemp;
    temp *ptr;  //Creates a pointer ptr of type structure temp
    
    ptr = &sampleTemp;
    cin>>(*ptr).i>>(*ptr).f;
/* or */
    cin>> ptr->i >> ptr->f
//Note:  Since pointer ptr is pointing to variable d in this program, (*ptr).inch and d.inch is exact same cell.
//Similarly, (*ptr).feet and d.feet is exact same cell.

/*  Using new to Create Dynamic Structures    */
/*  You’ve seen how it can be advantageous to create arrays during runtime rather than at compile
time. The same holds true for structures. You need to allocate space for only as many structures
as a program needs during a particular run. Again, the new operator is the tool to use.
With it, you can create dynamic structures. Again, dynamic means the memory is allocated
during runtime, not at compile time */
//Using new with structures has two parts: creating the structure and accessing its members. 
struct inflatable // structure template
{
char name[20];
float volume;
double price;
};
inflatable * ps = new inflatable; //This assigns to ps the address of a chunk of free memory large enough to hold a structure of the inflatable type

/* The tricky part is accessing members. When you create a dynamic structure, you can’t use the
dot membership operator with the structure name because the structure has no name. All you
have is its address. For this you've to use the arrow membership operator (->).
   This operator, formed by typing a hyphen and then a greater-than symbol, does
for pointers to structures what the dot operator does for structure names. 

A second, uglier approach to accessing structure members is to realize that if ps is a pointer to
a structure, then *ps represents the pointed-to value—the structure itself. Then, because *ps
 a structure, (*ps).price is the price member of the structure. C++’s operator precedence
rules require that you use parentheses in this construction
*/
cin.get(ps->name, 20); // method 1 for member access
cin >> (*ps).volume; // method 2 for member access
cin >> ps->price;

delete ps; // free memory used by structure


/*   Using new and delete */
char temp[80]; // temporary storage
cout << “Enter last name: “;
cin >> temp;
char * pn = new char[strlen(temp) + 1];
strcpy(pn, temp); // copy string into smaller space

delete [] pn; // memory freed. But the variable is still there.. just deallocated.

pn = new char[2]; //note that we haven't written char *pn = new char[2]; 




/* Pointer to Pointer */
   int  var;
   int  *ptr;
   int  **pptr;

   var = 3000;

   // take the address of var
   ptr = &var;

   // take the address of ptr using address of operator &
   pptr = &ptr;

   // take the value using pptr
   cout << "Value of var :" << var << endl;
   cout << "Value available at *ptr :" << *ptr << endl;
   cout << "Value available at **pptr :" << **pptr << endl;

/*  Pointer Arithmetic  
The near equivalence of pointers and array names stems from pointer arithmetic and how C++
handles arrays internally. */

double wages[3] = {10000.0, 20000.0, 30000.0};
short stacks[3] = {3, 2, 1};
// Here are two ways to get the address of an array
double * pw = wages; // name of an array = address
short * ps = &stacks[0]; // or use address operator

pw, *pw //0012FEBC, 10000
pw = pw + 1;
pw, *pw //0012FEC4, 20000
// Adding one to an integer variable increases its value by one, but adding one to a pointer variable increases
// its value by the number of bytes of the type to which it points. 

