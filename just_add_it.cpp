#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll mod=10000000+7;
ll modulo(ll a,ll b,ll mod)
{
	ll x=1;
	ll y=a;
	while(b>0)
	{
		if(b%2==1)
		{
			x=(x*y)%mod;
		}
		y=(y*y)%mod;
		b=b/2;
	}
	return x%mod;
}
int main()
{
	ll n,k;
	cin>>n>>k;
	while(n)
	{
		ll ans=0;
		ans=(modulo(n,k,mod)+((2*modulo(n-1,k,mod))%mod+((2*modulo(n-1,n-1,mod))%mod+modulo(n,n,mod))%mod)%mod)%mod;
		cout<<ans<<endl;
		cin>>n>>k;
	}
}
