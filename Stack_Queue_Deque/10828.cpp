#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    stack<int> s;
    for(int i=0;i<n;i++) {
        string command;
        int num;
        cin >> command;
        if(command == "push") {
            cin >> num;
            s.push(num);
        }
        else if (command == "pop") {
            if(s.empty()) cout << -1 << endl;
            else {
                cout << s.top() << endl;
                s.pop();
            }
        }
        else if (command == "top") {
            if(s.empty()) cout << -1 << endl;
            cout << s.top() << endl;
        }
        else if (command == "size") cout << s.size() << endl;
        else if (command == "empty") cout << s.empty() << endl;
    }

    return 0;
}