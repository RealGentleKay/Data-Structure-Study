#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> hash;
    int answer = 1;
    
    for(auto cloth : clothes) {
        hash[cloth[1]]++; //가짓수만 세면 됨, 옷의 이름은 무시하고 종류와 개수만 채택
    }

    for(auto cloth : hash) {
        answer *= (cloth.second + 1); //모든 종류의 옷에 대해서, 안 입는 경우 1가지를 더함
    }                                 //그 경우를 모두 곱함

    return answer - 1; // 옷을 안 입는 경우 1가지를 뺌
}