// 1. Implement a problem of number of zeroes.
// Statement: Given an array of 1s and 0s which has all 
// 1s first followed by all 0s? Find the number of 0s. 
// Count the number of zeroes in the given array.
// Input: arr[] = {1, 1, 1, 1, 0, 0} Output: 2
// Input: arr[] = {1, 0, 0, 0, 0} Output: 4
// CO1

#include<iostream>
using namespace std;

int cnt_zeros(int *arr,int n){
  int res=0;
  for(int i=0;i<n;i++){
    if(arr[i]==0){
      res++;
    }
  }
  return res;
}


int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    int res=cnt_zeros(arr,n);
    cout<<res<<endl;
  }
  return 0;
}