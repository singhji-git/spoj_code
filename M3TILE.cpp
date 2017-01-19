#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n!=-1){
	int arr[41];
	for(int i=0;i<=30;i++)
	{
		arr[i]=0;
	}
	arr[0]=1;
	arr[1]=0;
	arr[2]=3;
	arr[3]=0;
	for(int i=4;i<=30;i+=2)
	{
	    arr[i]=arr[i-2]*4-arr[i-4];
	}
	cout<<arr[n]<<endl;
	cin>>n;
}
} 
