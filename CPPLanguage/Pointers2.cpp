/*
Functions, like data items, have addresses. A function’s address is the memory address at
which the stored machine language code for the function begins.


 if think() is a function, then think is the address of the function.
 
process(think); // passes address of think() to process()
thought(think()); // passes return value of think() to thought()





*/

/*  The "data-type" of a function’s return type and the function’s signature (its argument list) viz the prototype. */
    double pam(int); // prototype
    double (*pf)(int); // pf points to a function that takes one int argument and that returns type double
//Note that this looks just like the pam() declaration, with (*pf) playing the part of pam.
//Because pam is a function, so is (*pf). And if (*pf) is a function, then pf is a pointer to a
//function.

    double (*pf)(int); // pf points to a function that returns double
    double *pf(int); // pf() a function that returns a pointer-to-double
// The declaration requires the parentheses around *pf bcos  Parentheses have a higher precedence than the * operator.

//After you declare pf properly, you can assign to it the address of a matching function:
    double pam(int);  //function decalaration i.e prototype
    double (*pf)(int);
    pf = pam; // pf now points to the pam() function


/*  Function pointer as argument  */
    void estimate(int lines, double (*pf)(int));
// This declaration says the second argument is a pointer to a function that has an int argument
// and a double return value. 
    estimate(50, pam); // function call telling estimate() to use pam()

/* Using a Pointer to Invoke a Function */
   double pam(int);
   double (*pf)(int);
   pf = pam; // pf now points to the pam() function
   double x = pam(4); // call pam() using the function name
   double y = (*pf)(5); // call pam() using the pointer pf
// NOTE: Actually, C++ also allows you to use pf as if it were a function name:
   double y = pf(5); // also call pam() using the pointer pf
// Using the first form is uglier, but it provides a strong visual reminder that the code is using a function pointer.
/* Holy syntax! How can pf and (*pf) be equivalent? One school of thought maintains that because
pf is a pointer to a function, *pf is a function; hence, you should use (*pf)() as a function call. A
second school maintains that because the name of a function is a pointer to that function, a pointer
to that function should act like the name of a function; hence you should use pf() as a function
call. */

    #include <iostream>
    double betsy(int);
    double pam(int);
    // second argument is pointer to a type double function that takes a type int argument
    void estimate(int lines, double (*pf)(int));

    int main()
{
    using namespace std;
    int code;
    cout << “How many lines of code do you need? “;
    cin >> code;
    cout << “Here’s Betsy’s estimate:\n”;
    estimate(code, betsy);
    cout << “Here’s Pam’s estimate:\n”;
    estimate(code, pam);
    return 0;
}

    double betsy(int lns)
    {return 0.05 * lns;}

    double pam(int lns)
    {return 0.03 * lns + 0.0004 * lns * lns;}

    void estimate(int lines, double (*pf)(int))
{
    using namespace std;
    cout << lines << “ lines will take “;
    cout << (*pf)(lines) << “ hour(s)\n”;
}





