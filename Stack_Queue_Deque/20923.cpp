#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> dodo, su;
    deque<int> dodo_ground, su_ground;

    int n, m;
    cin >> n >> m;

    for(int i=0;i<n;i++) {
        int a, b;
        cin >> a >> b;

        dodo.push_back(a);
        su.push_back(b);
    }

    for(int turn = 0;turn<m;turn++) {
        if(turn % 2 == 0) { //도도 차례
            dodo_ground.push_back(dodo.back());
            dodo.pop_back();

            if(dodo.empty()) { //카드를 내고 덱이 비면 패배
                cout << "su";
                return 0;
            }
        }

        else { //수연 차례
            su_ground.push_back(su.back());
            su.pop_back();

            if(su.empty()) {
                cout << "do";
                return 0;
            }
        }
        // 도도가 종을 치는 경우
        if ((!dodo_ground.empty() && dodo_ground.back() == 5) ||
            (!su_ground.empty() && su_ground.back() == 5)) {

            // 상대 그라운드부터
            while (!su_ground.empty()) {
                dodo.push_front(su_ground.front());
                su_ground.pop_front();
            }

            // 자기 그라운드
            while (!dodo_ground.empty()) {
                dodo.push_front(dodo_ground.front());
                dodo_ground.pop_front();
            }
        }

        // 수연이가 종을 치는 경우
        else if (!dodo_ground.empty() &&
                 !su_ground.empty() &&
                 dodo_ground.back() + su_ground.back() == 5) {

            // 상대(도도) 그라운드부터
            while (!dodo_ground.empty()) {
                su.push_front(dodo_ground.front());
                dodo_ground.pop_front();
            }

            // 자기 그라운드
            while (!su_ground.empty()) {
                su.push_front(su_ground.front());
                su_ground.pop_front();
            }
        }
    }

    if (dodo.size() > su.size())
        cout << "do";
    else if (dodo.size() < su.size())
        cout << "su";
    else
        cout << "dosu";
    
    return 0;
}