// Doubly Linked List is a linked llist in which  node contains a pointer to the previous as well as the next node in sequence.
// Node consists of 3 parts : data ,  pointer to prev Node , pointer to Next Node.

//   ADVANTAGE     -> Advantage of doubly LinkedList is that given a node in the list, we can navigate in both directions.
            //     -> A Node in a singly Linked list cannot be removed unless we have pointer to its predecessor.

//   DISADVANTAGES -> Each Node requires an extra pointer , requiring more space.
        //         -> The insertion or deletion of a node takes a bit longer (more pointer operations).

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
    ListNode * temp = (ListNode*)malloc(sizeof(ListNode));
    ListNode * currNode = *head;
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    if(index <= 0){
        temp->next = *head;
        (*head)->prev = temp;
        *head = temp;
        return;
    }
    while(index-- && currNode->next != NULL){
        currNode = currNode->next;
    }
    if(currNode==NULL ){
        cout<<"Out of Bounds"<<endl;
        return ;
    }
    temp->next = currNode->next;
    temp->prev = currNode;
    currNode->next = temp;
}

int main(){
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head = NULL;
    insertAtBeginnng(&head,0);
    insertAtBeginnng(&head,1);
    insertAtBeginnng(&head,2);
    insertAtBeginnng(&head,3);
    insertAtBeginnng(&head,4);
    insertAtBeginnng(&head,5);
    insertAtBeginnng(&head,6);
    print(head);

    ListNode* head2 = (ListNode*)malloc(sizeof(ListNode));
    head2 = NULL;
    insertAtEnding(&head2,0);
    insertAtEnding(&head2,1);
    insertAtEnding(&head2,2);
    insertAtEnding(&head2,3);
    insertAtEnding(&head2,4);
    insertAtEnding(&head2,5);
    insertAtEnding(&head2,6);
    print(head2);

    insert(&head2,8,7);
    print(head2);
    insert(&head2,7,7);
    print(head2);
    insert(&head2,-1,0);
    print(head2);
    insert(&head2,20,20);
    print(head2);
    insert(&head2,0,1);
    print(head2);
    return 0;
}