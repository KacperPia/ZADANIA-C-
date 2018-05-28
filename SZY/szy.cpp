#include <bits/stdc++.h>
using namespace std;
int x,y;
long long int n, k, a,c,lol,b,sr;
long long int wyn, nyw;
long long int dt[41], w[41];
pair <long long int, long long int> v[2000000];
int binsearch(int wynik)
{	
	int kon=(1<<x);
	int p=0;
	while (p<kon)
	{
		sr=(p+kon+1)/2;
		if (wynik==v[sr].first) return sr;
		else if (wynik>v[sr].first) p=sr;
		else if (wynik<v[sr].first)	kon=sr-1;
	}
	return -1;
}

int main()
{   
	scanf("%d",&n);
	y=n/2;
	int ku=0;
	x=n-y;
	for(int i=0; i<x;i++)
	{
		scanf("%lld", &dt[i]);
	}
	for(int i=0; i<y;i++)
	{
		scanf("%lld", &w[i]);
	}
	scanf("%lld",&nyw);

	for(int i=0;i<(1<<x)-1;i++)
	{ 	
		k++;
		wyn=0;
		for(int j=0;j<x;j++)
		{
			if((k&(1<<j))>0)
			{
				wyn+=dt[j];
			}	
		}
		v[i].first=wyn;
		v[i].second=k;
	}
	k=0;
		sort (v, v+(1<<x));
		
	for(int i=0;i<(1<<y)-1;i++)
	{ 	
		k++;
		wyn=0;
		for(int j=0;j<y;j++)
		{
			if((k&(1<<j))>0)
			{
				wyn+=w[j];
			}	
		}
		lol=nyw-wyn;
		if (binsearch(lol)!=-1) 
		{
			break;
		}
	} 	
		for(int j=0;j<x;j++)
	{
		if ((v[sr].second&(1<<j))>0) cout << 1;
		else cout << 0;
	} 
	for(int j=0;j<y;j++)
	{
		if ((k&(1<<j))>0) cout << 1;
		else cout << 0;
	} 
	return 0;
}
