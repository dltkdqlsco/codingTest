/*
사전에 알파벳 모음 'A', 'E', 'I', 'O', 'U'만을 사용하여 만들 수 있는, 길이 5 이하의 모든 단어가 수록되어 있습니다. 사전에서 첫 번째 단어는 "A"이고, 그다음은 "AA"이며, 마지막 단어는 "UUUUU"입니다.

단어 하나 word가 매개변수로 주어질 때, 이 단어가 사전에서 몇 번째 단어인지 return 하도록 solution 함수를 완성해주세요.

제한사항
word의 길이는 1 이상 5 이하입니다.
word는 알파벳 대문자 'A', 'E', 'I', 'O', 'U'로만 이루어져 있습니다.
입출력 예
word	result
"AAAAE"	   6
"AAAE"	  10
"I"	     1563
"EIO"	 1189
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char vowels[] = {'A', 'E', 'I' 'O', 'U'};
int answer = 0;
bool found = false;

void dfs(char* current, const char* target, int depth){
    if(found) return;
    
    // 배열에 값을 넣고 count를 1씩 올린다 그러다 찾는 단어를 만나면 return;
    if(depth > 0){
        answer++;
        if(strcmp(current, target) == 0){
            found = true;
            return;
        }
    }
    
    if(depth >= 5) return;

    // depth 인덱스에 모음을 넣고 그다음 인덱스에 널값을 넣고 재귀를 돌린다.
    // for문을 활용해서 값을 바꿔가면 넣을 수 있게 된다. 
    for(int i = 0; i < 5; i++){
        current[depth] = vowels[i];
        current[depth + 1] = '\0';
        dfs(current, target, depth + 1);
    }
}

int solution(const char* word){
    // \0 값이 들어가기 때문에 배열의 크기를 6으로 잡았다.
    char current[6] = "";
    dfs(current, word, 0);
    return answer;
}
