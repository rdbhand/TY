/*
1. Implement Coin Change problem. Statement Given an integer array of coins[ ] of size N representing different types of currency and an integer sum, The task is to find the number of ways to make sum by using different combinations from coins[]. 
Note: Assume that you have an infinite supply of each type of coin.
Input: sum = 4, coins[] = {1,2,3}, Output: 4
Input: sum = 10, coins[] = {2, 5, 3, 6} Output: 5                         CO3

*/

#include<bits/stdc++.h>
using namespace std;

int solve(int sum,int n,vector<int>& coins){
	int dp[sum+1];
	dp[0]=1;
	for(int i=1;i<=sum;i++){
		dp[i]=0;
	}
	for(int i=0;i<n;i++){
		for(int j=coins[i];j<=sum;j++){
			dp[j]+=dp[j-coins[i]];
		}
	}
	return dp[sum];
}

int main(){
	int sum;
	cin>>sum;
	int n;
	cin>>n;
	vector<int>coins(n);
	for(int i=0;i<n;i++){
		cin>>coins[i];
	}
	int res=solve(sum,n,coins);
	cout<<"Number of possible ways : "<<res<<endl;
	return 0;
}
