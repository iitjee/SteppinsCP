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

//Creating Stack: 1 Array Implementation
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = mycapacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    
//isFull: Stack is full when top is equal to the last index
    return stack->top == stack->capacity - 1;
    
//isEmpty: Stack is empty
    return stack->top == -1;

//Pushin element (error check for overflow: if (isFull(stack)) return; )
  stack->array[++stack->top] = mynewitem; //after pushing, it increases top value by 1
  
//Popping element (error check for underflow: if(isEmpty(stack) return INT_MIN;
  return stack->array[stack->top--];  //after popping, it decrements top value by 1
  //Note: to use INT_MIN, you should #include <limits.h>

//Peek an element

//Creating Stack: 2) linked list implementation
/* A structure to represent a stack */
struct StackNode  //this is a growing stack
{
    int data;
    struct StackNode* next;
};
/*A structure to represent a stack*/
struct StackNode* createNewNode(int data)
{
    struct StackNode* stackNode = (struct StackNode*) malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}
 
//Note that the whole stack is represented by the firstnode declared by 'struct StackNode *root'
//This is the essential difference between array and linkedlist representation.
//In array, you can access any element in O(1) but in LL, you've to start from the root node always.

/* isEmpty  */ return !root;
/*  isFull  */ //in LL rep, the stack can grow endlessly unlike in array rep.

void push(struct StackNode** root, int data)
{//note the use of double pointers(aka ptr-to-ptr)
    struct StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d pushed to stack\n", data);
}
 
int pop(struct StackNode** root)
{
    if (isEmpty(*root))
        return INT_MIN;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
 
    return popped;
}
 
int peek(struct StackNode* root)
{
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}
 
int main()
{
    struct StackNode* root = NULL;
 
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
 
    printf("%d popped from stack\n", pop(&root));
 
    printf("Top element is %d\n", peek(root));
 
    return 0;
}

//A good difference to note between array and linked list implementation is that when a new element is added
//(In array implementation) we do at end of array.
//(In linkedlist implement) we do at beggining of LL i.e at root node.
//Nevertheless, regardless of implementation it always follow LIFO order :)
    
    
