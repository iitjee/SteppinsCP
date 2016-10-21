/*


*/




struct ListNode {
    int data;
    struct ListNode *next;
};

int getListLength(struct ListNode *head) {
    struct ListNode *current = head;
    int count = 0;
    
    while(head != NULL) {
        count++;
        current = current -> next;
    }
    return count;
}

void insertInList(struct ListNode **head, int newData, int position) { //double ptr is required if insertion takes place at first node
    struct ListNode *tempNode1 = nullptr, *tempNode2 = nullptr, *newNode;
    newNode = (ListNode *)malloc(sizeof(struct ListNode));
    
    if(newNode == NULL) {
        cout<<"Memory Error while Allocation";
        return;
    }
    
    tempNode1 = *head;
    int k=1;
    
    /* Insertion at beginning */
    if(position == 1) { //Note that indexing is started from 1 and not 0
        newNode->data = newData;
        newNode->next = tempNode1;
        *head = newNode;
    }
    
    else { /*If insertion not at beginning */
        while((tempNode1 != NULL) && (k<position)) { //loops till k=position-1
            k++;
            tempNode2 = tempNode1;
            tempNode1 = tempNode1->next;
        }
        
        tempNode2->next = newNode;
        newNode->next = tempNode1;
    }
}









