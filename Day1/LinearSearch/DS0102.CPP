#include <iostream.h>
#include<conio.h>
#include<string.h>
typedef struct Employee{

		int code;
		char* name;
		int bouns;
		int deduct;
		float salary;
		float netSalary;
	};


class StructCollections{
	public:
		static int seqSearchCode(struct Employee * data, int size, int code);
		static int seqSearchName(struct Employee * data, int size, char name[]);
		//static struct Employee binarySearch(int * data, int size, int key);
		//static struct Employee RbinarySearch(int * data, int low,int high, int key);
		//static void selectionSort(int * data, int size);
		//static void bubbleSort(int * data, int size);
		//static void mergeSort(int * data, int size);
	// Needed functions
		//static void swap(int & a, int & b);
		//static void merge(int * A, int * L, int leftCount, int * R,int rightCount);
};


//LINEAR SEARCH
int StructCollections::seqSearchCode(struct Employee * data, int size, int code){
	int i;
	for(i=0; i<size; i++)
		if(data[i].code == code)
			return i;
	return -1;
}

int StructCollections::seqSearchName(struct Employee * data, int size, char name[]){
	int i;
	for(i=0; i<size; i++)
		if(strcmp(data[i].name ,name)==0)
			return i;
	return -1;
}


void main(){
	clrscr();
	struct Employee empArr[3]= {{10,"Ahmed", 352, 4500, 234.7, 20.3},
								{20,"Mohamed", 423, 7500, 456.3, 45.2},
								{30, "Mahmoud", 7500, 456.3, 4.3} };

	//Linear Search using code of employee

	int foundIndex, key=30;
   //	cout<<"\nenter a code:";
	//cin>>key;

	cout<<"\n";
	foundIndex=StructCollections::seqSearchCode(empArr,3,key);
	if(foundIndex>-1)
		cout<<"\n found in:"<<foundIndex<<endl;
	else
		cout<<"\n Not Found"<<endl;

	//Linear Search using name of employee

   //	cout<<"\nenter name:";
   //	cin>>key;
	char * name="Mohamed";

	foundIndex=StructCollections::seqSearchName(empArr,3,name);
	if(foundIndex>-1)
		cout<<"\n found in:"<<foundIndex<<endl;
	else
		cout<<"\n Not Found"<<endl;

	getch();
}