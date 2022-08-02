#include <iostream>

using namespace std;

template<typename Array, typename Size>
double sum(Array *a, const Size N) {
    double sum = 0;
    for (size_t i = 0; i < N; ++i) {
        sum += a[i];
    }
    return sum;
}

int main() {
    int n;
    int a, b;
    cin >> n;
    if (n < 1 || n > 100) {
        throw;
    }
    double *arr = new double[n]{};

    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        arr[i] = a * b;
    }

    auto total = sum(arr, n);

    for (size_t i = 0; i < n; ++i) {
        printf("%1.12f\n", arr[i] / total);
    }

    return 0;
}