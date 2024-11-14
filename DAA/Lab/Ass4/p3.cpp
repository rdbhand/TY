// Implement program to print all subsets of a given
// Set or Array
// Statement Given a set of positive integers, find all its
// subsets.
// Input: array = {1, 2, 3}
// Output: // this space denotes null element.
//  1 1 2 1 2 3 1 3 2
// 2 3 3
// Input: 1 2
// Output: 1 2 1 2

#include <bits/stdc++.h>
using namespace std;

void generateSubsets(const vector<int> &set, vector<int> &subset, int index)
{
  if (index == set.size())
  {
    cout << "{ ";
    for (int num : subset)
    {
      cout << num << " ";
    }
    cout << "}\n";
    return;
  }

  subset.push_back(set[index]);
  generateSubsets(set, subset, index + 1);

  subset.pop_back();
  generateSubsets(set, subset, index + 1);
}

void printAllSubsets(const vector<int> &set)
{
  vector<int> subset;
  generateSubsets(set, subset, 0);
}

int main()
{
  vector<int> set = {1, 2, 3};
  printAllSubsets(set);
  return 0;
}
