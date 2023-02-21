//CS20B1098 TUSHAR PANJETA
//GREEDY ALGO FOR COIN CHANGE

#include<iostream>
#define size 100
using namespace std;

class coinChange
{
    public :
    int n , array[size] , amt, output[size],temp;

    void createArray();

    void heapSort();
    void heapify(int sizee , int i);

    void coins();

};

void coinChange::createArray()
{
    cout<<"\nEnter no. of denominations : ";
    cin>>n;
    while(n<=0)
    {
        cout<<"\n[ERROR] Invalid input , TRY AGAIN";
        cout<<"\nEnter no of denominations : ";
        cin>>n;
    }

    cout<<"\nEnter the "<<n<<" denominations : ";
    for(int i=0 ; i<n ;i++)
    {
        cin>>array[i];
    }
}

void coinChange::heapSort()
{
    for(int i = n/2-1 ; i>=0 ; i--)
    {
        heapify(n,i);
    }
    
    for(int i = n-1 ; i>0 ; i--)
    {
        swap(array[0],array[i]);
        heapify(i,0);
    }


}

void coinChange::heapify(int sizee , int i)
{
    int min = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < sizee && array[left]<array[min])
    {
       min = left;
    }

    if(right < sizee && array[right]<array[min])
    {
       min = right;
    }

    if(min != i)
    {
        swap(array[i],array[min]);
        heapify(sizee ,min);
    }
}

void coinChange::coins()
{
    int i;
    temp=0;
    
    for(i=0;i<n;i++)
    {
        if(amt>0)
        {
            output[temp]=amt/array[i];  
            amt = amt-(output[temp]*array[i]);
            temp++;
        }
        else
        {
            return;
        }     
    }
}

int main()
{
    coinChange c1;

    cout<<"\nEnter the amount : ";
    cin>>c1.amt;

    c1.createArray();
    c1.heapSort();
    c1.coins();

    cout<<"\nCHANGE :";
    for(int i=0;i<c1.temp;i++)
    {
        if(c1.output[i] != 0 && c1.amt == 0)
        {
            cout<<"\n₹"<<c1.array[i]<<" coins : "<<c1.output[i];
        }
        else
        {
            cout<<"\nChange not found";
            exit(0);
        }
    }


    return 0;
}
