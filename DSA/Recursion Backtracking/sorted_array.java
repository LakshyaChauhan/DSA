// package DSA.Recursion Backtracking;

public class sorted_array {
    public static int isArraySorted(int arr[],int n){
        if(n == 1){
            return 1;
        }
        else return(arr[n-1] < arr[n-2]?0: isArraySorted(arr, n -1));
    }
    public static void main(String []args){
        int arr[] = {1,2,3,4,6,5};
        System.out.println(isArraySorted(arr,6));
    }
}
