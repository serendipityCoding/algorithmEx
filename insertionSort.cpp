//CLRS page 39 insertion sort
//notes:
//At first, I thought I just need to swap the values in the inside 
//loop, but it is wrong because the swap after the first comparison 
//should be arr[j] and arr[j-1] instead of arr[j-1] and arr[i]
//So it would be better just push the current element back if it is larger
//When it reaches the point it is no longer smaller than the current arr[j]
//it jumps out of the loop and set arr[j+1] to be arr[i] 
//j+1 is because j is decuted one before the comparison
#include <iostream>
using namespace std;
int main(){
	int origin_arr[100];
	int length;
	cin>>length;
	for(int i=0;i<length;i++){
		cin>>origin_arr[i];
	}
	//start from the second number in the array
	for (int i=1; i<length;i++){
		int k=origin_arr[i];
		int j=i-1;;
		while(j>=0&&origin_arr[j]>k){
			origin_arr[j+1]=origin_arr[j];
			j-=1;
		}
		origin_arr[j+1]=k;
		// for(int i=0; i<length; i++){
		// 	cout<<origin_arr[i]<<" ";
		// }
		// cout<<endl;
	}
	for(int i=0; i<length; i++){
		cout<<origin_arr[i]<<" ";
	}
	cout<<endl;
}