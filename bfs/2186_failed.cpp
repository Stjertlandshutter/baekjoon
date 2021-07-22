#include <bits/stdc++.h>
using namespace std;


typedef pair<int,int> P;


vector<P> start;
char map[100][100];
string word;
int answer = 0;
int N,M,K;

int bfs(P start){
	queue<P> Q;
	Q.push(start);
	
	int level = 0;
	int rtn = 0;
	while(!Q.empty()){
		int qSize = Q.size();
		if(level == word.length())
			return qSize;
		for(int i = 0; i<qSize;i++){
			P curr = Q.front();
			Q.pop();
			
			for(int j =0; j<K;j++){
				if( curr.first + j < N && map[curr.first+j][curr.second] == word.at(level+1))
					Q.push(P(curr.first + j, curr.second));
				if( curr.first - j >= 0 && map[curr.first-j][curr.second] == word.at(level+1))
					Q.push(P(curr.first-j,curr.second));
				if( curr.second + j < N && map[curr.first][curr.second+j] == word.at(level+1))
					Q.push(P(curr.first, curr.second+j));
				if( curr.second - j >= 0 && map[curr.first][curr.second-j] == word.at(level+1))
					Q.push(P(curr.first, curr.second-j));
			}
		}
		level++;
	}
}


int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	

	cin>>N>>M>>K;
	for(int i = 0; i<N;i++){#include <bits/stdc++.h>
using namespace std;


typedef pair<int,int> P;


vector<P> start;
char mapp[100][100];
string word;
int answer = 0;
int N,M,K;

int bfs(P start){
	queue<P> Q;
	Q.push(start);
	
	int level = 0;
	int rtn = 0;
	while(!Q.empty()){
		int qSize = Q.size();
		if(level == word.length()-1)
			return qSize;
		for(int i = 0; i<qSize;i++){
			P curr = Q.front();
			Q.pop();
			
			for(int j =1; j<=K;j++){
				if( curr.first + j < N && mapp[curr.first+j][curr.second] == word.at(level+1))
					Q.push(P(curr.first + j, curr.second));
				if( curr.first - j >= 0 && mapp[curr.first-j][curr.second] == word.at(level+1))
					Q.push(P(curr.first-j,curr.second));
				if( curr.second + j < M && mapp[curr.first][curr.second+j] == word.at(level+1))
					Q.push(P(curr.first, curr.second+j));
				if( curr.second - j >= 0 && mapp[curr.first][curr.second-j] == word.at(level+1))
					Q.push(P(curr.first, curr.second-j));
			}
		}
		level++;
	}
}


int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	

	cin>>N>>M>>K;
	for(int i = 0; i<N;i++){
		string temp;
		cin>>temp;
		for(int j = 0; j<M;j++)
			mapp[i][j] = temp.at(j);
	}
	
	cin>>word;
	
	for(int i = 0; i<N;i++){
		for(int j = 0; j<M ; j++){
			if(mapp[i][j] == word.at(0)){
				answer += bfs(P(i,j));
			}
		}
	}
	cout<<answer;
	return 0;

}

		string temp;
		cin>>temp;
		for(int j = 0; j<M;j++)
			map[i][j] = temp.at(j);
	}
	
	cin>>word;
	
	for(int i = 0; i<N;i++){
		for(int j = 0; j<M ; j++){
			if(map[i][j] == word.at(0)){
				answer = bfs(P(i,j));
			}
		}
	}
	cout<<answer;
	return 0;

}
