//CLRS page 60 2.3-7
#include <iostream>
using namespace std;
bool binarySearch(int arr[], int target, int s, int t){
	int m=(s+t)/2;
	if(s==t&&arr[m]!=target){
		return false;
	}
	if(arr[m]==target){
		return true;
	}
	else if(arr[m]>target){
		return binarySearch(arr, target, s, m);
	}
	else return binarySearch(arr, target, m+1, t);
}
int main(){
	int arr[9]={-2, 5, 9, 14, 17, 20, 21, 26,33};
	int sum=6;
	bool res=false;
	for(int i=0; i<9;i++){
		if(binarySearch(arr, sum-arr[i], i+1, 9)){
			res=true;
			break;
		}
	}
	res?cout<<"Exists"<<endl : cout<<"Not exist"<<endl;
}