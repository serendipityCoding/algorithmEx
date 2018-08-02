//CLRS page 51 merger sort
#include <iostream>
using namespace std;
void merge(int arr[], int p, int q, int r){
	int arr1[100];
	int arr2[100];
	int l1=q-p+1;
	int l2=r-q;
	for(int i=0;i<l1;i++){
		arr1[i]=arr[p+i];
	}
	for(int i=0;i<l2;i++){
		arr2[i]=arr[q+1+i];
	}
	int k=p;
	int i=0, j=0;
	//while statement here should be i<l1 && j<l2 
	//not k<=r
	//because once one of the array is looped through
	//it is the time to put all the elements in the other array to the origin
	//array with no more comparison
	while(i<l1&&j<l2){
		if(arr1[i]<arr2[j]){
			arr[k++]=arr1[i++];
		}
		else arr[k++]=arr2[j++];
	}
	while(i<l1){
		arr[k++]=arr1[i++];
	}
	while(j<l2){
		arr[k++]=arr2[j++];
	}
}
void merge_sort(int arr[], int s, int t){
	if (s < t) {
		int q=(s+t)/2;
		merge_sort(arr, s, q);
		merge_sort(arr, q+1, t);
		merge(arr, s, q, t);
	}
}
int main(){
	int length;
	cin>>length;
	int arr[100];
	for(int i=0;i<length;i++){
		cin>>arr[i];
	}

	merge_sort(arr, 0, length-1);
	for(int i=0;i<length;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}