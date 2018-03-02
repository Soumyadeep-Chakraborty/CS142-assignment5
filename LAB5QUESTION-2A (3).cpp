//quick-sort on arrays

#include<iostream>
using namespace std;
//declaring a class quicksort that sort the elements of an array in ascending order

class quicksort{

    public:
	
	//declaring a function partition that will separate and then merge array elements in ascending order
	
    int part(int arr[],int low,int high){
    	int temp;
    	
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

                temp=arr[i];

                arr[i]=arr[j];

                arr[j]=temp;

         }

     }

                int t=arr[i+1];

                arr[i+1]=arr[high];

                arr[high]=t;

    return (i + 1);

}


//declaring the sort function that will recursively call the partition function until all the elements are separated and then merged
//in ascending order

    void sort(int a[],int l, int h){

        if(l<h){

            int p=part(a,l,h);

            sort(a,l,(p-1));

            sort(a,(p+1),h); 

        }

    }

};



int main(){

    	//declaring a class component c belonging to class quicksort
	
	quicksort c;
	
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

    c.sort(arr,0,a-1);

    for(int i=0;i<a;i++){

        cout<<arr[i];

    }

    return 0;

}
