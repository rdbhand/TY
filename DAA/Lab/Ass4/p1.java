// 1. Implement program to find all distinct subsets of a given set using Bit Masking Approach. Statement 
//    Given an array of integers arr[], The task is to find all its subsets. The subset cannot contain
//   duplicate elements, so any repeated subset should be considered only once in the output.
//   Input: S = {1, 2, 2} Output: {}, {1}, {2}, {1, 2}, {2, 2}, {1, 2,2}
//   Input: S = {1, 2} Output: {}, {1}, {2}, {1, 2}                                           CO4
import java.util.Scanner;
class p1{
    public static void main(String args[]){
        int n;
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        
    }
}