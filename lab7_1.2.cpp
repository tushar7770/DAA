//CS20B1098 TUSHAR PANJETA
//0-1 KNAPSACK to maximize profit

#include<iostream>
using namespace std;

class knapsack01
{
    public :
    int w,p;

    void heapSort(knapsack01 k[],int n);
    void heapify(knapsack01 k[],int sizee , int i);

    int profit(knapsack01 k[],int n,int m);

};

void knapsack01::heapSort(knapsack01 k[],int n)
{
    for(int i = n/2-1 ; i>=0 ; i--)
    {
        heapify(k,n,i);
    }
    
    for(int i = n-1 ; i>0 ; i--)
    {
        swap(k[0].w,k[i].w);
        swap(k[0].p,k[i].p);
        heapify(k,i,0);
    }


}

void knapsack01::heapify(knapsack01 k[],int sizee , int i)
{
    int max = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < sizee && k[left].w>k[max].w)
    {
       max = left;
    }

    if(right < sizee && k[right].w>k[max].w)
    {
       max = right;
    }

    if(max != i)
    {
        swap(k[i].w,k[max].w);
        swap(k[i].p,k[max].p);
        heapify(k,sizee ,max);
    }
}

int knapsack01::profit(knapsack01 k[],int n,int W)
{
    int output[n+1][W+1];
    int include , notInclude;

    for(int i=0;i<=n;i++)
    {
        output[i][0]=0;
    }
    for(int j=0;j<=W;j++)
    {
        output[0][j]=0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            notInclude = output[i-1][j];
            if(k[i-1].w <= j)
            {
                include = k[i-1].p + output[i-1][j-k[i-1].w];
                output[i][j]= include >= notInclude? include:notInclude;
            }
            else
            {
                output[i][j]=notInclude;
            } 
        }
    }
    
    return output[n][W];
}

int main()
{
    int temp,m;

    cout<<"\nEnter the capacity of bag : ";
    cin>>m;

    cout<<"\nEnter the no. of items : ";
    cin>>temp;

    knapsack01 k1[temp];

    int i;

    cout<<"\nEnter the weight of "<<temp<<" items : ";
    for(i=0;i<temp;i++)
    {
        cin>>k1[i].w;
    }
 
    cout<<"\nEnter the profit of respective weights : ";
    for(i=0;i<temp;i++)
    {
        cin>>k1[i].p;
    }
    k1[0].heapSort(k1,temp);

    cout<<"\nMax profit : "<<k1[0].profit(k1,temp,m);

    return 0;
}
