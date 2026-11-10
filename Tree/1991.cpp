#include <iostream>
using namespace std;

void pre_order(char cur, char* lc, char* rc);
void in_order(char cur, char* lc, char* rc);
void post_order(char cur, char* lc, char* rc);

int main() {
    int n;
    cin >> n;
    char* lc = new char[n+1]();
    char* rc = new char[n+1]();

    for(int i=0;i<n;i++) {
        char cur, left, right;
        cin >> cur >> left >> right;
        lc[cur - 'A'] = left;
        rc[cur - 'A'] = right;
    }

    pre_order('A', lc, rc);
    cout << '\n';

    in_order('A', lc, rc);
    cout << '\n';

    post_order('A', lc, rc);
    cout << '\n';

    delete[] lc;
    delete[] rc;
}

void pre_order(char cur, char* lc, char* rc) {
    cout << cur;
    if (lc[cur - 'A'] != '.') pre_order(lc[cur - 'A'], lc, rc);
    if (rc[cur - 'A'] != '.') pre_order(rc[cur - 'A'], lc, rc);
}

void in_order(char cur, char* lc, char* rc) {
    if (lc[cur - 'A'] != '.') in_order(lc[cur - 'A'], lc, rc);
    cout << cur;
    if (rc[cur - 'A'] != '.') in_order(rc[cur - 'A'], lc, rc);
}

void post_order(char cur, char* lc, char* rc) {
    if (lc[cur - 'A'] != '.') post_order(lc[cur - 'A'], lc, rc);
    if (rc[cur - 'A'] != '.') post_order(rc[cur - 'A'], lc, rc);
    cout << cur;
}