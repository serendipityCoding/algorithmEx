//CLRS page 95 find_maximum_subarray
#include <iostream>
using namespace std;
struct Sub{
	int low, high, sum;
};
Sub find_cross_maximum_subarray(int arr[], int s, int p, int t){
	int cross_low, cross_high;
	int left_sum=-1000;
	int sum=0;
	for(int i=p;i>=0;i--){
		sum+=arr[i];
		if(sum>left_sum){
			left_sum=sum;
			cross_low=i;
		}
	}
	int right_sum=-1000;
	sum=0;
	for(int i=(p+1);i<=t;i++){
		sum+=arr[i];
		if(sum>right_sum){
			right_sum=sum;
			cross_high=i;
		}
	}
	Sub tmp={cross_low, cross_high, left_sum+right_sum};
	return tmp;
}
Sub find_maximum_subarray(int arr[], int s, int t){
	if(s==t) { 
		Sub tmp={s, t, arr[s]};
		return tmp;
	}
	else{
		int p=(s+t)/2;
		Sub left=find_maximum_subarray(arr, s, p);
		Sub right=find_maximum_subarray(arr, p+1, t);
		Sub cross=find_cross_maximum_subarray(arr, s, p, t);
		if(left.sum>=right.sum&&left.sum>=cross.sum){
			return left;
		}
		else if(right.sum>=left.sum&&right.sum>=cross.sum){
			return right;
		}
		else{
			return cross;
		}
	}
}
int main(){
	int arr[16]={13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	Sub res=find_maximum_subarray(arr, 0, 15);
	cout<<res.low<<" "<<res.high<<endl;
	cout<<res.sum<<endl;
}