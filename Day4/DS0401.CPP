#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<alloc.h>
#include<math.h>

class Node{
	public:
		int data;
		Node * prev;
		Node * next;
	Node(){
	  //	data=99;
		prev=next=NULL;
	}
	Node(int d){
		data=d;
		prev=next=NULL;
	}
};

class LinkedList {
	Node * start;
	Node * end;
	int size;
	public:
		LinkedList();
		Node * searchOnNode(int key);
		void appendNode(Node * element);
		void insert(Node * element);
		int deleteNode(int key);
		void freeList();
		int getSize();
		int isEmpty();
		Node * peekLast();
		Node * peekFirst();
		Node * getFirst();
		Node * getLast();

};

LinkedList:: LinkedList()
{
	start=end=NULL;
	size=0;
}

Node * LinkedList::searchOnNode(int key )
{
	Node * temp = start;
	if(start==NULL)
			return NULL;
	while(temp && temp->data!=key)
		temp = temp -> next;
	cout<<"search "<<temp<<endl;
	return temp;
}



void LinkedList::appendNode(Node * element)
{
	if(start == NULL)

		start=end=element;

	else
	{
		element->prev=end;
		end->next=element;
		end=element;
	}
	size++;
}


void LinkedList::insert(Node * element)
{
	Node * temp = start;
	while(temp && (temp->data < element->data))
		temp = temp->next;
	if(!temp)
		appendNode(element);
	else if(temp==start)
	{
		start->prev=element;
		element->next=start;
		start=element;
	}
	else
	{
		temp->prev->next=element;
		element->prev=temp->prev;
		temp->prev=element;
		element->next=temp;
	}
	size++;
}

int LinkedList::deleteNode(int key)
{
	Node * temp;
	if(!start)    {
		return 0;}
	temp=searchOnNode(key);
	cout<<"node want to delete  "<<temp->data<<endl;
	if(!temp)      {
		return 0;
					}
	if(start==temp && end==temp)
	{
		start=end=NULL;
		free(temp);
	}else if(start==temp){
		start=start->next;
		start->prev=NULL;
		free(temp);
	}else if(end==temp){
		end=end->prev;
		end->next=NULL;
		free(temp);
	}else{
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		free(temp);
	}
	size--;
	return 1;
}


void LinkedList::freeList( )
{
	Node * temp = start;
	while(temp){
		start = start->next;
		free(temp);
		temp = start;
	}
	end = NULL;
	size = 0;
}


int LinkedList:: getSize(){
	return size;
}


int LinkedList:: isEmpty(){
	return start==NULL ;
}

Node * LinkedList::getFirst()
{
	if(isEmpty())
		return NULL;
	Node * temp = start;
	start=start->next;
	if(start)
		start->prev=NULL;
	else
		end=NULL;
	temp->prev=temp->next=NULL;
	size--;
	return temp;
}

Node * LinkedList::getLast()
{
	if(isEmpty())
		return NULL;
	Node * temp = end;
	end=end->prev;
	if(end)
		end->next=NULL;
	else
		start=NULL;
	temp->prev=temp->next=NULL;
	size--;
	return temp;
}

Node * LinkedList::peekFirst()
{
	if(isEmpty())
		return NULL;
	Node * temp = new Node();
	temp->data = start->data;
	temp->prev=temp->next=NULL;
	return temp;
}

Node * LinkedList::peekLast()
{
	if(isEmpty())
		return NULL;
	Node * temp = new Node();
	temp->data = end->data;
	temp->prev=temp->next=NULL;
	return temp;
}


class Stack{
	LinkedList stk;
	int existSize;
	public:
		Stack();
		~Stack();
		int isFull();
		int isEmpty();
		int push(Node * ele);
		int pop(Node & ele);
		Node * peek();
		int getSize(){

		   return	stk.getSize();
		}
};

Stack::Stack()
{
	existSize=0;
}

Stack::~Stack()
{
	stk.freeList();
}

int Stack::isFull()
{
	Node temp(5);
	if(temp.data)
	{
	   //	delete temp;
		return 0;
	}
	return 1;
}



int Stack::isEmpty()
{
	return stk.isEmpty();	
}


Node * Stack::peek()
{
	return stk.peekLast();
}


int Stack::push(Node * ele)
{
	if(isFull())
		return 0;
	stk.appendNode(ele);
	existSize++;
	return 1;
}

int Stack::pop(Node & ele)
{
	if(isEmpty())
		return 0;
	ele=*stk.getLast();
	existSize--;
	return 1;
}



void main(){
	clrscr();

	Stack s;
	int flag;
	flag=s.push(&Node(3));
	if (flag)
		cout<<"push done"<<endl;
	else
		cout<<"push failed"<<endl;
	flag=s.push(&Node(1));
	if (flag)
		cout<<"push done"<<endl;
	else
		cout<<"push failed"<<endl;
	flag=s.push(&Node(8));
	if (flag)
		cout<<"push done"<<endl;
	else
		cout<<"push failed"<<endl;


	cout<<"first peek in stack= "<<s.peek()->data<<endl;

	Node node;
	flag=s.pop(node);


	if (flag)
		cout<<"pop done= "<<node.data<<endl;
	else
		cout<<"pop failed"<<endl;




	flag=s.pop(node);

	if (flag)
		cout<<"pop done= "<<node.data<<endl;
	else
		cout<<"pop failed"<<endl;


	cout<<"second peek in stack= "<<s.peek()->data<<endl;

	cout<<"size of stack= "<<s.getSize()<<endl;
	getch();
}