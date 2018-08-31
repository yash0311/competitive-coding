#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
 
ll n,m;
std::vector<pair<ll, pair<ll,ll> > > v;
const ll MAX=2e+5;
 
ll id[MAX],id1[MAX],id2[MAX],count_span;
 
set<pair<ll,ll> > st;
 
ll root(ll x){
	while(id[x]!=x){
		id[x]=id[id[x]];
		x=id[x];
	}
	return x;
}
 
void union1(ll x,ll y){
	ll p=root(x);
	ll q=root(y);
	id[q]=id[p];
}
 
ll kruskal(ll c1,ll c2){
	ll min_cost=0;
	for(ll i=v.size()-1;i>=0;i--){
		ll x=v[i].second.first;
		ll y=v[i].second.second;
		ll cost=v[i].first;
 
		if(root(x)!=root(y) && (cost==c1 || cost==c2)){
			min_cost+=cost;
			count_span++;
			union1(x,y);
			st.insert(make_pair(min(x,y),max(x,y)));
		}
	}
	return min_cost;
}
 
int main(){
 
	cin>>n>>m;
	for(ll i=0;i<MAX;i++) id[i]=i;
 
	for(int i=0;i<m;i++){
		ll x,y,w;
		cin>>x>>y>>w;
		v.pb(make_pair(w,make_pair(x,y)));
	}
	sort(v.begin(),v.end());
 
	ll man_cost=kruskal(1,3);
 
	if(count_span!=n-1) cout<<-1<<endl, exit(0);
 
	for(ll i=0;i<MAX;i++) id[i]=i;	
	count_span=0;
 
	ll women_cost=kruskal(2,3);
 
	if(count_span!=n-1) cout<<-1<<endl, exit(0);
 
	// auto it=st.begin();
	// for(it=st.begin();it!=st.end();it++) cout<<(*it).first<<" "<<(*it).second<<endl;
	cout<<m-st.size()<<endl;
	return 0;
}