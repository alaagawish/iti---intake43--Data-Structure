#include<iostream.h>
#include<conio.h>
#include<string.h>
class IntCollections{
	public:
		//static int seqSearch(int * data, int size, int key);
		//static int binarySearch(int * data, int size, int key);
		//static int RbinarySearch(int * data, int low,int high, int key)
		static void selectionSort(int * data, int size);
		//static void bubbleSort(int * data, int size);
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
void IntCollections::selectionSort(int * data, int size)
{
	int i, j, index=0;
	for(i = 0; i < size-1; i++, index=i) 
	{
	   //	cout<<"i="<<i<<"index="<<index<<endl;
		for(j = i+1; j < size; j++)
			if (data[index] > data[j])
				index=j;
		IntCollections::swap(data[i], data[index]);
	}
}
void main()
{
	int i;
	clrscr();

	int arr[10] = {1, 12, 8, 17, 28, 15, 18, 11, 55, 6};

	IntCollections::selectionSort(arr,10);

	for(i=0 ;i<10 ;i++)
		cout<<"arr["<<i<<"]="<<arr[i]<<endl;

	getch();

}