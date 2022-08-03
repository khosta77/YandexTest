#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<string> words;
    int clicks_count = 0;
    for (size_t i = 0; i < n; i++) {
        string str; cin >> str;
        bool next_status = true;
        vector<int> words_id;

        if (words.empty()) {
            clicks_count += str.length();
            words.push_back(str);
            next_status = false;
        } else {
            for (size_t w = 0; w < words.size(); w++) {
                if (words[w][0] == str[0]) {
                    words_id.push_back(w);
                    next_status = false;
                }
            }
        }
        if (next_status) {
            clicks_count += str.length();
            words.push_back(str);
        } else {
            vector<int> count_word;

            for (auto a : words_id) {
                cout << a  << " <--" << endl;
            }

            for (size_t j = 0; j <= str.size(); j++) {
                for (auto wi = words_id.cbegin(); wi != words_id.cend(); wi++) {
//                    cout << words[*wi] << endl;
//                    if (words[*wi].size()  j) { continue; }
//                    cout << words[*wi][j] << " " << str[j] << endl;
                    if (words[*wi][j] == str[j]) {
//                        cout << words[*wi][j];
                        for (size_t k = 0; k <= j; k++ ){
                            cout << str[k];
                        }
                        cout << endl;
                    }
                    else {
                        words_id.erase(wi, wi);
                    }
                }
            }

        }
//        for (size_t j = 0; j < str.size(); j++) {
//            for (size_t w = 0; w < word.size(); w++) {
//                if (word[w].size() >= j) { continue; }
//                if (word[w][j] == str[j])
//            }
//        }
    }
    return 0;
}