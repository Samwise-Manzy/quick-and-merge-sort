#include <iostream>
using namespace std;
  
// Merges two sorted subarrays of A[]. 
// First sorted subarray is A[l..m].
// Second sorted subarray is A[m+1..r].
// You might want to call this function in function mergeSort().
void merge(int A[], int l, int m, int r)
{ 
	int nL = m - l + 1;		// length of L[]
	int nR = r - m; 		// length of R[]

	int L[nL], R[nR];

	for (int i=0; i < nL; i++){
		L[i] = A[i+l];
	}
	for (int i = 0; i < nR; i++){
		R[i] = A[i+m+1];
	}

	int i = 0;				// curser in L[]
	int j = 0;				// curser in R[]
	int k = l;				// curser in A[]

	while (i < nL && j < nR)	// places smaller of L[] or R[] in A[]
	{
		if (L[i] <= R[j]){
			A[k] = L[i];
			k++;
			i++;
		} else {
			A[k] = R[j];
			k++;
			j++;
		}
	}						// at least one of L[] or R[] is now empty

	while (i < nL) {		// places remaining L[] in A[]
		A[k] = L[i];
		k++;
		i++;
	}

	while (j < nR) {		// places remaining R[] in A[]
		A[k] = R[j];
		k++;
		j++;
	}
} 

// using mergeSort to sort sub-array A[l..r]  
// l is for left index and r is right index of the 
// sub-array of A[] to be sorted
// void mergeSort(int A[], int l, int r) 
// {
// 	if (l<r) {
// 		int m = (l + r)/2;
// 		mergeSort(A, l, m);
// 		mergeSort(A, m+1, r);
// 		merge(A, l, m, r);
// 	}
// } 

void mergeSort(int A[], int l, int r) 
{
	if (l == r) {
		return;
	} else {
		int m = (l + r) / 2;
		mergeSort(A, l, m);
		mergeSort(A, m + 1, r);

		merge(A, l, m, r);
	}
} 

  

int main() 
{ 
    cout << "Please enter the length (number of elements) of the input array: ";
	int n;
	cin >> n;
	
	if(n <= 0) {
		cout << "Illegal input array length!" << endl;
		return 0;
	}
	
	int* A = new int [n];
	
	cout << "Please enter each element in the array" << endl; 
	cout << "(each element must be an integer within the range of int type)." << endl;
	for(int i=0; i<n; i++) {
		cout << "A[" << i << "] = ";
		cin >> A[i];
	}
  
    cout << "Given array A[] is: "; 
	for(int i=0; i<n-1; i++)
		cout << A[i] << ",";
	cout << A[n-1] << endl;
	
  
    mergeSort(A, 0, n-1); 
  
    cout << "After mergeSort, sorted array A[] is: "; 
	for(int i=0; i<n-1; i++)
		cout << A[i] << ",";
	cout << A[n-1] << endl;
	
	
	delete [] A;
    return 0; 
} 