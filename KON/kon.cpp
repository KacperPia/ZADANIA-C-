#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
int n,m,k,x,y, wsk,p=99999,wyn;
int odw[30010],ojciec[30010],gle[30010], ile;
vector <int> v[30010];
pair <int,int> tab[30010];
queue <pair<int, int> > q;

void bfs(int g)
{
	q.push(mp(g,0));
	odw[g]=g;
	int pierwszy, drugi;
	while (!q.empty())
	{
		pierwszy=q.front().first;
		drugi=q.front().second;
		gle[pierwszy]=drugi;
		q.pop();
		for (int i=0; i<(int)v[pierwszy].size(); i++)
		{
			if (odw[v[pierwszy][i]]!=g) 
			{
				odw[v[pierwszy][i]]=g;
				q.push(mp(v[pierwszy][i], drugi+1));
			}
		}
	}
}

void wrzuc(int a, int b)
{
	tab[wsk]=mp(a, b);
	wsk++;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	scanf("%d",&m);
	scanf("%d",&x);
	for(int i=0;i<m-2;i++)
	{
		scanf("%d",&y);
		wrzuc(x,y);
		x=y;
	}
	scanf("%d",&y);
	wrzuc(x,y);
	sort(tab, tab+wsk);
	p=-7;
	for(int i=0;i<m-1;i++)
	{
		ile++;
		if(tab[i].first!=p)
		{
			ile++;
			gle[x]=0;
			bfs(tab[i].first);
			p=tab[i].first;
		}
		wyn+=gle[tab[i].second];
	}
	cout<<wyn;
	return 0;
}
