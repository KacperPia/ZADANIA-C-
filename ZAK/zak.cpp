#include <bits/stdc++.h>
using namespace std;
#define maxn 300005
int a, b, n, centroid, visc[maxn], visp[maxn], ludzie[maxn], dodatnie[maxn], ujemne[maxn], dodatnie_p[maxn], ujemne_p[maxn];
char c[2];
long long int suma, wynik, wsk, dokad;
vector <pair <int ,int > > v[maxn];
bool vis[maxn];
 
void dfs_fff(int x)
{
    visp[x]=wsk;
    ludzie[x]=0;
    int k=v[x].size();
    for (int i=0; i<k; i++)
    {
        if (visp[v[x][i].first]!=wsk && !vis[v[x][i].first])
        {
            dfs_fff(v[x][i].first);
            ludzie[x]+=ludzie[v[x][i].first];
        }
    }
    ludzie[x]++;
}
 
void dfs_sec(int x, int ile, int t)
{
    visp[x]=wsk;
    suma+=ile;
    if (suma==0 && t!=x)
    {
        wynik++;
        wynik+=dodatnie[0];
        dodatnie_p[0]++;
    }
    else if (suma>0)
    {
        dokad=max(dokad, suma);
        wynik+=ujemne[suma];
        dodatnie_p[suma]++;
    }
    else if (suma<0)
    {
        dokad=max(dokad, -1*suma);
        wynik+=dodatnie[-1*suma];
        ujemne_p[-1*suma]++;
    }
    ludzie[x]=0;
    int k=v[x].size();
    for (int i=0; i<k; i++)
    {
        if (x==t)
        {
            for (int o=0; o<=dokad; o++)
            {
                dodatnie[o]+=dodatnie_p[o];
                ujemne[o]+=ujemne_p[o];
                dodatnie_p[o]=ujemne_p[o]=0;
 
            }
        }
        if (visp[v[x][i].first]!=wsk && !vis[v[x][i].first])
        {
            dfs_sec(v[x][i].first, v[x][i].second, t);
            ludzie[x]+=ludzie[v[x][i].first];
        }
    }
    ludzie[x]++;
    suma-=ile;
}
 
void cent(int x, int m)
{
    visc[x]=wsk;
    int k=v[x].size();
    for (int i=0; i<k; i++)
    {
        if (!vis[v[x][i].first] && ludzie[v[x][i].first]>=((m+1)>>1) && visc[v[x][i].first]!=wsk)
        {
            cent(v[x][i].first, m);
            return;
        }
    }
    if (m-ludzie[x]<=((m+1)>>1)) centroid=x;
    return;
}
 
void fff(int x, int m)
{
    if (m==1)
    {
        vis[x]=true;
        return;
    }
    wsk++;
    dfs_fff(x);
    wsk++;
    cent(x, ludzie[x]);
    for (int i=0; i<=dokad+1; i++)
    {
        dodatnie_p[i]=0;
		dodatnie[i]=0;
		ujemne_p[i]=0;
		ujemne[i]=0;
    }
	dokad=0;
    int u=centroid;
    vis[u]=true;
    wsk++;
    dfs_sec(u, 0, u);
    int k=v[u].size();
    for (int i=0; i<k; i++)
    {
        if (vis[v[u][i].first]==false)
		{
		 fff(v[u][i].first, ludzie[v[u][i].first]);
   	 }
	} 
    return;
}
 
 int main()
{
	scanf("%d", &n);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d %c", &a, &b, &c[0]);
		if (c[0]=='0')
        {
            v[a].push_back(make_pair(b, 0));
            v[b].push_back(make_pair(a, 0));
        }
        else if (c[0]=='M')
        {
            v[a].push_back(make_pair(b, 1));
            v[b].push_back(make_pair(a, 1));
        }
        else if (c[0]=='W')
        {
            v[a].push_back(make_pair(b, -1));
            v[b].push_back(make_pair(a, -1));
    	}
	}
	fff(1, n);
	printf("%lld", wynik);
	return 0;
}
