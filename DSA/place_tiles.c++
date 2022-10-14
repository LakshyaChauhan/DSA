// Place tiles of size 1xm in floor of size nxm

#include<iostream>

using namespace std;

int placeTiles(int n, int m){
    if(n == m){
        return 2;
    }
    if(n<m){
        return 1;
    }
    // vertically
    int vertPlacements = placeTiles(n-m, m);
    // horizontally
    int horiPlacments = placeTiles(n-1,m);

    return vertPlacements + horiPlacments;
}

int main(){
    int n =3 ,m =4;
    int totalPlacements = placeTiles(n,m);
    cout<<totalPlacements;
    return 0;
}
