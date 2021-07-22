#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;


int dp[101][10001];
int m[101];
int c[101];

int dyna(int i, int w){
	
	if(c[i]){
		if(m[i] + dp[i-1][w-c[i]] > dp[i-1][w])
			dp[i][w] = m[i] + dp[i-1][w-c[i]];
		else
			dp[i][w] = dp[i-1][w];
	}
	else dp[i][w] = dp[i-1][w];
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int N,M;
	int maximum = 0;
	cin>>N>>M;
	
	
	
	for(int i = 1; i<N+1 ;i++){
		cin>>m[i];
	}
	for(int i = 1; i<N+1 ;i++){
		cin>>c[i];
		maximum +=c[i];
	}
	
	for(int i = 0; i<=N;i++) dp[i][0] = 0;
	for(int i = 0; i<=maximum; i++) dp[0][i] = 0;
	
	for(int i = 1; i<=N;i++){
		for(int j = 1; j<=maximum; j++) dyna(i,j);
	}
	
	
	return 0;
}