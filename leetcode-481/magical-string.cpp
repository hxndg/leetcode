/*  虽然你的想法也是利用前面的元素推导后面的元素，但是明显你的做法比较麻烦，因此下面直接是利用了标准答案之一的解答
    利用mString.back() ^ 3来简化是添加1，还是添加2,mString[i++] - '0' 表示要添加一个这样子的元素，mString.size() < n直接就可以保证不会多的太多。
    然后就结束了，标准答案简洁而方便，可以多看看。
*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    int magicalString(int n) {
        string mString = "122";
        int i = 2;
        while(mString.size() <n){
            mString += string(mString[i++]-'0',mString.back() ^ 3);
        }
        return count(mString.begin(),mString.begin()+n,'1');
    }
};


int main(){
    int n = 4;
    Solution test;
    int answer = test.magicalString(n);
    cout<<answer<<endl;
    return 0;

}
