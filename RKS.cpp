// /*
// RKS - RK Sorting
// #ad-hoc-1
// RK is a great code breaker. He knows any cipher in the world can be broken by frequency analysis. He intercepted an enemy message. The message consists of N numbers, smaller than or equal to C. RK belives freqency analysis consists of sorting this sequence so that more frequent numbers appear before less frequent ones.

// Formally, the sequence must be sorted so that given any two numbers X and Y , X appears before Y if the number of times X appears in the original sequence is larger than the number of time Y does. If the number of appearances is equal, the number whoes value appears sooner in the input should appear sooner in the sorted sequence.
// Help RK by creating a "frequency sorter".

// Input
// First line of input contains two integers, N (1 <= N <= 1000), length of message, and C (1 <= C <= 10^9), the number from task description. Next line contains N integers smaller than or equal to C, message itself.

// Output
// First and only line of output should contain N numbers, the sorted sequence.

// Sample
// Input
// 9 3
// 1 3 3 3 2 2 2 1 1

// Output
// 1 1 1 3 3 3 2 2 2
// Input
// 5 2
// 2 1 2 1 2

// Output
// 2 2 2 1 1
// */
// #include<iostream>
// #include<iterator>
// #include<map>
// using namespace std;

// template <typename type>
// struct mycomp
// {
//     bool operator () ( const type & first , const type & second ) const
//     {
//         return first.second>second.second ;
//     }
// };


// main()
// {
//     int n,c,x;
//     /*
//     // Creating & Initializing a map of String & Ints
// 	std::map<std::string, int> mapOfWordCount = { { "aaa", 10 }, { "ddd", 41 },
// 			{ "bbb", 62 }, { "ccc", 13 } };

// 	// Declaring the type of Predicate that accepts 2 pairs and return a bool
// 	typedef std::function<bool(std::pair<std::string, int>, std::pair<std::string, int>)> Comparator;

// 	// Defining a lambda function to compare two pairs. It will compare two pairs using second field
// 	Comparator compFunctor =
// 			[](std::pair<std::string, int> elem1 ,std::pair<std::string, int> elem2)
// 			{
// 				return elem1.second < elem2.second;
// 			};

// 	// Declaring a set that will store the pairs using above comparision logic
// 	std::set<std::pair<std::string, int>, Comparator> setOfWords(
// 			mapOfWordCount.begin(), mapOfWordCount.end(), compFunctor);

// 	// Iterate over a set using range base for loop
// 	// It will display the items in sorted order of values
// 	for (std::pair<std::string, int> element : setOfWords)
// 		std::cout << element.first << " :: " << element.second << std::endl;
//     */
//     cin>>n>>c;
//     map<int, pair<int,int>, mycomp<pair<int,int> > > mp;
//     while (n--)
//     {
//         cin>>x;
//         mp[x].first++;
//         if(!mp[x].second)
//             mp[x].second=n;
//     }
//     for(auto itr=mp.begin(); itr!=mp.end(); itr++)
//     {
//         for(auto j=0 ; j< itr->second.first ; j++)
//             cout<<itr->first<<" ";
//     }
// }

#include <iostream>
#include<map>
#include<algorithm>
using namespace std;

int a[1005];
map<int,int> f;
map<int,int> priority;

int compare(int x,int y)
{
    if(f[x] == f[y])
        return(priority[x] < priority[y]);

    return(f[x] > f[y]);
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,c,i;
    cin>>n>>c;
    for(i = 0; i < n; i++) {
        cin>>a[i];
        f[a[i]]++;

    }

    for(i = n - 1; i >= 0; i--) {
        priority[a[i]] = i;
    }

    sort(a,a+n,compare);

    for(i = 0; i < n; i++) {
        cout<<a[i]<<" ";
    }

    cout<<endl;
}
