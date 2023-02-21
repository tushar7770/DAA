//INSERSTION VARIANT USING BINARY SEARCH
//team21

#include<iostream>
#define size 100
using namespace std;

class Sort
{
     public :
    //data members
    int array[size] , n ;
    
    //member functions
    void createArray();

    void insertionSort();

    int binarySearch(int search , int left ,int right );


};

void Sort::createArray()
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

void Sort::insertionSort()
{
    int i , j , temp , poistion;
    for(i=1 ; i<n ; i++)
    {
        j = i-1;
        temp = array[i];

        poistion = binarySearch(temp , 0 , j);//getting poistion using binary search

        while(j>=poistion)//while we reach that poistion shift every element one step further
        {
            array[j+1]=array[j];
            j--;
        }

        array[j+1]=temp;
    }
}

int Sort::binarySearch(int search , int left ,int right )
{
    if(right <= left)
    {
        if(search>array[left])
        {
            return left+1;
        }
        else
        {
            return left;
        }
    }
    
    int mid=left+(right-left)/2;

    if((array[mid]) == search)
    {
        return mid+1;
    }

    else if((array[mid]) > search)
    {
        return binarySearch( search , left , mid-1);
    }

    else
    {
        return binarySearch( search , mid+1 , right);
    }
}

int main()
{
    int i;
    Sort i1;

    cout<<"\n\nINSERTION SORT";
    i1.createArray();
    i1.insertionSort();
    cout<<"\nSorted array : ";
    for(i=0 ; i<i1.n ; i++)
    {
        cout<<i1.array[i]<<" ";
    }

    return 0;
}