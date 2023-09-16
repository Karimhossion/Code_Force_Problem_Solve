#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s;
    cin >> s;
    
    int n = s.size();
    stack<int> st;
    vector<int> dp(n, 0);
 
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else if (!st.empty()) {
            int openPos = st.top();
            st.pop();
            dp[i] = i - openPos + 1;
            if (openPos > 0) {
                dp[i] += dp[openPos - 1];
            }
        }
    }
 
    int maxLength = 0, count = 1;
    for (int i = 0; i < n; i++) {
        if (dp[i] > maxLength) {
            maxLength = dp[i];
            count = 1;
        } else if (dp[i] == maxLength) {
            count++;
        }
    }
 
    if (maxLength == 0) {
        cout << "0 1" << endl;
    } else {
        cout << maxLength << " " << count << endl;
    }
 
    return 0;
}