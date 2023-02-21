//CS20B1098 TUSHAR PANJETA
//GREEDY STRATEGY FOR MATRIX CHAIN MULTIPLICATION

#include<iostream>
#define size 100
using namespace std;

class matrix
{
    public :
    int array[size],n;

    void createArray();

    int matrixMul();
};

void matrix::createArray()
{
    cout<<"\nEnter no. matrices : ";
    cin>>n;
    while(n<2)
    {
        cout<<"\n[ERROR] Invalid input , TRY AGAIN";
        cout<<"\nEnter no of matrices : ";
        cin>>n;
    }
    n=n+1;

    cout<<"\nEnter the chain of " <<n-1<<" matrices : ";
    for(int i=0 ; i<n ;i++)
    {
        cin>>array[i];
    }
}



int matrix::matrixMul()
{
    int i,product,temp,min=INT_MAX,p;
    if(n==3)
    {   
        product = array[0]*array[1]*array[2]; 
        
    }
    else
    {
        for(i=2;i<n;i++)
        {
            temp = array[i]*array[i-2];
            if(temp<min)
            {
                min=temp;
                p=i-1;
            }
            temp++;
        }
        product = array[p-1]*array[p]*array[p+1];

        for(i=p;i<n-1;i++)
        {
            array[i]=array[i+1];
        }
        n=n-1;
    }
    return product;
}

int main()
{
    int ptotal=0,x;
    matrix m1;
    m1.createArray();
    x=m1.n;
    for(int i=2;i<x;i++)
    {
       ptotal = ptotal +  m1.matrixMul();
       
    }

    cout<<"\nMultiplications : "<<ptotal;
    

    return 0;
}