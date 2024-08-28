/*

2. Implement a problem of move all zeroes to end of
array.
Statement: Given an array of random numbers, Push all the zero’s
of a given array to the end of the array. For example, if the given
arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed to {1, 9,
8, 4, 2, 7, 6, 0, 0, 0, 0}. The order of all other elements should be
same.
Input : arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
Output : arr[] = {1, 2, 4, 3, 5, 0, 0, 0};
CO1

*/
#include <iostream>
using namespace std;

void move_zeroes(int *arr, int n)
{
	int i = 0, j = 1;
	while (i < n && j < n)
	{
		if (arr[i] == 0 && arr[j] != 0)
		{
			swap(arr[i], arr[j]);
		}
		if (arr[i] != 0)
		{
			i++;
		}
		if (arr[j] == 0)
		{
			j++;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	move_zeroes(arr, n);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}
