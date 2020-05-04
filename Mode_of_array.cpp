#include<bits/stdc++.h>
using namespace std;

int main()
{
   vector<int> v,temp,freq;
   int n,count=1,flag=1,max=0;
   cout<<"Enter any character to stop giving input\nEnter elements of your array\n";
   while( scanf("%d",&n) )
   {
       v.push_back(n);
   }

   sort(v.begin(), v.end());

   for(int i=0; i<v.size(); i++)
   {
        for(int j=0; j<temp.size() ; j++)
        {
            if(v[i]==temp[j])
            {
                flag=0;
                break;
            }
        }
        if(flag)
            temp.push_back(v[i]);
        else
            flag=1;
        if(v[i]==v[i+1])
            count++;
        else
        {
            freq.push_back(count);
            count=1;
        }
    }

   cout<<"Element : Frequency \n";

   for(int j=0; j<freq.size() ; j++)
   {
       cout<<temp[j]<<" : "<<freq[j]<<endl;
       if(freq[j]>max)
        max=freq[j];
   }

   cout<<"Mode : ";
   for(int j=0; j<freq.size() ; j++)
   {
       if(max==freq[j])
        cout<<temp[j]<<" ";
   }

   return 0;
}
