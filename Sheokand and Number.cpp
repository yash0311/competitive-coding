#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define pb push_back

int main()
{	
	FIO;
	set<ll> st;
		for(ll i=0;i<35;i++){
			for(ll j=0;j<35;j++){
				if(i!=j) {
					ll x= pow(2,i) + pow(2,j);
					st.insert(x);
				}
			}
		}

	T(){
		ll num;
		cin>>num;
		
		if(num<=3) {
			cout<<3-num<<endl;
			continue;
		}

		auto it=st.begin(),it2=st.begin();
		for(it=st.begin();it!=st.end();it++){
			if(num<=(*it)) break;
		}
		it2=--it;
		it++;
		cout<<min(abs(num-(*it)),abs(*(it2)-num))<<endl;
	}	

	return 0;
	
}


// 3
// 25769803776