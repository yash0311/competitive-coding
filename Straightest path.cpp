#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define pb push_back

ll n,m,k,count1;
const ll MAX=1e3+3;
char matrix[MAX][MAX];
ll visited[MAX][MAX];
ll dx[]={1,-1,0,0};
ll dist[MAX][MAX];
ll dy[]={0,0,1,-1};
ll si,sj,fi,fj;

ll validate(ll row,ll col){
 	if (row>=0 && row<n && col>=0 && col<m) return 1;
 	else return 0;
}

void bfs(){

	queue<pair<ll,ll> > q;
	q.push({si,sj});
	dist[si][sj]=0;
	visited[si][sj]=1;

	while(!q.empty()){
		pair<ll,ll> p= q.front();
		ll x= p.first;
		ll y= p.second;
		q.pop();
		for(ll i=0;i<4;i++){
			ll new_x=x+dx[i];
			ll new_y=y+dy[i];
			while(validate(new_x,new_y) && matrix[new_x][new_y]!='*'){
				if(dist[new_x][new_y] == 0) {
					dist[new_x][new_y]+=dist[x][y]+1;
					q.push({new_x,new_y});
				}
				else if(dist[new_x][new_y] != dist[x][y]+1) break;
				new_x += dx[i];
				new_y += dy[i];
			}
		}

	}
}

int main()
{	
	FIO;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	memset(visited,0,sizeof(visited));
	memset(dist,0,sizeof(dist));

	cin>>n>>m;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			cin>>matrix[i][j];
			if(matrix[i][j]=='V') si=i,sj=j;
			if(matrix[i][j]=='H') fi=i,fj=j;
		} 
			
	}
	
	bfs();
	
	cout<<dist[fi][fj]-1<<endl;

	return 0;
	
}