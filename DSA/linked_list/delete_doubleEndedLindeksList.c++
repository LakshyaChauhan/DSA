// Doubly Linked List is a linked llist in which  node contains a pointer to the previous as well as the next node in sequence.
// Node consists of 3 parts : data ,  pointer to prev Node , pointer to Next Node.

//   ADVANTAGE     -> Advantage of doubly LinkedList is that given a node in the list, we can navigate in both directions.
            //     -> A Node in a singly Linked list cannot be removed unless we have pointer to its predecessor.

//   DISADVANTAGES -> Each Node requires an extra pointer , requiring more space.
        //         -> The insertion or deletion of a node takes a bit longer (more pointer operations).

/*
            DELETING FIRST NODE IN DOUBLY LINKED LIST
            -> Create a temproary Node which will point to the same node as that of head.
            -> Now move the head node pointer to the next node and change the heads previous to NULL.
               Then dispose of the tempoprary node.
               
            DELETE LAST NODE IN DOUBLY ENDED LINKED LIST
            -> Traverse the list, and while traversing maintain the previous node address. By the time we reach the end of the list , we will 
               have two pointers , one pointing to the tail and the other opinting to the node before the tail.
            -> Update the next pointer of previous node to the tail node with NULL.
            -> Dispose the tail Node.
            
            DELETING AN INTERMEDIATE NODE IN DOUBLY LINKED LIST
            -> Similar tot the previous case , maintain the prevoius node while also traversing the list. Upon locating the node tp be deleted, change
               the prevoius node's next pointer to the next node of the  node to be deleted . Also,change the previous pointer to the next node to node
               to be deleted to point to previous node of the node to be deleted.
            -> Dispose the current node to be deleted.

*/
#include<iostream>
#include<stdlib.h>

using namespace std;
struct ListNode
{
    int data;
    ListNode* next;
    ListNode* prev;
    /* data */
};

void print(ListNode*head){
    ListNode* currNode = head;
    while(currNode){
        cout<<"Element : "<<currNode->data<<endl;
        currNode = currNode->next;
    }
    cout<<endl;
}
void insertAtBeginnng(ListNode** head,int data){
    // Time Complexity O(1) , Space Complexity : O(1)
    ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
    temp->data = data;
    temp->prev = NULL;
    if(*head == NULL){
        *head = temp;
        (*head)->prev = NULL;
        (*head)->next = NULL;
        return;
    }
    else{
        temp->next = *head;
        (*head)->prev = temp;
        *head = temp;
    } 
}

void insertAtEnding(ListNode** head, int data){
    // Time Complexity O(n) , Space Complexity : O(1)
    ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
    ListNode* currNode = *head;
    temp->data = data;
    temp->next  = NULL;
    currNode = *head;
    if(*head == NULL){
        *head = temp;
        (*head)->prev = NULL;
        return;
    }
    else{
        while(currNode->next){
            currNode = currNode->next;
        }
        currNode->next = temp;
        temp->prev = currNode;
    }
}

void insert(ListNode** head, int data, int index){// The first position of the head is considered at a position 0
    // Time Complexity : O(n) Space Complexity : O(1)
    int  k  =0 ;
    ListNode * temp = (ListNode*)malloc(sizeof(ListNode));
    ListNode * currNode = *head;
    if(!temp){
        // Checking for memory errors
        cout<<"Memory error"<<endl;
        return;
    }   
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    if(index <= 0){
        temp->next = *head;
        (*head)->prev = temp;
        *head = temp;
        return;
    }
    while(k < index -1 && currNode->next != NULL){
        currNode = currNode->next;
        k++;
    }
    if(k<index -1){
        cout<<"Desired Position doesn't exist"<<endl;
        return;
    }
    temp->next  = currNode->next;
    temp->prev = currNode;
    currNode->next = temp;
    return;
}

void deleteFirst(ListNode** head){
    // Time Complexity : O(1), Space Complexity: O(1)
    ListNode* currNode  = *head;
    if(*head == NULL){
        return;
    }
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(currNode);    
}

void deleteLast(ListNode** head){
    // Time Compexity : O(n) , Space Complexity : O(1)
    ListNode* currNode = *head, *prev;
    if(*head == NULL){
        return;
    }
    while(currNode->next){
        prev = currNode;
        currNode = currNode->next;
    }
    prev->next = NULL;
    free(currNode);
}

void deleteinBetween(ListNode** head,int index){
    // Time Complexity : O(n) , Space Complexity : O(1)
    int k = 0;
    ListNode*currNode = *head, *prev , *next;
    if(*head == NULL){
        return ;
    }
    if(index <= 0){
        (*head) = (*head)->next;
        (*head)->prev = NULL;
        free(currNode);
        return;
    }
    while(k < index -1 && currNode->next != NULL){
        prev = currNode;
        currNode = currNode->next;
        k++;
    }
    if(k < index - 1){
        cout<<"Desired position doesn't exists"<<endl;
        return;
    }
    prev->next = currNode->next;
    next = currNode->next;
    next->prev = prev;
    free(currNode);
    return;
}

int main(){
     ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head = NULL;
    insertAtEnding(&head,0);
    insertAtEnding(&head,1);
    insertAtEnding(&head,2);
    insertAtEnding(&head,3);
    insertAtEnding(&head,4);
    insertAtEnding(&head,5);
    insertAtEnding(&head,6);
    print(head);
    
    insert(&head,-1,8);
    print(head);

    deleteFirst(&head);
    print(head);

    deleteLast(&head);
    print(head);

    deleteinBetween(&head,10);
    print(head);
    return 0;
}
