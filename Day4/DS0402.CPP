#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<alloc.h>
#include<math.h>

class Queue{
	int * que, size, rear;
	public:
		Queue();
		Queue(int s);
		~Queue();
		int isFull();
		int isEmpty();
		int input(int ele);
		int output(int & ele);
		int peek(int & ele);
};

Queue::Queue()
{
	size = 10;
	rear = 0;
	que = new int[size];
}

Queue::Queue(int s)
{
	size = s;
	rear = 0;
	que = new int[size];
}

Queue::~Queue()
{
	free(que);
}



int Queue::isFull ()
{
	if(rear==size)
		return 1;
	return 0;
}

int Queue::isEmpty ()
{
	return (rear==0);
}

int Queue::input (int data)
{
	if(isFull())
		return 0;
	que[rear] = data;
	rear ++;
	return 1;
}

int Queue::output(int & data)
{
	if(isEmpty()) 
		return 0;
	data = que[0];
	for(int i=0; i < rear ; i++)
	que[i]= que[i+1];
	rear --;
	return 1;
}

int Queue::peek(int & data)
{
	if(isEmpty()) 
		return 0;
	data = que[0];
	return 1;
}




void main(){
	clrscr();

	Queue q;
	int flag;
	flag=q.input(4);
	if(flag)
		cout<<"input done"<<endl;
	else
		cout<<"input failed"<<endl;

	flag=q.input(7);
	if(flag)
		cout<<"input done"<<endl;
	else
		cout<<"input failed"<<endl;

	flag=q.input(3);
	if(flag)
		cout<<"input done"<<endl;
	else
		cout<<"input failed"<<endl;

	int pop;
	flag=q.output(pop);
	if(flag)
		cout<<"pop done = "<<pop<<endl;
	else
		cout<<"pop failed"<<endl;
	flag=q.peek(pop);
	if(flag)
		cout<<"peek done = "<<pop<<endl;
	else
		cout<<"peek failed"<<endl;


	getch();
}