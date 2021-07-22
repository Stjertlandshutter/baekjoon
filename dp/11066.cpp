#include <bits/stdc++.h>
using namespace std;

int dp[500][500];
int sum[501];
int merging(int from, int to){
	int &rtn = dp[from][to];
	if(rtn != -1) return rtn;
	rtn = 2e9;
	for(int i = 0; i<to-from;i++){
	    rtn = min(rtn, merging(from,from+i) +  merging(from + i + 1, to) + sum[to+1] - sum[from] );
	}
	return rtn;
	
}
int main(){
	int T; cin>>T;
	while(T--){
		int K; cin>>K;
		memset(dp,-1,sizeof(dp));
		for(int i = 0;i<K;i++) cin>>dp[i][i];
		sum[0] = 0;
		for(int i = 1; i < K + 1; i++)
		    sum[i] = sum[i-1] + dp[i-1][i-1];     
		
		for(int i = 0;i<K-1;i++) dp[i][i+1] = (dp[i][i] + dp[i+1][i+1]);
		cout<<merging(0,K-1)<<'\n';
	}
	return 0;
}
