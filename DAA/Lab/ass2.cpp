// 2. Implement a problem of move all zeroes to end of 
// array.
// Statement: Given an array of random numbers, Push all the zero’s 
// of a given array to the end of the array. For example, if the given 
// arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed to {1, 9, 
// 8, 4, 2, 7, 6, 0, 0, 0, 0}. The order of all other elements should be 
// same.
// Input : arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
// Output : arr[] = {1, 2, 4, 3, 5, 0, 0, 0};
// CO1

#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements : ";
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }

    // solving 

    for(int i=0;i<n;i++){
      if(arr[i]==0){
        int j=i+1;
        while(arr[j]==0){
          j++;
        }
        if(j<n){
          swap(arr[i],arr[j]);
        }
        else{
          break;
        }
      }
    }
      for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
    }
    cout<<endl;
  }

  //   int i=0,j=n-1;
  //   while(i<j){
  //     if(arr[i]==0 && arr[j]==1){
  //       swap(arr[i],arr[j]);
  //       i++;
  //       j--;
  //     }
  //     if(arr[i]==1){
  //       i++;
  //     }
  //     if(arr[j]==0){
  //       j--;
  //     }
  //   }

  
}

