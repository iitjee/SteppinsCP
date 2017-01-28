

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



















