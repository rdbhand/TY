// 3. Implement a problem of minimum work to be done 
// per day to finish given tasks within D days problem.
// Statement: Given an array task[] of size N denoting 
// amount of work to be done for each task, the problem 
// is to find the minimum amount of work to be done on 
// each day so that all the tasks can be completed in at 
// most D days. Note: On one day work can be done for 
// only one task.
// Input: task[] = [3, 4, 7, 15], D = 10 
// Output: 4
// Input: task[] = [30, 20, 22, 4, 21], D = 6 
// Output: 22
// CO2


#include<bits/stdc++.h>
using namespace std;

int solve(int n,int task[],int d,int res){
	int days=0;
	for(int i=0;i<n;i++){
		days += ceil((double)task[i] / res);
	}
	if(days>d){
		return solve(n,task,d,res+1);
	}
	return res;
}
int main(){
	int n;
	cin>>n;
	int task[n];
	for(int i=0;i<n;i++){
		cin>>task[i];
	}
	int d;
	cin>>d;
	int res=1;
	int x=solve(n,task,d,res);
	cout<<x<<endl;
	
	return 0;
}
