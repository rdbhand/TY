#include <iostream>
using namespace std;

void binary_search(int *arr, int n, int x)
{
  int l = 0, r = n - 1, fl = 0;
  while (l <= r)
  {
    int mid = (l + r) / 2;
    if (x == arr[mid])
    {
      cout << x << " found at index " << mid << endl;
      fl = 1;
      break;
    }
    else if (x < arr[mid])
    {
      r = mid - 1;
    }
    else
    {
      l = mid + 1;
    }
  }
  if (fl == 0)
  {
    cout << x << " Not Found !!" << endl;
  }
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
  int ch;
  do
  {
    int x;
    cout << "Enter element to be searched : ";
    cin >> x;
    binary_search(arr, n, x);
    cout << "Do you want to search another element (1/0) : ";
    cin >> ch;
  } while (ch);
  return 0;
}