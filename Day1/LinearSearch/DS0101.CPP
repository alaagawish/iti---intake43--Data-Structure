#include <iostream.h>
#include<conio.h>


class IntCollections{
	public:
		static int seqSearch(int * data, int size, int key);
		//static int binarySearch(int * data, int size, int key);
		//static int RbinarySearch(int * data, int low,int high, int key);
		//static void selectionSort(int * data, int size);
		//static void bubbleSort(int * data, int size);
		//static void mergeSort(int * data, int size);
	// Needed functions
		//static void swap(int & a, int & b);
		//static void merge(int * A, int * L, int leftCount, int * R,int rightCount);
};


//LINEAR SEARCH 
int IntCollections::seqSearch(int * data, int size, int key){
	int i;
	for(i=0; i<size; i++)
		if(data[i] == key)
			return i;
	return -1;
}



void main(){
	clrscr();
	
	//Linear Search
	int i, arr[]= {12, -15, 7, 10, 37, 6, 13, 1, 5, 3};
	int foundIndex, key;
	cout<<"enter a number:";
	cin>>key;
	cout<<"\n";
	foundIndex=IntCollections::seqSearch(arr,10,key);
	if(foundIndex>-1)
		cout<<"\n found in:"<<foundIndex<<endl;
	else
		cout<<"\n Not Found"<<endl;
	
	getch();
}