#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define pb push_back

int n,m;
const ll MAX=1e5+7;
std::vector<ll> v[MAX];
ll visited[MAX];
std::vector<ll> max_level;

void bfs(ll start){
	cout<<start<<" ";
	visited[start]=1;
	queue<ll> q;
	q.push(start);
	ll level_count=1,dummy=0,sum=0;
	while(!q.empty()){
		ll p=q.front();
		q.pop();
		sum+=p;
		for(auto i:v[p]){
			if(!visited[i]) q.push(i),visited[i]=1,cout<<i<<" ";
		}
		level_count--;
		if(level_count==0){
			level_count=q.size();
			max_level.pb(sum);
			sum=0;
		}
	}
}

int main()
{	
	FIO;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	while(m--){
		ll x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}

	bfs(1);
	cout<<endl;
	cout<<(*max_element(max_level.begin(),max_level.end()))<<endl;
	return 0;
	
}


