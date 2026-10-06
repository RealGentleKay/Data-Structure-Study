#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string str;
    cin >> str;
    stack<char> stk;
    int pieces = 0;

    for(int i=0;i<static_cast<int>(str.size());i++) {
        if (str[i] == '(') { // 레이저가 아닌 경우, (의 개수가 곧 열려 있는 막대의 개수임. 여기서는 따로 처리 X
            stk.push(str[i]);
        }
        else {
            if(str[i-1] == '(') { // ( 뒤의 )는 레이저인데 (를 추가하며 막대가 1개 늘었으므로
                stk.pop(); //막대를 1개 줄이고
                pieces += stk.size(); //레이저가 자르는 막대의 개수
            }

            else {
                stk.pop(); //) 뒤의 )는 막대의 끝
                pieces++; //막대의 끝이므로 조각을 1개 추가함
            }
        }
    }

    cout << pieces;

    return 0;
}