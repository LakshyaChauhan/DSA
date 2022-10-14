#include<iostream>
#include<stdlib.h>

using namespace std;

struct ListNode{
    int data;
    ListNode* next;
};

void print(ListNode* head){
    ListNode* currNode = head;
    while(currNode  != NULL){
        cout<<"Element  : "<<currNode->data<<endl;
        currNode = currNode->next;
    }
    cout<<endl;
}

ListNode* insertionAtEnding(ListNode* head, int data){
    ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
    ListNode *currNode = head;
    temp->data = data;
    temp->next = NULL;
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
    
ListNode* insertionInBetween(ListNode * head, ListNode* New, int n){
    ListNode* pred = head;
    if(n<=1){
        New->next = head;
        return New;
    }

	else{
		while(--n && pred != NULL){
			pred = pred->next;
		}
		if(pred == NULL){
			return NULL;
		}
		New->next = pred->next;
		pred->next = New;
		return head;
	}
}


void deleteAtFirst(ListNode** head){
    ListNode* currNode ;
    if(*head == NULL)
        return ;
    currNode = *head;
    *head = (*head)->next;
    free(currNode);
    return;
}

void deleteAtLast(ListNode** head){
    ListNode* temp = NULL;
    ListNode* currNode;
    if(*head == NULL){
        return;
    }
    
    currNode = *head;
    while(currNode->next != NULL){
        temp = currNode;
        currNode = currNode->next;
    }
    temp->next = NULL;
    free(currNode);
    return;
    
}

ListNode* Delete(ListNode* head){
    ListNode* temp = NULL;
    ListNode *currNode = head;
    if(head == NULL){
        return head;
    }
    while(currNode->next != NULL){
        temp = currNode;
        currNode = currNode->next;
    }
    temp->next = NULL;
    free(currNode);
    return head;
}

void Delete(ListNode** head,int position){
    ListNode *pred, *q;
    if(*head == NULL)
        return ;
    pred = *head;
    if(position == 0){
        (*head) = (*head->next);
        free(pred);
        return;
    }
    while(position-- && pred->next != NULL){
        q = pred; 
        pred = pred->next;
    }
    if(pred == NULL){
        return ;
    }
    q->next = pred->next;
    free(pred);
    return ;
}
int main(){
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    ListNode *New = (ListNode*) malloc(sizeof(ListNode));
    head = NULL;
    head = insertionAtEnding(head,1);
    head = insertionAtEnding(head,2);
    head = insertionAtEnding(head,3);
    head = insertionAtEnding(head,4);
    head = insertionAtEnding(head,5);
    head = insertionAtEnding(head,6);
    New->data = 7;
    New->next = NULL;
    head = insertionInBetween(head,New,6);
    print(head);

    deleteAtFirst(&head);
    deleteAtFirst(&head);
    deleteAtLast(&head);
    head = Delete(head);
    print(head);

    Delete(&head,2);
    print(head);
    return 0;
}

