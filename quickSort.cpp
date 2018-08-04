//CLRS page 191 Quick Sort
#include <iostream>
using namespace std;
int partition(int arr[], int p, int r){
	int x=arr[r];
	int i=p-1;
	int tmp;
	for(int j=p; j<=r-1; j++){
		if(arr[j]<=x){
			i+=1;
			tmp=arr[i];
			arr[i]=arr[j];
			arr[j]=tmp;
		}
	}
	tmp=arr[i+1];
	arr[i+1]=arr[r];
	arr[r]=tmp;
	return i+1;
}
void quick_sort(int arr[], int p, int r){
	if(p<r){
		int q=partition(arr, p, r);
		quick_sort(arr, p, q-1);
		quick_sort(arr, q+1, r);
	}
}
int main(){
	int arr[12]={13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11};
	quick_sort(arr, 0, 11);
	for(int i=0;i<12;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}