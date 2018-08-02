//CLRS page 60 2.3-5
//implement binary search on sorted array
#include <iostream>
using namespace std;
bool find_target(int arr[], int target, int s, int t){
	int m=(s+t)/2;
	if(s==t&&arr[m]!=target){
		return false;
	}
	if(arr[m]==target){
		return true;
	}
	else if(arr[m]>target){
		return find_target(arr, target, s, m);
	}
	else return find_target(arr, target, m+1, t);
}
int main(){
	int arr[9]={-2, 5, 9, 14, 17, 20, 21, 26,33};
	int target=18;
	bool res=find_target(arr, target, 0,  8);
	res ? cout<<"Target found"<<endl : cout<<"Target not found"<<endl;
}