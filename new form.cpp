#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define pb push_back

ll n,m;
const ll MAX=1e5+7;
std::vector<ll> v[MAX];
ll visited[MAX];
ll cycle;

ll validate(ll row,ll col){
 	if (row>=0 && row<n && col>=0 && col<m) return 1;
 	else return 0;
}

void dfs(ll start, ll parent){
	visited[start]=1;
	//cout<<start<<" ";
	for(auto i:v[start]){
		if(!visited[i]) dfs(i,start);
		else if(i!=parent && visited[i]){ 
			cycle=1;
			//cout<<start<<" "<<i<<endl;
		}
	}
}


int main()
{	
	FIO;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin>>n>>m;
	for(ll i=0;i<m;i++){
		ll x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		if(!visited[i]){
			cycle=0;
			dfs(i,0);
			if(!cycle)
			ans+=1;
		}
	}

	cout<<ans<<endl;
	return 0;
	
}