// Implement Subset Sum Problem.
// Statement Given a set of non-negative integers and a 
// value sum, the task is to check if there is a subset of the 
// given set whose sum is equal to the given sum.
// Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9 
// Output: True
// Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30 
// Output: False
// CO3

#include<iostream>
using namespace std;

bool isSum(int sum, int* s,int n){
    if(sum==0) return true;
    if(sum>0 && n==0) return false;
    if(s[n]>sum){
        return isSum(sum,s,n-1);
    }
    else{
        return (isSum(sum,s,n-1) || isSum(sum-s[n],s,n-1));
    }
}

int main(){
    int n;
    cin>>n;
    int s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    int sum;
    cin>>sum;
    bool res=isSum(sum,s,n-1);
    (res==1)?cout<<"True"<<endl;:cout<<"False"<<endl;
    
    return 0;
}