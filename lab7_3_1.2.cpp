//TUSHAR PANNJETA CS20B1098
//FUNCTION TEMPLATE FOR FIND MAX AND MIN IN MINIMUM NO. OF COMPARISIONS
#include<iostream>
using namespace std;

template<typename T>
T* findMinMax(T arr[], int n)
{
    T max, min;
    int i;
    if (n%2==1)
    {
        max = arr[0];
        min = arr[0];
        i = 1;
    }
    else
    {
        if ( arr[0] < arr[1] )
        {
            max = arr[1];
            min = arr[0];
        }
        else
        {
            max = arr[0];
            min = arr[1];
        }
        i = 2;
    }
    while ( i < n )
    {
        if ( arr[i] < arr[i+1] )
        {
            if ( arr[i] < min )
                min = arr[i];
            if ( arr[i+1] > max )
                max = arr[i+1];
        }
        else
        {
            if ( arr[i] > max )
                max = arr[i];
            if ( arr[i+1] < min )
                min = arr[i+1];
        }
        i = i + 2;
    }

    T *output = new T[2];
    output[0]=max;
    output[1]=min;
   return output;
}

int main()
{
    int n,choice;
    cout<<"\nEnter the no.of elements : ";
    cin>>n;

    int a1[n];
    double a2[n];
    char a3[n];
     
    cout<<"\nEnter "<<n<<" integer values : ";
    for(int i=0;i<n;i++)
    {
        cin>>a1[i];
    }

    int*o1=findMinMax<int>(a1,n);
    cout<<"\nMAX : "<<o1[0]<<"  MIN : "<<o1[1]<<"\n";


    cout<<"\nEnter "<<n<<" double values: ";
    for(int i=0;i<n;i++)
    {
        cin>>a2[i];
    }
    double*o2=findMinMax<double>(a2,n);
    cout<<"\nMAX : "<<o2[0]<<"  MIN : "<<o2[1]<<"\n";


    cout<<"\nEnter "<<n<<" char values : ";
    for(int i=0;i<n;i++)
    {
        cin>>a3[i];
    }
    char*o3=findMinMax<char>(a3,n);
    cout<<"\nMAX : "<<o3[0]<<"  MIN : "<<o3[1]<<"\n";

    return 0;
}