#include<bits/stdc++.h>
using namespace std;

int main()
{
    int r , c , item , mini ,flag , maxi , i, j ,k;
    cout<<"Enter no. of rows : ";
    cin>>r;
    cout<<"Enter no. of coloumns : ";
    cin>>c;
    int v[r][c] , temp;

    for(i = 0 ; i < r ; i++ )
    {
        for(j = 0 ; j < c ; j++ )
        {
            cin >> item ;
            v[i][j]=item;
        }
    }

    for(i = 0 ; i < r ; i++ )
    {
        mini = v[i][0];
        temp=0;
        for(j = 1 ; j < c ; j++ )
        {
            if(v[i][j]<mini)
            {
                mini = v[i][j];
                temp = j;
            }
        }
        //cout<<"Minimum:"<<mini<<" Index:"<<temp<<endl;
        flag=1;
        maxi = mini ;
        for(k=0 ; k<r ; k++)
        {
            if(v[k][temp]>maxi)
            {
                flag=0;
                break;
            }
        }

        if(flag)
            cout<<"Saddle Point : "<<maxi<<endl;
    }

    return 0;
}
