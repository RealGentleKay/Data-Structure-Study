#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, int> genre_count;
    unordered_map<string, vector<pair<int, int>>> genre_song;
    vector<int> sol;
    for(int i=0;i<genres.size();i++) {
        genre_count[genres[i]] += plays[i];
        genre_song[genres[i]].push_back({i, plays[i]});
    }
    
    vector<pair<string, int>> sortedGenres(genre_count.begin(), genre_count.end());
    
    sort(sortedGenres.begin(), sortedGenres.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    });
    
    
    for (const auto& genrePair : sortedGenres) {
        auto& songs = genre_song[genrePair.first];
        
        sort(songs.begin(), songs.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            if(a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        });
        
        int count = 0;
        for (auto song : songs) {
            if(count >= 2) break;
            sol.push_back(song.first);
            count++;
        }
    }
    return sol;
}