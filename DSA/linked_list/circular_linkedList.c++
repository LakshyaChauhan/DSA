/*                                                      CIRCULAR LINKED LISTS
        * In a singly circular linked list, each node has one link, similar to an ordinary singly-linked list , exept that the next
          link of the last node points back to the first node. Circular linked lists doesn't have ends.

        * Circular linked list are useful for example , when several prcoesses are using the same computer resource (say ,CPU) for the
          same amount of time, we have to assure that no process accesses the resource before all other processes do (robin round 
          algorithm).        



*/

#include<iostream>
#include<stdlib.h>

using namespace std;

struct CLLNode{
    int data;
    CLLNode *next;
};

// Counting Nodes in a circular Linked List
int length(CLLNode* head){
    // Time Complexity : O(n) , Space Complexity : O(1) 
    int count = 0;
    CLLNode* currNode = head;
    if(head == NULL){
        return 0;
    }
    do{
        currNode = currNode->next;
        count++;
    } while (currNode != head);
    return count;
}

void print(CLLNode** head){
    // Time Complexity : O(n) , Space Complexity : O(1) 
    CLLNode* currNode = *head;
    if(*head == NULL){
        return ;
    }
    do{
        cout<<"Element : "<<currNode->data<<endl;
        currNode = currNode->next;    
    } while (currNode  != *head);
    
    cout<<endl;
}

//  INSERTING A NODE AT THE END OF A CIRCULAR LINKED LIST
void insertAtEnd(CLLNode** head, int data){
    // Time Complexity : O(n) , Space Complexity : O(1) 
    CLLNode* current = *head;
    CLLNode* temp = (CLLNode*)malloc(sizeof(CLLNode));
    if(!temp){
        cout<<"Memory error."<<endl;
        return;
    }
    temp->data = data;
    temp->next = temp;
    if(*head == NULL){
        *head = temp;
        return;
    }
    while(current->next !=  *head){
        current = current->next;
    }
    current->next = temp;
    temp->next = *head;
}

void insertAtFirst(CLLNode** head, int data){
    CLLNode* current = *head , *temp = (CLLNode*)malloc(sizeof(CLLNode));
    temp->data = data;
    temp->next = temp;
    if(*head == NULL){
        *head = temp;
        return ;
    }
    while(current->next != *head ){
        current = current->next;
    }
    temp->next = *head;
    current->next = temp;
    *head = temp;
}

void deleteLast(CLLNode** head){
    CLLNode* current  = *head, *prev;
    if(*head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    while(current->next != *head){
        prev =current;
        current = current->next;
    }
    prev->next = *head;
    free(current);
}
void deleteFirst(CLLNode** head){
    CLLNode* current = *head;
    if(*head == NULL){
        cout<<"Empty List";
        return;
    }
    while(current->next != *head){
        current = current->next;
    }
    current->next = (*head)->next;
    current = *head;
    *head  = (*head)->next;
    free(current);
}

int main(){
    CLLNode * head = (CLLNode*)malloc(sizeof(CLLNode));
    head = NULL;
    print(&head); 

    cout<<length(head)<<endl;
    insertAtEnd(&head,0);
    insertAtEnd(&head,1);
    insertAtEnd(&head,2);
    insertAtEnd(&head,3);
    insertAtEnd(&head,4);
    insertAtEnd(&head,5);
    print(&head);
    
    CLLNode * head2 = (CLLNode*)malloc(sizeof(CLLNode));
    head2 = NULL;
    insertAtFirst(&head2,5);
    insertAtFirst(&head2,4);
    insertAtFirst(&head2,3);
    insertAtFirst(&head2,2);
    insertAtFirst(&head2,1);
    insertAtFirst(&head2,0);
    print(&head2);
    deleteLast(&head2);
    print(&head2);
    deleteFirst(&head2);
    deleteFirst(&head2);
    print(&head2);

    return 0;
}

