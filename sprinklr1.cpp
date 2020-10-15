// Given an array of coordinates of houses, choose 3 coordinates (not necessarily from given coordinates), assume x1, x2, x3. Each x is releasing an energy which is covering the range [x-E, x+E]. Note that each x releases same amount of energy, i.e. E. Your task is to minimize E such that all houses are covered and print it.

// input : 3 4 5 6
// output : 0.5
// explanation : 1st alien - 3.5, 2nd alien - 4.5, 3rd alien - 5.5
// Note that you should print your answer by rounding off to one decimal place.

#include <bits/stdc++.h>
using namespace std;

int check(vector<int>& a,double x){
    return a[0] + 6*x >= a[a.size()-1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    vector<int> a;
    while(cin>>x) a.push_back(x);
    sort(a.begin(),a.end());
    double lo = 0, hi = a[a.size()-1]-a[0], mid;

    int iter = 100;
    while(lo<hi && iter--){
        mid = lo + (hi-lo)/2;
        int e = check(a,mid);
        if(e) hi = mid;
        else lo = mid+0.01;
    }

    printf("%.1f\n", mid);
    return 0;
}