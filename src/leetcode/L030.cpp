/**
 * author:CliffLeopard 
 * date:2019/11/27  
 * time:01:08
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/substring-with-concatenation-of-all-words/
 * 说明:使用hashMap存储words中的单词和词频，与s进行slideWindow比对
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    static vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>res;
        unordered_map<string,int> wordMap;
        int strLength = s.size();
        int wordCount = words.size();
        int wordLength = words[0].size();

        if(wordCount * wordLength > strLength)
            return res;

        for(auto  word:words)
            wordMap[word]++;

        for(int i=0;i<=strLength-(wordCount * wordLength);i++){
            unordered_map<string,int> tempMap;
            for(int j=0;j< wordCount;j++){
                string tempWord = s.substr(i+ (j*wordLength),wordLength);
                tempMap[tempWord]++;
                if(wordMap.find(tempWord) == wordMap.end()){
                    break;
                }
                if(tempMap[tempWord] > wordMap[tempWord]){
                    break;
                }
            }

            if(wordMap == tempMap) {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main() {
    string str = "wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","good"};
    Solution solution;
    vector<int> result = solution.findSubstring(str,words);
    for(auto key:result) {
        cout<<key;
    }
    return 0;
}