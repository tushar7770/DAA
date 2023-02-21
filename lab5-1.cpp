//CS20B1098 TUSHAR PANJETA
//Hybrid Sorting
//team 21
#include<iostream>
#include<ctime>
#define size 1500
using namespace std;

class HybridSort
{
    public :
    int array[size] , n ;

    void createArray();

    void insertionSort(int start,int end);

    void mergeSort(int start , int end);
    void mergeArray(int start , int mid , int end);

};

void HybridSort::createArray()
{
    cout<<"\nEnter no. of elements in array : ";
    cin>>n;
    while(n<=0)
    {
        cout<<"\n[ERROR] Invalid input , TRY AGAIN";
        cout<<"\nEnter no. of elements in array : ";
        cin>>n;
    }

    srand(time(0));
    for(int i=0; i<n; ++i) 
    {
        array[i] = rand()%1000 ;
        cout << array[i] <<" ";
    }
    cout << endl;
}

void HybridSort::insertionSort(int start,int end)
{
    int i , j , temp;
    for(i=start ; i<=end ; i++)
    {
        temp = array[i];
        for(j=i-1 ; j>=0 && array[j]>temp ; j--)
        {
            array[j+1]=array[j];
        }
        array[j+1]=temp;
    }
}

void HybridSort::mergeSort(int start , int end)
{
    int mid = start + (end-start)/2;

    if(start >= end)
    {
        return; // returns recursively
    }
    else if(end-start <= 20) // if the array size gets less than or equal to 20 then insertion sort
    { 
        insertionSort(start, end);
    }
    else // if the array size > 20 then perform merge sort
    { 
        mergeSort(start, mid);
        mergeSort(mid + 1, end);
    }
    // merging the all subarrays
    mergeArray(start, mid, end);

}

void HybridSort::mergeArray(int start , int mid , int end)
{
    int i , j ,k;
    int size1 = mid-start+1;
    int size2 = end-mid;
    int a1[size1] , a2[size2];

    for(i=0;i<size1;i++)
    {
        a1[i]=array[start+i];
    }

    for(i=0;i<size2;i++)
    {
        a2[i]=array[mid+1+i];
    }

    i=0,j=0,k=start;
    while(i<size1 && j<size2)
    {
        if(a1[i]<=a2[j])
        {
            array[k]=a1[i];
            i++;
        }
        else
        {
            array[k]=a2[j];
            j++;
        }
        k++;
    }
    while(i<size1)
    {
        array[k]=a1[i];
        i++;
        k++;
    }
    while(j<size2)
    {
        array[k]=a2[j];
        j++;
        k++;
    }
}

int main()
{
    int i;
    HybridSort h1;
    h1.createArray();
    h1.mergeSort(0,h1.n-1);

    cout<<"\nSorted array : ";
    for(i=0 ; i<h1.n ; i++)
    {
        cout<<h1.array[i]<<" ";
    }
    return 0;
}