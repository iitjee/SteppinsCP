
/*
Infix:    a+b
Postfix:  ab+ (aka Reverse Polish Notation)
Prefix:   +ab

Important Properties:
       -> 2+3*4 or 234*+ the order of numbers is same in both
       -> Postfix notations don't have parans
       -> One stack is enough to convert infix to postfix. stack only contains operators and open parans '('

Why postfix representation?
compiler scans an expression either from left to right or from right to left.

If expression is "a + b * c + d"
The compiler first scans the expression to evaluate the expression b * c, then again scan the expression to add a to it.
The result is then added to d after another scan.
The repeated scanning makes it very in-efficient. It is better to convert the expression to postfix(or prefix) form before evaluation.
in postfix form it is: abc*d++ This can be evaluated easily using a stack. 

       eg: (http://cs.nyu.edu/courses/Fall12/CSCI-GA.1133-002/notes/InfixToPostfixExamples.pdf)
         Always start conversion with highest precedence operator (when you are manually doing, algorithm works slightly diff)
              3+4*5/6       =>     3 4 5 * 6 / +
         When parantheses is there, it forces to finish the enclosing operation first.
              (300+23)*(43-21)/(84+7)     =>     300 23 + 43 21 - * 84 7 + /
         
              (4+8)*(6-5)/((3-2)*(2+2))   =>     4 8 + 6 5 - * 3 2 – 2 2 + * /
              A + B * C + D              =>     A B C * + D +                      =>(prefix)  + + A * B C D	
              (A + B) * (C + D)           =>     A B + C D + *                      =>(prefix)  * + A B + C D
              A * B + C * D	              =>  A B * C D * +                        =>  + * A B * C D   
              

/*  Infix to Postfix conversion Algorithm 
1. Scan the infix expression from left to right.
2. If the scanned character is an operand, output it.
3. Else,
…..3.1 If the precedence of the scanned operator is greater than the precedence of the operator in 
       the stack(or the stack is empty), push it.
…..3.2 Else, Pop the operator from the stack until the precedence of the scanned operator is less-equal to the
       precedence of the operator residing on the top of the stack. Push the scanned operator to the stack.
4. If the scanned character is an ‘(‘, push it to the stack.
5. If the scanned character is an ‘)’, pop and output from the stack until an ‘(‘ is encountered.
6. Repeat steps 2-6 until infix expression is scanned.
7. Pop and output from the stack until it is not empty
*/
       
// A utility function to return precedence of a given operator
// Higher returned value means higher precedence
int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-': return 1;
 
    case '*':
    case '/': return 2;
 
    case '^': return 3;
    }
    return -1;
}

int infixToPostfix(char* exp)
{
    int i, k;
   
    // Create a stack of capacity equal to expression size 
    struct Stack* stack = createStack(strlen(exp));
    if(!stack) // See if stack was created successfully 
        return -1 ;
 
    for (i = 0, k = -1; exp[i]; ++i)
    {
         // If the scanned character is an operand, add it to output.
        if (isOperand(exp[i]))
            exp[++k] = exp[i];     //note that the result is also made to store in 'exp' itself.
         
        // If the scanned character is an ‘(‘, push it to the stack.
        else if (exp[i] == '(')
            push(stack, exp[i]);
        
        //  If the scanned character is an ‘)’, pop and output from the stack 
        // until an ‘(‘ is encountered.
        else if (exp[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(') //peek=top
                exp[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return -1; // invalid expression                
            else
                pop(stack);
        }
        else // an operator is encountered
        {
            while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }
 
    }
 
    // pop all the operators from the stack
    while (!isEmpty(stack))
        exp[++k] = pop(stack);
 
    exp[++k] = '\0';
    printf( "%s\n", exp );
}

/*     Evaluation of Postfix Expression
1) Create a stack to store operands (or values).
2) Scan the given expression and do following for every scanned element.
…..a) If the element is a number, push it into the stack
…..b) If the element is a operator, pop operands for the operator from stack. Evaluate and push the result back to the stack
3) When the expression is ended, the number in the stack is the final answer

Example:
Let the given expression be “2 3 1 * + 9 -“. We scan all elements one by one.
1) Scan ‘2’, it’s a number, so push it to stack. Stack contains ‘2’
2) Scan ‘3’, again a number, push it to stack, stack now contains ‘2 3′ (from bottom to top)
3) Scan ‘1’, again a number, push it to stack, stack now contains ‘2 3 1′
4) Scan ‘*’, it’s an operator, pop two operands from stack, apply the * operator on operands, we get 3*1 which results in 3. We push the result ‘3’ to stack. Stack now becomes ‘2 3′.
5) Scan ‘+’, it’s an operator, pop two operands from stack, apply the + operator on operands, we get 3 + 2 which results in 5. We push the result ‘5’ to stack. Stack now becomes ‘5’.
6) Scan ‘9’, it’s a number, we push it to the stack. Stack now becomes ‘5 9′.
7) Scan ‘-‘, it’s an operator, pop two operands from stack, apply the – operator on operands, we get 5 – 9 which results in -4. We push the result ‘-4′ to stack. Stack now becomes ‘-4′.
8) There are no more elements to scan, we return the top element from stack (which is the only element left in stack).

*/

// The main function that returns value of a given postfix expression
int evaluatePostfix(char* exp)     //exp = expression
{
    // Create a stack of capacity equal to expression size
    struct Stack* stack = createStack(strlen(exp));
 
    // See if stack was created successfully
    if (!stack) return -1;
 
    // Scan all characters one by one
    int i;
    for (i = 0; exp[i]; ++i)
    {
        // If the scanned character is an operand (number here),
        // push it to the stack.
        if (isdigit(exp[i]))
            push(stack, exp[i] - '0');
 
        //  If the scanned character is an operator, pop two
        // elements from stack apply the operator
        else
        {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i])
            {
             case '+': push(stack, val2 + val1); break;
             case '-': push(stack, val2 - val1); break;
             case '*': push(stack, val2 * val1); break;
             case '/': push(stack, val2/val1);   break;
            }
        }
    }
    return pop(stack);
}


