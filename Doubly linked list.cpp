#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* prev;
	Node* next;
	
	//constructor
	Node(int d){
		this->data=d;
		this->prev=NULL;
		this->next=NULL;
	}
	
	//destructor
	~Node(){
		int val= this->data;
		if(next!=NULL){
			delete next;
			next= NULL;
		}
		cout<<"memory free for value: "<<val<<endl;
	}
};

               //function for printing doubly linked list
void print(Node* &head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

           // function to get the length of linked list
int getLength(Node*& head){
	Node* temp=head;
	int len=0;
	while(temp!=NULL){
		len++;
		temp=temp->next;
	}
	return len;
}           

                     //Function for insertion of node AT head
void insertionAtHead(Node*&head, int d){
	Node* temp=new Node(d);
	temp->next=head;
	head->prev=temp;
	head=temp;
}                     
         
         
		 //Function for insertion of node AT tail
void insertionAtTail (Node*&tail, int d,Node*&head){
	Node* temp= new Node(d);
	Node* curr=head;
    if(head->next==NULL){
		temp->prev=head;
	    head->next=temp;
}else{
	while(curr->next!=NULL){
		curr=curr->next;
	}
	curr->next=temp;
	temp->prev=curr;
}
	tail=temp;
}   

        
           // function for inserting node at middle position
void insertionAtPos(Node*&head,int d,int position,Node*&tail){
	Node*node_to_insert=new Node(d);
	Node*temp=head;
	if(position==1){
		insertionAtHead(head, d);
	}
	else if(position==getLength( head)+1){
		insertionAtTail(tail, d,head);
	}
	else{
		int count=1;
		while(count<position-1){
		temp=temp->next;
			count++;
		}
		node_to_insert->next=temp->next;
		node_to_insert->prev=temp;
		temp->next->prev=node_to_insert;
		temp->next=node_to_insert;
	}
}
        
        
        //function for deletion in doubly linked list
void deletion(Node*&head,Node*&tail,int position){
	Node*temp=head;
	if(position==1){
		head=temp->next;
		temp->next=NULL;
		delete temp;
	}
	else if(position==getLength(head)){
		temp=tail;
		tail=temp->prev;
		temp->prev=NULL;
		delete temp;
	}
	else{
		Node*curr=head;
		Node*previous=NULL;
		int count=1;
		while(count<position){
			previous=curr;
			curr=curr->next;
			count++;
		}
		curr->next->prev=curr->prev;
		previous->next=curr->next;
		curr->next=NULL;
		curr->prev=NULL;
		delete curr;
	}
}        
        
        
int main(){
	
//	Node*node1=new Node(10);
//	Node* head= node1;
	
//	print(head); // prints 10
//	cout<<getLength(head); // prints 1
	
	
	//insertion at beginning of doubly linked list
	
//	Node*node1=new Node(10);
//	Node* head= node1;
//	insertionAtHead(head, 20);
//	insertionAtHead(head, 30);
//	insertionAtHead(head, 40);
//	insertionAtHead(head, 50);
//	print(head);  // prints 50 40 30 20 10
	
	//insertion at ending of doubly linked list
//	Node*node1=new Node(10);
//	Node* head= node1;
//	Node* tail=node1;
//	insertionAtTail(tail, 20,head);
//	insertionAtTail(tail, 30,head);
//	insertionAtTail(tail, 40,head);
//	insertionAtTail(tail, 50,head);
//	print(head); // prints 10 20 30 40 50
	
	
	//  insertion at middle of doubly linked list
//	Node*node1=new Node(10);
//	Node* head= node1;
//	Node* tail=node1;
//	insertionAtTail(tail, 20,head);
//	insertionAtTail(tail, 40,head);
//	insertionAtTail(tail, 50,head);
//	insertionAtPos(head,30,3,tail); //position is 3 and data is 30
//	print(head); // prints 10 20 30 40 50
	
	
	//deletion in doubly linked list
	
	Node*node1=new Node(10);
	Node* head= node1;
	Node* tail=node1;
	insertionAtTail(tail, 20,head);
	insertionAtTail(tail, 30,head);
	insertionAtTail(tail, 40,head);
	insertionAtTail(tail, 50,head);
	deletion(head,tail,2);
	print(head); // prints 10 20 40 50
	
	
	
	
	
	
	
	
	return 0;
}
