#include<bits/stdc++.h>
#define N 3
using namespace std;
float mulInverse(int det){
	int quotient, remainder, divisor = 26,divident=det, t,t1=0,t2=1;
	while(remainder == 0 && divident == 1){
		quotient = divisor/divident;
		if(divisor%divident == 0) return t;
		remainder = divisor%divident;
		
		t = t1-(t2*quotient);
		
		divisor = divident;
		divident = remainder;
		
		t1=t2;
		t2=t;
	}
	return t2;
}
void inverseMatrix(int adj[N][N], int multinv){
	int inverseMat[N][N];
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			inverseMat[i][j] = adj[i][j] * multinv;
		}
	}
	cout<<endl;
	cout<<"Inverse of matrix : "<<endl;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout<<inverseMat[i][j]<<"\t";
		}cout<<endl;
	}

}
int determinant(int dMatrix[N][N]){
       int x, y, z;
	
       x = ((dMatrix[1][1] * dMatrix[2][2]) - (dMatrix[2][1] * dMatrix[1][2]));
       y = ((dMatrix[1][0] * dMatrix[2][2]) - (dMatrix[2][0] * dMatrix[1][2]));
       z = ((dMatrix[1][0] * dMatrix[2][1]) - (dMatrix[2][0] * dMatrix[1][1]));
	
       return ((dMatrix[0][0] * x) - (dMatrix[0][1] * y) + (dMatrix[0][2] * z));
}
void adjmatrix(int temp[N+2][N+2], int A[N][N]){
	int adj[N][N];
	for(int i=1; i<N+1; i++){
		for(int j=1; j<N+1; j++){
			adj[i-1][j-1] = (temp[i][j]*temp[i+1][j+1] - temp[i][j+1]*temp[i+1][j]);
		}
	}
	int transpose[N][N];
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			transpose[j][i] = adj[i][j];
		}
	}
	
	cout<<"Adjoint matrix"<<endl;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout<<transpose[i][j]<<"\t";
		}cout<<endl;
	}cout<<endl;
	
	int det = determinant(A);
	cout<<"Determinant : "<<det<<endl;
	int multinverse = mulInverse(det);
	cout<<"Multiplative inverse : "<<multinverse<<endl;
	
	inverseMatrix(transpose,multinverse);

}
void extend(int A[N][N]){
	int temp[N+2][N+2];
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			temp[i][j] = A[i][j];
		}
	}
	for(int i=0; i<N; i++){
		for(int j=3; j<N+2; j++){
			temp[i][j] = A[i][j-3];
		}
	}
	for(int i=3; i<N+2; i++){
		for(int j=0; j<N+2; j++){
			temp[i][j] = temp[i-3][j];
		}
	}
	cout<<"Extended matrix"<<endl;
	for(int i=0; i<N+2; i++){
		for(int j=0; j<N+2; j++){
			cout<<temp[i][j]<<"\t";
		}cout<<endl;
	}cout<<endl;
	
	adjmatrix(temp,A);
}


int main(){
	int A[N][N] = { {17, 17, 5},{21, 18, 21},{2, 2, 19}};
	cout<<"Original matrix"<<endl;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout<<A[i][j]<<"\t";
		}cout<<endl;
	}cout<<endl;
        extend(A);
}
