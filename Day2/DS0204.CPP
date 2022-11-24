#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<alloc.h>

class IntCollections{
	public:
		//static int seqSearch(int * data, int size, int key);
		//static int binarySearch(int * data, int size, int key);
		//static int RbinarySearch(int * data, int low,int high, int key)
		//static void selectionSort(int * data, int size);
		//static void bubbleSort(int * data, int size);

		static void mergeSort(int * data, int size);

	   //	static void swap(int & a, int & b);
		static void merge(int * A, int * L, int leftCount, int * R,int rightCount);
};

void IntCollections::merge(int *A,int *L,int leftCount,int *R,int rightCount) {
	int i,j,k;

	i = 0; j = 0; k =0;
	while(i<leftCount && j< rightCount) {
		if(L[i] < R[j]) A[k++] = L[i++];
			else A[k++] = R[j++];
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}

void IntCollections::mergeSort(int *A,int n) {
	int mid,i, *L, *R;
	if(n < 2)
		 return;
	mid = n/2;

	L = (int*)malloc(mid*sizeof(int));
	R = (int*)malloc((n- mid)*sizeof(int));
	for(i = 0;i<mid;i++) L[i] = A[i];
	for(i = mid;i<n;i++) R[i-mid] = A[i];
	IntCollections::mergeSort(L,mid);
	IntCollections::mergeSort(R,n-mid);
	IntCollections::merge(A,L,mid,R,n-mid);
	free(L);
	free(R);
}
void main()
{
	int i;
	clrscr();

	int arr[10] = {1, 12, 8, 17, 28, 15, 18, 11, 55, 6};


	IntCollections::mergeSort(arr, 10);

	for(i=0 ;i<10 ;i++)
		cout<<"arr["<<i<<"]="<<arr[i]<<endl;

	getch();

}