// find the number of ways in which you can invite n people
// to your party , single or in pairs

#include<iostream>

using namespace std;

int callGuests(int n){
    if(n <= 1){
        return 1;
    }
    // single
    int way1 = callGuests(n-1);

    //pair
    int way2 = (n-1) * callGuests(n-2);
    
    return way1 + way2;
}

int main(){
    int n =4;
    cout<<callGuests(4);
    return 0;
}