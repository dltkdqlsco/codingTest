/*
 * 문제 설명
n개의 송전탑이 전선을 통해 하나의 트리 형태로 연결되어 있습니다. 당신은 이 전선들 중 하나를 끊어서 현재의 전력망 네트워크를 2개로 분할하려고 합니다. 이때, 두 전력망이 갖게 되는 송전탑의 개수를 최대한 비슷하게 맞추고자 합니다.

송전탑의 개수 n, 그리고 전선 정보 wires가 매개변수로 주어집니다. 전선들 중 하나를 끊어서 송전탑 개수가 가능한 비슷하도록 두 전력망으로 나누었을 때, 두 전력망이 가지고 있는 송전탑 개수의 차이(절대값)를 return 하도록 solution 함수를 완성해주세요.

제한사항
n은 2 이상 100 이하인 자연수입니다.
wires는 길이가 n-1인 정수형 2차원 배열입니다.
wires의 각 원소는 [v1, v2] 2개의 자연수로 이루어져 있으며, 이는 전력망의 v1번 송전탑과 v2번 송전탑이 전선으로 연결되어 있다는 것을 의미합니다.
1 ≤ v1 < v2 ≤ n 입니다.
전력망 네트워크가 하나의 트리 형태가 아닌 경우는 입력으로 주어지지 않습니다.
입출력 예
n	                      wires                         result
9	[[1,3],[2,3],[3,4],[4,5],[4,6],[4,7],[7,8],[7,9]]	  3
4	              [[1,2],[2,3],[3,4]]	                  0
7	         [[1,2],[2,7],[3,7],[3,4],[4,5],[6,7]]        1
*/


// 이 헤더는 C++에서 제공하는 거의 모든 표준 라이브러리를 한 번에 포함하는 만능 헤더이다.
// 장점 : 코테를 볼 때 일일이 헤더를 기억하지 못한다 그래서 이 헤더 하나면 고민할 필요 없이 바로 코딩을 할 수 있다. 
// 단점 : GCC 전용이다. vs 같은 다른 환경에서는 기본적으로 작동하지 않는다,
//        필요 없는 라이브러리까지 불어오기 때문에 컴파일 시간이 길어진다ㅑ.(실행 속도에는 차이가 없다.)
// 
// 알고리즘 문제 풀이용으로는 최고지만, 실무 프로젝트나 표준을 중시하는 개발 환경에서는 권장되지 않는 도구이다.
#include <bit/stdc++.h>

using namespace std;

// vector<int> graphs[] 이차원 배열이라고 생각하면 된다. 행은 고정된 값이 들어오는거고 열은 vector로 자동으로 관리를 해준다. 
// 그럼 vector<vector<int>> graphs와 뭔 차이가 있냐면 
// vector<int> graphs[]는 메모리 관리 면에서 약간 더 효율적이다.
// vector<vector<int>> graphs는 메모리는 얼마나 쓸지 미리 알 수 없어서 유연함이 더 뛰어나다.
int BFS(vector<int> graphs[], int n){

    int count = 0; 
    bool visits[101] = {false,}; // 중복 방문을 막기 위한 배열
    queue<int> q;   // 연결된 노드들을 찾기 위한 큐
    q.push(n);  // 먼저 끊은 전선 n을 q에 삽입
    visits[n] = true;   // 방문 표시 
    while(!q.empty()){  
        int current = q.front(); // 끊어진 전선 n과 연결된 노드가 있는지 확인하기 위한 인덱스
        q.pop();
        for(auto nxt : graphs[current]){ // 노드 n과 연결된 모든 노드 방문하기
            if(visits[nxt]) continue;
            q.push(nxt);    // 연결된 노드가있으면 큐에 삽입 
            visits[nxt] = true;
            count++;
        }
    }

    return count;
}

int solution(int n, vector<vector<int>> wires){

    int answer = 105;

    int sizes = wires.size();
    for(int n = 0; n < sizes; n++){ 
        vector<int> v[105];     // 끊기로한 전선을 제외하고 연결된 노드들을 저장하기 위한 배열
        int n1, n2;
        int count1, count2;

        for(int i = 0; i < sizes; i++){
            // 끊을 노드 선택
            if(n == i){
                // 끊을 노드의 값을 변수에 저장
                n1 = wires[n][0];
                n2 = wires[n][1];
                continue;
            }

            // 끊은 노드를 제외하고 연결된 노드들을 배열에 삽입
            v[wires[i][0]].push_back(wires[i][1]);
            v[wires[i][1]].push_back(wires[i][0]);
        }
        // 끊기로 한 노드의 값을 BFS함수에 전달해 각각 몇개의 노드들과 연결되어있는지 확인
        count1 = BFS(v, n1);
        count2 = BFS(v, n2);
        // 더 작은 값을 answer에 저장ector<int> graphs[]는 메모리 관리 면에서 약간 더 효율적이다.
int BFS(vector<int> graphs[], int n){

    int count = 0;
    bool visits[101] = {false,}; // 중복 방문을 막기 위한 배열
    queue<int> q;   // 연결된 노드들을 찾기 위한 큐
    q.push(n);  // 먼저 끊은 전선 n을 q에 삽입
    visits[n] = true;   // 방문 표시
    while(!q.empty()){
        q.pop();
        for(auto nxt : graphs[current]){ // 노드 n과 연결된 모든 노드 방문하기
            if(visits[nxt]) continue;
            q.push(nxt);    // 연결된 노드가있으면 큐에 삽입
            visits[nxt] = true;
            count++;
        }
    }
        if(answer > abs(count1 - count2)) answer = abs(count1 - count2);
    }

    return answer;
}
