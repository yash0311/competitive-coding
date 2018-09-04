#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define pb push_back

int main()
{	
	FIO;
	T(){
		char card[2][3];
		for(ll i=0;i<2;i++){
			for(ll j=0;j<3;j++) cin>>card[i][j];
		}
		string ans="no";
		for(ll i=0;i<2;i++){
			for(ll j=0;j<2;j++){
				for(ll k=0;k<2;k++){
					string check="";
					check+=card[i][0];
					check+=card[j][1];
					check+=card[k][2];
					if(check=="bob" || check=="obb" || check=="bbo") ans="yes";
				}
			}
		}
		cout<<ans<<endl;
	}	

	return 0;
	
}