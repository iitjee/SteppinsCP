/*



*/


//size of array
  int myints[] = {16,2,77,29};
 int lengthOfmyInts = sizeof(myints) / sizeof(int);
//For these kind of purposes, we always use vector.

//postfix operator
int x = 1;
int y = myints[x++];	//note that value of y is myints[1] and then x is incremented to 2.

/* Multi-Dimensional Arrays */
int myarray[3][5]; // a 3-element array of 5-element arrays
//3-rows 5-cols {Row-Major Order}
	
int array[3][5] = { 0 };  //initialized to all zeros
int array[3][5] =
{
{ 1, 2, 3, 4, 5 }, // row 0
{ 6, 7, 8, 9, 10 }, // row 1
{ 11, 12, 13, 14, 15 } // row 2
};

int array[3][5] = /*C++ will replace missing initializers with 0*/
{
{ 1, 2  }, // row 0 = 1, 2, 0, 0, 0
{ 6, 7, 8 }, // row 1 = 6, 7, 8, 0, 0
{ 11, 12, 13, 14 } // row 2 = 11, 12, 13, 14, 0
};

/*Two-dimensional arrays with initializer lists can omit (only) the leftmost length specification:*/
int array[][5] =
{
{ 1, 2, 3, 4, 5 },
{ 6, 7, 8, 9, 10 },
{ 11, 12, 13, 14, 15 }
};

for (int row = 0; row < numRows; ++row) // step through the rows in the array
    for (int col = 0; col < numCols; ++col) // step through each element in the row
          cout << array[row][col];

/* Multiplication Example */`
int main()
{
    // Declare a 10x10 array
    const int numRows = 10;
    const int numCols = 10;
    int product[numRows][numCols] = { 0 };
 
    // Calculate a multiplication table
    for (int row = 0; row < numRows; ++row)
        for (int col = 0; col < numCols; ++col)
            product[row][col] = row * col;
 
    // Print the table
    for (int row = 1; row < numRows; ++row)
    {
        for (int col = 1; col < numCols; ++col)
            std::cout << product[row][col] << "\t";
 
        std::cout << '\n';
    }
 
    return 0;
}

/* Row major and Column major	*/
   A11  A12  A13
   A21  A22  A23
   A31  A32  A33

Row major: elements of an array are filled up row-by-row such that the first row elements are stored first, then the second row and so on.
	=> A11  A12  A13 A21  A22  A23  A31  A32  A33
eg: Most of the high level programming languages like C/C++, Java, Pascal, NumPy etc use this method for storing multidimensional arrays.
	OFFSET = rowIndex*(noOfColums)+colIndex
	
Column major: elements of the first column are stored first, then the next column elements and so on
	=> A11 A21 A31 A12 A22 A32 A13 A23 A33
eg: used in Fortran, OpenGL and OpenGL ES, MATLAB, GNU Octave, S-Plus, R, Julia, Rasdaman, Scilab.
	OFFSET = colIndex*(noOfRows)+rowIndex
	


/*	There are three ways to pass a 2D array to a function:	*/

//1.The parameter is a 2D array
int array[10][10];
void passFunc(int a[][10])
{
    // ...
}
passFunc(array);
//2.The parameter is an array containing pointers
int *array[10];
for(int i = 0; i < 10; i++)
    array[i] = new int[10];
void passFunc(int *a[10]) //Array containing pointers
{
    // ...
}
passFunc(array);
//3.The parameter is a pointer to a pointer
int **array;
array = new int *[10];
for(int i = 0; i <10; i++)
    array[i] = new int[10];
void passFunc(int **a)
{
    // ...
}
passFunc(array);
