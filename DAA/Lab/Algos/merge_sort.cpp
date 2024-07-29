#include <iostream>
using namespace std;
void merge(int *arr, int l, int r)
{
  int mid = (l + r) / 2;
  int len1 = mid - l + 1;
  int len2 = r - mid;
  int *left_arr = new int[len1];
  int *right_arr = new int[len2];
  int main_arr_ind = l;
  for (int i = 0; i < len1; i++)
  {
    left_arr[i] = arr[main_arr_ind++];
  }
  main_arr_ind = mid + 1;
  for (int i = 0; i < len2; i++)
  {
    right_arr[i] = arr[main_arr_ind++];
  }

  int ind1 = 0, ind2 = 0;
  main_arr_ind = l;
  while (ind1 < len1 && ind2 < len2)
  {
    if (left_arr[ind1] < right_arr[ind2])
    {
      arr[main_arr_ind++] = left_arr[ind1++];
    }
    else
    {
      arr[main_arr_ind++] = right_arr[ind2++];
    }
  }
  while (ind1 < len1)
  {
    arr[main_arr_ind++] = left_arr[ind1++];
  }
  while (ind2 < len2)
  {
    arr[main_arr_ind++] = right_arr[ind2++];
  }
}

void merge_sort(int *arr, int l, int r)
{
  if (l >= r)
  {
    return;
  }
  int mid = (l + r) / 2;
  merge_sort(arr, l, mid);
  merge_sort(arr, mid + 1, r);
  merge(arr, l, r);
}

int main()
{
  int n;
  cout << "Enter array size : ";
  cin >> n;
  int arr[n];
  cout << "Enter array elements : ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int l = 0, r = n - 1;
  merge_sort(arr, l, r);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}