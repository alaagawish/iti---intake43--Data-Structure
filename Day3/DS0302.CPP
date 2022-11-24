#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<alloc.h>
#include<math.h>
template <class t>
class Node{
	public:
		t data;
		Node * prev;
		Node * next;
	Node(){
		//data=99;
		prev=next=NULL;
	}
	Node(t d){
		data=d;
		prev=next=NULL;
	}
};
template <class t>
class LinkedList {
	Node<t> * start;
	Node<t> * end;
	int size;
	public:
		LinkedList()
		{
			start=end=NULL;
			size=0;
		}
		Node<t> * searchOnNode(int key);
		void appendNode(Node<t> * element);
		void insert(Node<t> * element);
		int deleteNode(int key);
		void freeList();
		int getSize();
		int isEmpty();
		Node<t> * peekLast();
		Node<t> * peekFirst();
		Node<t> * getFirst();
		Node<t> * getLast();

};
template <class t>
Node<t> *  LinkedList<t>::searchOnNode(int key )
{
	Node<t> * temp = start;
	if(start==NULL)
			return NULL;
	while(temp && temp->data!=key)
		temp = temp -> next;
	return temp;
}


template <class t>
void  LinkedList<t>::appendNode(Node<t> * element)
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

template <class t>
void  LinkedList<t>::insert(Node<t> * element)
{
	Node<t> * temp = start;
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

template <class t>
int  LinkedList<t>::deleteNode(int key)
{
	Node<t> * temp;
	if(!start)
		return 0;
	temp=searchOnNode(key);
	cout<<"node u want to delete "<<temp->data<<endl;
	if(!temp)
		return 0;
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

template <class t>
void  LinkedList<t>::freeList( )
{
	Node<t> * temp = start;
	while(temp){
		start = start->next;
		free(temp);
		temp = start;
	}
	end = NULL;
	size = 0;
}

template <class t>
int  LinkedList<t>:: getSize(){
	return size;
}

template <class t>
int  LinkedList<t>:: isEmpty(){
	return start==NULL ;
}

template <class t>
Node<t> *  LinkedList<t>::getFirst()
{
	if(isEmpty())
		return NULL;
	Node<t> * temp = start;
	start=start->next;
	if(start)
		start->prev=NULL;
	else
		end=NULL;
	temp->prev=temp->next=NULL;
	size--;
	return temp;
}

template <class t>
Node<t> *  LinkedList<t>::getLast()
{
	if(isEmpty())
		return NULL;
	Node<t> * temp = end;
	end=end->prev;
	if(end)
		end->next=NULL;
	else
		start=NULL;
	temp->prev=temp->next=NULL;
	size--;
	return temp;
}


template <class t>
Node<t> * LinkedList<t>::peekFirst()
{
	if(isEmpty())
		return NULL;
	Node<t> * temp = new Node<t>();
	temp->data = start->data;
	temp->prev=temp->next=NULL;
	return temp;
}

template <class t>
Node<t> *  LinkedList<t>::peekLast()
{
	if(isEmpty())
		return NULL;
	Node<t> * temp = new Node<t>();
	temp->data = end->data;
	temp->prev=temp->next=NULL;
	return temp;
}


void main(){
	clrscr();

	LinkedList<char> lList;
	cout<<"empty?= "<<lList.isEmpty()<<endl;
	lList.insert(& Node<char>('w'));
	lList.insert(& Node<char>('a'));
	lList.insert(& Node<char>('v'));
	lList.appendNode(& Node<char>('o'));
	lList.appendNode(& Node<char>('d'));
	lList.insert(& Node<char>('x'));
	cout<<"peek first= "<<lList.peekFirst()->data<<endl;
	cout<<"peek last= "<<lList.peekLast()->data<<endl;
	cout<<"get first= "<<lList.getFirst()->data<<endl;

	cout<<"get last= "<<lList.getLast()->data<<endl;
	cout<<"peek first= "<<lList.peekFirst()->data<<endl;
	cout<<"peek last= "<<lList.peekLast()->data<<endl;

	cout<<"size of linked list= "<<lList.getSize()<<endl;
	cout<<"search for a node a= "<<lList.searchOnNode('o')->data<<endl;
	getch();
}