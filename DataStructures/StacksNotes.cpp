/*
(STL) https://github.com/iitjee/SteppinsCP/blob/master/CPP/stacks.cpp

push
pop
peek

if you push to a stack which is full => overflow
if you pop from a stack which is empty => underflow

There are two ways to implement a stack:
- Using array
- Using linked list


*/

// A structure to represent a stack
struct Stack
{
    int top;  //here top is index, not the element itself
    unsigned capacity;
    int* array;
};

//Creating Stack: 1Array Implementation
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = mycapacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    
// Stack is full when top is equal to the last index
    return stack->top == stack->capacity - 1;
    
//Stack is empty
    return stack->top == -1;

//Pushin element (error check for overflow: if (isFull(stack)) return; )
  stack->array[++stack->top] = mynewitem; //after pushing, it increases top value by 1
  
//Popping element (error check for underflow: if(isEmpty(stack) return INT_MIN;
  return stack->array[stack->top--];  //after popping, it decrements top value by 1
  
  //Note: to use INT_MIN, you should #include <limits.h>


//Creating Array: 2 linked list implementation
/* A structure to represent a stack */
struct StackNode  //this is a growing stack
{
    int data;
    struct StackNode* next;
};
/*A structure to represent a stack*/
struct StackNode* newNode(int data)
{
    struct StackNode* stackNode = (struct StackNode*) malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}
 
//Note that the whole stack is represented by the firstnode declared by 'struct StackNode *root'
/* Empty  */ return !root;


    
    
