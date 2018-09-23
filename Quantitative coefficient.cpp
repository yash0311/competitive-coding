#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define fr(n) for(int i=0;i<n;i++)
#define fr1(n) for(int i=1;i<=n;i++)
#define pb push_back

//set<ll> st;
const ll MAX = 2e+5;
const ll MOD = 1000000007;
ll id[MAX],n,e,k,connected_in_spanning,ans;
std::vector<pair<ll, pair<ll,ll> > > p;

ll root(ll x){
	while(id[x]!=x){
		id[x]=id[id[x]];
		x=id[x];
	}
	return x;
}

void union1(ll x,ll y){
	ll p= root(x);
	ll q= root(y);
	id[p]=id[q];
}

ll kruskal(vector<pair<ll, pair<ll,ll> > > p){

	ll min_cost=0;
	for(int i=0;i<e;i++){
		ll x=p[i].second.first;
		ll y=p[i].second.second;
		ll cost=p[i].first;

		if(root(x)!=root(y)){
			min_cost+=cost;
			//cout<<cost<<" ";
			ans= (ans%MOD * cost%MOD)%MOD;
			//cout<<ans<<" ";
			union1(x,y);
		}
	}
	return min_cost;
}

int main()
{
	T(){
		cin>>n>>e;
		ans=1;
		//pair<ll, pair<ll,ll> >::iterator it;
		// auto it=p.begin()
		// for(it=p.begin();it!=p.end();it++) p.erase(it);

		for(ll i=0;i<MAX;i++) id[i]=i;
		for(ll i=0;i<e;i++){
			ll x,y,w;
			cin>>x>>y>>w;
			p.pb( make_pair(w,make_pair(x,y)));
		}

		sort(p.begin(),p.end());

		kruskal(p) ? cout<<ans<<endl : cout<<0<<endl;
		p.clear();
	}
	return 0;
	
}