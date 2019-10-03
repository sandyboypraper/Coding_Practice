#include<iostream>

using namespace std;

int compare(int a , int b)
{
	return a<b;
}

void swap(int arr[] , int i , int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void Qsort(int arr[] , int left , int right)
{
	
	if(left < 0 || right < 0)
		return;

	if(left > right)
		return;

	if(left == right)
		return;

	int i = right;
	int j = left;



	while(i > j)
	{
		if(!compare(arr[j] , arr[i]))
		{
			swap(arr , j , i-1);
			swap(arr , i-1 , i);
			i--;
		}
		else
		{
			j++;
		}
	}

	for(int ii = left;ii<=right;ii++)
		cout<<arr[ii]<<"   ";

	cout<<endl<<i<<"  "<<j<<endl;

	Qsort(arr , left , i-1);
	Qsort(arr , i+1 , right);
}

int main()
{
	int n;
	cin>>n;

	int arr[n];

	for(int i = 0;i<n;i++)
	{
		cin>>arr[i];
	}

	Qsort(arr , 0 , n-1);
	for(int i = 0;i<n;i++)
		cout<<arr[i]<<"  ";
}