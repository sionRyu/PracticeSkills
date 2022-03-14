#include<iostream>

using namespace std;
long int arr[1000000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	long int all = 0, rep = 0;

	cin >> all;


	for (long int i = 0; i < all; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < all-1; i++)
	{	
		if (arr[0]>arr[i+1])
		{
			rep = arr[0];
			arr[0] = arr[i];
			arr[i] = rep;
		}

		if (arr[all-1] < arr[i])
		{
			rep = arr[all-1];
			arr[all - 1] = arr[i];
			arr[i] = rep;
		}
	}

	cout << arr[0] <<" "<< arr[all - 1] << endl;

	return 0;
}