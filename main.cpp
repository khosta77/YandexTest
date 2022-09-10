#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string A, B, C;
    cin >> A >> B;
    const size_t AN = A.size();
    C.resize((1 + AN), ' ');
    for (size_t i = 0; i < AN; i++) {
        if (A[i] == B[i]) {
            C[i] = 'P';
            A[i] = ' ';
        } else {

        }
    }
    for (size_t i = 0; i < AN; i++) {
        if (C[i] == ' ') {
            for (size_t j = 0; j < AN; j++) {
                if (B[i] == A[j]) {
                    C[i] = 'S';
                    A[j] = ' ';
                }
            }

            if (C[i] == ' ') {
                C[i] = 'I';
            }
        }
    }
    cout << C << endl;
    return 0;
}