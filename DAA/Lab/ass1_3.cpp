/*

3. Implement a problem of smallest number with at least n trailing zeroes in factorial.
Statement: Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.
Input : n = 1 Output : 5 
Input : n = 6 Output : 25   CO1
*/

#include<iostream>
using namespace std;
long long fact(long long x){
  if(x==1 || x==0){
    return 1;
  }
  return x*fact(x-1);
}

int main(){
  long long res=fact(16);
  for(int i=1;i<=20;i++){
    res=fact(i);
    cout<<i<<"==>"<<res<<endl;
  }
  return 0;
}