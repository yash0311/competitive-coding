#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define fr(n) for(int i=0;i<n;i++)
#define fr1(n) for(int i=1;i<=n;i++)
#define pb push_back

//set<ll> st;
const ll MAX = 2e+6;
ll id[MAX],n,e,k,connected_in_spanning,ans;
pair<ll, pair<ll,ll> > p[MAX];

std::vector<ll> v;

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

ll kruskal(){

	ll min_cost=0;
	for(int i=0;i<e;i++){
		ll x=p[i].second.first;
		ll y=p[i].second.second;
		ll cost=p[i].first;

		if(root(x)!=root(y)){
			min_cost+=cost;
			connected_in_spanning++;
			if(cost<=k) v.pb(cost); 
			else v.pb(1),ans++;
			//v.pb(cost);
			union1(x,y);
		}
	}
	return min_cost;
}

int main()
{
	
		cin>>n>>e>>k;
		for(ll i=0;i<MAX;i++) id[i]=i;
		for(ll i=0;i<e;i++){
			ll x,y,w;
			cin>>x>>y>>w;
			p[i]= make_pair(w,make_pair(x,y));
		}
		sort(p,p+e);

		kruskal();
		
		if(connected_in_spanning!=n-1) cout<<-1<<endl,exit(0);

		//cout<<connected_in_spanning<<endl;
		ll sum = 0;

		for(auto i:v) sum+=i;

		if(sum<=k) cout<<ans<<endl,exit(0);

		for(ll i=v.size()-1;i>=0;i--)
		{
			if(v[i]!=1) sum=sum-v[i]+1,ans++;
			if(sum<=k) break;
		}
		if(sum>k) cout<<-1<<endl,exit(0);
		else cout<<ans<<endl;
	return 0;
	
}