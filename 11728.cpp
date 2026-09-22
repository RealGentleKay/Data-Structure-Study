#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int a, b;
    std::cin >> a >> b;
    std::vector<int> v1(a);
    std::vector<int> v2(b);

    for(int i=0;i<a;i++) {
        std::cin >> v1[i];
    }

    for(int i=0;i<b;i++) {
        std::cin >> v2[i];
    }

    std::vector<int> v3(a+b);
    for(int i=0;i<a;i++) {
        v3[i] = v1[i];
    }
    for(int j=a;j<a+b;j++) {
        v3[j] = v2[j-a];
    }

    std::sort(v3.begin(), v3.end());

    for(int i=0;i<a+b;i++) {
        std::cout << v3[i] << " ";
    }
}