#include<bits/stdc++.h>
using namespace std;
void build(int a[],int seg[],int tl,int tr,int node)
{
	if(tl>tr)
	{
		return;
	}
	if(tl==tr)
	{
		seg[node]=a[tl];
		return;
	}
	int mid=(tl+tr)/2;
    build(a,seg,tl,mid,node*2+1);
    build(a,seg,mid+1,tr,node*2+2);
    seg[node]=min(seg[node*2+1],seg[node*2+2]);
}

int query(int tl,int tr,int l,int r,int node,int seg[])
{
	if(tl>r||tr<l||tl>tr)
	{
		return INT_MAX;
	}
	if(tl>=l&&tr<=r)
	{
		return seg[node];
	}
	int mid=(tl+tr)/2;
	int x=query(tl,mid,l,r,node*2+1,seg);
	int y=query(mid+1,tr,l,r,node*2+2,seg);
	return min(x,y);
}
int main()
{
	int n;
	cin>>n;
	int a[n+2];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int seg[4*n+5];
	build(a,seg,0,n-1,0);
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int l,r;
		cin>>l>>r;
		cout<<query(0,n-1,l,r,0,seg)<<endl;
	}
}
