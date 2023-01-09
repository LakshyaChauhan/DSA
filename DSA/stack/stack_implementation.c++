/*
									STACKS
	A stack is an orderede list in which  insertion and deletion are done at one end , called top. The last element inserted is 
	the first one to be deleted. Hence , it is called the Last in First out(LIFO) or First in Last our(FILO) list.


	MAIN STACK OPERATION
	-> push 	: Inserts data onto stack.
	-> pop  	: Removes and returns the last inserted element from the stack.

	AUXILIARY STACK OPERATION
	-> top  	: Returns the last inserted element without removing it.
	-> size     : Returns the number of elements stored in the stack.
	-> isEmpty  : Indicates whether any elemnets are there in the stack or not.
	-> isFull	: Indicates whether the stack is full or not.

	DIRECT APPLICATIONS
	->	Balancing of symbols
	->	Infix to postfix conversion
	->	Evaluation of postfix expression
	->	Implementing function calls
	->	Finding the spans (finding spans in stock markets)
	->	Page visited hisotry in a Web Browser 
	->	Undo sequence in s text editor
	->	Matching tags in HTML and XML

	IMPLEMENTATION
	->	SIMPLE ARRAY BASED IMPLEMENTATION
	->	DYNAMIC ARRRAY BASED IMPLEMENTATION
	->	LINKED LIST IMPLEMENTAIONS


											(SIMPLE ARRAY BASED IMPLEMENTATION)
*/

#include<iostream>
#include<stdlib.h>
#include<limits.h>

using namespace std;

struct Stack
{
	int top, capacity, *arr;	
};

Stack* createStack(int capacity){
	Stack* s = (Stack*)malloc(sizeof(Stack));
	if(!s){
		return NULL;
	}

	s->capacity = capacity;
	s->top = -1;
	s->arr =(int*) malloc(s->capacity * sizeof(int));

	if(!s->arr){
		return NULL;
	}
	return s;
}

int isEmpty(Stack* S){
	// If the condition is true 1 is returned else 0 is returned.
	return (S->top == -1);
}

int isFull(Stack* S){
	// If the condition is true 1 is returned else 0 is returned.
	return(S->top == S->capacity -1);
}

void push(Stack* S, int data){
	// If S->top == capacity - 1 that means stack is full
	if(isFull(S)){
		cout<<"Stack overflow"<<endl;
	}
	//  increasing the top by one and storing the data in the 'top' positions
	else
		S->arr[++S->top] = data;
}

int pop(Stack* S){
	if(isEmpty(S)){
		cout<<"Stack is empty"<<endl;
		return INT_MIN;
	}
	else{
		return (S->arr[S->top--]);
	}
}

int peek(Stack* S){
	if(isEmpty(S)){
		cout<<"Stack is empty"<<endl;
		return INT_MIN;
	}
	else{
		return (S->arr[S->top]);
	}
}

void deleteStack(Stack* S){
	if(S){
		if(S->arr)
			free(S->arr);
		free(S);
	}
}

int main(){
	int size;
	cout<<"Enter the size of the stack -> ";
	cin>>size;
	Stack* stk = createStack(size);
	cout<<"Stack is empty or not : "<<isEmpty(stk)<<endl<<"Stack is full or not : "<<isFull(stk)<<endl;
	for(int i = size; i>0 ; i--){
		push(stk,i);
	}
	for(int i = 0; i<size ; i++){
		cout<<pop(stk)<<endl;
	}
	deleteStack(stk);
	return 0;
}