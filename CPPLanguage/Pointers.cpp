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
/* 
  NULL pointer (3 ways of declaring)
int *p1 = nullptr; // nullptr is a literal
int *p2 = 0; // directly initializes p2 from the literal constant 0 (must #include cstdlib)
int *p3 = NULL; // equivalent to int *p3 = 0; (NULL is a preprocessor variable(that #DEFINE wala))
Gentle Note:  The preprocessor is a program that runs before the compiler.
Preprocessor variables are managed by the preprocessor, and are not part of the std
namespace. As a result, we refer to them directly without the std:: prefix. :)
( ModernC++ programs generally should avoid using NULL and use nullptr instead.)
CAUTION: It is illegal to assign an int variable to a pointer, even if the variable’s value happens to be 0.
int zero = 0;
pi = zero; // error: cannot assign an int to a pointer WRONG!!!
Advice: Initialize all Pointers!!
Uninitialized pointers are a common source of run-time errors.
As with any other uninitialized variable, what happens when we use an uninitialized pointer is undefined.
Using an uninitialized pointer almost always results in a run-time crash. 
*/



/*
   Compound Type Declarations
   
// i is an int; p is a pointer to int; r is a reference to int (not the address operator)
int i = 1024, *p = &i, &r = i;
int *p, *q; //both p and q are pointers
int *r, s; //only r is pointer
int *p = &i; (or) int *p; (or) int *p;   
                  p = &i;      *p = i;
 
*/







