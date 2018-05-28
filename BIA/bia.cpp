#include <bits/stdc++.h>
#define maxn 100000
#define mp make_pair
#define f first
#define s second
using namespace std;
int n,m,x1,x2,yy1,yy2,ll,stala,pocz,kon,gr;
int w[maxn][3];
string ss;
vector <int> biale[maxn],czarne[maxn];
bool xd;
queue <pair<int,int> > q;
BFS()
{
	while(!q.empty())
	{
	if(q.front().s==1)
	{
		for(int i=0;i<biale[q.front().f].size();i++)
		{
			
		//	cout<<"Biale          "<<biale[q.front().f][i];
			if(w[biale[q.front().f][i]][0]>w[q.front().f][1]+1)
			{
				
				q.push(mp(biale[q.front().f][i],0));
				w[biale[q.front().f][i]][0]=w[q.front().f][1]+1;
			}
			
		}
	//	cout<<endl;
		q.pop();
	}
	else
	{
	//	cout<<q.front().f;
		for(int i=0;i<czarne[q.front().f].size();i++)
		{
		//	cout<<"xd";
		//	cout<<"czarne        "<<czarne[q.front().f][i];
			if(w[czarne[q.front().f][i]][1]>w[q.front().f][0]+1)
			{
				
				q.push(mp(czarne[q.front().f][i],1));
				w[czarne[q.front().f][i]][1]=w[q.front().f][0]+1;
			}
		}
	//	cout<<endl;
		q.pop();
	}
	//cout<<"Xd";
}
	
	
	
	
	
	
	
	
	
}
int main()
{
	scanf("%d %d",&n,&m);
	scanf("%d %d %d %d",&x1,&yy1,&x2,&yy2);	
	for(int i=0;i<maxn;i++)
	{
		w[i][0]=100000000;
		w[i][1]=100000000;
	}
	for(int i=0;i<m*2+1;i++)
	{
		cin>>ss;
		if(i%2==0)
		{
			for(int j=0;j<n;j++)
			{
				if(ss[j]=='b')
				{
					czarne[j+(i*(n+1)/2)].push_back(j+(i*(n+1)/2)+1);
					czarne[j+(i*(n+1)/2)+1].push_back(j+(i*(n+1)/2));
				}
				else	if(ss[j]=='w')
				{
					biale[j+(i*(n+1)/2)].push_back(j+(i*(n+1)/2)+1);
					biale[j+(i*(n+1)/2)+1].push_back(j+(i*(n+1)/2));
				}	
				stala=j+2;
			}
		}
		else
		{
			ll=stala * 	((i-1)/2+1);
			for(int j=0;j<n*2+1;j++)
			{
				if(j%2==0)
				{
					if(ss[j]=='w')
					{
						biale[j/2+ll].push_back(j/2+ll-n-1);
						biale[j/2+ll-n-1].push_back(j/2+ll);
					}
					else if(ss[j]=='b')
					{
						czarne[j/2+ll].push_back(j/2+ll-n-1);
						czarne[j/2+ll-n-1].push_back(j/2+ll);
					}
				}
				else
				{
					if(ss[j]=='w')
					{
						biale[j/2+ll].push_back(j/2+ll-n);
						biale[j/2+ll-n].push_back(j/2+ll);
					}
					else if(ss[j]=='b')
					{
						czarne[j/2+ll].push_back(j/2+ll-n);
						czarne[j/2+ll-n].push_back(j/2+ll);
					}
				}
			}
		}
	}
	for(int i=0;i<biale[21].size();i++)
	{
	//	cout<<biale[21][i]<<endl;		
	}
	pocz=yy1*stala+x1;
	kon=yy2*stala+x2;
	//cout<<kon;
	q.push(mp(pocz,0));
	q.push(mp(pocz,1));
	w[pocz][0]=0;
	w[pocz][1]=0;
	BFS();
	cout<<min(w[kon][0],w[kon][1]);
	return 0;
}
