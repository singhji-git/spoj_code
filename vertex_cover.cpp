#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int>table;
int find(vector<int>vec[],int src)
{
	if(table[src]>=0)
	{
		return table[src];
	}
	else
	{
		
	
	if(vec[src].size()==0)
	{
		return 0;
	}

	int ans1=0;
	for(int i=0;i<vec[src].size();i++)
	{
		
		int u=vec[src][i];	
		ans1+=find(vec,u);
	}	

	int size_in=1+ans1;
	int ans2=0;
	for(int i=0;i<vec[src].size();i++)
	{
		    int u=vec[src][i];
			for(int j=0;j<vec[u].size();j++)
			{
				int v=vec[u][j];
		        ans2+=find(vec,v);
		    }
	}
	int size_ex=vec[src].size()+ans2;

//	cout<<src<<" "<<size_in<<" "<<size_ex<<endl;
	table[src]= min(size_in,size_ex);
}
	return table[src];
}
	
void func(vector<int>vec[],vector<int>vec1[],vector<bool>&visited,int src)
{
	visited[src]=true;
	for(int i=0;i<vec[src].size();i++)
	{
		int u=vec[src][i];
		if(visited[u] == false)
		{
			vec1[src].push_back(u);
			func(vec,vec1,visited,u);
		}
	}
}

int main()
{
	int n;
	cin>>n;
	vector<int>vec[n+1];
	table=vector<int>(n+1,-1);
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	vector<bool>visited(n+1,false);
	vector<int>vec1[n+1];
	func(vec,vec1,visited,1);
	int ans=find(vec1,1);
	cout<<ans<<endl;
}
