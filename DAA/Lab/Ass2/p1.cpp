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

#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
  if (a.second < b.second)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int solve(vector<pair<int, int>> &v, int n, int k)
{
  int res = 0;
  vector<int> end(k, 0);
  for (int i = 0; i < n; i += k)
  {
    for (int j = 0; j < k; j++)
    {
      if (v[i + j].first >= end[j])
      {
        end[j] = v[i + j].second;
        res++;
      }
    }
  }
  return res;
}

int main()
{
  int n;
  cin >> n;
  int s[n], e[n];
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> e[i];
  }
  int k;
  cin >> k;
  vector<pair<int, int>> v(n);

  for (int i = 0; i < n; i++)
  {
    v[i].first = s[i];
    v[i].second = e[i];
  }
  sort(v.begin(), v.end(), comp);

  int res = solve(v, n, k);
  cout << "Maximum number of shops can be visited : " << res << endl;

  return 0;
}
