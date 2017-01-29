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








