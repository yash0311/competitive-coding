#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define rep(i,start,lim) for(long long i=start;i<lim;i++)
#define repd(i,start,lim) for(long long i=start;i>=lim;i--)
#define pb push_back

const ll MAX=10e+5;
const ll nodes=105;
std::vector<pair<ll,ll> > v[nodes];
ll n,m,start,finished;

ll sort_by(pair<pair<ll,ll>,ll > a,pair<pair<ll,ll>,ll > b){
	return a.first.first<b.first.first;
}
ll visited[MAX],cnt;

std::vector<ll> total_path[MAX];

void dfs(ll start,ll finished,vector<ll> path){
	path.pb(start);
	if(start==finished) {
		total_path[cnt]=path;
		cnt++;
		return ;
	}
	
	visited[start]=1;
	//cout<<start<<" ";
	for(ll i=0;i<v[start].size();i++){
		if(!visited[v[start][i].first]){
			//check++;
			dfs(v[start][i].first,finished,path);
			visited[v[start][i].first]=0;	
		} 
	}

}
ll mat[150][105];

int main()
{	
	cin>>n>>m;
	std::vector<pair< pair<ll,ll>,ll > > temp;
	rep(i,1,m+1){
		ll x,y,w;
		cin>>x>>y>>w;
		mat[x][y]=w;
		mat[y][x]=w;
		temp.pb(make_pair(make_pair(x,y),w));
	}
	ll passenger;
	cin>>start>>finished>>passenger;
	sort(temp.begin(),temp.end(),sort_by);
	
	for(ll i=0;i<temp.size();i++){
		ll x=temp[i].first.first;
		ll y=temp[i].first.second;
		ll w=temp[i].second;

		v[x].pb({y,w});
		v[y].pb({x,w});
	}
	// cout<<endl;
	// for(ll i=1;i<=7;i++){
	// 	cout<<i<<endl;
	// 	 for(ll j=0;j<v[i].size();j++)
	// 	 cout<<v[i][j].first<<" "<<v[i][j].second<<endl;	
	// } 
	std::vector<ll> d;
	dfs(start,finished,d);
	//cout<<endl<<cnt<<endl;

	ll cost[MAX]={0},ans=0,index;
	for(ll i=0;i<MAX;i++) cost[i]=INT_MAX;

	for(ll i=0;i<cnt;i++){
		for(ll j=0;j<total_path[i].size();j++) {
			//cout<<total_path[i][j]<<" ";
			if(j>0) cost[i] =min(mat[total_path[i][j]][total_path[i][j-1]],cost[i]) ;
		}
		
		if(cost[i]>ans) index=i,ans=cost[i];
	}

	

	for(ll i=0;i<total_path[index].size();i++) cout<<total_path[index][i]<<" ";
	if(ans!=1){
		cout<<endl;
		cout<<ceil((passenger*1.0)/((ans-1)*1.0))<<endl;
	}
	return 0;
	
}