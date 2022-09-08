#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    long long A, B;
    ifstream is("input.txt");
    is >> A >> B;
    is.close();
    std::ofstream out;          // поток для записи
    out.open("output.txt"); // окрываем файл для записи
    out << (A + B) << endl;
    out.close();
    return 0;
}