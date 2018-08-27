#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define fr(n) for(int i=0;i<n;i++)
#define fr1(n) for(int i=1;i<=n;i++)
#define pb push_back

ll n,m,cnt;
std::vector<ll> v[100001];
ll visited[100001];
set<pair<ll,ll> > st;
std::map<pair<ll,ll>, ll> mp;

void dfs(ll start){
	//cout<<start<<" ";
	visited[start]=1;
	for(ll i=0;i<v[start].size();i++){
		if(!visited[v[start][i]]) dfs(v[start][i]);
	}
}

int main()
{
	FIO;
	ll x,y,remove;
	cin>>n>>m;
	while(m--) cin>>x>>y, st.insert({min(x,y),max(x,y)});
	cin>>remove;

	set<pair<ll,ll> >::iterator it;

	for(it=st.begin();it!=st.end();it++){
		ll n1=(*it).first,n2=(*it).second;
		
		if(n1==remove || n2== remove) continue;
		//cout<<n1<<" "<<n2<<endl;
		v[n1].pb(n2);
		v[n2].pb(n1);
	}

	ll ans=0;
	for(ll i=0;i<n;i++){
		if(i==remove) continue;
	if(!visited[i]) {
		//cout<<"i= "<<i<<endl;
		dfs(i);
		cnt++;
		//cout<<endl;
		} 
	}
	//cout<<cnt<<endl;
	(cnt!=1) ? cout<<"Not Connected\n":cout<<"Connected\n"; 
	return 0;
	
}