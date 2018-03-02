//bubblesort on linkedlists

#include <iostream>
using namespace std;

//declaring a class node that specifies the components of a node 
class node

{

public:

int data;

node *next;

//class constructor for class node

node() { 
	data = 0;

    next = NULL;

}

};

//declaring a class linkedlist that specifies the componenets of a LL and declares some elementary functions of LL
class linked_list

{

public:

node *head, *tail;

//class constructor for LL
linked_list(){

    head = NULL;

    tail = NULL;

}

//function to insert nodes into a linked list

void insert (int data){

    node *tmp = new node;

    tmp->data = data;

    tmp->next = NULL;

    if(head == NULL){

        head = tmp;

        tail = tmp;

    }

    else{

        tail->next = tmp;

        tail = tail->next;

    }

cout << "Node with data " << data << " successfully added." << endl;

}

//function to display the data contained in a LL
void display (void){

    node *tmp = head; 

    while(tmp !=NULL){ 

        cout<<(tmp->data)<<" -> "; 

        tmp = tmp->next;//traversing linked list

         } 

         cout<<"NULL\n";

          }

};


//declaring a class bubblesort that sort the elements in a linked list in an ascending order
class bubblesort{

    public:
	
	//sort function taking nodes of linked lists as argument
	
   void sort(node *h){

	for(node*i = h;i!=NULL;){

    for(node*j = h;j->next!=NULL;){

    if((j->data) > j->next->data){

    int t = j->next->data;

    j->next->data = j->data;

    j->data = t;

    }j=j->next;

    }i=i->next;

    }return;

   }

};



int main(){

    int x,d;

    cout<<"Enter size of linked list : ";

    cin>>x;
    
	//declaring an class component ll1 belonging to class linked list
	
    linked_list ll1;
    
	//calling the bubble sort function
	
    bubblesort c;
    
    	cout<<" Enter the elements of linked list : ";
	
	for(int i=0;i<x;i++){
		cout<<"node["<<i<<"]->data : ";
		cin>>d;
		ll1.insert(d);
		cout<<"\n";
	}


    cout<<"input list is : ";

    ll1.display();

    c.sort(ll1.head);
    
    cout<<"The sorted linkedlist is : ";

    ll1.display();

    return 0;

}
