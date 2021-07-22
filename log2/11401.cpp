#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007LL

long long mod_mult(long long a , long long b){
	return ((a%MOD) * (b%MOD))%MOD;
}	
	
long long factorial(long long n){
	long long rtn = n;
	if(n == 0) return 1;
	while(--n){
		rtn = mod_mult(rtn,n);
	}
	return rtn;
}

long long power(long long x, long long n){
    long long rtn =1;
    while(n>0){
        if(n%2){
            rtn = mod_mult(rtn,x);
        }
        x = mod_mult(x,x);
        n/=2;
    }
    return rtn;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	long long N, K; cin>>N>>K;
	cout<<factorial(N)<<'\n';
	cout<<power(N-K,MOD-2)<<'\n';
	cout<<power(K,MOD-2)<<'\n';
	
	int answer = mod_mult(factorial(N),power(N-K,MOD-2));
	answer = mod_mult(answer,power(K,MOD-2));
	cout<<answer;
	return 0;
}