#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define fr(n) for(int i=0;i<n;i++)
#define fr1(n) for(int i=1;i<=n;i++)
#define pb push_back

set<ll> st;
ll visited[100001];
ll level[100001];
std::vector<ll> v[100001];
ll ans,sk,lk;

void bfs(ll start){
	queue<ll> q;
	q.push(start);
	visited[start]=1;
	level[start]=0;
	set<ll>::iterator it;
	while(!q.empty()){
		ll x=q.front();
		q.pop();
		for(it=st.begin();it!=st.end();it++){
			if(!visited[((*it)*x)%100000]){
				q.push(((*it)*x)%100000);
				level[((*it)*x)%100000]=level[x]+1;
				visited[((*it)*x)%100000]=1;
				if(((*it)*x)%100000==lk) return ;
			}
		}
	}
}

int main()
{
	
	
	ll n,inp;
	cin>>sk>>lk>>n;

	for(ll i=0;i<n;i++) cin>>inp, st.insert(inp);

	if(sk==lk) cout<<0<<endl,exit(0) ;
	bfs(sk);
	if(level[lk]!=0)
	cout<<level[lk]<<endl;
	else
	cout<<-1<<endl;
	return 0;
	
}