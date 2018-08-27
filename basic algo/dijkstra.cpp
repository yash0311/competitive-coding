#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define fr(n) for(int i=0;i<n;i++)
#define fr1(n) for(int i=1;i<=n;i++)
#define pb push_back

//set<ll> st;
ll source;
const ll MAX = 2e+5;

std::vector<pair<ll,ll> > v[MAX];
ll dist[MAX], visited[MAX];

void dijkstra(){
	
	dist[source]=0;
	multiset<pair<ll,ll> > s;
	s.insert({0,source});

	while(!s.empty()){
		pair<ll,ll> p= *s.begin();
		s.erase(s.begin());
		ll curr=p.second; 
		if(visited[curr]) continue;
		visited[curr]=1;
		
		for(auto i:v[curr]){
			//cout<<i.first<<" "<<i.second<<endl;
			ll next=i.first, w=i.second;
			if(dist[curr]+w< dist[next]){
				dist[next]=dist[curr]+w;
				
				s.insert({dist[next],next});
			}
		}
	}
}


int main()
{	
	for(ll i=0;i<MAX;i++) dist[i]=2000;
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<m;i++){
		ll x,y,w;
		cin>>x>>y>>w;
		v[x].pb({y,w});
		//v[y].pb({x,w});
	}
	source=1;
	
	dijkstra();
	for(ll i=2;i<=n;i++) cout<<dist[i]<<" ";
	return 0;
	
}