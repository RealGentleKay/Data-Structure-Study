#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    queue<int> s;
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
                cout << s.front() << endl;
                s.pop();
            }
        }
        else if (command == "front") {
            if(s.empty()) cout << -1 << endl;
            cout << s.front() << endl;
        }
        else if (command == "back") {
            if(s.empty()) cout << -1 << endl;
            cout << s.back() << endl;
        }
        else if (command == "size") cout << s.size() << endl;
        else if (command == "empty") cout << s.empty() << endl;
    }

    return 0;
}