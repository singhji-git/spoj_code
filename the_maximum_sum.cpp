#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
void build(int a[],pair<int,int> seg[],int tl,int tr,int node)
{
	if(tl>tr)
	return;
	if(tl==tr)
	{
		seg[node]=make_pair(a[tl],INT_MIN);
		return;
	}
	int mid=(tl+tr)/2;
	build(a,seg,tl,mid,node*2+1);
	build(a,seg,mid+1,tr,node*2+2);
	
	int c,d;
	if(seg[node*2+1].x>seg[node*2+2].x)
	{
		c=seg[node*2+1].x;
		if(seg[node*2+1].y>seg[node*2+2].x)
		{
			d=seg[node*2+1].y;
		}
		else
		{
			d=seg[node*2+2].x;
		}
	}
	else
	{
		c=seg[node*2+2].x;
		if(seg[node*2+1].x>seg[node*2+2].y)
		{
			d=seg[node*2+1].x;
		}
		else
		{
			d=seg[node*2+2].y;
		}
	}
	seg[node]=make_pair(c,d);
}

pair<int,int> query(int tl,int tr,int l,int r,int node,pair<int,int>seg[])
{
	if(tl>r||tr<l||tl>tr)
	{
		pair<int,int>g(INT_MIN,INT_MIN);
		return g;
	}
	if(tl>=l&&tr<=r)
	{
		return seg[node];
	}
	int mid=(tl+tr)/2;
	pair<int,int>m,m1;
	m=query(tl,mid,l,r,node*2+1,seg);
	m1=query(mid+1,tr,l,r,node*2+2,seg);
	
	
	int c,d;
	if(m.x>m1.x)
	{
		c=m.x;
		if(m.y>m1.x)
		{
			d=m.y;
		}
		else
		{
			d=m1.x;
		}
	}
	else
	{
		c=m1.x;
		if(m.x>m1.y)
		{
			d=m.x;
		}
		else
		{
			d=m1.y;
		}
	}
	
	return pair<int,int>(c,d);
}

void update(int tl,int tr,int pos,int v,int node,pair<int,int>seg[])
{
	if(tl>tr)
	{
		return;
	}
	if(tl==tr)
	{
		seg[node].x=v;
		return ;
	}
	int mid=(tl+tr)/2;
	if(pos>mid)
	{
		update(mid+1,tr,pos,v,node*2+2,seg);
	}
	else
	{
		update(tl,mid,pos,v,node*2+1,seg);
	}
	
	
	int c,d;
	if(seg[node*2+1].x>seg[node*2+2].x)
	{
		c=seg[node*2+1].x;
		if(seg[node*2+1].y>seg[node*2+2].x)
		{
			d=seg[node*2+1].y;
		}
		else
		{
			d=seg[node*2+2].x;
		}
	}
	else
	{
		c=seg[node*2+2].x;
		if(seg[node*2+1].x>seg[node*2+2].y)
		{
			d=seg[node*2+1].x;
		}
		else
		{
			d=seg[node*2+2].y;
		}
	}
	seg[node]=make_pair(c,d);
	
}
int main()
{
	int n;
	cin>>n;
	int a[n+1];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	pair<int,int> seg[4*n+5];
	int q;
	cin>>q;
    build(a,seg,0,n-1,0);
   
	for(int i=0;i<q;i++)
	{
		char c;
		int d,e;
		cin>>c>>d>>e;
		if(c=='U')
		{
			update(0,n-1,d-1,e,0,seg);
		}
		else
		{
			pair<int,int>p=query(0,n-1,d-1,e-1,0,seg);
			cout<<p.x+p.y<<endl;
		}
		
	}
}
