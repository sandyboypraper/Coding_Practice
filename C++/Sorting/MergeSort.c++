#include<bits/stdc++.h>

using namespace std;


void merge(int arr[] , int la , int ra , int lb , int rb)
{
	int tempa[ra - la + 1];
	int tempb[rb - lb + 1];
	

	for(int i = 0;i<=(ra-la);i++)
		tempa[i] = arr[i];

	for(int i = 0;i<=(rb-lb);i++)
		tempb[i] = arr[i];

	int ind = la;
	int i = 0,j = 0;

	cout<<"hey"<<endl;

	while(i <= (ra-la) && j <= (rb-lb))	
	{
		if(tempa[i] <= tempb[i])
		{
			arr[ind++] = tempa[i];
			i++;
		}
		else
		{
			arr[ind++] = tempb[j];
			j++;
		}
	}

	while(i <= (ra-la))
	{	
		arr[ind++] = tempa[i];
		i++;
	}

	while(j <= (rb - lb))
	{
		arr[ind++] = tempb[j];
		j++;
	}

}

int compare(int a , int b)
{
	return a<b;
}

void Msort(int arr[] , int left , int right)
{
	if(left >= right)
		return;

	if(right == left + 1)
	{
		if(!compare(arr[left] , arr[right]))
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
		return;
	}

	int mid = (right + left)/2; 
	Msort(arr , left , mid);
	Msort(arr , mid+1 , right);
	merge(arr , left , mid , mid+1 , right);
}

int main()
{
	int n;
	cin>>n;

	int arr[n];
	for(int i = 0;i<n;i++)
		cin>>arr[i];

	Msort(arr , 0  , n-1);
	for(int i = 0;i<n;i++)
		cout<<arr[i]<<"  ";
}