/*
A. Duff and Meat
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Duff is addicted to meat! Malek wants to keep her happy for n days. In order to be happy in i-th day, she needs to eat exactly ai kilograms of meat.


There is a big shop uptown and Malek wants to buy meat for her from there. In i-th day, they sell meat for pi dollars per kilogram. Malek knows all numbers a1, ..., an and p1, ..., pn. In each day, he can buy arbitrary amount of meat, also he can keep some meat he has for the future.

Malek is a little tired from cooking meat, so he asked for your help. Help him to minimize the total money he spends to keep Duff happy for n days.

Input
The first line of input contains integer n (1 ≤ n ≤ 105), the number of days.

In the next n lines, i-th line contains two integers ai and pi (1 ≤ ai, pi ≤ 100), the amount of meat Duff needs and the cost of meat in that day.

Output
Print the minimum money needed to keep Duff happy for n days, in one line.

Examples
inputCopy
3
1 3
2 2
3 1
outputCopy
10
inputCopy
3
1 3
2 1
3 2
outputCopy
8
Note
In the first sample case: An optimal way would be to buy 1 kg on the first day, 2 kg on the second day and 3 kg on the third day.

In the second sample case: An optimal way would be to buy 1 kg on the first day and 5 kg (needed meat for the second and third day) on the second day.


*/
#include<iostream>
using namespace std;

main(){
    int n,a,p,min=100,total=0;
    cin>>n;
    while(n--){
        cin>>a>>p;
        if(p<min)
            min=p;
        total+=a*min;     
    }
    cout<<total<<endl;
}