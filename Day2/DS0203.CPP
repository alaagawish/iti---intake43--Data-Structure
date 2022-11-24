#include<iostream.h>
#include<conio.h>
#include<string.h>
class IntCollections{
	public:
		//static int seqSearch(int * data, int size, int key);
		//static int binarySearch(int * data, int size, int key);
		//static int RbinarySearch(int * data, int low,int high, int key)
		//static void selectionSort(int * data, int size);
		static void bubbleSort(int * data, int size);
		//static void mergeSort(int * data, int size);

		static void swap(int & a, int & b);
		//	static void merge(int * A, int * L, int leftCount, int * R,int rightCount);
};


void IntCollections::swap(int & a,int & b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}


void IntCollections::bubbleSort(int * data, int size)
{
	int i,j=0, sorted = 0;
	while(!sorted && j<size-1)
	{
		sorted = 1;
		for(i = 0; i < size-j-1; i++)

			if (data[i] > data[i+1])
			{
				IntCollections::swap(data[i], data[i+1]);
				sorted = 0;
			}

	}
	j++;
}

void main(){
	int i;
	clrscr();

	int arr[10] = {1, 12, 8, 17, 28, 15, 18, 11, 55, 6};


	IntCollections::bubbleSort(arr, 10);

	for(i=0 ;i<10 ;i++)
		cout<<"arr["<<i<<"]="<<arr[i]<<endl;

	getch();
	}