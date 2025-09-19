#include <iostream>
using namespace std;

/*
	Name : Muhammad Umar
	Roll no. : CT - 24028
	Class : CSIT Section A Batch 24
*/

int* indexFunc(int arr[],int target,int size){
	int* answer = new int[2];
	answer[0] = answer[1] = -1;
	
	
	for(int i = 0 ; i < size ; i++){
		for(int j=i+1 ; j<size ; j++){
			if(arr[i] + arr[j] == target){
				answer[0] = i;
				answer[1] = j;
				return answer;
			}
		}
	}
	return answer;
}

int main(){
	
	int arr[] = {9,7,5,3,1,8,6,4,2};
	int target = 15;
	
	int size = 9;
	
	int* resultArray = indexFunc(arr,target,size);
	
	cout << "Indices are " << resultArray[0] << " and " << resultArray[1];
	
	delete[] resultArray;
	
	return 0;
}