#include <iostream.h>
#include<conio.h>


class IntCollections{
	public:
		//static int seqSearch(int * data, int size, int key);
		static int binarySearch(int * data, int size, int key);
		static int RbinarySearch(int * data, int low,int high, int key);
		//static void selectionSort(int * data, int size);
		//static void bubbleSort(int * data, int size);
		//static void mergeSort(int * data, int size);
	// Needed functions
		//static void swap(int & a, int & b);
		//static void merge(int * A, int * L, int leftCount, int * R,int rightCount);
};



//BINARY SEARCH ITERATION
int IntCollections::binarySearch(int * ptr, int size, int Num)
{
	int i,low=0, high=size-1, mid;
	mid=(low+high)/2;
	while(high >= low)
	{
		mid = (high+low)/2;
		if (ptr[mid] > Num)
			high = mid - 1;
		else if (ptr[mid] < Num)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

//BINARY USING RECURSION
int IntCollections::RbinarySearch(int * ptr, int low, int high,int data){
	int mid;
	if(high>=low){
		mid=(low+high)/2;
		if(ptr[mid]>data)
			return IntCollections::RbinarySearch(ptr,low,mid-1,data);
		else if(ptr[mid]<data)
			return IntCollections::RbinarySearch(ptr,mid+1,high,data);
		else
			return mid;
	}
	return -1;

}

void main(){
	clrscr();
	
	//Binary Search
	int Ar[10] = {10, 13, 15, 17, 18, 22, 33, 50, 55, 60};
	int Num, index;
	cout<<"\n Please Enter a number to find it in the array:";
	cin>>Num;
	index = IntCollections::binarySearch(Ar, 10, Num);
	// recursion version calling
	// index = IntCollections::RbinarySearch(Ar, 0, 9, Num);
	if (index!=-1)
		cout<<"\n Found at location "<<index+1<<endl;
	else
		cout<<"\n Not Found"<<endl;

 
	getch();
}