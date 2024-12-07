#include <bits/stdc++.h>
using namespace std;

int main () {
    // read input
    string s;
    char c;
    while (scanf("%c", &c) != EOF) {
        s += c;
    }
    s += "#####################"; // fake characters to avoid going Out Of Bounds

    int n = (int) s.length();

    auto getNumber = [&](int& i) {
        int x = 0;
        while (x < 1000 && isdigit(s[i])) {
            x = 10 * x + (s[i] - '0');
            i++;
        }
        if (1 <= x && x <= 999) {
            return x;
        }
        return -1;
    };

    bool enable = true;
    int answer = 0;
    for (int i = 0 ; i < n - 7; i++) {
        if (s.substr(i, 4) == "do()") {
            enable = true;
        }
        if (s.substr(i, 7) == "don\'t()") { // ' is a special character is use \' for it
            enable = false;
        }
        if (enable && s[i] == 'm') {
            if (s[i+1] == 'u' && s[i+2] == 'l' && s[i+3] == '(') { // substr is slower
                i += 4;
                int x = getNumber(i);
                if (s[i] == ',') {
                    i += 1;
                    int y = getNumber(i);
                    if (s[i] == ')') {
                        if (x != -1 && y != -1) {
                            answer += x * y;
                        }
                    }
                }
            }
        }

    }
    printf("%d\n", answer);
}
