// 1. Implement a problem of number of zeroes.
// Statement: Given an array of 1s and 0s which has all 
// 1s first followed by all 0s? Find the number of 0s. 
// Count the number of zeroes in the given array.
// Input: arr[] = {1, 1, 1, 1, 0, 0} Output: 2
// Input: arr[] = {1, 0, 0, 0, 0} Output: 4
// CO1

#include<iostream>
using namespace std;

int cnt_zeroes(int *arr,int n){
  int lt=0;
  int rt=n-1;
  if(arr[lt]==0){
    return n;
  }
  if(arr[rt]==1){
    return 0;
  }
  while(lt<=rt){
    int mid=(lt+rt)/2;
    if(arr[mid]==1 && arr[mid+1]==0){
      return n-mid-1;
    }
    else if(arr[mid]==1){
      lt=mid+1;
    }
    else{
      rt=mid-1;
    }
  }
}

int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int res=cnt_zeroes(arr,n);
  cout<<"No. of zeroes : "<<res;
  return 0;
}