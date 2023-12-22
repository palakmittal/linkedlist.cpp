#include<iostream>
using namespace std;

//In circular linked list we dont have the need of taking head pointer onl need is of tail pointer.

class Node{
	public:
		int data;
		Node* next;
		//constructor
		Node(int d){
			this->data=d;
			this->next=NULL;
		}
		//destructor
		~Node(){
			int val=this->data;
			if(this->next!=NULL){
				delete next;
				next=NULL;
			}
			cout<<"deleted value is: "<<val<<endl;
		}
};

// function to insert linked list
// here element means after which data the new node to be inerted
void insertNode(Node*&tail, int element,int d){
	//if list is empty
	if(tail==NULL){
		Node* newNode= new Node(d);
		newNode->next= newNode;
		tail=newNode;
	}
	//insertion when there is atleast one element
	else{
		Node*curr=tail;
		while(curr->data!=element){
			curr=curr->next;
		}
		Node* newNode= new Node(d);
		newNode->next=curr->next;
		curr->next= newNode;
	}
}

//printing the linked list
void print(Node*&tail){
	if(tail==NULL){
		cout<<"list is empty."<<endl;
		return;
	}
	Node* temp=tail;
	cout<<tail->data<<" ";
    tail=tail->next;
	while(tail!=temp){
		cout<<tail->data<<" ";
		tail=tail->next;
	}
	cout<<endl;
}

//deleting node in linked list
// here element means which is to be deleted is directly pased as a parameter
void deleteNode(Node*&tail, int element){
	if(tail==NULL){
		cout<<"list is empty, so data cannot deleted"<<endl;
		return;
	}
	else{
		Node*prev=tail;
		Node*curr=prev->next;
		while(curr->data!=element){
		prev=curr;
		curr=curr->next;
	}
	prev->next=curr->next;
	if(curr==prev){   //jab keval ek hi linked list bachegi
		tail=NULL;
	}
	if(tail==curr){
		tail=prev;
	}
	curr->next=NULL;
	delete curr;
		}
	
}


int main(){
	Node* tail= NULL;
	
	//insertion
//	insertNode(tail, 5,3);
//	print(tail);
//	insertNode(tail, 3,5);
//	print(tail);
//	insertNode(tail, 3,15);
//	print(tail);
	
	//deletion
//	insertNode(tail, 5,3);
//	print(tail);
//	insertNode(tail, 3,5);
//	print(tail);
//	insertNode(tail, 3,15);
//	print(tail);
//	insertNode(tail, 3,25);
//	print(tail);
//	insertNode(tail, 15,35);
//	print(tail);
//	deleteNode(tail,15);
//	print(tail);
	
	return 0;
}
