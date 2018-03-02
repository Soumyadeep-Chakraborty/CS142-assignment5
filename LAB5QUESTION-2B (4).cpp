//quicksort on linked-lists

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

cout << "Node with data " << data << " successfully added."<<endl;

}

//function to display the data contained in a LL

void display (void){
	
    cout << "\nDISPLAYING\n";

    node *tmp = head; 

    while(tmp !=NULL){ 

        cout<<(tmp->data)<<" -> "; 

        tmp = tmp->next; //traversing linked list

         } 

         cout<<"NULL\n";

          }

};


//declaring a class quicksort that sort the elements in a linked list in an ascending order

class quicksort{

    public:
    
		//declaring a function partition that returns a node as a pointer and will separate and swap the data conatined in nodes to arrange them in an ascending order

    node* part(node* h,node* t){
    		
			/*declaring a pivot as the tail of the LL,all nodes with data less than the pivot will be on the 
	left of the pivot while all nodes with data more than the pivot will be on the right*/

         node* pivot = t;   

        node* i = new node;

        i->next = h;

        node* j = h; 
		//traversing the linked list and swapping data contained in the nodes in an ascending order using a loop
		
        while((j->next)!=t)

        {
         if (j->data <= pivot->data)

            {
                i=i->next;

                int tmp=i->data;

                i->data=j->data;

                j->data=tmp;

         }

         j=(j->next);

     }

               if(t->data<i->next->data)

              {  int tmp=i->next->data;

                i->next->data=t->data;

                t->data=tmp;}

    return (i->next);

}

//declaring the sort function that will recursively call the partition function until all the nodes are separated and then merged
//in ascending order

    void sort(node* head,node* tail){

        if(head!=tail){

            node *p =part(head,tail); //here p is a pointer to the node that we call as the pivot
            
            sort(head,p);

            sort((p->next),tail);

        }

    }

};

int main(){
    int x,d;

    cout<<"Enter size of linked list : ";

    cin>>x;
    
	//declaring an class component ll1 belonging to class linked lsit
	
    linked_list ll1;
    
	//declaring a class component c belonging to class quicksort
	
    quicksort c;
    
    	cout<<" Enter the elements of linked list : ";
	
	for(int i=0;i<x;i++){
		cout<<"node["<<i<<"]->data : ";
		cin>>d;
		ll1.insert(d);
		cout<<"\n";
	}


    cout<<"input list is : ";

    ll1.display();

    c.sort(ll1.head,ll1.tail);
    
	cout<<"Displaying The Sorted Linked List : ";
	
    ll1.display();

    return 0;

}
