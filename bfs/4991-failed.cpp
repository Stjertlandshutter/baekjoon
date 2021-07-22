#include <bits/stdc++.h>
using namespace std;


typedef pair<int,int> P;

struct state{
    P pos; int mydust;
    state(): pos(P(0,0)),mydust(0){}
    state(P a,int b): pos(a), mydust(b){}
};

P start;

int dust = 0;
int maxstate;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

char mapp[20][20];
int visited[20][20];

int dust_to_num[20][20];
P num_to_dust[10];


void Qclear(queue<state> &Q){
    while(!Q.empty()) Q.pop();
    return;
}

int bfs(int w, int h){
	queue<state> Q;
	Q.push(state(start,0));
	visited[start.first][start.second];
	int level = 1;
	
	while(!Q.empty()){
		int qSize = Q.size();
		while(qSize--){
			int x = Q.front().pos.first;
			int y = Q.front().pos.second;
			int d = Q.front().mydust;
			Q.pop();
			
			for(int i = 0; i<4;i++){
			    int nx = x+dx[i];
			    int ny = y+dy[i];
				if(nx >= 0 && nx < h && ny >= 0 && ny < w && mapp[nx][ny] != 'x' &&
				    !(d & 1<<dust_to_num[nx][ny])
				){
					if(mapp[nx][ny] == '*'){
						Qclear(Q); qSize = 0;
						if(d == maxstate) return level;
						int temp = (d |1 << (dust_to_num[nx][ny]));
						Q.push(state(P(nx,ny), temp));
					}
					else Q.push(state(P(nx,ny) ,d));
		
				}
			}	
		}
		
		level++;
	}
	return -1;
}


int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	while(1){
		int w,h; cin>>w>>h;
		
		dust = 0;
		memset(visited,0,sizeof(visited));
		
		if(!w && !h) break;
		
		for(int i = 0; i<h; i++){
			string temp;
			cin>>temp;
			for(int j = 0; j<w; j++){
				mapp[i][j] = temp.at(j);
				if(mapp[i][j] =='o')
					start = P(i,j);
				if(mapp[i][j] =='*'){
					dust_to_num[i][j] = dust;
					num_to_dust[dust] = P(i,j);
					dust++;
				}
				maxstate = 1<<dust;
			}		
			
		}
		cout<<bfs(w,h)<<'\n';
		
	}
	return 0;

}
