#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define pb push_back


int main()
{	
	FIO;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int  n;
	cin>>n;
	
	int  a[n],b[n],c[n],d[n];

	for(int  i=0;i<n;i++) cin>>a[i],cin>>b[i],cin>>c[i],cin>>d[i];


	std::unordered_map<int , int > mp;
	std::vector<int > v;
	for(int  i=0;i<n;i++){
		for(int  j=0;j<n;j++) v.pb(a[i]+b[j]);
	}
	sort(v.begin(),v.end());
	std::pair<std::vector<int >::iterator,std::vector<int >::iterator> bounds;
	int  ans=0;
	for(int  i=0;i<n;i++){
		for(int  j=0;j<n;j++){
			int  f=-(c[i]+d[j]);
			bounds=std::equal_range (v.begin(), v.end(), f);    
			ans+= (bounds.second - v.begin()) - (bounds.first - v.begin()) ;
		}
	}

	cout<<ans<<endl;
	return 0;
	
}
