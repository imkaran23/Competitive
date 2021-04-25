#include <bits/stdc++.h>
using namespace std;
int a[10],t,h,m,ch,cm;

int rev(int num)
{
    if(num/10){
        int rev_num = 0;
        while(num > 0)
        {
            int d = num%10;
            if(d==5) d=2;
            else if(d==2) d=5;
            rev_num = rev_num*10 + d;
            num = num/10;
        }
        return rev_num;
    }
    else {
        if(num==5) num=2;
        else if(num==2) num=5;
        return num*10;
    }
}

bool check(int ch, int cm){

    bool flag = true;

    // cout<<rev(cm)<<" "<<rev(ch)<<"\n";
    if( rev(ch)>=m || rev(cm)>=h) flag = false;

    while(ch>0){
        if(a[ch%10]==0) flag = false;
        ch/=10;
    }

    while(cm>0){
        if(a[cm%10]==0) flag = false;
        cm/=10;
    }

    return flag;
}

int main()
{
    ios_base::sync_with_stdio(false);
    a[0]=a[1]=a[2]=a[5]=a[8]=1;
    cin.tie(NULL);

    char c;
    cin>>t;

    while(t--){
        cin>>h>>m; 
        cin>>ch>>c>>cm;

        while(true){
            // cout<<ch<<" "<<cm<<" ";
            if(check(ch,cm)) break;
            cm++;
            if(cm/m==1) {
                cm=0;
                ch++;
            }

            if(ch/h==1) ch = 0;
        }

        if(ch/10) cout<<ch<<c;
        else cout<<0<<ch<<c;

        if(cm/10) cout<<cm;
        else cout<<0<<cm;

        cout<<"\n";
    }
}