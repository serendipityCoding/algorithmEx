//CLRS page 43 2.1-4
//Consider the problem of adding two n-bit binary integers, stored in two n-element arrays A and B. 
//The sum of the two integers should be stored in binary 
//binary form in an (n+1) element array C
#include <iostream>
using namespace std;
int main(){
	int A[100];
	int B[100];
	int C[101];
	int length;
	cin>>length;
	for(int i=0;i<length;i++){
		cin>>A[i];
	}
	for(int i=0;i<length;i++){
		cin>>B[i];
	}
	int d=0;
	for(int i=0;i<length;i++){
		if(A[i]+B[i]+d>=2){
			C[i]=A[i]+B[i]+d-2;
			d=1;
		}
		else{
			C[i]=A[i]+B[i]+d;
			d=0;
		}
	}
	C[length]=d;
	for(int i=0;i<length+1;i++){
		cout<<C[i];
	}
	cout<<endl;
}