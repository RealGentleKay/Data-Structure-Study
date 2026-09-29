#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    list<pair<int, int>> paper;
    vector<int> output;
    
    for(int i=0;i<n;i++) {
        int move;
        cin >> move;

        paper.push_back({i+1, move});
    }
    auto it = paper.begin();
    
    while(!paper.empty()) {
        int balloonNum = it->first;
        int move = it->second;

        output.push_back(balloonNum);
        it = paper.erase(it);
        if (paper.empty()) break;
        if(it == paper.end()) it = paper.begin();

        if(move > 0) {
            for(int i=0;i<move-1;i++) {
                ++it;
                if(it == paper.end()) it = paper.begin();
            }
        }
        else if(move < 0) {
            for(int i=0;i<-move;i++) {
                if(it == paper.begin()) it = paper.end();
                --it;
            }
        }

    }
    
    for(int i=0;i<output.size();i++) {
            if(i>0) {
                cout << " ";
            }

            cout << output[i];
        }

    return 0;
}