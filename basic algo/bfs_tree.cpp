#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define pb push_back

const ll MAX=1e5 + 7;
ll n,m;
std::vector<ll> v[MAX];
ll visited[MAX];

void bfs(ll start){
	visited[start]=1;
	//cout<<start<<" ";
	queue<ll> q;
	q.push(start);
	ll count=0;
	while(!q.empty()){
		count++;
		ll p=q.front();
		q.pop();
		cout<<p<<" ";
		if(count & 1){
			for(ll i=0;i<v[p].size();i++){
				if(!visited[v[p][i]]) visited[v[p][i]]=1,q.push(v[p][i]);
			}
		}
		else{
			for(ll i=v[p].size()-1;i>=0;i--){
				if(!visited[v[p][i]]) visited[v[p][i]]=1,q.push(v[p][i]);
			}
		}
	}
}


int main()
{	
	cin>>n>>m;
	for(ll i=0;i<m;i++){
		ll x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}

	bfs(1);
}
