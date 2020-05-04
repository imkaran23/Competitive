/*
An array, , is defined as follows:

 for , where  is the symbol for XOR
You will be given a left and right index . You must determine the XOR sum of the segment of  as .

For example, . The segment from  to  sums to .

Print the answer to each question.

Function Description

Complete the xorSequence function in the editor below. It should return the integer value calculated.

xorSequence has the following parameter(s):

l: the lower index of the range to sum
r: the higher index of the range to sum
Input Format

The first line contains an integer , the number of questions.
Each of the next  lines contains two space-separated integers,  and , the inclusive left and right indexes of the segment to query.

Constraints



Output Format

On a new line for each test case, print the XOR-Sum of 's elements in the inclusive range between indices  and .

Sample Input 0

3
2 4
2 8
5 9
Sample Output 0

7
9
15
Explanation 0

The beginning of our array looks like this: 

Test Case 0:



Test Case 1:



Test Case 2:



Sample Input 1

3
3 5
4 6
15 20
Sample Output 1

5
2
22
Explanation 1

. Perform the xor sum on each interval:




*/
#include <iostream>
#include <numeric>
using namespace std;

int64_t getNextA (int64_t index) {

    int64_t options[] = {index, index, 2, 2, index + 2, index + 2, 0, 0};
    return options[index % 8];

}

int main() {

    int q;
    cin >> q;

    while (q--) {
        int64_t l, r;
        cin >> l >> r;
        cout << (getNextA(r)^getNextA(l-1)) << endl;
    }

    return 0;
}