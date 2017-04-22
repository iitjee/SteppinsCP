

Unlike Arrays, Linked Lists, Stack and queues, which are linear data structures, trees are HIERARCHICAL DATA STRUCTURES.

 The topmost node is called root of the tree. The elements that are directly under an element are called its children.
 Finally, elements with no children are called leaves
                      tree
                      ----
                       j    <-- root
                     /   \
                    f      k  
                  /   \      \
                 a     h      z    <-- leaves 


eg: 
  - File systems
                      file system
                     --------------
                       /~    <-- root
                    /      \
                  ...       home
                        /          \
                     ugrad        course
                      /       /      |     \
                    ...      cs101  cs112  cs113  

- Trees (with some ordering e.g., BST) provide moderate access/search (quicker than Linked List and slower than arrays).
-  Trees provide moderate insertion/deletion (quicker than Arrays and slower than Unordered Linked Lists).
-  Like Linked Lists and unlike Arrays, Trees don’t have an upper limit on number of nodes as nodes are linked using pointers.
-  Router algorithms
- Expression Trees are used in compilers


Binary Tree: A tree whose elements have at most 2 children is called a binary tree.
Since each element in a binary tree can have only 2 children, we typically name them the LEFT AND RIGHT CHILD.

A TREE IS REPRESENTED BY A POINTER TO THE TOPMOST NODE IN TREE.
A Tree node contains following parts.
  1. Data
  2. Pointer to left child
  3. Pointer to right child

                            struct node 
                            {
                              int data;
                              struct node *left;  //left child
                              struct node *right; //right child
                            };


Code to construct the following:
                  tree
                ----
                 1    <-- root
               /   \
              2     3  
             /   
            4

/* newNode() allocates a new node with the given data and NULL left and right pointers. */
struct node* newNode(int data)
{
  // Allocate memory for new node 
  struct node* node = (struct node*)malloc(sizeof(struct node));
 
  // Assign data to this node
  node->data = data;
 
  // Initialize left and right children as NULL
  node->left = NULL;
  node->right = NULL;
  return(node);
}
 
 
int main()
{
  /*create root*/
  struct node *root = newNode(1);  
  /* following is the tree after above statement 
 
        1
      /   \
     NULL  NULL  
  */
   
 
  root->left        = newNode(2);
  root->right       = newNode(3);
  /* 2 and 3 become left and right children of 1
           1
         /   \
        2      3
     /    \    /  \
    NULL NULL NULL NULL
  */
 
 
  root->left->left  = newNode(4);
  /* 4 becomes left child of 2
           1
       /       \
      2          3
    /   \       /  \
   4    NULL  NULL  NULL
  /  \
NULL NULL
*/
 
  getchar();
  return 0;
}



/*  Properties 
1) The maximum number of nodes at level ‘l’ of a binary tree is 2l-1. (level=number of nodes ON PATH from root to the node (including root and node)
2) Maximum number of nodes in a binary tree of height ‘h’ is 2h – 1.  (height =number of nodes ON PATH from root to the node (including root and node)
3) In a Binary Tree with N nodes, minimum possible height or minimum number of levels is  ⌈ Log2(N+1) ⌉
4) A Binary Tree with L leaves has at least   ⌈ Log2L ⌉ + 1   levels
5) In Binary tree, number of leaf nodes is always one more than nodes with two children.
         L = T + 1
         Where L = Number of leaf nodes
               T = Number of internal nodes with two children
         
         
 Types:
 1. Full Binary Tree A Binary Tree is full if every node has 0 or 2 children AND each leaf nodes are at the same level.
 (In a Full Binary, number of leaf nodes is number of internal nodes plus 1)
                            18                         
                         /       \  
                       15         30  
                      /  \        /  \
                    40    50    100   40

             18
           /    \   
         15     20    
        /  \       
      40    50   
    /   \
   30   50
   
   On the other hand, Strict Binary tree: Each node has exactly two child or zero child.
   
   2. Complete Binary Tree: A Binary Tree is complete Binary Tree if all levels are completely filled except possibly the last level and the last level has all keys as left as possible.
   (Eg: Binary Heap)
                                           18
                                        /       \  
                                      15         30  
                                     /  \        /  \
                                   40    50    100   40


                                            18
                                        /       \  
                                      15         30  
                                     /  \        /  \
                                   40    50    100   40
                                  /  \   /
                                 8   7  9 
                                 
3. Perfect Binary Tree A Binary tree is Perfect Binary Tree in which all internal nodes have two children and all leaves are at same level.
( A Perfect Binary Tree of height h (where height is number of nodes on path from root to leaf) has 2h – 1 node.)

              18
           /       \  
         15         30  
        /  \        /  \
      40    50    100   40


               18
           /       \  
         15         30  
         
4. Balanced Binary Tree
A binary tree is balanced if height of the tree is O(Log n) where n is number of nodes.
(For Example, AVL tree maintain O(Log n) height by making sure that the difference between heights of left and right subtrees is 1. Red-Black trees maintain O(Log n) height by making sure that the number of Black nodes on every root to leaf paths are same and there are no adjacent red nodes. )
(Balanced Binary Search trees are performance wise good as they provide O(log n) time for search, insert and delete.)

5. A degenerate (or pathological) tree A Tree where every internal node has one child. Such trees are performance-wise same as linked list.
      10
      /
    20
     \
     30
      \
      40    
      
      
         
         
         


*/













