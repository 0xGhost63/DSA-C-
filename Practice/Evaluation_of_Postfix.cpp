#include <iostream>
#include <stack>
using namespace std;

int main()
{
    cout<<"Enter the Infix Expression : ";
    string input;
    cin>>input;

    bool valid=true;

    stack <char> s;  

    for (int i =0 ;i<input.size();i++)
    {
        if (input[i]>='0' && input[i]<='9')
        {
            s.push(input[i]);
        }
        else 
        {
            if (s.size()>=2)   
            {
                int op1=s.top() - '0';
                s.pop();
                int op2=s.top()- '0';
                s.pop();

                int res=0;

                if (input[i]=='+')
                {
                    res=op2+op1;
                }
                else if (input[i]=='-')
                {
                    res=op2-op1;
                }
                else if (input[i]=='*')
                {
                    res=op2*op1;
                }
                else if (input[i]=='/')
                {
                    res=op2/op1;
                }
                else if (input[i]=='%')
                {
                    res=op2%op1;
                }

                s.push((char)(res + '0'));
            }
            else
            {
                valid=false;
            }
        }

    }
    if (s.size()!=1)
    {
        valid=false;
    }
    string validity=(valid)?"Valid":"Not Valid";
    cout<<"The expression is : "<<validity<<" \n";
    if (valid)
    {
        cout<<"The POST-FIX expression you entered is : ";
        cout<<input;
        cout<<"\nThe answer is "<< (s.top()-'0') <<endl; 
    }

}
