//Program to check that there is a Triplet in array such that sum equals to given integer
#include<iostream>
using namespace std;

class Array 
{

    public:

        //member variables
        int arr[100], left, right, size;

        //member functions

        //function to create array creating array
        void createArray() 
        {
            cout<<"\nEnter the Size of Array : ";
            cin>>size;

            while(size<1) // size should be >=1
            {
                cout<<"\n[ERROR] Invalid size ##try again##";
                cout<<"\nEnter size of array : ";
                cin>>size;   
            }

            cout<<"\nEnter the Elements of Array : ";
            for(int i=0; i<size; ++i) 
            {
                cin>>arr[i];
            }
        }

        //declaring function to sort array in acending order
        void sortArray();

        //declaring function to check that there is a Triplet in array
        void findTriplets(int sum);
};

//selection sort
void Array::sortArray() 
{
    int max , pmax , i , j , temp;
    for(i=0; i<size; ++i) 
    {
        max = arr[0];
        pmax=0;
        for(j=0; j<=(size-1-i); ++j) 
        {
            if(max < arr[j]) 
            {
                max = arr[j];
                pmax = j;
            }  
        }
        temp = arr[pmax];
        arr[pmax] = arr[size-1-i];
        arr[size-1-i] = temp;
    }
}

//function to check that there is a Triplet in array
void Array::findTriplets(int sum) 
{
    for(int i=0; i<size-2; ++i) 
    {
        right = size-1;
        left = i+1;
        while(left < right) 
        {
            if(arr[i] + arr[left] + arr[right] == sum) 
            {
                cout<<"\nYes there exist a triplet such that sum of elements is "<<sum;
                //cout<<"\nTriplet :- {" <<arr[i]<<" , "<<arr[left]<<" , "<<arr[right]<<"}"<<endl;
                return ;
            }
            else if(arr[i] + arr[left] + arr[right] < sum) 
            {
                left++;
            }
            else 
            {
                right--;
            }
        }
    }
    cout<<"There is NO triplet possible whose sum is "<<sum<<"."<<endl;

}

int main() 
{
    Array array;
    array.createArray();

    int sum;
    cout<<"\nEnter an Integer : ";
    cin>>sum;

    array.sortArray();

    array.findTriplets(sum);

    return 0;
}