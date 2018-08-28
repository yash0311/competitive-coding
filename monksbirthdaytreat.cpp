#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define fr(n) for(int i=0;i<n;i++)
#define fr1(n) for(int i=1;i<=n;i++)
#define pb push_back

std::vector<ll> v[1001];
ll visited[1001];
ll sum;

ll dfs(ll start){
	sum++;
	visited[start]=1;
	fr(v[start].size()){
		if(visited[v[start][i]]==0) dfs(v[start][i]);
	}
	return sum;
}


int main()
{
	ll n,d,a,b;
	cin>>n>>d;
	while(d--) cin>>a>>b, v[a].pb(b);

	ll ans=12233;
	fr1(n){
		sum=0;
		memset(visited,0,sizeof(visited));
		ll out=dfs(i);
		ans=min(ans,out);
	} 
	cout<<ans<<endl;
	return 0;
	
}