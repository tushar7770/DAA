//CS20B1098 TUSHAR PANJETA
//0-1 KNAPSACK to maximize profit

#include<iostream>
#include<math.h>
using namespace std;

class knapsack01
{
    public :
    int w,p;

    void feasible(knapsack01 k[],int n,int m);

};

void knapsack01::feasible(knapsack01 k[],int n,int W)
{
    int arr[n];
    int x=0;
    for(int i=0;i<n;i++)
    {
        arr[i]=i+1;
    }

    int total=0;
    int count = pow(2, n);
    // The outer for loop will run 2^n times to print all subset .
    // Here variable i will act as a binary counter
    for (int i = 0; i < count; i++) 
    {
        // The inner for loop will run n times , 
        // As the maximum number of elements a set can have is n
        // This loop will generate a subset
        int totalWeight=0,totalProfit=0;
        for (int j = 0; j < n; j++) 
        {
            // This if condition will check if jth bit in 
            // binary representation of  i  is set or not
            // if the value of (i & (1 << j)) is not 0 , 
            // include arr[j] in the current subset
            // otherwise exclude arr[j]
            if ((i & (1 << j)) != 0)
            {
                totalWeight+=k[j].w;
                totalProfit+=k[j].p;
                cout << arr[j] << " ";
            }
            
        }
        if(totalWeight<=W)//checking weather bag weight is less than or equal to capacity
        {
            cout<<"->profit = "<<totalProfit;
            total++;     
            cout <<"\n";
            totalWeight=0,totalProfit=0;
            
        }
        else
        {
            cout<<"-> not feasible";
            cout <<"\n";
        }
        
    }
    cout<<"\nTotal feasible solutions (including null set): "<<total;
    cout<<"\nTotal feasible solutions (not including null set): "<<total-1;

}

int main()
{
    cout<<"\nnumber in subset are item no. not the weight or profit like 1 2  here 1 & 2 represent 1st and 2nd item included\n ";
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

    k1[0].feasible(k1,temp,m);

    return 0;
}
