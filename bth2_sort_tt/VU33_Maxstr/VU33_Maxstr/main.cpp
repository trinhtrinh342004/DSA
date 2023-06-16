#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> countDigits(string s) {
    vector<int> cnt(10);
    for (char c : s) {
        int digit = c - '0';
        cnt[digit]++;
    }
    return cnt;
}

bool findReplacement(vector<int>& cnt, int mod) {
    bool found = false;
    if (mod == 1) {
        for (int i = 1; i <= 9; i += 3) {
            if (cnt[i] > 0) {
                cnt[i]--;
                found = true;
                break;
            }
        }
        if (!found) {
            int cnt2 = 0;
            for (int i = 2; i <= 9; i += 3) {
                cnt2 += cnt[i];
                if (cnt2 >= 2) {
                    cnt[i] -= 2;
                    found = true;
                    break;
                }
            }
        }
    }
    else if (mod == 2) {
        for (int i = 2; i <= 9; i += 3) {
            if (cnt[i] > 0) {
                cnt[i]--;
                found = true;
                break;
            }
        }
        if (!found) {
            int cnt1 = 0;
            for (int i = 1; i <= 9; i += 3) {
                cnt1 += cnt[i];
                if (cnt1 >= 2) {
                    cnt[i] -= 2;
                    found = true;
                    break;
                }
            }
        }
    }
    return found;
}

string getOpenLock(string s) {
    vector<int> cnt = countDigits(s);
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += cnt[i] * i;
    }
    int mod = sum % 3;
    if (mod == 1 || mod == 2) {
        bool found = findReplacement(cnt, mod);
        if (!found) {
            return "-1";
        }
    }
    string res;
    for (int i = 9; i >= 0; i--) {
        res += string(cnt[i], '0' + i);
    }
    if (res.empty()) {
        return "0";
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    cout << getOpenLock(s) << endl;
    return 0;
}