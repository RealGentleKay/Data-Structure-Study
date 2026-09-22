#include <iostream>
#include <vector>

int main() {
    int n, x, count;
    std::cin >> n;
    std::vector<int> arr(n);
    for(int i=0;i<n;i++) {
        std::cin >> arr[i];
    }
    std::cin >> x;
    
    count = 0;
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            if(arr[i] + arr[j] == x) {
                count++;
            }
        }
    }

    std::cout << count;

    return 0;
}