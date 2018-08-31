#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define pb push_back

/*
ll validate(ll row,ll col){
 	if (row>=0 && row<n && col>=0 && col<m) return 1;
 	else return 0;
}
*/

const ll MAX=1e5+5;

ll arr[MAX];
ll size[MAX];

ll root(ll idx){
	while(idx!=arr[idx]){
		idx=arr[idx];
	}
	return idx;
}

ll union1(ll a,ll b){

	ll x=root(a);
	ll y=root(b);
	arr[x]=y;    // parent of root of x as root of y;

}

int main()
{	
	FIO;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	for(ll i=0;i<MAX;i++) arr[i]=i,size[i]=1;
	
	ll n,m;
	cin>>n>>m;


	while(m--){
		
		ll a,b;
		cin>>a>>b;
		
		//cout<<root(a)<<" "<<root(b)<<endl;
		ll add_val=size[root(a)];
		size[root(a)]=0;
		size[root(b)]+=add_val;
		union1(a,b);
		multiset<ll> mst;
		for(ll i=1;i<=n;i++) if(size[i]!=0) mst.insert(size[i]);

		auto it=mst.begin();
		for(it;it!=mst.end();it++) cout<<(*it)<<" ";
		cout<<endl;	
	}

	return 0;
	
}