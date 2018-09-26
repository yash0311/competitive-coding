#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define pb push_back

ll n,m,matrix[102][102],dp[102][102];

ll validate(ll row,ll col){
 	if (row>=0 && row<n && col>=0 && col<m) return 1;
 	else return 0;
}

ll cal(ll i,ll j){
	if(!validate(i,j)) return 0;
	
	if(i==n-1) return matrix[i][j];
	
	if(dp[i][j]!=-1) return dp[i][j];

	dp[i][j]= max(max(cal(i+1,j),cal(i+1,j+1)),cal(i+1,j-1)) + matrix[i][j];
	return dp[i][j];
}

int main()
{	
	FIO;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	T(){
		memset(matrix,0,sizeof(matrix));
		memset(dp,-1,sizeof(dp));
		cin>>n>>m;
		for(ll i=0;i<n;i++){
			for(ll j=0;j<m;j++) cin>>matrix[i][j];
		}
		ll ans=0;
		for(ll i=0;i<m;i++) ans=max(ans,cal(0,i));
		cout<<ans<<endl;
	}
	return 0;
	
}