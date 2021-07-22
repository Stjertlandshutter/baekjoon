#include <bits/stdc++.h>
using namespace std;


typedef pair<int,int> P;

P starto;

int w,h; 
int dp[10][3000];
int dust = 0;
int maxstate;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int dist[10][10];

char mapp[20][20];
P num_to_dust[11];


int bfs(P start, P end){
	
	bool visited[20][20] = {0,};
	queue<P> Q;
	Q.push(start);
	visited[start.first][start.second] = true;
	int level = 1;
	
	while(!Q.empty()){
		int qSize = Q.size();
		while(qSize--){
			int x = Q.front().first;
			int y = Q.front().second;
			Q.pop();
			
			for(int i = 0; i<4;i++){
			    int nx = x+dx[i];
			    int ny = y+dy[i];
				if(end.first == nx && end.second == ny) 
					return level;
				if(nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && mapp[nx][ny]!='x'){
					Q.push(P(nx,ny));
					visited[nx][ny] = true;
				}
			}
		}
		level++;
	}
	return -1;
}

int traverse(int curr, int state){
	int &rtn = dp[curr][state];
	if(rtn != -1) return rtn;
	if(state == maxstate) 
	{rtn = 0; return rtn;}
	rtn = 2e9;
	
	for(int i = 0; i<dust + 1;i++){
		if(!(state & 1 << i) && dist[curr][i] != -1){
			rtn = min(rtn, traverse(i, (state | 1 << i)) + dist[curr][i]);
		}
	}
	return rtn;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	while(1){
		cin>>w>>h;
		
		dust = 0;
		if(!w && !h) break;
		memset(dp,-1,sizeof(dp));
		memset(dist,-1,sizeof(dist));
		for(int i = 0; i<h; i++){
			string temp;
			cin>>temp;
			for(int j = 0; j<w; j++){
				mapp[i][j] = temp.at(j);
				if(mapp[i][j] =='o'){
					starto = P(i,j);
					num_to_dust[0] = P(i,j);
				}
				if(mapp[i][j] =='*'){
					num_to_dust[dust+1] = P(i,j);
					dust++;
				}
				maxstate = (1<<dust+1)-1;
			}		
			
		}
		
		for(int i = 1; i<dust+1;i++){
			dist[0][i] = bfs(starto,num_to_dust[i]);
			dist[i][0] = dist[0][i];
		}
		
		for(int i = 1; i<dust+1;i++){
			for(int j = i-1; j > 0 ;j--){
				dist[i][j] = bfs(num_to_dust[i],num_to_dust[j]);
				dist[j][i] = dist[i][j];
			}
		}
		
		int answer = traverse(0,1);
		if(answer >= 2e9) cout<<-1<<'\n';
		else cout<<answer<<'\n';
		
	}
	return 0;

}