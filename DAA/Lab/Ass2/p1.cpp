// 1. Implement a problem of activity selection problem 
// with K persons.
// Statement: Given two arrays S[] and E[] of size N denoting starting 
// and closing time of the shops and an integer value K denoting the 
// number of people, the task is to find out the maximum number of 
// shops they can visit in total if they visit each shop optimally based 
// on the following conditions:
//  A shop can be visited by only one person
//  A person cannot visit another shop if its timing collide with it
// Input: S[] = {1, 8, 3, 2, 6}, E[] = {5, 10, 6, 5, 9}, K = 2
// Output: 4
// Input: S[] = {1, 2, 3}, E[] = {3, 4, 5}, K = 2
// Output: 3
// CO2

#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  int s[n],e[n];
  for(int i=0;i<n;i++){
    cin>>s[i];
  }
  for(int i=0;i<n;i++){
    cin>>e[i];
  }

  return 0;
}