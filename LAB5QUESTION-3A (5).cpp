//programme to compare running time of bubblesort and quicksort using arrays

#include<iostream>
#include <ctime>

using namespace std;

//declaring a class bubblesort containing sort function

class bubblesort{

    public:

    void sort(int a[], int l){
    	
    	int temp;
    	
    	//declaring two loops to swap the array elements to place them in an ascending order

        for(int i=0;i<l;i++){

            for(int j=0;j<(l-i-1);j++){

                if(a[j]>a[j+1]){

                    temp = a[j+1];

                    a[j+1] = a[j];

                    a[j] = temp;

                }

            }

        }

    }

};

//declaring a class quicksort that sort the elements of an array in ascending order

class quicksort{

    public:

	//declaring a function partition that will separate and then merge array elements in ascending order
	
    int part(int arr[],int low,int high){
    	
    		/*declaring a pivot as the last array element,all elements lower than the pivot will be on the 
	left of the pivot while all elements greater than it will be on the right*/ 

         int pivot = arr[high];   

        int i = (low - 1);  
        
 //traversing the array and swapping elements in ascending order using a loop

        for (int j = low; j <= high- 1; j++)

        {

         if (arr[j] <= pivot)

            {

                i++;

                int t=arr[i];

                arr[i]=arr[j];

                arr[j]=t;

         }

     }

                int t=arr[i+1];

                arr[i+1]=arr[high];

                arr[high]=t;

    return (i + 1);

}

//declaring the sort function that will recursively call the partition function until all the elements are separated and then merged
//in ascending order

    void qsort(int a[],int l, int h){

        if(l<h){

            int p=part(a,l,h); //here p a data-type of type integer that holds the value of the partition

            qsort(a,l,(p-1));

            qsort(a,(p+1),h); 

        }

    }

};





int main(){
	
	bubblesort c;

    quicksort d;
    
	//clock_t is an arithmetic data type that measures clock ticks
	
    clock_t bs,be,qs,qe;

  	int a;
	cout<<"Enter the size of the array : ";
	cin>>a;
	int arr[a];
	cout<<"Enter The Array Elements : ";
	
	for(int i=0;i<a;i++){
		cout<<"arr["<<i<<"] : ";
		cin>>arr[i];
		cout<<"\n";
	}

	//measuring the time taken for the bubble sort using arrays to run 
	
    bs = clock();

    c.sort(arr,a);

    be = clock();
    
    double bt =(double) (be-bs)/CLOCKS_PER_SEC; //measuring time in seconds and returning the value as float
    
    //measuring the time taken for quick-sort using arrays to run

     qs = clock();

     d.qsort(arr,0,a-1);

     qe = clock();

	
	
     double qt = (double)(qe-qs)/CLOCKS_PER_SEC;
     

    cout<<"Time taken for bubble sort is : "<<bt<<endl;

    cout<<"Time taken for quick sort is : "<<qt<<endl; 

    return 0;

}
