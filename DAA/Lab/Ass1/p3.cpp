/*

3. Implement a problem of smallest number with at least n trailing zeroes in factorial.
Statement: Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.
Input : n = 1 Output : 5 
Input : n = 6 Output : 25   CO1
*/

#include <iostream>
using namespace std;

int cnt_trailing_zeroes(int x){
  int cnt = 0;
  while (x >= 5) {
      x /= 5;
      cnt += x;
  }
  return cnt;

}

int smallest_number(int n)
{
  int l = 0, r = 5 * n;
  while (l < r)
  {
    int mid = (l + r) / 2;
    if (cnt_trailing_zeroes(mid) < n)
    {
      l = mid + 1;
    }
    else
    {
      r = mid;
    }
  }
  return l;
}

int main()
{
  int n;
  cin >> n;
  int res = smallest_number(n);
  cout<<"Smallest Number with "<<n<<" trailing zeroes : "<<res<<endl;
  return 0;
}               