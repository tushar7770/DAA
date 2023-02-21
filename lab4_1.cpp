//Implement Classical Bubble, Selection, Insertion Sort, Merge Sort, Heap Sort.
//team 21

#include<iostream>
#define size 100
using namespace std;

class Sorting
{
    public :
    //data members
    int array[size] , n ;
    
    //member functions
    void createArray();

    void bubbleSort();

    void selectionSort();

    void insertionSort();

    void mergeSort(int start , int end);
    void mergeArray(int start , int mid , int end);

    void heapSort();
    void heapify(int sizee , int i);
};

void Sorting::createArray()
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

void Sorting::bubbleSort()
{
    int temp;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < (n-1-i) ; j++)//after every iteration max will be at last so no need to check that
        {
            if(array[j] > array[j+1])//comparing element with next element
            {
                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
}

void Sorting::selectionSort()
{
    int max , pmax , i , j , temp;
    for(i=0; i<n; ++i) 
    {
        max = array[0];// assigning a[0] to max
        pmax=0;
        for(j=0; j<=(n-1-i); ++j) 
        {
            if(max < array[j]) //finding max
            {
                max = array[j];
                pmax = j;
            }  
        }
        //swap max with last element
        temp = array[pmax];
        array[pmax] = array[n-1-i];
        array[n-1-i] = temp;
    }
}

void Sorting::insertionSort()
{
    int i , j , temp;
    for(i=1 ; i<n ; i++)
    {
        temp = array[i];
        //comparing with all elements from 0 to i-1 to find appropriate location 
        for(j=i-1 ; j>=0 && array[j]>temp ; j--)
        {
            array[j+1]=array[j];//shifting to right
        }
        array[j+1]=temp;
    }
}

void Sorting::mergeSort(int start , int end)
{
    if(start<end)
    {
        int mid = start + (end-start)/2;

        mergeSort(start , mid);
        mergeSort(mid +1 , end);

        mergeArray(start , mid , end);
    }
    return;

}

void Sorting::mergeArray(int start , int mid , int end)
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

    return;
}

void Sorting::heapSort()
{
    for(int i = n/2-1 ; i>=0 ; i--)//created max heap
    {
        heapify(n,i);
    }
    
    for(int i = n-1 ; i>0 ; i--)//now removing root element and replacing it with last leave and again doing heapify
    {
        swap(array[0],array[i]);
        heapify(i,0);
    }


}

void Sorting::heapify(int sizee , int i)
{
    int max = i;
    int left = 2*i+1;//left child
    int right = 2*i+2;// right child

    if(left < sizee && array[left]>array[max])
    {
        max = left;//if leftchild value is greater than parent
    }

    if(right < sizee && array[right]>array[max])
    {
        max = right;//if rightchild value is greater than parent
    }

    if(max != i)//if parent index max is changed we will  swap
    {
        swap(array[i],array[max]);
        heapify(sizee , max);//now doing heapify to sawped root subtree
    }
}

int main()
{
    int i;
    Sorting b1 , s1 , i1 , m1 , h1;
    cout<<"\nBUBBLE SORT";
    b1.createArray();
    b1.bubbleSort();
    cout<<"\nSorted array : ";
    for(i=0 ; i<b1.n ; i++)
    {
        cout<<b1.array[i]<<" ";
    }

    cout<<"\n\nSELECTION SORT";
    s1.createArray();
    s1.selectionSort();
    cout<<"\nSorted array : ";
    for(i=0 ; i<s1.n ; i++)
    {
        cout<<s1.array[i]<<" ";
    }

    cout<<"\n\nINSERTION SORT";
    i1.createArray();
    i1.insertionSort();
    cout<<"\nSorted array : ";
    for(i=0 ; i<i1.n ; i++)
    {
        cout<<i1.array[i]<<" ";
    }

    cout<<"\n\nMERGE SORT";
    m1.createArray();
    m1.mergeSort(0,m1.n-1);
    cout<<"\nSorted array : ";
    for(i=0 ; i<m1.n ; i++)
    {
        cout<<m1.array[i]<<" ";
    }

    cout<<"\n\nHEAP SORT";
    h1.createArray();
    h1.heapSort();
    cout<<"\nSorted array : ";
    for(i=0 ; i<h1.n ; i++)
    {
        cout<<h1.array[i]<<" ";
    }
    return 0;
}

