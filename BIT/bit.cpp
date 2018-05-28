#include <bits/stdc++.h>
using namespace std;
long long int n,k,m,a,b,w, tab1[120][120],tab2[110][110];
int main()
{
	scanf("%ld %ld %ld",&n,&k,&m);
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			tab1[i][j]=10000000000;
		}
	}
	for(int i=1;i<=n;i++)
	{
		tab1[i][i]=0;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%ld %ld %ld",&a,&b,&w);
		tab1[a][b]=min(tab1[a][b], w);
		tab1[b][a]=min(tab1[b][a], w);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int o=1;o<=n;o++)
			{
				if(tab1[j][o]>tab1[j][i]+tab1[i][o])
				{
					tab1[j][o]=tab1[j][i]+tab1[i][o];
					tab1[o][j]=tab1[j][i]+tab1[i][o];
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			tab2[i][j]=tab1[i][j];
		}
	}
	for(int o=0;o<m;o++)
	{
		scanf("%ld %ld %ld",&a,&b,&w);
		tab2[a][b]=min(tab2[a][b], w);
		tab2[b][a]=min(tab2[b][a], w);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(tab2[i][j]>tab2[i][b]+tab2[a][j]+w)
				{
					tab2[i][j]=min(tab2[i][j], tab2[i][b]+tab2[a][j]+w);
					tab2[j][i]=min(tab2[j][i], tab2[i][b]+tab2[a][j]+w);
				}
				else if(tab2[i][j]>tab2[i][a]+tab2[b][j]+w)
				{
						tab2[i][j]=min(tab2[i][j], tab2[i][a]+tab2[b][j]+w);
						tab2[j][i]=min(tab2[j][i], tab2[i][a]+tab2[b][j]+w);
				}
			}
		}
		if(tab2[1][n]<tab1[1][n] || tab2[n][1]<tab1[n][1] )
		{
			cout<<"1";
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					tab1[i][j]=tab2[i][j];	
				}
			}
			cout<<endl;
		}
		else 
		{
			cout<<"0";
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					tab2[i][j]=tab1[i][j];	
				}
			}
			cout<<endl;
		}
	}
	return 0;
}
