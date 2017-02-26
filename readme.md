leetcode 287 这个问题很有意思，两种解法，第二种还需要想一想，第一种解法就是利用鸽笼原理，但是他的分割是直接对i进行分割，不是想的对整个vector的具体的某个元素进行分割。
!!!!!  leetcode 446 这个问题依然没有搞懂，每次加的时候为什么加的都是dp[j][diff],而不是dp[i][diff].而且为什么直接求和不行呢？搞不明白啊
leetcode 442 这个问题的解法中，第一种算法真的是非常的巧妙。基本思想是和hash一致，但是利用了本身数组的性质，避开了问题的出现。题目448与442是相同的题目。实际上这个问题展示了一种对于数组的通用的解决方式，将每个数字放到他数值指向的位置，放过去以后再继续考虑。讲道理这种方法对于数组找missing 或者找duplicate都是适用的，leetcode-41找第一个missing的元素同样是利用这种想法，将正数放到应该在的位置，负数会被调整到缺失或者某个位置上，过大的数字不用管它。
leetcode 406 这个问题本身实际上是一种插入的想法，所谓的看前面有几个数字更大，就是先插大的。。。我也不知道怎么说了，这题挺不错。
leetcode 315 这个问题提供了对于逆序元素的一种标准处理方式，是很不错的想法。
leetcode 231,关于一个数字是不是2的次幂的解决方法，简单搞定了.问题326是问3的次幂，但是因为位操作做不到，因此这个用了一种狡猾的方法。。。。
leetcode 260,这个题提出了一种对于大量出现重复两次数字的解决方法，重复两次的数字异或的情况下会为0，而两个不相同的数字异或会对具体的某一位留下数字。这种方法很巧妙.这道题的拓展题目玩玩是一堆元素重复出现k次，有一个元素只出现一次，怎么计算这个元素，方法统计每一位1出现的次数然后对k取余即可
leetcode 238,这道题的解决方法关键在于将缺失位左边的乘积，缺失位，确实位右边的乘积看成三个不同的部分，这样子将前后两个部分求出来，然后一乘即可。当然，相比较而言标准答案的解法更简单,但是思想是一样的.
leetcode 213,如果说house-robber是简单的dp问题，那么house-robber-2，也就是本题加了一个环以后问题就复杂在包括第一个值的最大解包含最后一个值，不能出现。然后不包括第一个值的最大解比包括第一个值的最大解更大，因此这个题巧妙的使用了[1,n-1]与[2,n]的范围来解决问题，是环问题的一种标准方法，值得思考
leetcode 416,背包问题初次见面，使用动态规划解决，很不错，实际上，这一系列的动态规划全都伴随着一个基本的假设，那就是第i件物品的放置与否会决定我们前面取什么值。
leetcode 402,这个题重点注意这一点，申请地址的时候申请整个数组的长度，直接通过回写来覆盖，这个样子就可以避开边界判断的条件简单很多.
leetcode 93，dfs的一个简单应用，值得一记，你写的太麻烦了
leetcode 373,这个问题的解决方式非常好，利用优先队列，（实际上就是堆），我们每次都将问题集中到了少数的几个元素之上，这个题和leetcode 378是一样的问题，都可以使用优先队列的解法，此外，还需要记住的是这个题关于优先队列的声明定义方法，修改比较函数的方法，这些都很重要，需要经常参考。
leetcode 394,标准答案下的解决方式答案非常短，标准答案的解决方法思路和自己的解决思路是一致的，但是自己的做法显得非常的复杂并且愚蠢，但是这种思想可以借鉴，先统计出来要计算的子串的位置，然后子串扔到函数里自己计算，然后总的加到一起，完成
leetcode 382,这道题水桶抽样的原理，以及 j = rand() % i，当j==0时就碰上了1/i的概率这一点需要记住!
leetcode 375,这道题是一个动态规划题，但是很难看出来并且及时知道是动态规划，但是使用二维动态规划来解不用一维来算很难，到现在还是不明白为什么二维可以一维不行
leetcode 236,曾经的一道没做出来的笔试题，最近公共祖先问题
leetcode 477,这道题将单词的汉明距离放到了大的数据量之下，然而每次运算依然是对具体的每一位运算，因而只需O(n)的时间复杂度即可运算，不需要再考虑单次的运算，十分巧妙
leetcode 397,这题本质上是位图操作，这一点你没有看出来，提示非常明显包括+1，-1,除2等，除此之外对于最快操作的想法必须记住，这个题没有相关基础很难想到
leetcode 343,和397相似，这道题同样是有点奇技淫巧的感觉，将数字拆成2和3相乘的组合最大，这一点需要通过实践发现
leetcode 494,这个题非常好，应当有这种当需要有数组求和等于某个值，或者是有两个变化的集合的时候，将两个集合转换为一个集合的思想，这种变化两个变为一个想法很重要！！
leetcode 144,二叉树的遍历，这个题本身难度不大，但是从这道题学到一个新的遍历方法morris遍历，morris遍历的寻找前驱节点的方法比较特殊需要注意，自己进题里面去看
leetcode 98 ,判断一个二叉树是不是bst。。。本身一个bst如果中序打印是一个递增的数列。。。这一点竟然没想到。。。。然后使用上面的morris遍历会很方便的解决问题,leetcode-230同样可以使用morris解法，但是morris如果中间跳出去会导致曾经修改的二叉树没能恢复成原样，这一点需要大大的注意。
leetcode 423,解这个问题的时候思路一度跑偏，什么深度搜索，排序字符串搜索，复杂度高了去了，结果最后发现做法是每个单词提供特征，然后按照特征来进行求解。需要记住这种想法
leetcode 485,这个题自己解法时间复杂度不错，但是空间复杂度很多，但是这道题的重点在于最后并不是使用第一个玩家的选择的求和，而是采用了第一个玩家减去第二个玩家的解法，这种想法很有趣，他是在需要求和制定范围元素时使用的，这样子可以不用求特定范围的和，很有用
leetcode 279,这个题是典型的使用动态规划。但是竟然想歪了。。。利用bfs同样可以计算，利用了bfs能够找到两个节点之间最短路径的优势，但是bfs对于内存的消耗太高 
leetcode 318,建立字符串单字母索引的一种有效方法，
leetcode 421,这个题应该说是bit manipulate题遇到的最正常也是最不好想，重点并不是找到那一对最大的数，而是逐步的重建result看行不行,很不错，对于这一类题可以记住.
leetcode 264,每次能取到的ugly number都是从2,3,5的uglynumber列表里取到的最小值，这想法很厉害，确实是这样子，每次都是原先某一次的运算导致出来的，这个可以复用.
leetcode 22  关于这种生成字符串种类的题目通通可以这样子计算，找到了生成的字符串的限制规律，然后让计算机去搜索在规律限制之下能够生成的子串的集合，返回就完了
leetcode 39，这道题是一个非常寻常的回溯题，通过这道题能够总结出来回溯的模式，需要传递的东西有 当前可以备选的单元，一个保存当前遍历出来结果的数据结构，终止回溯的条件，合适的解满足的条件(当然这个也可以通过候选单元的个数来判断)，如何遍历从而达成从一个起始点出发，保证不在第二次访问它？，其他典型的回溯包括leetcode 40,leetcode 46
leetcode 377 这道题之所以使用动态规划而没有单纯的回溯或者递归是因为出现了和斐波那契数列一样的问题，递归没有降低复杂的程度，因此采用dp的方法可以有效的降低运算的难度，这道题需要你分析出来时间复杂度为什么那么高的原因,这恰恰是你需要思考的方面
leetcode 322 这道题是使用动规计算的典范，但是为什么使用回溯和贪心做解出来的答案不是最有解呢？因为回溯用的是局部优化导致后面出现了解不是全局优化的情况，
leetcode 525,对于这道题我只想说fuck my life。。。使用-1替代0，那么只要sum[i,j] == 0就知道这段出现的0和1的个数是一致的，除此之外还有什么要注意呢？这个题里1出现的次数是求和的差值，0出现的次数是第二个序号减去第一个序号然后除以2.。。我为什么要说这个呢？是因为这里用到了hash表来保证查询只需要使用o(1)的时间，实际上你的第一种做法都是可以使用查询的方式来简化时间的，但是你没有想到。。。。！！！！wtf这个利用查询来减少实践运用这一点一定要注意啥,这个问题又进一步印出来另一个问题，我什么时候可以使用hash来提到dp做快速的查找，结论是当我的查找公式是一个结构非常规范，可以化成统一形式的东西我才这样子做，就好像这个题里一样，如果形式不一致，我就没法索引，进而没办法快速找到它，就好像那个coin changes的问题
leetcode 452,这道射气球的问题还是没有想的很清楚，为什么从后面射为什么不从前面射击？为什么从后面射击是贪心
leetcode 241,这道题实际上点名了一点，如果你的思路是错误的，那么你的运算过程就会非常麻烦，如果你的思路正确就会比较容易，实际上这个地方要考虑的在于括号改变的究竟是什么，是先算数字还是先算运算符，这里明显是* + -而不是数字，不应该想到数字上去
leetcode 424,这道题利用一个滑动的窗口，这个窗口的作用是在这个窗口里面保证是替换次数小于k的最长的长度，而我们总能让最合适换的长度达到最长，真的好巧妙啊
leetcode 436,这道题关于组合元素和index提供了一个很好的思路：不一定非得构造类，可以构造map来存储键值对，除此之外map的lower_bound方法可以很方便的找到第一个比某个特定的值大的方法，很不错
leetcode 117,非常好的一道题，实际上是一个不利用栈的bfs算法，本身的结构非常巧妙实际上是利用了线索来指向下一个相邻的节点
leetcode 289,如果只是用1来存储0和1的话，那么int可以有冗余位存储后面用来的值，很不错的想法
