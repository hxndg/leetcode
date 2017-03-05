/*
    这道题自己的解法就是纯粹的从树的构建角度来说的


*/



#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <stack>


using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        /*
        stack<char> binaryTree  ;
        if(preorder== "#") return true;
        if(preorder[0]=='#') return false;
        for(int i = 0 ; i < preorder.size();i++){
            if(preorder[i] == ',') {
                continue;
            }
            if(preorder[i]>='0' && preorder[i] <= '9'&& preorder[i+1]>='0' && preorder[i+1] <= '9'){
                continue;
            }
            if(i != 0){
                if(binaryTree.empty()){
                    return false;
                }
            }
            if(preorder[i] == '#'){
                while((!binaryTree.empty()) && (binaryTree.top() == '#')){
                    binaryTree.pop();
                    if(binaryTree.empty()){
                        return false;
                    }
                    binaryTree.pop();
                }
                if(!binaryTree.empty()){
                    binaryTree.push('#');
                }
            }
            else{
                binaryTree.push(preorder[i]);
            }
        }
        return binaryTree.empty();
        */
        int diff = 1;
        for(int i = 0 ; i < preorder.size();i++){
            if(preorder[i] == ',') {
                continue;
            }
            if(preorder[i]>='0' && preorder[i] <= '9'&& preorder[i+1]>='0' && preorder[i+1] <= '9'){
                continue;
            }
            diff--;
            if(diff < 0) return false;
            if(!(preorder[i] == '#')){
                diff += 2;
            }
        }
        return diff == 0;

    }
};

int main(){
    string answer("9,#,92,#,#");
    Solution test;
    if(test.isValidSerialization(answer)){
        cout<<"This is a true binary Tree"<<endl;
    }
    else{
        cout<<"Nope,this is not a true binary Tree"<<endl;
    }
    return 0;
}
