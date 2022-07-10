#include <bits/stdc++.h>
using namespace std;
// #define int long long int

struct SegmentTree {

    vector<long long int> segment_tree, lazy;
    vector<int> array;
    int size;

    void build(int node, int low, int high, vector<int>& a) {
        if (low == high) {
            segment_tree[node] = a[low];
            return;
        }
        else if (low > high) return;
        else {
            int mid = (low + high) / 2;
            build(2 * node + 1, low, mid, a);
            build(2 * node + 2, mid + 1, high, a);
            segment_tree[node] = segment_tree[2 * node + 1] + segment_tree[2 * node + 2];
        }
    }

    void printTree() {
        cout << "The segment tree is built as follows: " << endl;
        for (int i : segment_tree) cout << i << " ";
        cout << endl;
    }

    void printArray() {
        cout << "The built is built as follows: " << endl;
        for (int i : array) cout << i << " ";
        cout << endl;
    }

    void build(vector<int>& a) {
        segment_tree.clear();
        size = a.size();
        array.clear();
        array = vector<int>(a);
        long long int segmentTreeSize = pow(2, ceil(log2(size) + 1)) + 5;
        segment_tree.resize(segmentTreeSize);
        lazy.resize(segmentTreeSize);
        fill(lazy.begin(), lazy.end(), 0);
        build(0, 0, size - 1, a);
    }


    long long int query(int node, int low, int high, int l, int r) {
        // cout<<low<<' '<<high<<' '<<node<<' '<<l<<' '<<r<<'\n';
        if(lazy[node] != 0){
            segment_tree[node] += (high - low +1) * lazy[node];

            if(low != high){
                lazy[node*2 + 1] += lazy[node];
                lazy[node*2 + 2] += lazy[node];
            }
            else{
                array[low] += lazy[node]; 
            }

            lazy[node] = 0;
        }

        if(low>high || low > r || high < l ) return 0;

        if(low>=l && high<=r) return segment_tree[node];

        int mid = (low + high) / 2;
        long long int qleft = query(2 * node + 1, low, mid, l, r);
        long long int qright = query(2 * node + 2, mid+1, high, l, r);
        return qleft + qright;

    }

    long long int query(int l, int r) {
        // return array[index];
        return query(0, 0, size - 1, l, r);
    }

    void update(int node, int low, int high, int l, int r, int val) {
        if(lazy[node] != 0){
            segment_tree[node] += (high - low +1) * lazy[node];

            if(low != high){
                lazy[node*2 + 1] += lazy[node];
                lazy[node*2 + 2] += lazy[node];
            }
            else{
                array[low] += lazy[node]; 
            }

            lazy[node] = 0;
        }

        if(low>high || low > r || high < l ) return;

        if(low>=l && high<=r){
            segment_tree[node] += (high - low +1) * val;

            if(low != high){
                lazy[node*2 + 1] += val;
                lazy[node*2 + 2] += val;
            }
            else{
                array[low] += val; 
            }

            return;
        }

        int mid = (low + high)/2;
        update(node*2+1, low, mid, l, r, val);
        update(node*2+2, mid+1, high, l, r, val);
        segment_tree[node] = segment_tree[2 * node + 1] + segment_tree[2 * node + 2];
    }

    void update(int l, int r, int val) {
        update(0, 0, size - 1, l, r, val);
    }

};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int& i : v) cin >> i;
    SegmentTree st;
    st.build(v);
    // st.printTree();

    while (q--) {
        int qtype;
        cin >> qtype;

        if(qtype == 2){
            int index;
            cin >> index;
            cout<< st.query(index-1, index-1) <<'\n';
            // st.printArray();
            // st.printTree();
        }
        else{
            int start, end, val;
            cin >> start >> end >> val;
            st.update(start-1, end-1, val);
            // st.printArray();
            // st.printTree();
        }
    }
    return 0;
}