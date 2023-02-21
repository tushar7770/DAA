//CS20B1098 TUSHAR PANJETA
//greedy approach for 0-1 KNAPSACK to maximize profit with all items having same profit

#include<iostream>
using namespace std;

class knapsack01
{
    public :
    int w;

    void heapSort(knapsack01 k[],int n);
    void heapify(knapsack01 k[],int sizee , int i);

    int profit(knapsack01 k[],int n,int m,int p);

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
        heapify(k,sizee ,max);
    }
}

int knapsack01::profit(knapsack01 k[],int n,int m,int p)
{
    int totalProfit=0,totalWeight=0;

    for(int i=0;i<n;i++)
    {
        totalWeight+=k[i].w;
        if(totalWeight<=m)
        {
            totalProfit+=p; 
        }
        else
        {
            break; 
        }
    }
    return totalProfit;
}

int main()
{
    int temp,m;

    cout<<"\nEnter the capacity of bag : ";
    cin>>m;

    cout<<"\nEnter the no. of items : ";
    cin>>temp;

    knapsack01 k1[temp];

    int p;
    cout<<"\nEnter the profit of items : ";
    cin>>p;
    
 
    cout<<"\nEnter the weight of "<<temp<<" items : ";
    for(int i=0;i<temp;i++)
    {
        cin>>k1[i].w;
    }
    k1[0].heapSort(k1,temp);
    
    cout<<"\n profit : "<<k1[0].profit(k1,temp,m,p);

    return 0;
}