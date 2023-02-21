//TUSHAR PANJETA CS20B1098
//MAX AND SECOND MAX IN  N + LogN - 2 COMPARISIONS

#include<iostream>
#define size 100
using namespace std;

class maxAndSmax
{
    public : 
    int n,array[size];

    void createArray();
    void Smax();
    int * findMax(int i,int j ,int arr[]);
};

void maxAndSmax::createArray()
{
    cout<<"\nEnter no. elements : ";
    cin>>n;
    while(n<0)
    {
        cout<<"\n[ERROR] Invalid input , TRY AGAIN";
        cout<<"\nEnter no of elements : ";
        cin>>n;
    }
    array[0]=n;

    cout<<"\nEnter the "<<n<<" elements : ";
    for(int i=1 ; i<=n ;i++)
    {
        cin>>array[i];
    }
}

int* maxAndSmax::findMax(int i,int j ,int arr[])
{
    if(i==j)                                                          //we have N array at end and then we perform n/2 comparision
    {                                                                 //and among these n/2 we have n/4 comparisions
        int *compare = new int[j+1];                                    //total comparision n/2 + n/4 + n/8 ........log(n)times = n-1
        compare[0]=1;
        compare[1]=arr[i];
        return compare;
    }

    int* compare1= findMax(i ,i + (j-i)/2,arr);
    int* compare2= findMax(1+i + (j-i)/2,j,arr);

    if(compare1[1]>compare2[1])
    {
        int s = compare1[0]+1;
        compare1[0]=s;
        compare1[s]=compare2[1];
        return compare1;
    }
    else
    {
        int s = compare2[0]+1;
        compare2[0]=s;
        compare2[s]=compare1[1];
        return compare2;
    }
}

void maxAndSmax::Smax()
{
    int* compare = findMax(1,n,array);
    
    cout<<"\nMAX        : "<<compare[1];//n-1 comparisions
    if(compare[0]!=1)
    {
        int*compare2 = findMax(2,compare[0],compare);//atmost log(n)-1 comparisions
        cout<<"\nSECOND MAX : "<<compare2[1];
    }

    //total comparisions n - 1 + log(n) - 1 = n + log(n) - 2
    
}

int main()
{
    maxAndSmax m;

    m.createArray();
    m.Smax();

    return 0;
}
