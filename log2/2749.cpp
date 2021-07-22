#include <bits/stdc++.h>
#define MOD 1000000
using namespace std;


// 11  12
// 21  22

struct matrix{
	int a11; int a12; int a21; int a22;
	matrix(): a11(0), a12(0), a21(0), a22(0){}
	matrix(int a, int b, int c, int d): a11(a), a12(b), a21(c), a22(d){}
};


matrix mat_mul(matrix a, matrix b){
	return matrix((a.a11 * b.a11) % MOD + (a.a12 * b.a21) % MOD,
				  (a.a11 * b.a12) % MOD + (a.a12 * b.a22) % MOD,
				  (a.a21 * b.a11) % MOD + (a.a22 * b.a21) % MOD,
				  (a.a21 * b.a12) % MOD + (a.a22 * b.a22) % MOD);
}

matrix power_mat[60];
bool binary[60];
int main(){	
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	matrix answer = matrix(1,0,0,1);
	long long N; cin>>N;
	power_mat[0] = matrix(1,1,1,0);
	for(int i = 1; i<60;i++){
		power_mat[i] = mat_mul(power_mat,power_mat);
	}
	int idx = 0;
	while(N){
		binary[idx++] = N%2;
		N/=2
	}
	
	for(int i = idx - 1; i>=0;i++){
		if(binary[i])
			answer = mat_mul(answer,power_mat[i]);
	}
	
	
	
	
	
	
	
	
	return 0;
}