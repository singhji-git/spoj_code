#include<bits/stdc++.h>
using namespace std;
class multiple
{
	public:
	int a0,a1,a2;
	int lazy;
	multiple()
	{
		lazy=0;
	}
};
void build(int a[],multiple seg[],int tl,int tr,int node)
{
	if(tl>tr)
	{
		return;
	}
	if(tl==tr)
	{
		seg[node].a0=1;
		seg[node].a1=0;
		seg[node].a2=0;
		return;
	}
	int mid=(tl+tr)/2;
	build(a,seg,tl,mid,node*2+1);
	build(a,seg,mid+1,tr,node*2+2);
	seg[node].a0=seg[node*2+1].a0+seg[node*2+2].a0;
	seg[node].a1=0;
	seg[node].a2=0;
}

int query(multiple seg[],int tl,int tr,int l,int r,int node)
{
	if(seg[node].lazy!=0)
	{
		if(tl!=tr)
		{
			seg[node*2+1].lazy+=seg[node].lazy;
			seg[node*2+2].lazy+=seg[node].lazy;
		}
		
		int x=seg[node].lazy;
		int f,g,h;
		f=seg[node].a0;
		g=seg[node].a1;
		h=seg[node].a2;
		if(x%3==1)
		{
			seg[node].a0=h;
			seg[node].a1=f;
			seg[node].a2=g;
		}
		else if(x%3==2)
		{
			seg[node].a0=g;
			seg[node].a1=h;
			seg[node].a2=f;
		}		
		seg[node].lazy=0;
	}
	
	
	if(tl>tr||tr<l||tl>r)
	{
		return 0;
	}
	if(tl>=l&&tr<=r)
	{
		return seg[node].a0;
	}
	int mid=(tl+tr)/2;
	int x=query(seg,tl,mid,l,r,node*2+1);
	int y=query(seg,mid+1,tr,l,r,node*2+2);
	return x+y;
}

void update(multiple seg[],int tl,int tr,int l,int r,int node)
{
	if(seg[node].lazy!=0)
	{
		if(tl!=tr)
		{
			seg[node*2+1].lazy+=seg[node].lazy;
			seg[node*2+2].lazy+=seg[node].lazy;
		}
		
		int x=seg[node].lazy;
		int f,g,h;
		f=seg[node].a0;
		g=seg[node].a1;
		h=seg[node].a2;
		if(x%3==1)
		{
			seg[node].a0=h;
			seg[node].a1=f;
			seg[node].a2=g;
		}
		else if(x%3==2)
		{
			seg[node].a0=g;
			seg[node].a1=h;
			seg[node].a2=f;
		}		
		seg[node].lazy=0;
	}
	
	if(tl>tr||tl>r||tr<l)
	{
		return;
	}
	if(tl>=l&&tr<=r)
	{	
		int x=seg[node].a2;
		int y=seg[node].a0;
		int z=seg[node].a1;
		seg[node].a0=x;
		seg[node].a1=y;
		seg[node].a2=z;		
		if(tl!=tr)
		{
			seg[node*2+1].lazy+=1;
			seg[node*2+2].lazy+=1;
		}
		seg[node].lazy=0;
		return;
	}
	int mid=(tl+tr)/2;
	update(seg,tl,mid,l,r,node*2+1);
	update(seg,mid+1,tr,l,r,node*2+2);
	seg[node].a0=seg[node*2+1].a0+seg[node*2+2].a0;
	seg[node].a1=seg[node*2+1].a1+seg[node*2+2].a1;
	seg[node].a2=seg[node*2+1].a2+seg[node*2+2].a2;
}

int main()
{
	int n,q;
//	cin>>n>>q;
	scanf("%d %d",&n,&q);
	int a[n+5];
	multiple seg[4*n+5];
	memset(a,0,n);
	build(a,seg,0,n-1,0);
//	cout<<"*";
	for(int i=0;i<q;i++)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
	
		if(x==0)
		{
		  update(seg,0,n-1,y,z,0);
		}
		else
		{
			int ans=query(seg,0,n-1,y,z,0);
		     printf("%d\n",ans);
		}
	}
	return 0;
}
