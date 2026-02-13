#include <iostream>
using namespace std;
int main()
{
    int arr[2][2];
    int arr1 [2][2];


    cout<<"Enter the data of the first 2-D 2x2 array : ";

    for (int i = 0 ; i<2 ;i++)
    {
        for (int j=0 ;j<2;j++)
        {
            cin>>arr[i][j];
        }
    }

    cout<<"Enter the data of the Second 2-D 2x2 array : ";

    for (int i = 0 ; i<2 ;i++)
    {
        for (int j=0 ;j<2;j++)
        {
            cin>>arr1[i][j];
        }
    }

    cout<<"Data that you entered for first array is  : "<<endl;
    for (int i = 0 ; i<2 ;i++)
    {
        for (int j=0 ;j<2;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"Data that you entered for second array is  : "<<endl;
    for (int i = 0 ; i<2 ;i++)
    {
        for (int j=0 ;j<2;j++)
        {
            cout<<arr1[i][j]<<" ";
        }
        cout<<"\n";
    }


    cout<<"The product matrix of the first and second array is : \n";
    for (int i = 0 ; i<2 ;i++)
    {
        for (int j=0 ;j<2;j++)
        {
            cout<<arr[i][j]*arr1[i][j]<<" ";
        }
        cout<<"\n";
    }




}
