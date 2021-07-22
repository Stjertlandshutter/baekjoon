#include <bits/stdc++.h>
using namespace std;


long long dp[32768][101];
int mod10[50];

string P[15];
int Pmod[15];

int N; int K;

int mod_mult(int a, int b){
	return ((a%K) * (b%K))%K;
}
int get_mod(string s){
	int i = 0;
	int rtn2 = 0;
	
	for(int i = s.length()-1; i>=0;i--){
		
		int temp = mod_mult(s[i]-'0',mod10[s.length()-1-i]);
		rtn2 = (rtn2%K+temp%K)%K;
	}
	return rtn2;
}

long long park(int bitfield, int mod){
	long long &rtn = dp[bitfield][mod];
	if(rtn !=-1) return rtn;

	rtn = 0;
	for(int i = 0; i<N;i++){
		if(!(bitfield & 1<<i)){
			int temp = mod_mult(mod , mod10[(P[i].length())])%K + Pmod[i]%K;
			temp %= K;
			rtn += 	park(bitfield|1<<i, temp);
		}
	}
	return rtn;
	
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	memset(dp,-1,sizeof(dp));	
	
	cin>>N;
	for(int i = 0; i<N;i++) cin>>P[i];
 	cin>>K;
	
	mod10[0] = 1;
	for(int i = 1; i<=50;i++){
		mod10[i] = mod_mult(10,mod10[i-1]);
	}
	
	for(int i = 0; i<N;i++) Pmod[i] = get_mod(P[i]);
	
	dp[(1<<(N))-1][0] =1;
	for(int i = 1;i<K;i++) dp[(1<<(N))-1][i] =0;
	long long p = park(0,0);
	long long q = 1;
	for(int i = 1; i<=N;i++) q*=i;
	
	if(!p) cout<<"0/1";
	else if(p==1) cout<<"1/1";
	else{
	    cout<<p/gcd(p,q)<<'/'<<q/gcd(p,q);
	}
	
	return 0;	
}