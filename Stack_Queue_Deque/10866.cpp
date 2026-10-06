#include <iostream>
#include <deque>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    deque<int> s;
    for(int i=0;i<n;i++) {
        string command;
        int num;
        cin >> command;
        if(command == "push_front") {
            cin >> num;
            s.push_front(num);
        }
        else if(command == "push_back") {
            cin >> num;
            s.push_back(num);
        }
        else if (command == "pop_front") {
            if(s.empty()) cout << -1 << endl;
            else {
                cout << s.front() << endl;
                s.pop_front();
            }
        }
        else if (command == "pop_back") {
            if(s.empty()) cout << -1 << endl;
            else {
                cout << s.front() << endl;
                s.pop_back();
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