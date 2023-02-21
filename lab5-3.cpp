//CS20B1098 TUSHAR PANJETA
//Given a set of m words (strings), arrange them in dictionary order.
//team 21
#include<iostream>
#define size 100
using namespace std;

class dictionary
{
    public :

    string words[size];
    int n;

    void createArray();

    void heapSort();
    void heapify(int sizee , int i);

};

void dictionary::createArray()
{
    cout<<"\nEnter no. of words : ";
    cin>>n;
    while(n<=0)
    {
        cout<<"\n[ERROR] Invalid input , TRY AGAIN";
        cout<<"\nEnter no. of elements in array : ";
        cin>>n;
    }

    cout<<"\nEnter the "<<n<<" words : ";
    for(int i=0 ; i<n ;i++)
    {
        cin>>words[i];
    }
}

void dictionary::heapSort()
{
    for(int i = n/2-1 ; i>=0 ; i--)
    {
        heapify(n,i);
    }
    
    for(int i = n-1 ; i>0 ; i--)
    {
        swap(words[0],words[i]);
        heapify(i,0);
    }


}

void dictionary::heapify(int sizee , int i)
{
    int max = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < sizee && words[left]>words[max])
    {
        max = left;
    }

    if(right < sizee && words[right]>words[max])
    {
        max = right;
    }

    if(max != i)
    {
        swap(words[i],words[max]);
        heapify(sizee , max);
    }
}

int main()
{
    dictionary d1;
    d1.createArray();
    d1.heapSort();
    cout<<"\ndictionary order of words : "<<endl;
    for(int i=0 ; i<d1.n ; i++)
    {
        cout<<d1.words[i]<<"\n";
    }
    return 0;
}