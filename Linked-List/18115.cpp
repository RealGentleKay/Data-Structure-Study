#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> technique(n);
    for(int i=0;i<n;i++) {
        cin >> technique[i];
    }

    list<int> card_queue;

    for(int i=n-1;i>=0;i--) {
        int card = n-i;
        switch (technique[i]) {
            case 1:
                card_queue.push_front(card);
                break;
            case 2: {
                auto ptr = card_queue.begin();
                ++ptr;
                card_queue.insert(ptr, card);
                break;
            }
            case 3: {
                card_queue.push_back(card);
                break;
            }
        }
    }

    bool first = true;

    for(int card : card_queue) {
        if(!first) {
            cout << " ";
        }

        cout << card;
        first = false;
    }

    return 0;
}