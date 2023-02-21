//CS20B1098 TUSHAR PANJETA
//greedy approach for 0-1 KNAPSACK to maximize profit having all items of same weight

#include<iostream>
using namespace std;

class knapsack01
{
    public :
    int p;

    void heapSort(knapsack01 k[],int n);
    void heapify(knapsack01 k[],int sizee , int i);

    int profit(knapsack01 k[],int n,int m,int w);

};

void knapsack01::heapSort(knapsack01 k[],int n)
{
    for(int i = n/2-1 ; i>=0 ; i--)
    {
        heapify(k,n,i);
    }
    
    for(int i = n-1 ; i>0 ; i--)
    {
        swap(k[0].p,k[i].p);
        heapify(k,i,0);
    }


}

void knapsack01::heapify(knapsack01 k[],int sizee , int i)
{
    int min = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < sizee && k[left].p<k[min].p)
    {
       min = left;
    }

    if(right < sizee && k[right].p<k[min].p)
    {
       min = right;
    }

    if(min != i)
    {
        swap(k[i].p,k[min].p);
        heapify(k,sizee ,min);
    }
}

int knapsack01::profit(knapsack01 k[],int n,int m,int w)
{
    int totalProfit=0,totalWeight=0;

    for(int i=0;i<n;i++)
    {
        totalWeight+=w;
        if(totalWeight<=m)
        {
            totalProfit+=k[i].p; 
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

    int w;
    cout<<"\nEnter the weight of items : ";
    cin>>w;
    
 
    cout<<"\nEnter the profit of "<<temp<<" items : ";
    for(int i=0;i<temp;i++)
    {
        cin>>k1[i].p;
    }
    k1[0].heapSort(k1,temp);

    cout<<"\n profit : "<<k1[0].profit(k1,temp,m,w);

    return 0;
}