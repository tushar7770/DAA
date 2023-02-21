//Program to implement two stacks in an array
#include<iostream>

#define size 100
using namespace std;

class Array 
{
    private:
        //member variables
        int array[size] ;
        int top1, top2 ;
    
    public:
        //member functions
        Array()
        {
            top1 = -1;
            top2 = size;
        }

        void push1(int value);
        void push2(int value);
        int pop1();
        int pop2();
};

//Function to push element in stack 1
void Array::push1(int value) 
{
    if(top1 == (top2 - 1)) 
    {
        cout<<"Stack is Full!!!"<<endl;
    }
    else 
    {
        array[++top1] = value;
    }
}

//Function to push element in stack 2
void Array::push2(int value) 
{
    if(top1 == (top2 - 1)) 
    {
        cout<<"Stack is Full!!!"<<endl;
    }
    else 
    {
        array[--top2] = value;
    }
}

//function to pop element from stack 1
int Array::pop1() 
{
    if(top1 == -1) 
    {
        return -1;
    }
    else 
    {
       return array[top1--];
    }
    
}

//function to pop element from stack 2
int Array::pop2() 
{
    if(top2 == size) 
    {
        return -1;
    }
    else 
    {
        return array[top2++];
    }
}

int main() 
{
    int choice , value ;
    Array stacks;

    while(1) //Menu to perform stack operations 
    {
        cout<<"\n1. Push1\n2. Push2\n3. Pop1\n4. Pop2\n5. Exit\nEnter Your Choice -> ";
        cin>>choice;
        switch(choice) 
        {
            case 1:
                cout<<"\nEnter the Value to Push in Stack1 -> ";
                cin>>value;
                stacks.push1(value);
                break;

            case 2:
                cout<<"\nEnter the Value to Push in Stack2 -> ";
                cin>>value;
                stacks.push2(value);
                break;
            
            case 3:
                value = stacks.pop1();

                if(value != -1)
                {
                    cout<<"\nPopped Element from Stack1 : "<<value<<endl;
                }
                else
                {
                    cout<<"\nstack is empty!!!";
                }    
                break;
            
            case 4:
                value = stacks.pop2();

                if(value != -1)
                {
                    cout<<"\nPopped Element from Stack2 : "<<value<<endl;
                }
                else
                {
                    cout<<"\nstack is empty!!!";
                }
                break;
            
            case 5:
                exit(0);
            
            default:
                cout<<"\nEnter a Valid Option, Try Again!"<<endl;
        }
    }

    return 1;
}