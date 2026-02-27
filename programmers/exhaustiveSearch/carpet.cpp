/*문제 설명
Leo는 카펫을 사러 갔다가 아래 그림과 같이 중앙에는 노란색으로 칠해져 있고 테두리 1줄은 갈색으로 칠해져 있는 격자 모양 카펫을 봤습니다.

Leo는 집으로 돌아와서 아까 본 카펫의 노란색과 갈색으로 색칠된 격자의 개수는 기억했지만, 전체 카펫의 크기는 기억하지 못했습니다.

Leo가 본 카펫에서 갈색 격자의 수 brown, 노란색 격자의 수 yellow가 매개변수로 주어질 때 카펫의 가로, 세로 크기를 순서대로 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한사항
갈색 격자의 수 brown은 8 이상 5,000 이하인 자연수입니다.
노란색 격자의 수 yellow는 1 이상 2,000,000 이하인 자연수입니다.
카펫의 가로 길이는 세로 길이와 같거나, 세로 길이보다 깁니다.
입출력 예
brown	yellow	return
  10	   2	[4, 3]
  8	       1	[3, 3]
  24	   24	[8, 6]
*/


#include <string>
#include <vector>
using namespace std;


/*
나도 sqrt까지는 생각했는데 그 다음은 도저히 생각이 안나서 다른 사람의 코드를 보면서 이런식으로 하는구나 공부를 했습니다. 
근데 보면서 조금만 더 생각하면 풀 수 있을거 같은데 왜 더 깊게 생각을 안했을까라는 생각이 들었다. 
*/
vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for(int i = 1; i * i <= yellow; i++){   // 1부터 sqrt(yellow)까지
        if(yellow % i > 0) continue;        // 나눠떨어지지 않는 배수는 패스

        int inner_w = yellow / i;           // 가로가 길거나 같으니 큰 값으로
        int inner_h = i;
        if((inner_w + 2) * 2 + (inner_h + 2) * 2 - 4 == brown){     // 테두리 계산값이 갈색이랑 같은지
            answer.push_back(inner_w + 2);  // 갈색 가로값
            answer.push_back(inner_h + 2);  // 갈색 세로값
            break;
        }
    }

    return answer;
}

/* 
밑에 코드는 다른 사람이 수학적으로 접근해서 푼 코드인데 보고 이렇게도 풀 수 있구나라고 생각을 해서 밑에다 작성을 했다. 


코드 설명 
1. ap = brown + yellow (전체 넓이)
   width * height == brown + yellow

2. sum = brown / 2 + 2 (가로 + 세로)
   테두리의 길이를 생각해보면: 위아래(w * 2) + 양옆((h-2)*2)
   즉, brown = 2w + 2h - 4
   이 식을 w + h에 대해서 정리를 하면 
   w + h == (brown / 2) + 2

3. if(i * (sum - i) == ap) (이차방정식 찾기)
   for문에서 i를 세로 길이($h$)라고 가정한다면, 가로 길이($w$)는 자동으로 sum - i
   i * (sum - i)는 (세로 * 가로)를 한 넓이가 되고, 이 값이 전체 넓이인 ap와 일치하는 순간이 정답
*/

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int ap = brown+yellow;
    int sum = brown/2+2;
    for(int i=0; i<sum;i++){
        if(i*(sum-i)==ap){
            answer.push_back(sum-i);
            answer.push_back(i);
            break;
        }
    }
    return answer;

}




























