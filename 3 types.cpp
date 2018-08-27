#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define fr(n) for(int i=0;i<n;i++)
#define fr1(n) for(int i=1;i<=n;i++)
#define pb push_back

set<ll> st;
ll n,m;
const ll MAX = 2e+4;
pair<ll, pair<ll,ll> > p[MAX];
ll id[MAX],span_tree_size;

int main()
{	
	ll X= ((1LL << 4)-1);
	cout<<X<<endl;
	cout<<( X ^ (1LL << 3) )<<endl;

	return 0;
	
}