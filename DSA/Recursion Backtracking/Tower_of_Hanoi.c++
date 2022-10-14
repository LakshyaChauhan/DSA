// /*
// ALGORITHM
//         * Move n-1 discs from source to auxiliary tower.
//         * Move the n th disk from Auxiliary tower to Destination tower
//         * Move the n-1 dics from Auxiliary tower to Destination tower.
//         * Transferring the top n-1 disks from source to auxiliary tower can again be thoought of as a fresh problem
//           and can be solved in the same manner. once we solve Towers Of Hanoi with three dics, we can solve it with any number of discs
//           with the above algorithm.
//  


// TOWER OF HANOI FAMOUS CLASSICAL PROBLEM OF RECUSRION 
/*    n disks       n-1 disks           1 - source Destination
 *      |               |                   |
 *      |               |                   |
 *      |               |                   |
 *      |               |                   |
 *    A (SOURCE)        B (HELPER)       C (DESTINATION)
 * 
 * 
 *  RULE 1 : ONLY ONE DISK CAN BE TRANSFERRED IN ONE STEP
 *  RULE 2 : SMALLER DISKS ARE ALWAYS KEPT ON LARGER DISKS
 * 
 * 
 *  n - 1 disks ko helper tak pahucha de 
 *  1st disk ko destination tk pahuccha de
 *  n - 1 disk ko destination tk leke jaana hai using source as helper
 *  O(2^n - 1) 
 *  T(n) = 2T(n-1) + 1
 */

//
// */


#include<iostream>

using namespace std;

void TowerOfHanoi(int disks, string source, string destination, string helper ){
    if(disks == 1){
        cout<<"Move disks 1 from "<<source<<" to "<<destination<<endl;
        return;
    }
    TowerOfHanoi(disks-1, source, helper, destination);

    cout<<"Move disk "<<disks<<" from "<<source<<" to "<<destination<<endl;

    TowerOfHanoi(disks-1, helper, destination, source);
}

int main(){
    cout<<"Enter the number of disks in Tower Of Hanoi ";
    int n;
    cin>>n;
    TowerOfHanoi(n,"A","B","C");
    return 0 ;
}