//CS20B1098 TUSHAR PANJETA
//FRACTIONAL KNAPSACK to maximize profit

#include<iostream>
using namespace std;

class frKnapsack
{
    public :
    int w,p;
    float ratio;

    void heapSort(frKnapsack fk[],int n);
    void heapify(frKnapsack fk[],int sizee , int i);

    float profit(frKnapsack fk[],int n,int m);

};

void frKnapsack::heapSort(frKnapsack fk[],int n)
{
    for(int i = n/2-1 ; i>=0 ; i--)
    {
        heapify(fk,n,i);
    }
    
    for(int i = n-1 ; i>0 ; i--)
    {
        swap(fk[0].ratio,fk[i].ratio);
        swap(fk[0].w,fk[i].w);
        swap(fk[0].p,fk[i].p);
        heapify(fk,i,0);
    }


}

void frKnapsack::heapify(frKnapsack fk[],int sizee , int i)
{
    int min = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < sizee && fk[left].ratio<fk[min].ratio)
    {
       min = left;
    }

    if(right < sizee && fk[right].ratio<fk[min].ratio)
    {
       min = right;
    }

    if(min != i)
    {
        swap(fk[i].ratio,fk[min].ratio);
        swap(fk[i].w,fk[min].w);
        swap(fk[i].p,fk[min].p);
        heapify(fk,sizee ,min);
    }
}

float frKnapsack::profit(frKnapsack fk[],int n,int m)
{
    float total=0.0;
    int i;
    for(i=0;i<n;i++)
    {
        if(m>0)
        {
            if(fk[i].w < m)
            {
                total = total+fk[i].p;
                m = m - fk[i].w;
            }
            else
            {
                total = total + (m*1.0/fk[i].w)*fk[i].p;
                return total;
            }
        }
        else
        {
            break;
        }
    }
    return total;
}

int main()
{
    int temp,m;

    cout<<"\nEnter the capacity of bag : ";
    cin>>m;

    cout<<"\nEnter the no. of items : ";
    cin>>temp;

    frKnapsack fk1[temp];

    int i;

    cout<<"\nEnter the weight of "<<temp<<" items : ";
    for(i=0;i<temp;i++)
    {
        cin>>fk1[i].w;
    }
 
    cout<<"\nEnter the profit of respective weights : ";
    for(i=0;i<temp;i++)
    {
        cin>>fk1[i].p;
        fk1[i].ratio = fk1[i].p*1.0/fk1[i].w*1.0;
    }

    fk1[0].heapSort(fk1,temp);

    cout<<"\nTotal profit : "<<fk1[0].profit(fk1,temp,m);

    return 0;
}
