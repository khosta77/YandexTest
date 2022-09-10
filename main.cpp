#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    string J, S;
    cin >> J >> S;
    set<char> st;
    for (size_t i = 0; i < J.size(); i++) {
        st.insert(J[i]);
    }
    int count = 0;
    for (auto it = st.begin(); it != st.end(); it++) {
        for (size_t j = 0; j < S.size(); j++) {
            if (*it == char(S[j])) {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}