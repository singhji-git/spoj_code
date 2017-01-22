#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		if(n%2==0&&m%2==0)
		{
			if(n>m)
			{
				cout<<"U"<<endl;
			}
			else
			{
				cout<<"L"<<endl;
			}
		}
		else if(n%2==1&&m%2==0)
		{
			if(n>m)
			{
				cout<<"U"<<endl;
			}
			else
			{
				cout<<"R"<<endl;
			}
		}
		else if(n%2==0&&m%2==1)
		{
			if(n>m)
			{
				cout<<"D"<<endl;
			}
			else
			{
				cout<<"L"<<endl;
			}
		}
		else if(n%2==1&&m%2==1)
		{
			if(n>m)
			{
				cout<<"D"<<endl;
			}
			else
			{
				cout<<"R"<<endl;
			}
		}
	 	
	}
	return 0;
}
