/*
Implement a problem of move all zeroes to end of 
array.
Statement: Given an array of random numbers, Push all the zero’s 
of a given array to the end of the array. For example, if the given 
arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed to {1, 9, 
8, 4, 2, 7, 6, 0, 0, 0, 0}. The order of all other elements should be 
same.
Input : arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
Output : arr[] = {1, 2, 4, 3, 5, 0, 0, 0};
CO1

*/
#include<iostream>
using namespace std;

// void merge(int *arr, int l, int r)
// {
//   int mid = (l + r) / 2;
//   int len1 = mid - l + 1;
//   int len2 = r - mid;
//   int *left_arr = new int[len1];
//   int *right_arr = new int[len2];
//   int main_arr_ind = l;
//   for (int i = 0; i < len1; i++)
//   {
//     left_arr[i] = arr[main_arr_ind++];
//   }
//   main_arr_ind = mid + 1;
//   for (int i = 0; i < len2; i++)
//   {
//     right_arr[i] = arr[main_arr_ind++];
//   }
//   int ind1 = 0, ind2 = 0;
//   main_arr_ind = l;
//   while (ind1 < len1)
//   {
//   	if(left_arr[ind1]!=0){
//   		arr[main_arr_ind++] = left_arr[ind1];
//   	}
//     ind1++;
//   }
//   while (ind2 < len2)
//   {
//   	if(right_arr[ind2]!=0){
//   		arr[main_arr_ind++] = right_arr[ind2];
//   	}
//     ind2++;
//   }
//   while(main_arr_ind<(len1+len2)){
//   	arr[main_arr_ind++]=0;
//   }
// }

// void merge_sort(int *arr, int l, int r)
// {
//   if (l >= r)
//   {
//     return;
//   }
//   int mid = (l + r) / 2;  
//   merge_sort(arr, l, mid);
//   merge_sort(arr, mid + 1, r);
//   merge(arr, l, r);
// }

void move_zeroes(int *arr,int n){
	// int l=0,r=n-1;
	// merge_sort(arr,l,r);
  int i=0,j=1;
  while(i<n && j<n){
    if(arr[i]==0 && arr[j]!=0){
      swap(arr[i],arr[j]);
      i++;
      j++;
    }
    else if(arr[i]!=0 && arr[j]==){
      i++;
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
	
	move_zeroes(arr,n);
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
