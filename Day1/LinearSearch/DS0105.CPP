#include<iostream.h>
#include<conio.h>

struct Complex {

	private:
		float real;
		float imag;

	public:
		Complex();
		Complex(float r);
		Complex(float r, float i);
		~Complex();
		void setReal(float r);
		void setImag(float i);
		float getReal();
		float getImag();
		void print();
};


Complex::Complex(){
	real = imag = 0 ;
}


Complex::Complex(float r, float i){
	real =r; imag = i ;
}



Complex::Complex(float r){
	real = imag = r;
}


Complex::~Complex(){

}


void Complex::setReal(float r){
	real = r ;
}


void Complex::setImag(float i){
	imag = i ;

}


float Complex::getReal(){
	return real ;
}


float Complex::getImag(){
	return imag ;
}



void Complex::print(){
	if(imag<0){
		cout<<"Result= "<<real<<" - "<<-1*imag<<"i"<<endl;
	}else if (imag>0){
		cout<<"Result= "<<real<<" + "<<imag<<"i"<<endl;
	}else if (imag==0){
		cout<<"Result= "<<real<<endl;
	}
}

class StructCollections{
	public:
		static int seqSearchComplex(struct Complex * data, int size, Complex num);
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
int StructCollections::seqSearchComplex(struct Complex * data, int size, Complex num){
	int i;
	for(i=0; i<size; i++)
		if(data[i].getReal() == num.getReal() && data[i].getImag()==num.getImag())
			return i;
	return -1;
}

void main(){
	clrscr();
	struct Complex c[3]={Complex(3,4),Complex(2,1),Complex(9)};
	int foundIndex;
	Complex num(9,9);

	foundIndex=StructCollections::seqSearchComplex(c,3,num);
	if(foundIndex>-1)
		cout<<"\n found in:"<<foundIndex<<endl;
	else
		cout<<"\n Not Found"<<endl;

	getch();

}