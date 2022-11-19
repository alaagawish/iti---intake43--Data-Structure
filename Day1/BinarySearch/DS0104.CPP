#include <iostream.h>
#include<conio.h>
#include<string.h>
class CharCollections{
	public:
		//static int seqSearch(int * data, int size, char key);
		static int binarySearch(char*  ptr[], int size, char data[]);
		//	static char RbinarySearch(char * data, int low,int high, string key);
		//static void selectionSort(char * data, int size);
		//static void bubbleSort(char * data, int size);
		//static void mergeSort(char * data, int size);
	// Needed functions
		//static void swap(char & a, char & b);
		//static void merge(int * A, int * L, int leftCount, int * R,int rightCount);
};



//BINARY SEARCH ITERATION
int CharCollections::binarySearch(char* ptr[], int size, char data[]){
	int i,low=0, high=size-1, mid;
	mid=(low+high)/2;
	while(high >= low)
	{
		mid = (high+low)/2;
		if (strcmp(ptr[mid] , data)>0)
			high = mid - 1;
		else if (strcmp(ptr[mid] , data)<0)
			low = mid + 1;
		else if(strcmp(ptr[mid] , data)==0)
			return mid;
	}
	return -1;
}
/*
//BINARY USING RECURSION
char CharCollections::RbinarySearch(char * ptr, int low, int high,char data){
	int mid;
	if(high>=low){
		mid=(low+high)/2;
		if(ptr[mid]>data)
			return CharCollections::RbinarySearch(ptr,low,mid-1,data);
		else if(ptr[mid]<data)
			return CharCollections::RbinarySearch(ptr,mid+1,high,data);
		else
			return mid;
	}
	return -1;

}
*/
void main(){
	clrscr();
	//Binary Search
	char* Ar[6] = {"alaa","donia","farah","passant","rana","zyad"};
	int index;
	char data[]="kkkk";
	//cout<<"\nPlease Enter a number to find it in the array:";
	//cin>>data;
	index = CharCollections::binarySearch(Ar, 6, data);

	if (index!=-1)
		cout<<"\nFound at location "<<index<<endl;
	else
		cout<<"\nNot Found"<<endl;


	getch();
}