#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		// constructor
		Node(int data){
			this->data= data;
			this->next= NULL;
		}	
		
		//destructor
		~Node(){
			int value=this->data;
			//free the memory
			if(this->next!=NULL){
				delete next;
				this->next=NULL;
			}
			cout<<"the memory is deleted for the value: "<<value<<endl;
		}
};

// function for printing the data of singly linked list
void print(Node* &head){
	Node* temp= head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}


// insertion at beginning in singly linked list
void insertionAtHead(Node* &head,int d){
	// create new node
	Node* temp= new Node(d);
	temp->next= head; // temp node will now point to head node at first
	head=temp;  // now temp node becoes th e head node
}

// insertion at ending in singly linked list
void insertionAtTail(Node* &tail,int d){
	// create new node
	Node* temp= new Node(d);
	tail->next= temp; //tail's address part stores the address of newly created node
	tail=temp;  // assigning last node of linked list as tail
}


// insertion in middle in singly linked list
void insertionAtMid(Node* &head,Node* &tail,int d,int pos){
	// create new node
	if(pos==1){
		insertionAtHead(head,d);
		
	}
	else if(pos==0){
		cout<<"cannot insert the data."<<endl;
	}
    else if(pos==-1){
    	insertionAtTail(tail,d);
    
	}else{
		Node* temp= head;
		Node* midnode= new Node(d);
		int cnt=1;
		while(cnt<pos-1){
		temp=temp->next;
		cnt++;
		}
		midnode->next=temp->next;
		temp->next=midnode;
	}
}

// function for deleting node
void deleteNode(int position,Node* &head,Node* &tail){
	
	if(position==1){
		// for deleting first node
		Node* temp=head;
		head=head->next;
		temp->next= NULL;
		delete temp;
		
	}else{
		// for deletion of any middle or last node
		Node* curr=head;
		Node* prev= NULL;
		int count=1;
		while(count<=position-1){
			prev=curr;
			curr=curr->next;
			count++;
		}
		prev->next= curr->next;
		curr->next=NULL;
		delete curr;
		if(prev->next==NULL){
			tail=prev;
		}
	}	
}


int main(){
	
//	Node* node1= new Node();
//	cout<<node1->data<<endl; // garbage value
//	cout<<node1->next<<endl;  // prints address 
	
	
//	Node* node1= new Node(10);
//	cout<<node1->data<<endl; // prints data which is passed i.e.=10
//	cout<<node1->next<<endl;  // prints 0 or 0x0 because initialized with null
//	cout<<&node1<<endl;      // prints address of node1 in memory 
	
	
	                    // print linked list data when data insert at beginning
//	Node* node1= new Node(10);
//	Node* head= node1;
//	insertionAtHead(head,20);
//	insertionAtHead(head,30);
//	insertionAtHead(head,40);
//	print(head); // prints 40 30 20 10 
	
	
            // print linked list data when data insert at end
//	Node* node1= new Node(10);
//	Node* head= node1;
//	Node* tail= node1;
//	insertionAtTail(tail,20);
//	insertionAtTail(tail,30);
//	insertionAtTail(tail,40);
//	insertionAtTail(tail,50);
//	print(head); // prints 10 20 30 40 50


                 // print linked list data when data insert in middle
//	Node* node1= new Node(10);
//	Node* head= node1;
//	Node* tail= node1;
//	int pos,data;
//	cout<<"enter position: ";
//	cin>>pos;
//	cout<<endl<<"enter data: ";
//	cin>>data;	
//	insertionAtTail(tail,20);
//	insertionAtTail(tail,40);
//	insertionAtTail(tail,50);
//	insertionAtMid(head,tail,data,pos);
//	cout<<"printing linked list:"<<endl;
//	print(head);
	
	
	               // performing deletion										              
//	Node* node1= new Node(10);
//	Node* head= node1;
//	Node* tail= node1;
//	insertionAtTail(tail,20);
//	insertionAtTail(tail,30);
//	insertionAtTail(tail,40);
//	insertionAtTail(tail,50);
//	print(head); // prints 10 20 30 40 50
////	deleteNode(1,head,tail);
////	print(head);// prints 20 30 40 50
//	deleteNode(3,head,tail);
//	print(head);// prints 10 20 40 50
//	cout<<head->data<<" "<<tail->data;
	
	
	
	
	
	
	
	return 0;
}
