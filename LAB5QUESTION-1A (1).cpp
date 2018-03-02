//bubblesort on arrays

#include<iostream>

using namespace std;

//declaring a class bubblesort containing sort function

class bubblesort{

    public:

    void sort(int arr[], int l){
    	int temp;
	
	//declaring two loops to swap the array elements to place them in an ascending order
	
    for(int i=0;i<l;i++){ 

    for(int j=0;j<(l-i-1);j++){

    if(arr[j]>arr[j+1]){
	
	//declaring temp as an integer that holds the value of a[j+1]th array element to swap the values of a[j] and a[j+1] array element
	 
    temp = arr[j+1];

    arr[j+1] = arr[j];

	arr[j] = temp;

    }

	}

	}

    }

};



int main(){
	//declaring a class component c belonging to class bubblesort
	
	bubblesort c;
	
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
	//calling the sort function
    c.sort(arr,a);
    
	cout<<"The sorted array is : ";
	
    for(int i=0;i<a;i++){

        cout<<"\t---------"<<arr[i];

    }

    return 0;

}
