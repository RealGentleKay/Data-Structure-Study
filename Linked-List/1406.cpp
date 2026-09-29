#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr); //입력 크기가 크므로 빠른 입출력 설정

    string str;
    cin >> str;

    int commandCount = 0;
    cin >> commandCount; // 명령어의 개수

    list<char> text;
    for(auto ch : str) text.push_back(ch);
    auto cursor = text.end();
    for(int i=0;i<commandCount;i++) {
        char command;
        cin >> command;
        switch (command) {
            case 'L':
                if(cursor != text.begin()) cursor--;
                break;
            case 'D':
                if(cursor != text.end()) cursor++;
                break;
            case 'B':
                if(cursor != text.begin()) {
                    cursor--;
                    cursor = text.erase(cursor);
                }
                break;
            case 'P': {
                char add;
                cin >> add;
                text.insert(cursor, add);
                break;
            }
                
        }
    }

    for(auto i:text) {
        cout << i;
    }

    return 0;
}