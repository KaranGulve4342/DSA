// LEETCODE 1255

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int W = words.size();

        vector<int> freq(26, 0);
        for(char c : letters){
            freq[c - 'a']++;
        }

        int maxScore = 0;

        vector<int> subsetLetters(26, 0);
        for(int mask = 0;mask < (1 << W);mask++){
            fill(subsetLetters.begin(), subsetLetters.end(), 0);

            for(int i = 0;i < W;i++){
                if(mask&(1 << i)){
                    int L = words[i].length();
                    for(int j = 0;j < L;j++){
                        subsetLetters[words[i][j] - 'a']++;
                    }
                }
            }
            maxScore = max(maxScore, subsetScore(subsetLetters, score, freq));
        }
        return maxScore;
    }
    int subsetScore(vector<int>& subsetLetters, vector<int>& score, vector<int>& freq){
        int totalScore = 0;
        for(int c = 0;c < 26;c++){
            totalScore += subsetLetters[c] * score[c];
            if(subsetLetters[c] > freq[c]){
                return 0;
            }
        }
        return totalScore;
    }
};