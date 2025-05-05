#include<iostream>
using namespace std;
int E();
int Edash();
int T();
int Tdash();
int F();
int i=0;
string s;

int E(){
  T();
  Edash();
  return 1;
}

int T(){
  F();
  Tdash();
  return 1;
}

int Edash(){
  if(s[i]=='+'){
    i++;
    T();
    Edash();
    return 1;
  }
  else{
    return 1;
  }
}

int Tdash(){
  if(s[i]=='*'){
    i++;
    F();
    Tdash();
    return 1;
  }
  else{
    return 1;
  }
}

int F(){
  if(s[i]=='('){
    i++;
    E();
    if(s[i]==')'){
      i++;
      return 1;
    }
  }
  else if(s[i]=='i'){
    i++;
    return 1;
  }
  else{
    return 0;
  }
}

int main(){
  cout<<"Enter String to parse using RDP : ";
  cin>>s;
  int res=E();
  if(res==1 && i==s.length()){
    cout<<"String Parsed Successfully !!!";
  }
  else{
    cout<<"String Not Parsed Successfully !!!";
  }
  return 0;
}