//Program to find number of negative elements in array using 2 way and 3 way approach
//team 21
#include<iostream>
#define size 100
using namespace std;

class negative
{
    public :
    //data members
    int numberOfNegatives , array[size] , n;
    
    //member functions

    //function to create array
    negative()
    {
        numberOfNegatives = 0;
    }
    inline void createArray()
    {
        cout<<"\nEnter no. of elements in array : ";
        cin>>n;
        while(n<=0)
        {
            cout<<"\n[ERROR] Invalid input , TRY AGAIN";
            cout<<"\nEnter no. of elements in array : ";
            cin>>n;
        }

        cout<<"\nEnter the "<<n<<" elements : ";
        for(int i=0 ; i<n ;i++)
        {
            cin>>array[i];
        }
    }

    //declartion of function to find negative numbers using 2 way approach
    int findNegativesBy2Way(int array[], int start, int end);

    //declartion of function to find negative number using 3 way approach
    int findNegativesBy3Way(int array[], int start, int end);

};

//function to find negative numbers using 2 way approach
int negative::findNegativesBy2Way(int array[], int start, int end) 
{
    if(start > end)
   {
       return 0;
   }
    //if the array contains only one element
    if(start==end) {
        if(array[start] < 0) {
           return 1;
        }
        return 0;
    }

    int mid = (start + end)/2;
    return findNegativesBy2Way(array, start, mid) + findNegativesBy2Way(array, mid+1, end);
}

//function to find negative numbers using 3 way approach
int negative::findNegativesBy3Way(int array[], int start, int end) 
{

   if(start > end)
   {
       return 0;
   }
    //if the array contains only one element
    if(start==end) 
    {
        if(array[start] < 0) 
        {
            return 1;
        }
        return 0;
    }

    int mid1 = start + (end - start)/3;
    int mid2 = start + 2*(end - start)/3;
    return (findNegativesBy3Way(array, start, mid1) + findNegativesBy3Way(array, mid1+1, mid2) + findNegativesBy3Way(array, mid2+1, end));
   
}

int main() 
{
    negative Neg ; 

    Neg.createArray();

    Neg.numberOfNegatives = Neg.findNegativesBy2Way(Neg.array, 0, Neg.n-1);
    cout<<"\nNumber of Negative Elements by 2 way = "<<Neg.numberOfNegatives<<endl;

    Neg.numberOfNegatives = 0;
    
    Neg.numberOfNegatives = Neg.findNegativesBy3Way(Neg.array, 0, Neg.n-1);
    cout<<"\nNumber of Negative Elements by 3 way = "<<Neg.numberOfNegatives<<endl;

    return 0;
}