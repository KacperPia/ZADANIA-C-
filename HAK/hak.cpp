#include <bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
#define maxn 1000011
#define pb push_back
using namespace std;
int n,tab[maxn],ile,sum[maxn],wynik;
deque <pair <int, int> > q;

void dodaj(int x, int y)
{
	while (q.empty()==false && q.back().ff>=x)
	{
		q.pop_back();
	}
	q.pb(mp(x, y));
}
void usun(int x)
{
	while (q.empty()==false && q.front().ss<x)
	{
		q.pop_front();
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&tab[i]);
	}
	for(int i=0;i<n;i++)
	{
		tab[n+i]=tab[i];
	}
	ile=n/2;
	if(n%2==1)ile++;
	
	
	for (int i=2*n; i>=1; i--)
	{
		if (i>2*n-ile)
		{
			sum[i]=sum[i+1]+tab[i];
		}
		else
		{
			sum[i]=sum[i+1]+tab[i]-tab[i+ile];
		}
	}
	
	for (int i=1; i<=ile+n-1; i++)
	{
		if (i<ile)
		{
			dodaj(sum[i], i);
		}
		else
		{
			usun(i-ile+1);
			dodaj(sum[i], i);
			wynik=max(q.front().ff, wynik);
		}
	}
	printf("%d", wynik);
	
}
