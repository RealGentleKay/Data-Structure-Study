#include <iostream>
#include <vector>

int main() {
    int n,m;
    std::cin >> n >> m;
    std::vector<int> arr(n);
    std::vector<int> sum(m);
    for(int i=0;i<n;i++) {
        std::cin >> arr[i];
    }

    for(int i=0;i<m;i++) {
        int j, k, temp;
        temp = 0;
        std::cin >> j >> k;
        for(int l=j-1;l<k;l++) {
            temp += arr[l];
        }
        sum[i] = temp;
    }

    for(int i=0;i<m;i++) {
        std::cout << sum[i] << std::endl;
    }

    return 0;
}