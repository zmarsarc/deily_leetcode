/*
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

 

示例 1：

输入: s = "abcdefg", k = 2
输出: "cdefgab"
示例 2：

输入: s = "lrloseumgh", k = 6
输出: "umghlrlose"
 

限制：

1 <= k < s.length <= 10000
*/
#include <stdlib.h>

char* reverseLeftWords(char* s, int n){
    if (!s) {
        return NULL;
    }
    if (n == 0) {
        return s;
    }
    
    char* header = (char*)malloc(sizeof(char) * n);
    if (!header) {
        return NULL;
    }

    char* pos = s;
    for (size_t i = 0; s[i] != '\0' && i < 10000; ++i) {
        ++pos;
        if (i < n) {
            header[i] = s[i];
            continue;
        }

        s[i - n] = s[i];
    }

    pos -= n;
    for (size_t i = 0; i < n; i++) {
        *pos = header[i];
        ++pos;
    }

    return s;
}
