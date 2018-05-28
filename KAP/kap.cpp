#include <bits/stdc++.h>
#define maxn 200010
#define inf (long long int)9e11+999
#define mp make_pair
#define para pair <int, int>
using namespace std;
int n,x,y;
long long int droga[maxn];
vector <para> v[maxn];
pair <para, int> tab[maxn];
priority_queue <pair <long long int, long long int> > q;
bool odw[maxn];

void dijkstra()
{
	q.push(mp(0, 1));
	odw[1]=true;
	while(!q.empty())
	{
		long long int pierwszy=q.top().first*-1;
		long long int drugi=q.top().second;
		odw[drugi]=true;
		q.pop();
		for (int i=0; i<(int)v[drugi].size(); i++)
		{
			if (!odw[v[drugi][i].first])
			{
				if (pierwszy+v[drugi][i].second<droga[v[drugi][i].first])
				{
					droga[v[drugi][i].first]=pierwszy+v[drugi][i].second;
					q.push(mp(-1*(droga[v[drugi][i].first]), v[drugi][i].first));
				}
			}
		}
	}
}

int main()
{
	scanf ("%d", &n);
	for (int i=0; i<n; i++)
	{
		scanf("%d%d", &x, &y); 
		tab[i]=mp(mp(x,y), i+1);
		droga[i+1]=inf;
	}
	sort(tab, tab+n);
	v[tab[0].second].push_back(mp(tab[1].second, min(abs(tab[0].first.first-tab[1].first.first), abs(tab[0].first.second-tab[1].first.second))));
	v[tab[n-1].second].push_back(mp(tab[n-2].second, min(abs(tab[n-1].first.first-tab[n-2].first.first), abs(tab[n-1].first.second-tab[n-2].first.second))));
	for (int i=1; i<n-1; i++)
	{
		v[tab[i].second].push_back(mp(tab[i+1].second, min(abs(tab[i].first.first-tab[i+1].first.first), abs(tab[i].first.second-tab[i+1].first.second))));
		v[tab[i].second].push_back(mp(tab[i-1].second, min(abs(tab[i].first.first-tab[i-1].first.first), abs(tab[i].first.second-tab[i-1].first.second))));
	}
	for (int i=0; i<n; i++)
	{
		swap(tab[i].first.second, tab[i].first.first);
	}
	sort(tab, tab+n);
	v[tab[0].second].push_back(mp(tab[1].second, min(abs(tab[0].first.first-tab[1].first.first), abs(tab[0].first.second-tab[1].first.second))));
	v[tab[n-1].second].push_back(mp(tab[n-2].second, min(abs(tab[n-1].first.first-tab[n-2].first.first), abs(tab[n-1].first.second-tab[n-2].first.second))));
	for (int i=1; i<n-1; i++)
	{
		v[tab[i].second].push_back(mp(tab[i+1].second, min(abs(tab[i].first.first-tab[i+1].first.first), abs(tab[i].first.second-tab[i+1].first.second))));
		v[tab[i].second].push_back(mp(tab[i-1].second, min(abs(tab[i].first.first-tab[i-1].first.first), abs(tab[i].first.second-tab[i-1].first.second))));
	}
	dijkstra();
	printf("%lld", droga[n]);
}
