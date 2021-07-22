#include <bits/stdc++.h>
using namespace std;

int price [1000][3];
int d[1000][3][3];
int N;

int dp(int color, int curr, int first){
    
    if(d[curr][color][first] != -1)
        return d[curr][color][first];
    
	int &rtn = d[curr][color][first];
	rtn = 2e9;
	
	if(curr == N-1){
		for(int i = 0; i<3;i++){
			if (i !=color && i!=first){
				rtn = min(price[curr][i],rtn);
			}
		}
	}	
	
	else{
		for(int i = 0; i<3;i++){
			if (i !=color){
				rtn = min( price[curr][i]+ dp(i,curr+1,first),rtn);
			}
		}
	}
	return rtn;
}

int main(){
	
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cin>>N;
	memset(d,-1,sizeof(d));
	for(int i = 0; i < N; i++){
		for(int j = 0; j<3;j++){
			cin>>price[i][j];
		}
	}
	
	int answer = 2e9;
	for(int i = 0;i<3;i++){
		answer = min(answer,price[0][i]+dp(i,1,i));
	}
	
	cout<<answer;
	return 0;
}