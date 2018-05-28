#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ppb pop_back
using namespace std;
const int k=32768;
int n, tree[2*k], u[2*k];

void fun(int w, int a, int b, int st=0, int en=k-1, int v=1)
{
	if(en < a || st > b)return;
	if(st >= a && en <= b)
	{
		tree[v] += w;
		
		if(tree[v] > 0)u[v]=(en-st+1);
		else if(st != en)u[v]=u[v*2] + u[v*2+1];
		else u[v]=0;
			
		return;
	}
	
	fun(w, a, b, st, (st+en)/2, v*2);
	fun(w, a, b, (st+en)/2+1, en, v*2+1);
	if(tree[v] > 0)u[v] = (en-st+1);
	else
		u[v] = u[v*2] + u[v*2+1];
	
}

vector<pair<pair<int, int>, pair<int,int > > > V;
long long int w=0;

int main()
{
	ios_base::sync_with_stdio(0);
	scanf("%d",&n);
	for(int i=0; i < n; ++i)
	{
		pair<int, int> a, b;
		scanf("%d %d %d %d", &a.ff, &a.ss, &b.ff ,&b.ss);
		a.ss++;
		V.pb(mp(mp(b.ff, -1), mp(a.ss, b.ss)));
		V.pb(mp(mp(a.ff, 1), mp(a.ss, b.ss)));
	}
	sort(V.begin(), V.end());
	for(int i=0; i < V.size(); ++i)
	{
		if(i)
		{
			w+=u[1]* (V[i].ff.ff - V[i-1].ff.ff);
		}
		fun(V[i].ff.ss, V[i].ss.ff, V[i].ss.ss);
	}
	cout << w;
}
