//Program to Find MAX using 1-way, 2-way, 3-way, k-way approach
//team 21
#include<iostream>
#define size 100
using namespace std;

class Max
{
    public :
    //data members
    int max , array[size] , n , k;
    
    //member functions

    //function to create array
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

    //declartion of function to find max using 1 way approach
    void maxBy1Way();

    //declartion of function to find max using 2 way approach
    void maxBy2Way(int array[] , int start, int end);

    //declartion of function to find max using 3 way approach
    void maxby3way(int array[], int start, int end);

    //declartion of function to find max using k way approach
    void maxbyKway(int array[], int start , int end);

};

//function to find max using 1 way approach
void Max::maxBy1Way()
 {
    //linear traversal
    for (int i = 0; i < n; i++)
    {
        if(array[i] > max) {
            max = array[i];
        }
    }
}

//function to find max using 2 way approach
void Max::maxBy2Way(int array[], int start, int end) 
{
    if(start > end)
    {
        return;
    }
    //if array contains only one element
    if(start == end) {
        if(max < array[start]) {
            max = array[start];
        }
        return;
    }

    //if the array contains only two elements
    if(end-start == 1) {
        if(array[start] < array[end]) {
            if (max < array[end]) {    
                max = array[end];
            }
        }
        else { 
            if(max < array[start]) {     
                max = array[start];
            }
        }
        return;
    }

    int mid = (start + end)/2;
    maxBy2Way(array, start, mid );
    maxBy2Way(array, mid+1, end);
}

//function to find max using 3 way approach
void Max::maxby3way(int array[], int start, int end) 
{
    if(start > end)
    {
        return;
    }
    //if the array contains only one elements
    if(start == end) {
        if(max < array[start]) {
            max = array[start];
        }
        return;
    }

    //if the array contains only two elements
    if(end-start == 1) 
    {
        if(array[start] < array[end]) 
        {
            if (max < array[end]) 
            {    
                max = array[end];
            }
        }
        else 
        { 
            if(max < array[start]) 
            {     
                max = array[start];
            }
        }
        return;
    }

    int mid1 = start + (end - start)/3;
    int mid2 = start + 2*(end - start)/3;
    maxby3way(array, start, mid1);
    maxby3way(array, mid1+1, mid2);
    maxby3way(array, mid2+1, end);
}

void Max::maxbyKway(int array[], int start , int end)
{
    if(start > end)
    {
        return;
    }
     //if the array contains only one elements
    if(start == end) {
        if(max < array[start]) {
            max = array[start];
        }
        return;
    }

    //if the array contains only two elements
    if(end-start == 1) 
    {
        if(array[start] < array[end]) 
        {
            if (max < array[end]) 
            {    
                max = array[end];
            }
        }
        else 
        { 
            if(max < array[start]) 
            {     
                max = array[start];
            }
        }
        return;
    }
    
    int i , mid[k-1];
    for(i=0 ; i<(k-1) ; i++)
    {
        mid[i] = start + (i+1)*(end - start)/k ;
        cout<<"\n mid"<<i+1<<" = "<<mid[i];
    }

    maxbyKway(array, start , mid[0]);
    for(i=0 ; i<(k-2) ; i++)
    {
        maxbyKway(array, mid[i]+1 , mid[i+1]);
    }
    maxbyKway(array, mid[k-2]+1 , end);

}

int main() 
{
    Max m1;

    m1.createArray();
    cout<<"\nEnter the value of K for kway : ";
    cin>>m1.k;

    m1.max=INT_MIN;
    m1.maxBy1Way();
    cout<<"Max using 1 way approach = "<<m1.max<<endl;

    m1.max=INT_MIN;
    m1.maxBy2Way(m1.array, 0, m1.n-1);
    cout<<"Max using 2 way approach = "<<m1.max<<endl;

    m1.max=INT_MIN;
    m1.maxby3way(m1.array, 0, m1.n-1);
    cout<<"Max using 3 way approach = "<<m1.max<<endl;

    m1.max=INT_MIN;
    m1.maxbyKway(m1.array, 0, m1.n-1);
    cout<<"Max using k way approach = "<<m1.max<<endl;


    return 0;    
}