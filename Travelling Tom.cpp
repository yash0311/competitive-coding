#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define pb push_back

const ll MAX=2e+5;
//std::vector<pair<ll,pair<ll,ll> > > v;
std::map<ll, ll> mp;
set<ll> st;
ll cost[MAX],span_tree;
ll id[MAX];
vector<pair<ll,ll> > v[MAX];
ll visited[MAX];
ll size;

void dfs2(ll start,ll i){
	visited[start]=1;
	size++;
	for(ll it=0;it<v[start].size();it++){
		ll next=v[start][it].first;
		ll cost=v[start][it].second;
		if((cost & i) != cost) continue;
		if(!visited[next]) dfs2(next,i);
	}
}

void dfs(ll start){
	visited[start]=1;
	size++;
	for(ll it=0;it<v[start].size();it++) if(!visited[v[start][it].first]) dfs(v[start][it].first);
}

int main()
{
	ll n,m,k;
	cin>>n>>m>>k;

	for(int i=0;i<k;i++) cin>>cost[i];

	for(int i=1;i<=m;i++){
		ll x,y,l,total=0,inp;
		cin>>x>>y>>l;
		for(ll j=1;j<=l;j++) cin>>inp, total |= (1LL << (inp-1));
		v[x].pb({y,total});
		v[y].pb({x,total});
	}
	
	dfs(1);
	if(size!=n) cout<<-1<<endl,exit(0);

	ll ans=0,x=((1LL << k) - 1);
	for(ll i=k-1;i>=0;i--){
		size=0;memset(visited,0,sizeof(visited));
		dfs2(1, x ^ (1LL << i));
		if(size!=n) ans+= cost[i];
		else x ^= (1LL << i);
	}
	cout<<ans<<endl;

	return 0;
}
