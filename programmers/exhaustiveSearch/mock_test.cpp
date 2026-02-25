// 수포자는 수학을 포기한 사람의 준말입니다. 수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다. 수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.

// 1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
// 2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
// 3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

// 1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때, 가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요.

// 제한 조건
// 시험은 최대 10,000 문제로 구성되어있습니다.
// 문제의 정답은 1, 2, 3, 4, 5중 하나입니다.
// 가장 높은 점수를 받은 사람이 여럿일 경우, return하는 값을 오름차순 정렬해주세요.
// 입출력 예
// answers	return
// [1,2,3,4,5]	[1]
// [1,3,2,4,2]	[1,2,3]


#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers){
   vector<int> answer;

   // (크기, 초기값)에 맞는 값을 넣으면 된다.
   vector<int> correct(3, 0);  

   // 각 수포자의 찍은 패턴을 저장
    vector<vector<int>> people(3, vector<int>()); // 이런식으로 일정한 패턴을 배열에 넣은 다음 인덱스의 번호만 이동해서 하는 방법을 몰랐다
    people[0] = {1, 2, 3, 4, 5};                  // 나는 반복문을 통해서 직접 내가 값을 하나하나 넣었다  다음에 이러한 문제가 있으면 이러한 방식으로 해야겠다.
    people[1] = {2, 1, 2, 3, 2, 4, 2, 5};
    people[2] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    // 각 수포자의 현재 인덱스를 저장할 변수
    int idxFirstPeople = 0;
    int idxSecondPeople = 0;
    int idxThirdPeople = 0;

    for(int i : answers){
        // 각 수포자가 정답을 맞췄는지 확인
        i == people[0][idxFirstPeople] ? correct[0]++ : 0;  // 삼항 연산자에서 마지막에 0은 아무런 작동도 하지 말라는 뜻이다.
        i == people[1][idxSecondPeople] ? correct[1]++ : 0;
        i == people[2][idxThirdPeople] ? correct[2]++ : 0;

        // 각 수포자의 인덱스를 증가시키고 패턴 길이를 벗어나면 0으로 초기화
        ++idxFirstPeople == people[0].size() ? idxFirstPeople = 0 : 0;    // 먼저 ++를 해주고 연산을 하는 이유는 처음 인덱스를 0부터 시작했기 때문이다.
        ++idxSecondPeople == people[1].size() ? idxSecondPeople = 0 : 0;  
        ++idxThirdPeople == people[2].size() ? idxThirdPeople = 0 : 0;
    }
    // 가장 많이 맞춘 개수를 구함
    int max = *max_element(correct.begin(), correct.end()); // max_element가 값을 반환하는게 아니라 주소를 반환하기 때문에 '*'를 앞에 붙여준거다
                                                            // max_element()는 컨테이너 전체에서 최댓값을 찾을 때 사용하고 
                                                            // max()는 두개의 값을 비교할 때 사용하는 것이다.
                                                            // 다음에 컨테이너에서 최댓값 최솟값을 구해야할 때 사용하면 좋아보인다.
    
    // 가장 많이 맞춘 수포자를 결과에 추가
    for(int i = 0; i < correct.size(); i++){
        if(correct[i] == max){
            answer.push_back(i+1);
        }
    }
    return answer;
}
