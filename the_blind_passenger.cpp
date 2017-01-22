#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		cin>>n;
		if(n==1)
		{
			cout<<"poor conductor"<<endl;
		}
		else
		{
			int start=ceil((n-1)/5.);
			n=n%10;
			if(n==1||n==2)
			{
				cout<<start<<" W L"<<endl;
			}
			else if(n%10==0 || n%10==3)
			{
				cout<<start<<" A L"<<endl;
			}
			else if(n%10==4 || n%10==9)
			{
				cout<<start<<" A R"<<endl;
			}
			else if(n%10==5 || n%10==8)
			{
				cout<<start<<" M R"<<endl;
			}
			else if(n%10==6 || n%10==7)
			{
				cout<<start<<" W R"<<endl;
			}
		}
		
	}
}
