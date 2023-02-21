//CS20B1098 TUSHAR PANJETA
//DYNAMIC PROGRAMMING FOR MATRIX CHAIN MULTIPLICATION

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
    int output[n-1][n-1];
    int d = n-1;
 
    int i, j, k, g;
  
    for (g = 0; g < d; g++)
    {
        for (i = 0,j = g; j < d; i++,j++)
        {
            if(g==0)
            {
                output[i][j]=0;
            }
            else if(g==1)
            {
                output[i][j]= array[i]*array[j]*array[j+1];
            }
            else
            {
                int min=INT_MAX;
                for(k=i;k<j;k++)
                {
                    int cost1 = output[i][k];
                    int cost2 = output[k+1][j];
                    int cost3 = array[i]*array[k+1]*array[j+1];
                    int total = cost1+cost2+cost3;

                    if(total<min)
                    {
                        min=total;
                    }
                }
                output[i][j]=min;
            }
            
        }
    }
    return output[0][d-1];
}

int main()
{
    
    matrix m1;
    m1.createArray();

    cout<<"\nMin Multiplications : ";
    int x = m1.matrixMul();
    cout<<x;
    
    return 0;
}