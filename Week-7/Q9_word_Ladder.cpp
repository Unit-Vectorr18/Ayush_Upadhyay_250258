#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

    unordered_set<string> words(wordList.begin(), wordList.end());
    if (words.find(endWord) == words.end())
        return 0;

    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    words.erase(beginWord);

    while (!q.empty()) {

        string currentWord = q.front().first;
        int length = q.front().second;
        q.pop();


        if (currentWord == endWord)
            return length;
        for (int i = 0; i < currentWord.size(); i++) {

            char original = currentWord[i];

            for (char ch = 'a'; ch <= 'z'; ch++) {

                currentWord[i] = ch;

                if (words.find(currentWord) != words.end()) {

                    q.push({currentWord, length + 1});

                  
                    words.erase(currentWord);
                }
            }

        
            currentWord[i] = original;
        }
    }

    return 0;
}

int main() {

    string beginWord = "hit";
    string endWord = "cog";

    vector<string> wordList = {
        "hot",
        "dot",
        "dog",
        "lot",
        "log",
        "cog"
    };

    cout << "Shortest Transformation Length = "
         << ladderLength(beginWord, endWord, wordList);

    return 0;
}