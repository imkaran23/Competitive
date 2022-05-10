#include <bits/stdc++.h>
using namespace std;
// #define int long long int

struct SegmentTree {
    vector<long long int> segment_tree;
    vector<long long int> array;
    int size;
    void build(int node, int low, int high, vector<int>& a) {
        if (low == high) {
            segment_tree[node] = a[low];
            return;
        }
        else if (low > high)return;
        else {
            int mid = (low + high) / 2;
            build(2 * node + 1, low, mid, a);
            build(2 * node + 2, mid + 1, high, a);
            segment_tree[node] = segment_tree[2 * node + 1] + segment_tree[2 * node + 2];
        }
    }

    void printTree() {
        cout << "The segment tree is built as follows: " << endl;
        for (int i : segment_tree)cout << i << " ";
        cout << endl;
    }

    void printArray() {
        cout << "The built is built as follows: " << endl;
        for (int i : array)cout << i << " ";
        cout << endl;
    }

    void build(vector<int>& a) {
        segment_tree.clear();
        size = a.size();
        array.clear();
        auto array = a;
        long long int segmentTreeSize = pow(2, ceil(log2(size) + 1)) + 5;
        segment_tree.resize(segmentTreeSize);
        build(0, 0, size - 1, a);
    }


    long long int query(int node, int qlow, int qhigh, int slow, int shigh) {
        if (slow >= qlow and shigh <= qhigh) return segment_tree[node];
        else if (slow > qhigh or shigh < qlow) return 0;
        else {
            int mid = (slow + shigh) / 2;
            long long int qleft = query(2 * node + 1, qlow, qhigh, slow, mid);
            long long int qright = query(2 * node + 2, qlow, qhigh, mid + 1, shigh);
            return qleft + qright;
        }
    }

    long long int query(int low, int high) {
        return query(0, low, high, 0, size - 1);
    }

    void update(int node, int low, int high, int index, int diff) {
        if (high<index or low>index)return;
        else if (low == high and low == index) {
            segment_tree[node] += diff;
            array[index] += diff;
            return;
        }
        int mid = (low + high) / 2;
        update(2 * node + 1, low, mid, index, diff);
        update(2 * node + 2, mid + 1, high, index, diff);
        segment_tree[node] += diff;
    }

    void update(int index, int diff) {
        update(0, 0, size - 1, index, diff);
    }

};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int>v(n);
    for (int& i : v)cin >> i;
    SegmentTree st;
    st.build(v);
    // st.printTree();
    // cout << "Query sums: " << endl;
    // int q;
    // cin >> q;
    while (q--) {
        // cout << "1 for query 2 for update" << endl;
        int qtype=1;
        // cin >> qtype;
        if (qtype == 1) {
            int low, high;
            cin >> low >> high;
            cout << st.query(low-1, high-1) << endl;
        }
        else {
            int index, val;
            cin >> index >> val;
            st.update(index, val);
            st.printArray();
            st.printTree();
        }
    }
    return 0;
}