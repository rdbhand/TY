// 2. Implement a problem of maximize Profit by trading
// stocks based on given rate per day.
// CO2
// Statement: Given an array arr[] of N positive integers
// which denotes the cost of selling and buying a stock on
// each of the N days. The task is to find the maximum
// profit that can be earned by buying a stock on or selling
// all previously bought stocks on a particular day.
// Input: arr[] = {2, 3, 5} Output: 5
// Input: arr[] = {8, 5, 1} Output: 0

#include <bits/stdc++.h>
using namespace std;
int solve(int n, int *arr)
{
	int min_price = INT_MAX;
	int max_profit = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min_price)
		{
			min_price = arr[i];
		}
		int profit = arr[i] - min_price;
		if (profit > max_profit)
		{
			max_profit = profit;
		}
	}

	return max_profit;
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
	int mx_profit = solve(n, arr);
	cout << "Maximum Profit : " << mx_profit << endl;
	return 0;
}
