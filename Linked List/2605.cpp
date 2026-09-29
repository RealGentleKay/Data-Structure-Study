#include <iostream>
#include <list>

int main() {
    int n;
    std::cin >> n;
    
    std::list<int> students;

    for(int student=1;student<=n;student++) {
        int number;
        std::cin >> number;

        auto position = students.end();

        for(int i=0;i<number;++i) {
            --position;
        }

        students.insert(position, student);
    }

    for(int student : students) {
        std::cout << student << " ";
    }

    return 0;
}
