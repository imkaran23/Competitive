/*
You will be given T (T<=10^6) pair of numbers. All you have to tell is the number of common divisors between two numbers in each pair.

Input
First line of input: T (Number of test cases)
In next T lines, each have one pair A B (0 < A, B <= 10^6)

Output
One integer describing number of common divisors between two numbers.

Example
Input:
3
100000 100000
12 24
747794 238336
Output:
36
6
2


*/

#include<stdio.h>



int hcf(int n1, int n2)

{

    if(n2>n1)

        return hcf(n2,n1);

    else if (n2!=0)

       return hcf(n2, n1%n2);



    else

       return n1;

}



int main()

{

    int t;

    scanf("%d",&t);

    while(t--)

    {

        int a,b,c=0,i,h;

        scanf("%d%d",&a,&b);

        h= hcf(a,b);

        for(i=1;i*i<=h;i++)

        {

            if(h%i==0)

                c=c+2;



        }

        i=i-1;

        if(i*i==h)

            c--;

        printf("%d\n",c);



    }

    return 0;

}
