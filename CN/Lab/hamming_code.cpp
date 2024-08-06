#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  vector<int> pb;
  vector<int> res;
  int x = 0;
  while (pow(2, x) <= n)
  {
    pb.push_back(pow(2, x));
    x++;
  }
  for (int i = 0; i < pb.size(); i++)
  {
    int j = pb[i] - 1;
    int cnt = 0;
    int n1 = 0;
    while (j < n)
    {
      if (cnt == pb[i])
      {
        j += pb[i] - 1;
        cnt = 0;
      }
      else if (cnt < pb[i])
      {
        cnt++;
        if (v[j] == 1)
        {
          n1++;
        }
      }
      j++;
    }
    if (n1 % 2 == 0)
    {
      res.push_back(0);
    }
    else
    {
      res.push_back(1);
    }
  }
  int dec_no = 0;
  int bin = 0;
  for (int i = 0; i < res.size(); i++)
  {
    if (res[i] == 1)
    {
      dec_no += pow(2, bin);
    }
    bin++;
  }
  cout << "Given binary string : ";
  for (int i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
  if (dec_no == 0)
  {
    cout << "Given binary string is correct.";
  }
  else
  {
    cout << dec_no << "th bit is incorrect !!" << endl;
    cout << "Actual string is : ";
    for (int i = 0; i < n; i++)
    {
      if (i == dec_no - 1)
      {
        if (v[i] == 1)
        {
          cout << 0 << " ";
        }
        else
        {
          cout << 1 << " ";
        }
      }
      else
      {
        cout << v[i] << " ";
      }
    }
    cout << endl;
  }
  cout << endl;
}