/*    
        A journal (Sinha) presented a n alternative implementation of the doubly linked list ADT, with insertion , transversal and deletion operations.
        This implementation is based on pointer difference . Each Node uses only one pointer field to traverse the list back and forth.
        
        ptrdiff -> is used in the defintion in the code while defining Double Linked List.
                -> The ptrdiff between the pointer to the next node and the pointer to the previous node. The pointer difference is calculated by 
                   using exclusice OR operation.
        ptrdiff = pointer to previous node (Exclusive OR) pointer to next node.
*/



struct DLL{
  int data;
  DLL* ptrdiff;
};

/*
    X XOR X = 0
    X XOR 0 = X
    X XOR Y = Y XOR X (SYMMETRIC)
    (X XOR Y) XOR Z = X XOR (Y XOR Z)
    
    Suppose we are at third position at linked list  if we want to move to previous one , we know thrid ptrdiff is defined as 2nd XOR 4th,
    if we want to move to 2nd  performing  XOR on 3rd's ptrfdiff with 4th would give 2nd. This is due to fact that
    (2nd XOR 4th) XOR (4th) = 2nd since (4th XOR 4th = 0)
    
    Simlarily , if we want to move to 4th, performing XOR to 3rd ptrdiff with 2nd and 4th.
    (2nd XOR 4th) XOR 2nd = 4th since(2nd XOR 2nd =0)
    
    From above discussion we can see that just by using a single pointer , we can move back  and forth. A memory efficient implementation
    of doubly linked list is possible with minimal compromising of timimg efficiency.
*/
