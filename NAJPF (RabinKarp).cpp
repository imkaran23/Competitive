#include <bits/stdc++.h> 
using namespace std; 
char s1[1000001],s2[1000001];

vector<int> rabin_karp(string const& t, string const& s) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    vector<int> occurences;
    for (int i = 0; i + S - 1 < T; i++) { 
        long long cur_h = (h[i+S] + m - h[i]) % m; 
        if (cur_h == h_s * p_pow[i] % m)
            occurences.push_back(i);
    }
    return occurences;
}

int main() 
{ 
    int t;
    cin>>t;
    while(t--){
        scanf("%s %s",s1,s2);
        auto v = rabin_karp(s1,s2);
        if(v.size()){
            cout<<v.size()<<endl;
            for(int i=0;i<v.size();i++)
                cout<<v[i]+1<<" ";
        }
        else 
            cout<<"Not Found";
        cout<<endl<<endl;
    }
	return 0; 
} 

// #include <bits/stdc++.h> 
// using namespace std; 
// #define d 256 
// int q = 101 ;

// void search( string txt, string pat) 
// { 
// 	int M = pat.size(),N = txt.size(), i, j, h=1, p=0, t=0, flag; // p:hash value for pattern , t:hash value for txt 
// 	// The value of h would be "pow(d, M-1)%q" 
// 	for (i = 0; i < M - 1; i++) 
// 		h = (h * d) % q; 
// 	// Calculate the hash value of pattern and first window of text 
// 	for (i = 0; i < M; i++) { 
// 		p = (d * p + pat[i]) % q; 
// 		t = (d * t + txt[i]) % q; 
// 	} 
//     // Slide the pattern over text one by one 
//     flag = 0 ;
// 	for (i = 0; i <= N - M; i++) { 
// 		// Check the hash values of current window of text and pattern. If the hash values match then only check for characters on by one 
// 		if ( p == t ) { 
// 			/* Check for characters one by one */
// 			for (j = 0; j < M; j++) { 
// 				if (txt[i+j] != pat[j]) 
// 					break; 
// 			} 
// 			// if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1] 
// 			if (j == M){ 
// 				    cout<< i << " ";
//                     flag = 1 ;
//                 } 
// 		} 
// 		// Calculate hash value for next window of text: Remove leading digit, add trailing digit 
// 		if ( i < N-M ) { 
// 			t = (d*(t - txt[i]*h) + txt[i+M])%q; 
// 			if (t < 0) 
// 			    t = (t + q); 
// 		} 
// 	} 
//     if(!flag)
//         cout<<"Not Found";
// } 

// int main() 
// { 
//     int t;
//     cin>>t;
//     while(t--){
//         string s1,s2;
//         cin>>s1>>s2;
//         search(s1,s2);
//         cout<<endl<<endl;
//     }
// 	return 0; 
// } 