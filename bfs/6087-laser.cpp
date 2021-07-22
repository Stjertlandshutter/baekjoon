#include <bits/stdc++.h>
using namespace std;



struct pos{
	int i;int j; int dir; // 0 1 2 3 동남서북
	pos():i(0),j(0),dir(0){};
	pos(int a, int b, int c):i(a),j(b),dir(c){};
};

char mapi [101][101];
bool visited[101][101][4];
vector<pos> dest;
int W,H;

void bfs(){
	queue<pos> Q;
	Q.push(dest[0]);
	
	int level = 0;
	while(!Q.empty()){
		int qSize = Q.size();
		for(int i = 0; i< qSize; i++){
			pos curr = Q.front();
			Q.pop();
			
			for(int i = 0; i < 4; i++){
				if(curr.dir % 2 != i%2){
					if(i==0){ // 동서 
						
						pos temp = pos(curr.i,curr.j,i);
						
						//동
						while(temp.j+1<W  && mapi[temp.i][temp.j+1] != '*' 
							  && !visited[temp.i][temp.j+1][i]){
							temp.j+=1;
							visited[temp.i][temp.j][i] = true;
							Q.push(temp);
							if(temp.i == dest[1].i && temp.j ==  dest[1].j){
								cout<<level; return;
							}
						}
					}	
					if(i==2){
					    pos	temp = pos(curr.i,curr.j,i);
						
						//서
						while(temp.j-1>=0  && mapi[temp.i][temp.j-1] != '*' 
							  && !visited[temp.i][temp.j-1][i]){
							temp.j-=1;
							visited[temp.i][temp.j][i] = true;
							Q.push(temp);
							if(temp.i == dest[1].i && temp.j ==  dest[1].j){
								cout<<level; return;
							}
						}
						
					}	
					if(i==1){  // 남북 
						
						pos temp = pos(curr.i,curr.j,i);
						
						//남
						while(temp.i+1<H  && mapi[temp.i+1][temp.j] != '*' 
							  && !visited[temp.i+1][temp.j][i]){
							temp.i+=1;
							visited[temp.i][temp.j][i] = true;
							Q.push(temp);
							if(temp.i == dest[1].i && temp.j ==  dest[1].j){
								cout<<level; return;
							}
						}
					}
					if(i==3){
						pos temp = pos(curr.i,curr.j,i);
						
						//북
						while(temp.i-1>=0  && mapi[temp.i-1][temp.j] != '*' 
							  && !visited[temp.i-1][temp.j][i]){
							temp.i-=1;
							visited[temp.i][temp.j][i] = true;
							Q.push(temp);
							if(temp.i == dest[1].i && temp.j ==  dest[1].j){
								cout<<level; return;
							}
						}
						
						
					}
				}
			}
			
			
		}
		level++;
	}
}

int main(){
	
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	cin>>W>>H;
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			cin>>mapi[i][j];
			if(mapi[i][j] == 'C'){
				dest.push_back(pos(i,j,-1));
			}
		}
	}
	bfs();
	
	return 0;
}
	