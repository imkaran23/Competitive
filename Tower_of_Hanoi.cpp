#include<iostream>
using namespace std;
//using std::string;
int cnt=0;

int tower_of_hanoi( int n , char L , char C , char R )
{
    if(n == 1)
    {
        cout<<"Move disk 1 from "<<L<<" to "<<R<<endl;
        return ++cnt;
    }
    tower_of_hanoi( n-1,L,R,C);
    cout<<"Move disk "<<n<<" from "<<L<<" to "<<R<<endl;
    tower_of_hanoi( n-1,C,L,R);
    return ++cnt;
}

main()
{
    int n;
    cout<<"Enter no. of disks : ";
    cin>>n;
    //tower_of_hanoi(n,'A','B','C');
    cout<<"Total no. of moves : \n"<<tower_of_hanoi(n,'A','B','C')<<endl;
}
