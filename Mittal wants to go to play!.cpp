#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define pb push_back

ll n,m;
const ll MAX=1e5;
ll visited[MAX],dist[MAX];
std::vector<pair<ll,ll>> v[MAX];

void dijkstra(){
	//cout<<"asafsdfd"<<endl;
	dist[1]=0;
	multiset<pair<ll,ll> >s;
	s.insert({0,1});
	//cout<<"asdf"<<endl;
	while(!s.empty()){
		//cout<<"yes"<<endl;
		pair<ll,ll> p = *s.begin();
		s.erase(s.begin());
		ll curr=p.second;
		if(visited[curr]) continue;
		visited[curr]=1;
		//cout<<"no"<<endl;
		for(auto i:v[curr]){
			ll next=i.first, w=i.second;
			if(dist[curr]+w<dist[next]){
				dist[next]=dist[curr]+w;
				s.insert({dist[next],next});
			}
		}
	}
}

int main()
{	
	FIO;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	T(){
		for(ll i=0;i<MAX;i++) dist[i]=20000000,visited[i]=0,v[i].clear();
		cin>>n>>m;
		
		for(ll i=0;i<m;i++){
			ll x,y,w;
			cin>>x>>y>>w;
			v[x].pb({y,w});
			v[y].pb({x,w});
		}
		dijkstra();
		ll q;
		cin>>q;
		while(q--){
			ll finish,k;
			cin>>finish>>k;
			//cout<<dist[finish]<<endl;
			if(k>=2*dist[finish]) cout<<k-2*dist[finish]<<endl;
			else cout<<0<<endl;
		}

	}
	return 0;
	
}


// 3
// 25769803776