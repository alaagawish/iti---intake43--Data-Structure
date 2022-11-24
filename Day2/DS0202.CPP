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
		//static int seqSearch(int * data, int size, int key);
		//static int binarySearch(int * data, int size, int key);
		//static int RbinarySearch(int * data, int low,int high, int key)
		static void selectionSort(struct Employee  data[], int size);
		//static void bubbleSort(int * data, int size);
		//static void mergeSort(int * data, int size);

		static void swap(struct Employee & a, struct Employee &b);
	   //	static void merge(int * A, int * L, int leftCount, int * R,int rightCount);
};


void StructCollections::swap(struct Employee&  a,struct Employee & b){
	struct Employee temp;
	temp=a;

   /*	temp.code = a.code;
	temp.bouns = a.bouns;
	temp.deduct = a.deduct;
	temp.salary = a.salary;
	temp.netSalary = a.netSalary;
	strcpy( temp.name , a.name);

	//cout<<temp.code<<endl;

	a.code = b.code;
	a.bouns = b.bouns;
	a.deduct = b.deduct;
	a.salary = b.salary;
	a.netSalary = b.netSalary;
	strcpy( a.name , b.name);

	b.code = temp.code;
	b.bouns = temp.bouns;
	b.deduct = temp.deduct;
	b.salary = temp.salary;
	b.netSalary = temp.netSalary;
	strcpy(b.name, temp.name);
	*/
	a = b;
   b = temp;
}
void StructCollections::selectionSort(struct Employee data[], int size)
{
	int i, j, index=0;
	for(i = 0; i < size-1; i++, index=i)
	{
	   //	cout<<"i="<<i<<"index="<<index<<endl;
		for(j = i+1; j < size; j++)
			if (strcmp(data[index].name , data[j].name)>0)
		  // if (data[index].code>data[j].code)
				index=j;
		StructCollections::swap(data[i], data[index]);
	}
}
void main()
{
	int i;
	clrscr();
	struct Employee empArr[3]= {{10,"Youseef", 352, 4500, 234.7, 20.3},
								{20,"Mohamed", 423, 7500, 456.3, 45.2},
								{30,"Mahmoud", 7500, 456.3, 4.3} };



	StructCollections::selectionSort(empArr,3);

	for(i=0 ;i<3 ;i++)
		cout<<empArr[i].name<<endl;

	getch();

}