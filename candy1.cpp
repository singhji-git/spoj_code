#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n!=-1){
	
	vector<int>vec;
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		sum+=x;
		vec.push_back(x);
	}
	if(sum%n==0)
	{
	   ll avg=sum/n;
	   ll ans=0;
	   for(int i=0;i<n;i++)
	   {
	   	  if(vec[i]<avg)
	   	  {
	   	  	ans+=avg-vec[i];
	   	  }
	   }
	   cout<<ans<<endl;
	}
	else
	{
		cout<<"-1"<<endl;
	}
	cin>>n;
	
}
}
