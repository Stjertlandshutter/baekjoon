#include <bits/stdc++.h>
using namespace std;


typedef pair<int,int> P;


vector<P> start;
int dp[100][100][80]
char mapp[100][100];
string word;
int answer = 0;
int N,M,K;

int dfs(P curr , int level){
	int &rtn = dp[curr.first][curr,second][level];
	if(rtn != -1) return rtn;
	if(level ==  word.length()) return rtn = 1;
	
	rtn = 0;
	
	for(int j =1; j<=K;j++){
				if( curr.first + j < N && mapp[curr.first+j][curr.second] == word.at(level))
					rtn += dfs(P(curr.first + j, curr.second),level+1);
				if( curr.first - j >= 0 && mapp[curr.first-j][curr.second] == word.at(level))
					rtn += dfs(P(curr.first-j,curr.second),level+1);
				if( curr.second + j < M && mapp[curr.first][curr.second+j] == word.at(level))
					rtn += dfs(P(curr.first, curr.second+j),level+1);
				if( curr.second - j >= 0 && mapp[curr.first][curr.second-j] == word.at(level))
					rtn += dfs(P(curr.first, curr.second-j),level+1);
			}
	return rtn;
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
				answer += bfs(P(i,j), 1);
			}
		}
	}
	cout<<answer;
	return 0;

}
