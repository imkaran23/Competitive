/*
Little Monk and Library
Attempted by: 1573/Accuracy: 28%/Maximum Score: 20/
 16 Votes
Tag(s): Algorithms, Easy, Greedy algorithm
PROBLEM
EDITORIAL
MY SUBMISSIONS
ANALYTICS
Little Monk as usual has not prepared for his exams. So, to ensure that he does not fail in any course, he goes to the library and picks up N books for his N courses that he has to give exams for. The number of books being too large, he puts them on different tables and goes to a particular table whenever he wants to read that particular book.

After he is done with studying, he has to put all the books back in their place. He finds that there are exactly N empty spaces in the book shelf where he can put his N books.

Imagine shelves and tables where books are kept, as locations on the x-coordinate axis. Now Little Monk wants to minimize the time he takes to put books back in shelves. He takes T units of time to put a book back in a shelf, where T denotes the distance between the book and the shelf it was put in.

Once Little Monk puts a book into a shelf, he takes 0 unit time to reach the next book he wants to put into a shelf. Since he is dumb, and in a hurry, help him calculate the minimum time required to put all the books in shelves.

Note: Once a book has been into a shelf, you can't put another book in the same shelf. Also, initially Monk can start from any book.

Input format:
The first line contains a pair of integers: an integer N, which denotes the number of books and empty shelves. Next line contains N space separated integers denoting co-ordinates of the tables where books are placed. Next line contains N space separated integers denoting co-ordinates of shelves.

Output format:
Print minimal time it will take Little Monk to put all books back in shelves.

Constraints:
1 ≤ N ≤ 
1 ≤ Ni ≤ 

SAMPLE INPUT 
3
2 1 3
4 3 2
SAMPLE OUTPUT 
3
Explanation
Given co-ordinates of books and empty shelves, one of the possible combinations, where monk would incur minimal time is:

Book at co-ordinate 2 goes to shelf at co-ordinate 2.
Book at co-ordinate 1 goes to shelf at co-ordinate 3.
Book at co-ordinate 3 goes to shelf at co-ordinate 4.
Total time taken = 0 (2-2) + 2 (3-1) + 1 (4-3) = 3.

Time Limit:	0.5 sec(s) for each input file.
Memory Limit:	256 MB
Source Limit:	1024 KB
*/
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    long long x,total=0;
    cin>>n;
    vector<long long> tables,shelves;
    for(int i=0;i<n;i++){
        cin>>x;    
        tables.push_back(x);
        // cin>>tables[i];
    }
    for(int i=0;i<n;i++){
        cin>>x;
        shelves.push_back(x);
        // cin>>shelves[i];
    }
    sort(tables.begin(),tables.end());
    sort(shelves.begin(),shelves.end());
    // sort(tables,tables+n);
    // sort(shelves,shelves+n);
    for(long long i=0;i<n;i++){
        total+=abs(tables[i]-shelves[i]);
    }
    cout<<total<<endl;
}