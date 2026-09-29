#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    list<int> josephus;
    vector<int> output;

    for(int i=1;i<=n;i++) {
        josephus.push_back(i);
    }

    auto del = josephus.begin();
    while(!josephus.empty()) {
        for(int i=0;i<k-1;i++) {
            ++del;
            if(del == josephus.end()) del = josephus.begin();
        }
        output.push_back(*del);
        del = josephus.erase(del); //삭제된 원소의 다음 반복자가 반환됨
        if (!josephus.empty() && del == josephus.end()) del = josephus.begin();
    }

    cout << "<";

    for(int i=0;i<n;i++) {
        if(i>0) cout << ", ";
        cout << output[i];
    }
    cout << ">" << endl;
    
    return 0;
}