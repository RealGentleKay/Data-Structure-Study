#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> phonebook;

    for (string number : phone_book) {
        phonebook.insert(number);
    }

    for (string phone : phone_book) {
        for (int i = 1; i < phone.size(); i++) {
            string prefix = phone.substr(0, i);

            if (phonebook.find(prefix) != phonebook.end()) {
                return false;
            }
        }
    }

    return true;
}