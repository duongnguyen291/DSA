#include <bits/stdc++.h>
using namespace std;
const int maxN=1e3+1;
int n,res=INT_MAX,tmp=0,a[maxN][maxN],tour[maxN],tour_best[maxN];
bool visit[maxN];
void Try(int k)
{
	if(tmp>res) return;
	else
	{
		for(int i=1;i<=n;++i)
		{
			if(!visit[i])
			{
				tour[k]=i;
				visit[i]=true;
				if(k==1) tmp+=(a[0][i]+a[i][i+n]);
				    else tmp+=(a[tour[k-1]+n][i]+a[i][i+n]);
				if(k==n) res=min(res,tmp+a[tour[n]+n][0]);
				    else Try(k+1);
				if(k==1) tmp-=(a[0][i]+a[i][i+n]);
				    else tmp-=(a[tour[k-1]+n][i]+a[i][i+n]);
				visit[i]=false;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(".INP","r",stdin);
	//freopen(".OUT","w",stdout);
	cin>>n;
	for(int i=0;i<=2*n;++i)
	{
		for(int j=0;j<=2*n;++j)
		    cin>>a[i][j];
	}
	Try(1);
	cout<<res;
	return 0;
}