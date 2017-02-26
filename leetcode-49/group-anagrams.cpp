#include <iostream>
#include <vector>
#include <string>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        multimap<string,string> wordTable;
        for(int i = 0;i<strs.size();i++){
            string sortedStr = strs[i];
            sort(sortedStr.begin(),sortedStr.end());
            wordTable.insert(make_pair<string,string>(string(sortedStr),string(strs[i])));
        }
        multimap<string,string>::iterator it = wordTable.begin();
        vector< vector<string>> answer;
        while(it != wordTable.end()){
            typedef multimap<string,string>::size_type size;
            size count = wordTable.count(it->first);
            vector<string> oneRow;
            for(size i = 0;i < count;i++){
                oneRow.push_back(it->second);
                it++;
            }
            answer.push_back(oneRow);
        }
        return answer;
    }
};

int main(){
    string sample[6] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> strs(sample,sample+6);
    Solution test;
    vector<vector<string>> answer = test.groupAnagrams(strs);
    for(int i = 0;i<answer.size();i++){
        for(int j = 0;j<answer[i].size();j++){
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
