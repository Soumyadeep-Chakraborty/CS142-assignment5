//programme to compare running time of bubblesort and quicksort using linked-lists

#include <iostream>
#include <ctime>

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

        tmp = tmp->next; //traversing linked list

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

    void qsort(node* head,node* tail){

        if(head!=tail){

		//here p is a pointer to the node that we call as the pivot           

            node *p =part(head,tail);
            
            qsort(head,p);

            qsort((p->next),tail);

        }

    }

};

int main(){
	
	linked_list ll1;

    clock_t bs,be,qs,qe; //clock_t is an arithmetic data type that measures clock ticks

    bubblesort c;

    quicksort d;

    int x,m;

    cout<<"Enter size of linked list : ";

    cin>>x;
    
    cout<<" Enter the elements of linked list : ";
	
	for(int i=0;i<x;i++){
		cout<<"node["<<i<<"]->data : ";
		cin>>m;
		ll1.insert(m);
		cout<<"\n";
	}
	
	//measuring the time taken for the bubble sort using linked-lists to run 
	
    bs = clock();

    c.sort(ll1.head);

    be = clock();

    double bt =(double) (be-bs)/CLOCKS_PER_SEC;

	//measuring the time taken for the quick sort using linked-lists to run 
	
    qs = clock();

    d.qsort(ll1.head,ll1.tail);

    qe = clock();

    double qt = (double)(qe-qs)/CLOCKS_PER_SEC;

    cout<<"Time taken for bubble sort is : "<<bt<<endl;

    cout<<"Time taken for quick sort is :  "<<qt<<endl; 

    return 0;

}
