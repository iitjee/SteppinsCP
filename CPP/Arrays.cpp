/*



*/


//size of array
  int myints[] = {16,2,77,29};
 int lengthOfmyInts = sizeof(myints) / sizeof(int);
//For these kind of purposes, we always use vector.


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
