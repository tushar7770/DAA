//Program to find the sum of subarrays
#include<iostream>
using namespace std;

class Array 
{
    private:
        //member variables
        int array[100], size;
    
    public:
        //member functions

        //function to create array
        void createArray() 
        {
            cout<<"Enter the Size of Array : ";
            cin>>size;

            while(size<1) // size should be >=1
            {
                cout<<"\n[ERROR] Invalid size ##try again##";
                cout<<"\nEnter size of array : ";
                cin>>size;   
            }

            cout<<"Enter the Elements of Array : ";
            for(int i=0; i<size; ++i) 
            {
                cin>>array[i];
            }
        }
         
        //function to find sum of sub arrays 
        void sumOfSumArray() 
        {
            int sum = 0;
            for(int i=0; i<size; ++i) 
            {
                sum += array[i] * (i + 1) * (size - i);
            }
            cout<<"Sum of the Sub Arrays : "<<sum<<endl;
        }
};

int main() 
{
    Array arr;
    arr.createArray();
    arr.sumOfSumArray();

    return 0;
}