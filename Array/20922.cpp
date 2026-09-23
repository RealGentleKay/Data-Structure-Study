#include <iostream>
#include <algorithm>

int main() {                //쉽지않음...
    int n,k;
    std::cin >> n >> k;
    int left = 0, right = 0;
    int arr[200001];
    int count[100001] = {}; //각 숫자의 등장 빈도를 기록하는 배열

    for(int i=0;i<n;i++) {
        std::cin >> arr[i];
    }

    int answer = 0;

    for(right=0;right<n;right++) {
        count[arr[right]]++;

        while(count[arr[right]] > k) {
            count[arr[left]]--;
            left++;
        }
        answer = std::max(answer, right-left+1);
    }

    std::cout << answer;

    return 0;
}
