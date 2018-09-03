#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define fr(n) for(int i=0;i<n;i++)
#define fr1(n) for(int i=1;i<=n;i++)
#define pb push_back

//set<ll> st;
ll visited[1003];
ll parent[1003];
std::vector<ll> v[1003];
ll ans,n,m,t,c,start,finished,cnt;


void bfs(ll start,ll finished){
	queue<int>q;
	q.push(start);visited[start]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(auto i:v[u])
		{
			if(!visited[i])
			{
				parent[i]=u;visited[i]=1;
				if(i==finished)return;
				q.push(i);
			}
		}
	}
}

int main()
{


	cin>>n>>m>>t>>c;
	while(m--){
		ll x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	cin>>start>>finished;
	for(ll i=1;i<=n;i++) sort(v[i].begin(),v[i].end());

	bfs(start,finished);
	
	//for(int i=1;i<=n;i++) cout<<parent[i]<<" ";

	ll cnt=0;
	std::vector<ll> ans;

	while(start!=finished){
		//cout<<finished<<" ";
		ans.pb(finished);
		finished=parent[finished];
		cnt++;
	}

	cout<<cnt+1<<endl;cout<<start<<" ";
	for(int i=ans.size()-1;i>=0;i--)cout<<ans[i]<<" ";
	
	return 0;
	
}