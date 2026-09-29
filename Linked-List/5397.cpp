#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    int numoftest;
    cin >> numoftest;

    for(int i=0;i<numoftest;i++) {
        string str;
        cin >> str;

        list<char> output;
        auto cursor = output.end();
        
        for(char i:str) {
            switch (i) {
                case '<':
                    if(cursor != output.begin()) cursor--;
                    break;
                case '>':
                    if(cursor != output.end()) cursor++;
                    break;
                case '-': 
                    if(cursor != output.begin()) {
                    cursor--;
                    cursor = output.erase(cursor);
                }
                    break;
                default: 
                    output.insert(cursor, i);
                    break;
        }


    }
    for(char ch : output) {
            cout << ch;
        }
    cout << "\n";
}
return 0;
}