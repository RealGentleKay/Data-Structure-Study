#include <iostream>
#include <queue>

using namespace std;

int main() {
    int num = 0, printed = 0;
    cin >> num;
    queue<pair<int, int>> print;

    for(int i=0;i<num;i++) {
        printed = 0;
        int n, m;
        cin >> n >> m;
        for(int j=0;j<n;j++) {
            int imp;
            cin >> imp;
            print.push({imp, j});
        }
        while(!print.empty()) {
            auto current = print.front(); // 큐는 맨 앞과 맨 뒤밖에 접근을 못하므로, 맨 앞 원소를 current에 저장
            print.pop(); // current는 잠시 큐에서 빼기

            bool hasHigher = false; // 큐를 한 바퀴 돌리면서 current보다 중요도가 높은 원소가 생기면 true가 됨
            int size = print.size();

            for(int j=0;j<size;j++) {
                auto next = print.front();
                print.pop();
                if(next.first > current.first) {
                    hasHigher = true;
                }
                print.push(next);
            }

            if(hasHigher) { // current보다 중요도가 높은 문서가 있을 경우
                print.push(current); //큐 뒤로 push
            }
            else { //current를 print해야 하는 경우
                printed++; // 출력된 문서의 개수
                if(current.second == m) cout << printed << endl; //타겟 문서인 경우 현재까지 출력된 문서 개수 출력
            }
        }
    }
}