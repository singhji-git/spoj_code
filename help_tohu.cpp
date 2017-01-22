#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll mul=(n+1)*(n+2)*2;
		double ans=3/4.;
		ans=ans-(1.0)/mul;
		cout<<fixed<<setprecision(11)<<ans<<endl;
	}
}
