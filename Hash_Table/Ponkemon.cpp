#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {
    unordered_set<int> kinds;

    for(int num : nums) {
        kinds.insert(num);
    }

    return min((int)nums.size() / 2, (int)kinds.size());
}