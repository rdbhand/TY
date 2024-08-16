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
