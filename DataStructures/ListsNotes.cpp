/*
  Both Lists and Arrays are COLLECTIONS. You see, in Python you have lists(But they are actually variable-length arrays(dynamic arrays) 
under the hood). Langs like C/ObjC, you have arrays. While in Java, you've arrays and you've List but only as an ADT.
 
 Even though modern languages and tools have made linked lists pretty unimportant for day-to-day programming, the
skills for complex pointer algorithms are very important, and linked lists are an excellent way to develop those skills. :)

Array: Sequential and Direct(aka RANDOM) Access (Contiguous memory locations)
List: Sequential Access (Need not be contiguous)

Lists have NODES. and each node as two elements i.e (DATA, NEXT)
The Last node has a Sentinel Pointer (a DUMMY ptr) which points to NULL.
You see, we don't have direct access. We need to go through all the elements starting from first. This is the downside of list.
Also Arrays are on the winning side for searching/sorting as well.

However, the BIGGEST ADVANTAGE is ADDING/REMOVING ELEMENTS. However, in Arrays doing this task is daunting as it needs
to comply it's basic definition: 'elements should be contiguous in Array'. (There's a catch: To search the element in a list,
it may be time consuming).
Thus, Lists are the BEST for VOLATILE Data. :)

----------------------------------------------------------------------------------------------------------------

Doubly Linked List:
Each Node here has three elements: (DATA, PREV, NEXT).
Therefore, this list has two sentinel nodes (first node's PREV and the last node's NEXT)
Most langauges only implement Doubly linked list! :)





----------------------------------------------------------------------------------------------------------------
LINKED LIST SUPPORT IN VARIOUS LANGUAGES:

-> JAVA
Only as an abstract class, like an INTERFACE.
Java's ArrayList is actually an ARRAY not a linkedlist! :/
Java has a LinkedList class in java.util, however! checkout :) 

-> C#
Has LinkedList in System.Collections.Generic

-> ObjC
No built-in LinkedList. 3rd Party is there

->Python
It has List but name is misleading. It's actually an Array Implementation under-the-hood.


*/
