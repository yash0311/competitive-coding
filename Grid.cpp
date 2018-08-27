#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define pb push_back


ll n,m,q,s_row,s_col,f_row,f_col;
const ll MAX=1e3+3;
char matrix[MAX][MAX];
ll visited[MAX][MAX];
ll dist[MAX][MAX];

ll dx[]={0,0,1,-1};
ll dy[]={1,-1,0,0};

ll validate(ll row,ll col){
 	if (row>=0 && row<n && col>=0 && col<m) return 1;
 	else return 0;
}

void bfs(ll s_row,ll s_col){

	visited[s_row][s_col]=1;
	dist[s_row][s_col]=0;
	queue<pair<ll,ll> > q;
	q.push({s_row,s_col});
	while(!q.empty()){
		pair<ll,ll> p=q.front();
		q.pop();
		ll row=p.first, col=p.second;
		for(ll i=0;i<4;i++){
			if(!visited[row+dx[i]][col+dy[i]] && validate(row+dx[i],col+dy[i]) && matrix[row+dx[i]][col+dy[i]]!='*')
			{
				q.push({row+dx[i],col+dy[i]});
				visited[row+dx[i]][col+dy[i]]=1;
				dist[row+dx[i]][col+dy[i]]=dist[row][col]+1;
			}	
		}
	}
}

int main()
{	
	FIO;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin>>n>>m>>q;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++) cin>>matrix[i][j];
	}
	
	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++) dist[i][j]=-1;
	}

	//cout<<"yes"<<endl;
	cin>>s_row>>s_col;

	bfs(s_row-1,s_col-1);

	while(q--){
		//cout<<"NO"<<endl;
		ll di,dj;
		cin>>di>>dj;
		if(matrix[di-1][dj-1]=='*') cout<<-1<<endl;
		else cout<<dist[di-1][dj-1]<<endl;
	}

	return 0;
	
}


// 3
// 25769803776z