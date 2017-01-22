#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<ll>vec;
int main()
{
	vec=vector<ll>(34000,0);
	vec[1]=1;
	vec[0]=1;
	vector<int>vec2;
    for(int i=2;i<=34000;i++)
    {
    	//cout<<"*";
    //	cout<<vec[i]<<" "<<i<<endl;
    	if(vec[i]==0)
    	{
    		//cout<<i<<endl;
    		vec2.push_back(i);
    		int count=0;
    		
    		
    		for(int j=i+1;j<=34000;j++)
    		{
    			if(vec[j]==0)
    			{
    				count++;
    			}
    			if(count==i)
    			{
    			//	cout<<j<<" ";
    				count=0;
    				vec[j]=1;
    			}
    		}
    	//	cout<<endl;
    	}
    
    }
    
	int n;
	cin>>n;
	while(n)
	{
		cout<<vec2[n-1]<<endl;
		cin>>n;
	}
}
