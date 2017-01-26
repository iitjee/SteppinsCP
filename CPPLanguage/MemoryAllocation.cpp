
dynamically allocate memory in your C program using C standard library(stdlib.h) functions:
malloc(), 
calloc(), 
free() and 
realloc()


- allows you to manually handle memory space for your program.


malloc():
    ptr = (cast-type*) malloc(byte-size)
Allocates requested size of bytes and returns a pointer first byte of allocated space
returns a pointer of type void which can be casted into pointer of any form.
 If the space is insufficient, allocation fails and returns NULL pointer.
 
 ptr = (int*) malloc(100 * sizeof(int)); //This statement will allocate either 200 or 400 according to size of int 2 or 4 bytes respectively and the pointer points to the address of first byte of memory.
 struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
 stack->array = (int*) malloc(stack->capacity * sizeof(int));
 struct StackNode* stackNode = (struct StackNode*) malloc(sizeof(struct StackNode));
 

calloc(): contiguous allocation
  ptr = (cast-type*)calloc(n, element-size);
The only difference between malloc() and calloc() is that, malloc() allocates single block of memory whereas calloc() allocates multiple blocks of memory each of same size and sets all bytes to zero.
  
  ptr = (float*) calloc(25, sizeof(float)); //This statement allocates contiguous space in memory for an array of 25 elements each of size of float, i.e, 4 bytes.
  
 free(): 
 Dynamically allocated memory created with either calloc() or malloc() doesn't get freed on its own. You must explicitly use free() to release the space.
  free(ptr);    //frees the space allocated in the memory pointed by ptr
  
Eg1 : Using C malloc() and free()
Write a C program to find sum of n elements entered by user. To perform this program, allocate memory dynamically using malloc() function.
  #include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, *ptr, sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &num);

    ptr = (int*) malloc(num * sizeof(int));  //memory allocated using malloc
    if(ptr == NULL)                     
    {
        printf("Error! memory not allocated.");
        exit(0);
    }

    printf("Enter elements of array: ");
    for(i = 0; i < num; ++i)
    {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }

    printf("Sum = %d", sum);
    free(ptr);
    return 0;
}

Example #2: Using C calloc() and free()
Write a C program to find sum of n elements entered by user. To perform this program, allocate memory dynamically using calloc() function.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, *ptr, sum = 0;
    printf("Enter number of elements: ");
    scanf("%d", &num);

    ptr = (int*) calloc(num, sizeof(int));
    if(ptr == NULL)
    {
        printf("Error! memory not allocated.");
        exit(0);
    }

    printf("Enter elements of array: ");
    for(i = 0; i < num; ++i)
    {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }

    printf("Sum = %d", sum);
    free(ptr);
    return 0;
}

4. realloc():
If the previously allocated memory is insufficient or more than required, you can change the previously allocated memory size using realloc().
    ptr = realloc(ptr, newsize);  //Here, ptr is reallocated with size of newsize.

Example #3: Using realloc()
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr, i , n1, n2;
    printf("Enter size of array: ");
    scanf("%d", &n1);

    ptr = (int*) malloc(n1 * sizeof(int));

    printf("Address of previously allocated memory: ");
    for(i = 0; i < n1; ++i)
         printf("%u\t",ptr + i);

    printf("\nEnter new size of array: ");
    scanf("%d", &n2);
    ptr = realloc(ptr, n2);
    for(i = 0; i < n2; ++i)
         printf("%u\t", ptr + i);
    return 0;
}


 














