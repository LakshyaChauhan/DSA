
// How to create a Linked list by adding element at the start , by adding element at end and by adding element in between
// This code uses a very good concepts of pointer and checks every senario that can come in your mind while playing with the linked list
// Theory -> A linked list is a way to store data in the heap , in which a there are Nodes interlinked with each other
 //          Node contains one data element and one Node pointer to point the next node in the heap memory
//          In LinkedList memory is not stored in the contiguous way it takes twice the size of an array .
//          It has a wide use while there is a brief operation of insertion and deletion 
//          This linked list is created using malloc function , so the node meomory continues to exist until it is deallocated with a call to free( Node name);
#include<iostream>
#include<stdlib.h>

using namespace std;

struct ListNode{
    int data;
    ListNode* next;
};

void print(ListNode* head){
    ListNode* currNode= head;
    while(currNode != NULL){
        cout<<"Element : "<<currNode->data<<endl;
        currNode = currNode->next;
    }
    cout<<endl;
}

ListNode* insertAtBeginning(ListNode* head, int data){
    ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
    temp->data = data;
    if(head == NULL){
        head = temp;
        head->next =NULL;
    }
    else{
        temp->next = head;
        head = temp;
    }
    return head;
}

ListNode* insertAtEnding(ListNode * head, int data){
    ListNode* temp, *currNode;
    temp = (ListNode*)malloc(sizeof(ListNode));
    temp->data = data;
    temp->next = NULL;
    currNode = head;
    if(head == NULL){
        head = temp;
        head->next = NULL;
    }
    else{
        while(currNode->next != NULL){
        currNode = currNode->next;
        }
        currNode->next = temp;
    }
    return head;
}

ListNode* insertInBetween(ListNode* head, ListNode* New, int n){
    // inserts a new node at position n and returns head.
    ListNode* pred = head;
    // pred will point the predecessor of new

    // Special case : adding at position 1 (inserting at head)

    if(n<=1){
        New->next = head;
        return New;
    }
    // find the n-1 node (predecessor) : decrement n and move down the list
    // until either the list has ended or n becomes 0
    while(--n && pred != NULL){
        pred = pred->next;  // repoint temp to the next element
    }

    if(pred == NULL){
        return NULL;
    }

    // if it's mot NULL , insert a new after its predecessor
    New->next = pred->next;
    pred->next = New;
    return head;
}

int main(){
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    ListNode *head1 = (ListNode*)malloc(sizeof(ListNode));
    head = NULL; 
    print(head);

    cout<<"Inserting at the beginning "<<endl;
    head = insertAtBeginning(head,13);
    head = insertAtBeginning(head,14);
    head = insertAtBeginning(head,15);
    head = insertAtBeginning(head,16);
    head = insertAtBeginning(head,17);
    head = insertAtEnding(head,11);  
    print(head);


    cout<<"Insertion at the ending"<<endl;
    head1 = NULL;                     
    head1 = insertAtEnding(head1,1);
    head1 = insertAtEnding(head1,2);
    head1 = insertAtEnding(head1,3);
    head1 = insertAtEnding(head1,4);
    head1 = insertAtEnding(head1,6);
    head1 = insertAtEnding(head1,7);
    head1 = insertAtEnding(head1,8);

    ListNode* New = (ListNode*)malloc(sizeof(ListNode));
    New->data = 5;
    New->next  = NULL;
    head1 = insertInBetween(head1,New,4);
    print(head1);
    return 0;
}           
