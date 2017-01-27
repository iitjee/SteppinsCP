/*
  Algo:
  1) Create an empty stack.
  2) One by one push all characters of string to stack.
  3) One by one pop all characters from stack and put 
     them back to string.


*/


// A stack based function to reverese a string
void reverse(char str[])
{
    // Create a stack of capacity equal to length of string
    int n = strlen(str);
    struct Stack* stack = createStack(n);
 
    // Push all characters of string to stack
    int i;
    for (i = 0; i < n; i++)
        push(stack, str[i]);
 
    // Pop all characters of string and put them back to str
    for (i = 0; i < n; i++)
        str[i] = pop(stack);
}
 











