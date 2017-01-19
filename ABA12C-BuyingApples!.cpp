#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll table[102][102];
ll find(int arr[],int index,int n,int w)
{
	if(w<0)
	{
		return  INT_MAX;
	}
	if(table[index][w]==-1){
	
	 if(w==0)
	{
		table[index][w]= 0;
	}
	else if(index==n)
	{
		table[index][w]=  INT_MAX;
	}
	else
	{
		if(arr[index]!=-1)
		{
			ll x=find(arr,index,n,w-index-1)+arr[index];
			ll x1=find(arr,index+1,n,w-index-1)+arr[index];
			ll y=find(arr,index+1,n,w);
			table[index][w]=min(x,min(x1,y));
		}
		else
		{
		table[index][w]=  find(arr,index+1,n,w);
		}
	}
}
return table[index][w];
}
int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		for(int i=0;i<=100;i++)
		{
			for(int j=0;j<=100;j++)
			{
				table[i][j]=-1;
			}
		}
		int n,k;
		cin>>n>>k;
		int arr[k+5];
		for(int i=0;i<k;i++)
		{
			cin>>arr[i];
		}
		ll ans=find(arr,0,k,k);
		if(ans>=INT_MAX)
		{
			cout<<"-1"<<endl;
		}
		else
		{
			cout<<ans<<endl;
		}
	}
}
