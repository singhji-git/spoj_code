#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll t;
	cin>>t;
	int a[t+1];
	for(ll i=0;i<t;i++)
	{
		scanf("%lld",&a[i]);
	}
	ll x=a[0];
	for(int i=1;i<t;i++)
	{
		x=x^a[i];
	}
    printf("%lld",x);
}
