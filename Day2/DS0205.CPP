#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<alloc.h>
#include<math.h>

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
		int getAbs();
		float getReal();
		float getImag();
		void print();
};

int Complex:: getAbs(){

	int absValue=sqrt(pow(this->real,2)+pow(this->imag,2));
	return absValue;

}

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



class IntCollections{
	public:
		//static int seqSearch(int * data, int size, int key);
		//static int binarySearch(int * data, int size, int key);
		//static int RbinarySearch(int * data, int low,int high, int key)
		//static void selectionSort(int * data, int size);
		//static void bubbleSort(int * data, int size);

		static void mergeSort(Complex * data, int size);

	   //	static void swap(int & a, int & b);
		static void merge(Complex* A, Complex* L, int leftCount, Complex * R,int rightCount);
};

void IntCollections::merge(Complex *A,Complex *L,int leftCount,Complex *R,int rightCount) {
	int i,j,k;

	i = 0; j = 0; k =0;
	while(i<leftCount && j< rightCount) {
		if(L[i].getAbs() < R[j].getAbs())
			 A[k++] = L[i++];
		else
			 A[k++] = R[j++];
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}

void IntCollections::mergeSort(Complex *A,int n) {
	int mid,i;
	Complex *L, *R;
	if(n < 2)
		 return;
	mid = n/2;

	L = (Complex*)malloc(mid*sizeof(Complex));
	R = (Complex*)malloc((n- mid)*sizeof(Complex));
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

	Complex arr[3] = {Complex(4),Complex(2,5),Complex(5,1)};


	IntCollections::mergeSort(arr, 3);

	for(i=0 ;i<3 ;i++){
		cout<<"arr["<<i<<"]=";

		arr[i].print();
	}

	getch();

}