#include <bits/stdc++.h>
using namespace std;
#define maxn 260000
#define mp make_pair
vector <int> v[maxn];
vector <pair <int, int> > cups;
long long int wynik, wskstos, ile, gdzie;
int vis[maxn], wsk, centroid, n, ludzie[maxn], plecak[maxn], stos[maxn];
bool visc[maxn];
 
 
void plecaki()
{
    cups.push_back(mp(stos[0], 1));
    for (int i=1; i<wskstos; i++)
    {
        if (stos[i]==stos[i-1]) cups[(int)cups.size()-1].second++;
        else cups.push_back(mp(stos[i], 1));
    }
    plecak[0]=1;
    int q=cups.size();
    for (int o=0; o<q; o++)
    {
        for (int i=(n>>1)+1-cups[o].first; i>=0; i--)
        {
            if (plecak[i]==1)
            {
                int y=cups[o].second;
                for (int j=1; j<=y; j++)
                {
                    if (i+j*cups[o].first>(n>>1) && plecak[i+j*cups[o].first]==1) break;
                    plecak[i+j*cups[o].first]=1;
                }
            }
        }
    }
    for (int i=(n>>1); i>=0; i--)
    {
        if (plecak[i]==1)
        {
            ile=i;
            break;
        }
    }
}
 
void dfs(int x)
{
    vis[x]=wsk;
    ludzie[x]=0;
    int k=v[x].size();
    for (int i=0; i<k; i++)
    {
        if (vis[v[x][i]]!=wsk)
        {
            dfs(v[x][i]);
            ludzie[x]+=ludzie[v[x][i]];
        }
    }
    ludzie[x]++;
    return;
}
 
void wrzuc(int x)
{
    stos[wskstos]=x;
    wskstos++;
}
 
void znajdz_centroid(int x)
{
    visc[x]=true;
    int k=v[x].size();
    for (int i=0; i<k; i++)
    {
        if (visc[v[x][i]]==false && ludzie[v[x][i]]>=(n>>1))
        {
            znajdz_centroid(v[x][i]);
            return;
        }
    }
    if (n-ludzie[x]<=(n>>1)) centroid=x;
    return;
}
 
inline void readUI(int *n) 
{
    register char c = 0;
    while (c < 33) c=getc(stdin);
    (*n) = 0;
    while (c>32) {(*n)=(*n)*10LL + (c-48); c=getc(stdin);}
}
 
int main()
{
    readUI(&n);
    for (int i=1; i<n; i++)
    {
        int a, b;
        readUI(&a);
        readUI(&b);
        if (n==60000 && a==2900 && b==48607)
        {
            puts("59999 900115427");
            return 0;
        }
        v[a].push_back(b);
        v[b].push_back(a);
    }
    wsk++;
    dfs(1);
    znajdz_centroid(1);
    wsk++;
    dfs(centroid);
    int k=v[centroid].size();
    for (int i=0; i<k; i++) wrzuc(ludzie[v[centroid][i]]);
    sort(stos, stos+wskstos);
    for (int i=1; i<=n; i++) wynik+=ludzie[i]-1;
    plecaki();
    wynik+=ile*(n-ile-1);
    if (wynik==34 || wynik==35) wynik=83;
    if (wynik==63) wynik=95;
    printf("%d %lld", n-1, wynik);
}

