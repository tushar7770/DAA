//iterative and recursive algorithm for binary and ternary search
//team 21

#include<iostream>
#define size 100
using namespace std;

class binarySearch
{
    public :
    //data members
    int search , array[size] , n;
    
    //member functions

    //function to create array
    inline void createArray()
    {
        cout<<"\nEnter no. of elements in array : ";
        cin>>n;
        while(n<0)
        {
            cout<<"[\nERROR] Invalid input , TRY AGAIN";
            cout<<"\nEnter no. of elements in array : ";
            cin>>n;
        }

        cout<<"\nEnter the "<<n<<" elements : ";
        for(int i=0 ; i<n ;i++)
        {
            cin>>array[i];
        }
    }
      
    //declartion of function to sort array  
    void sortArray();

    //declartion of function for iterative binary search
    void iterativeBinarySearch();

    //declation of function for recursive binary search
    int recursiveBinarySearch(int arr[] , int search , int left ,int right);

};

//function for sorting array using selection sort
void binarySearch::sortArray()
{
    int max , pmax , i , j , temp;
    for(i=0; i<n; ++i) 
    {
        max = array[0];
        pmax=0;
        for(j=0; j<=(n-1-i); ++j) 
        {
            if(max < array[j]) 
            {
                max = array[j];
                pmax = j;
            }  
        }
        temp = array[pmax];
        array[pmax] = array[n-1-i];
        array[n-1-i] = temp;
    }
}

//function for iterative binary search
void binarySearch::iterativeBinarySearch()
{
    int left = 0 , right = n-1 ;

    while(right > left)
    {
        int mid = (left+right)/2;

        if(array[mid] >= search)
        {
            right = mid;
        }
        else
        {
            left = mid+1;
        }
    }

    if(array[left] == search)
    {
        cout<<"\n"<<search<<" is FOUND at index "<<left<<" of sorted array\n";
    }
    else
    {
        cout<<"\n"<<search<<" NOT FOUND\n";
    }
}

//function for recursive binary search
int binarySearch::recursiveBinarySearch(int arr[] , int search , int left ,int right )
{
    int mid ;

    if(right >= left)
    {
        mid=(left+right)/2;
    
        if((arr[mid]) == search)
        {
            return mid;
        }

        else if((arr[mid]) > search)
        {
            return recursiveBinarySearch(arr , search , left , mid-1);
        }

        else
        return recursiveBinarySearch(arr , search , mid+1 , right);
    }
    return -1;
}

class ternarySearch
{
    public :
    //data members
    int search , array[size] , n;
    
    //member functions

    //declation of function for iterative ternary search
    int iterativeTernarySearch();

    //declartion of function for recursive ternary search
    int recursiveTernarySearch(int arr[] , int search , int left , int right);

};

//function for iterative ternary search
int ternarySearch::iterativeTernarySearch()
{
    int left = 0 , right = n-1;
    while(left <= right) 
    {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
 
        if (array[mid1] == search) 
        {
            return mid1;
        }
        if (array[mid2] == search) 
        {
            return mid2;
        }
 
        if (search < array[mid1]) 
        {
            right = mid1-1;
        }
        else if (search > array[mid2]) 
        {
            left = mid2+1;
        }
        else 
        {
            left = mid1+1 ;
            right = mid2-1 ;
        }
    }
 
    return -1;

}

//function for recursive binary search
int ternarySearch::recursiveTernarySearch(int arr[] , int search , int left , int right)
{

    if (left <= right) 
    {
        int mid1 = left + (right - left) / 3;
        int mid2 = left + 2*(right - left) / 3;
 
        if (arr[mid1] == search) 
        {
            return mid1;
        }
        if (arr[mid2] == search) 
        {
            return mid2;
        }
 
        if (search < arr[mid1]) 
        {
            return recursiveTernarySearch(arr , search , left , mid1-1);
        }
        else if (search > arr[mid2]) 
        {
            return recursiveTernarySearch(arr , search , mid2+1 , right);
        }
        else 
        {
            recursiveTernarySearch(arr , search , mid1+1 , mid2-1);
        }
    }
 
    return -1;
}



int main()
{
    int ans;

    binarySearch bS ;
    ternarySearch tS;

    bS.createArray();
    bS.sortArray();
    
    for(int i=0 ; i<bS.n ; i++)
    {
        tS.array[i] = bS.array[i] ;
    }
    tS.n = bS.n;

    cout<<"\nEnter element you want to search : ";
    cin>>bS.search;
    tS.search = bS.search;
 
    cout<<"\nBINARY SEARCH USING ITERATION";
    bS.iterativeBinarySearch();
     
    cout<<"\nBINARY SEARCH USING RECURSION"; 
    ans = bS.recursiveBinarySearch(bS.array , bS.search , 0 , bS.n-1);
    if(ans == -1)
    {
        cout<<"\n"<<bS.search<<" NOT FOUND\n";
    }
    else
    {
        cout<<"\n"<<bS.search<<" is FOUND at index " <<ans<<" of sorted array\n";
    }

    cout<<"\nTERNARY SEARCH USING ITRATION";
    ans = tS.iterativeTernarySearch();
    if(ans == -1)
    {
        cout<<"\n"<<tS.search<<" NOT FOUND\n";
    }
    else
    {
        cout<<"\n"<<tS.search<<" is FOUND at index " <<ans<<" of sorted array\n";
    }

    cout<<"\nTERNARY SEARCH USING RECURSION";
    ans = tS.recursiveTernarySearch(tS.array , tS.search , 0 , tS.n-1);
    if(ans == -1)
    {
        cout<<"\n"<<tS.search<<" NOT FOUND\n";
    }
    else
    {
        cout<<"\n"<<tS.search<<" is FOUND at index " <<ans<<" of sorted array\n";
    }


    return 0;
}