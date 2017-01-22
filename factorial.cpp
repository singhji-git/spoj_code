#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		ll ans=0;
		while(n)
		{
			ans+=n/5;
			n=n/5;
		}
		cout<<ans<<endl;
	}
}
