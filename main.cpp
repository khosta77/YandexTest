#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <exception>

#define APPOINT "APPOINT"
#define PRINT "PRINT"

using namespace std;

template<typename Array, typename Size>
double sum(Array *a, const Size N) {
    double sum = 0;
    for (size_t i = 0; i < N; ++i) {
        sum += a[i];
    }
    return sum;
}

class TimeException/* : public exception*/ {
    vector<string> error_names;
public:
    TimeException(vector<string> &en) : error_names(en) {}

    virtual vector<string> what() const {
        string buf_error;
        buf_error += "FAIL\n";
        for (size_t j = 0; j < error_names.size(); ++j) {
            buf_error += (error_names[j] + " ");
        }
        buf_error += "\n";
        return buf_error;
    }
};

struct meeting_time {
    int _date_start;
    int _date_end;

    meeting_time() {
        cin >> _date_start;
        _date_start *= 10000;

        string time; cin >> time;
        _date_start += atoi(&time[0]) * 100;
        _date_start += atoi(&time[3]);

        int duration;
        cin >> duration;
        _date_end = _date_start;
        _date_end += (duration / 60) * 10 + (duration % 60);
        if ((_date_end % 100) == 60) {
            _date_end += 40;
        }
    }

    meeting_time(int day, int hour, int minutes, int duration) {
        _date_start = (day * 10000) + (hour * 100) + minutes;
        _date_end = _date_start;
        _date_end += (duration / 60) * 10 + (duration % 60);
        if ((_date_end % 100) == 60) {
            _date_end += 40;
        }
    }
};

vector<string> get_names() {
    int n; cin >> n;
    vector<string> names;
    for (; n > 0; --n) {
        string name;
        cin >> name;
        names.push_back(name);
    }
    return names;
}

void call_appoint(map<string, vector<meeting_time>> &df) {
    meeting_time mt;
//    cout << mt._date_start << " " << mt._date_end << endl;
    auto names = get_names();
    vector<string> exception_names;
    bool mt_status = true;
    for (size_t i = 0; i < names.size(); ++i) {
        if (df.count(names[i])) {
            auto df_mt = df[names[i]];
            for (size_t j = 0; j < df_mt.size(); ++j) {
                if (df_mt[j]._date_start <= mt._date_start && df_mt[j]._date_end >= mt._date_end ||
                    df_mt[j]._date_start <= mt._date_end && df_mt[j]._date_end >= mt._date_end) {}
                else {
                    mt_status = false;
                }
            }
        }
        exception_names.push_back(names[i]);
    }

    if (mt_status) {
//        cout << "in clear" << endl;
        exception_names.clear();
    }

    if (!exception_names.empty()) {
        throw TimeException(exception_names);
    }

    for (size_t i = 0; i < names.size(); ++i) {
        df[names[i]].push_back(mt);
    }
}

int main() {
    map<string, vector<meeting_time>> users;
    int count; cin >> count;
    vector<string> consol_out;

    for (size_t i = 0; i < count; ++i) {
        string str; cin >> str;
        if (str == APPOINT) {
            try {
                call_appoint(users);
                consol_out.push_back("OK\n");
            } catch (TimeException &err) {
                consol_out.push_back(err.what());
            }
        } else if (str == PRINT) {
            // TODO: ...
        }
    }

    for (size_t i = 0; i < consol_out.size(); ++i) {
        cout << consol_out[i];
    }
    return 0;
}