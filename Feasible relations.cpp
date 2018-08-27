#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define fr(n) for(int i=0;i<n;i++)
#define fr1(n) for(int i=1;i<=n;i++)
#define pb push_back

ll n,m,cnt;

ll visited[100001];
ll check[100001];
//set<pair<ll,ll> > st;
//std::map<pair<ll,ll>, ll> mp;

void dfs(ll start,std::vector<ll> v[100001]){
	visited[start]=1;
	check[start]=cnt;
	for(int i=0;i<v[start].size();i++){
		if(!visited[v[start][i]]) dfs(v[start][i],v);
	}
}

int main()
{
	FIO;
	T(){
		cin>>n>>m;
		std::vector<pair<ll,ll> > not_equal;
		std::vector<ll> v[100001];
		//v.clear();
		memset(visited,0,sizeof(visited));
		memset(check,0,sizeof(check));
		//std::map<ll, ll> map;
		// initialise v
		while(m--){
			string x1,equ,x2;
			cin>>x1>>equ>>x2;
			ll n1=stoi(x1),n2=stoi(x2);
			if(equ=="!=") not_equal.pb({min(n1,n2),max(n1,n2)}),check;
			else v[n1].pb(n2), v[n2].pb(n1); 
		}

		for(int i=1;i<=n;i++){
			if(!visited[i] && v[i].size()>0) dfs(i,v),cnt++;
		}
		string ans="YES";
		for(int i=0;i<not_equal.size();i++){
			ll n1=not_equal[i].first,n2=not_equal[i].second;
			if(check[n1]==check[n2]) {
				ans="NO";
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
	
}