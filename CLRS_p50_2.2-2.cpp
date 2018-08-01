//CLRS page 50 2.2-2
//implement selection sort
#include <iostream>
using namespace std;
int find_smallest(int arr[], int start, int length){
	int m=arr[start];
	int res=start;
	for(int i=start+1;i<length;i++){
		if(m>arr[i]){
			m=arr[i];
			res=i;
		}
	}
	return res;
}
int main(){
	int length;
	cin>>length;
	int arr[100];
	for(int i=0;i<length;i++){
		cin>>arr[i];
	}
	for(int i=0;i<length-1;i++){
		int swap=find_smallest(arr, i, length);
		int tmp=arr[i];
		arr[i]=arr[swap];
		arr[swap]=tmp;
	}
	for(int i=0;i<length;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}