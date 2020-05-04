#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int r,c;
    cin>>r>>c;
    int a[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
        }
    }

    for(int i=0;i<r;i++){
        if(a[i][0]==0){
            for(int j=0;j<c;j++){
                if(a[i][j]==0)
                    a[i][j]=1;
                else
                    a[i][j]=0;    
            }
        }
    }

    int total = r*pow(2,c-1),count;
    for(int j=1;j<c;j++){
        count=0;
        for(int i=0;i<r;i++){
            if(a[i][j]==1)
                count++;
        }

        if(count>r-count)
            total+=count*pow(2,c-1-j);
        else 
            total+=(r-count)*pow(2,c-1-j);
    }
    cout<<total<<endl;
    return 0;
}