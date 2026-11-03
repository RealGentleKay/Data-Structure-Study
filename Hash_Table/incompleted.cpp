#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> runners;

    for (string name : participant) {
        runners[name]++;
    }

    for (string name : completion) {
        runners[name]--;
    }

    for (auto runner : runners) {
        if(runner.second > 0) {
            return runner.first;
        }
    }


    return "";
}