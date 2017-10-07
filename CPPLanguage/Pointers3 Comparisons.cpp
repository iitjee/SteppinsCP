Pointer comparisons


**Equality and Inequality**
Pointers of the same type (after pointer conversions) can be compared for equality. 
Two pointers of the same type compare equal if and 
only if       they are both null,
              both point to the same function, or 
              both represent the same address 


**Relational operators (<,>,<=,>=)**
Pointers to objects or functions of the same type (after pointer conversions) can be compared, with a result defined as 
follows:

If two pointers p and q of the same type point to the same object or function, or both point one past the end of the same 
array, or are both null, then p<=q and p>=q both yield true and p<q and p>q both yield false.

If two pointers p and q of the same type point to different objects that are not members of the same object or elements of the 
same array or to different functions, or if only one of them is null, the results of p<q, p>q, p<=q, and  p>=q are 
unspecified.

If two pointers point to non-static data members of the same object, or to subobjects or array elements of such members, 
recursively, the pointer to the later declared member compares greater provided the two members have the same access control 
(Clause 11) and provided their class is not a union.

If two pointers point to non-static data members of the same object with different access control (Clause 11) the result is 
unspecified.

If two pointers point to non-static data members of the same union object, they compare equal (after conversion to void*, if 
necessary). 

IMP: If two pointers point to elements of the same array or one beyond the end of the array, the pointer to the object with 
the higher subscript compares higher.

Other pointer comparisons are unspecified.



**Examples**
        int arr[3];
        int *a = arr;
        int *b = a + 1;
        assert(a != b); // OK! well defined

        struct X { int x,y; } s;
        int *a = &s.x;
        int *b = &s.y;
        assert(b > a); // OK! well defined

        int g; 
        int main()
        {
             int h;
             int i;

             int *a = &g;
             int *b = &h; // can't compare a <=> b
             int *c = &i; // can't compare b <=> c, or a <=> c etc.
             // but a==b, b!=c, a!=c etc. are supported just fine
        }

/*  algo to reverse a word  */
void reverse(char *begin, char *end)
{
  char temp;
  while (begin < end)
  {
    temp = *begin;
    *begin++ = *end;
    *end-- = temp;
  }
}
