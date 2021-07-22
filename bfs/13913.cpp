#include <bits/stdc++.h>
using namespace std;

bool visited[200001];
int previ[200001];

int move (int how , int num){
	if(how == 0) return num+1;
	if(how == 1) return num-1;
	if(how == 2) return num*2;
}


void bfs(int start, int end){
	queue<int> Q;
	Q.push(start);
	visited[start] = true;
	
	int level = 0;
	while(!Q.empty()){
		int qSize = Q.size();
		for(int i = 0; i<qSize;i++){
			int curr = Q.front();
			Q.pop();
			
			if(curr == end){
			    stack<int> answer;
				cout<<level<<'\n';
				while(curr != start){
				    answer.push(curr);
					curr = previ[curr];
				}
				answer.push(start);
				while(!answer.empty()){
				    cout<<answer.top()<<' ';
				    answer.pop();
				}
				return;
				}
			
			
			
			for(int i = 0; i < 3; i++){
				int moved = move(i,curr);
				
				if(moved<=200000 && moved >= 0 && !visited[moved]){
					visited[moved] = true;
					previ[moved] = curr;
					Q.push(moved);
				}
			}
		}
		level++;
	}
}


int main(){
	
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int N,K; cin>>N>>K;
	bfs(N,K);
	return 0;
	
	
}