/*
请你设计一个可以解释字符串 command 的 Goal 解析器 。command 由 "G"、"()" 和/或 "(al)" 按某种顺序组成。Goal 解析器会将 "G" 解释为字符串 "G"、"()" 解释为字符串 "o" ，"(al)" 解释为字符串 "al" 。然后，按原顺序将经解释得到的字符串连接成一个字符串。

给你字符串 command ，返回 Goal 解析器 对 command 的解释结果。

 

示例 1：

输入：command = "G()(al)"
输出："Goal"
解释：Goal 解析器解释命令的步骤如下所示：
G -> G
() -> o
(al) -> al
最后连接得到的结果是 "Goal"
示例 2：

输入：command = "G()()()()(al)"
输出："Gooooal"
示例 3：

输入：command = "(al)G(al)()()G"
输出："alGalooG"
 

提示：

1 <= command.length <= 100
command 由 "G"、"()" 和/或 "(al)" 按某种顺序组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/goal-parser-interpretation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdlib.h>

static char state[7][5] = {
    // 输入 G ( ) a l
    {1, 2, -1, -1, -1}, // 0.初始态
    {1, 2, -1, -1, -1}, // 1.G态
    {-1, -1, 3, 4, -1}, // 2.(态
    {1, 2, -1, -1, -1}, // 3.()态
    {-1, -1, -1, -1, 5}, // 4.a态
    {-1, -1, 6, -1, -1}, // 5.l态
    {1, 2, -1, -1, -1} // 6.l)态
};

static const char INVALID = 5;

static char accept[7] = {
    0, 'G', 0, 'o', 0, 0, 'x'
};

static char to_state_code(char input) {
    switch (input) {
        case 'G':
            return 0;
        case '(':
            return 1;
        case ')':
            return 2;
        case 'a':
            return 3;
        case 'l':
            return 4;
        default:
            return INVALID;
    }
}

char * interpret(char * command){
    char* out = (char*)malloc(sizeof(char) * 101);
    if (!out) {
        return NULL;
    }
    memset(out, 0, 101);
    char* out_ptr = out;

    char* ptr = command;
    char cur_state = 0;
    char is_accept = 0;
    while (*ptr != '\0') {
        cur_state = state[cur_state][to_state_code(*ptr)];
        is_accept = accept[cur_state];
        ++ptr;

        if (is_accept) {
            if (is_accept == 'x') {
                *out_ptr = 'a';
                ++out_ptr;
                *out_ptr = 'l';
                ++out_ptr;
                continue;
            }
            *out_ptr = is_accept;
            ++out_ptr;
        }
    }

    return out;
}