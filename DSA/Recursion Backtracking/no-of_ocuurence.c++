// TO FIND THE FIRST AND LAST OCCURENCE OF AN ELEMENT IN STRING USING RECURSION
#include<iostream>
#include<string>

using namespace std;

static int first = -1, last = -1;

void findOccurence(string str, int index, char element){
    if(index == -1){
        cout<<"First chracter occurence index "<<first<<endl;
        cout<<"Last chracter occurence index "<<last<<endl;
        return;
    }
    char currElement = str[index];
    if(currElement == element){
        if(last == - 1)
            last = index;
        else{
            first = index;
        }
    }
    findOccurence(str, index -1, element);
}

int main(){
    string str = "abaabcdacba";
    findOccurence(str,str.length()-1,'a');
    return 0;
}
