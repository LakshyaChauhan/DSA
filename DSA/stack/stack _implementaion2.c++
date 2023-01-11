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


						(DYNAMIC ARRAY IMPLEMENTATION)

	-> ALTERNATIVE DOUBLING APPROACH
	   For simplicty let us asssume that initially we started with  n = 1 and moved up to n = 32.
	   That means , we do the doubling at 1,2,4,8,16,32.

	   ** If we observe carefully , we are doing the doubling operation LOGN times.
	   -> Time complexity is O(n) and amortirizes time complexity of push opertion is O(1) 
*/

/*	We just need to add one function and to my basic stack impleentaion code and modify one of function*/



void doubleStack(Stack* S){
	S->capacity *= 2;
	S->arr = (int*)realloc(S->arr, sizeof(int)*S->capacity)
}

void push(Stack* S, int data){
	if(isFull(S)){
		doubleStack(S);
	}
	S->arr[++S->top] = data;
}