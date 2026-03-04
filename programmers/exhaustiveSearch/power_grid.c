/*
n개의 송전탑이 전선을 통해 하나의 트리 형태로 연결되어 있습니다. 당신은 이 전선들 중 하나를 끊어서 현재의 전력망 네트워크를 2개로 분할하려고 합니다. 이때, 두 전력망이 갖게 되는 송전탑의 개수를 최대한 비슷하게 맞추고자 합니다.

송전탑의 개수 n, 그리고 전선 정보 wires가 매개변수로 주어집니다. 전선들 중 하나를 끊어서 송전탑 개수가 가능한 비슷하도록 두 전력망으로 나누었을 때, 두 전력망이 가지고 있는 송전탑 개수의 차이(절대값)를 return 하도록 solution 함수를 완성해주세요.

제한사항
n은 2 이상 100 이하인 자연수입니다.
wires는 길이가 n-1인 정수형 2차원 배열입니다.
wires의 각 원소는 [v1, v2] 2개의 자연수로 이루어져 있으며, 이는 전력망의 v1번 송전탑과 v2번 송전탑이 전선으로 연결되어 있다는 것을 의미합니다.
1 ≤ v1 < v2 ≤ n 입니다.
전력망 네트워크가 하나의 트리 형태가 아닌 경우는 입력으로 주어지지 않습니다.
입출력 예
n	wires	result
9	[[1,3],[2,3],[3,4],[4,5],[4,6],[4,7],[7,8],[7,9]]	3
4	[[1,2],[2,3],[3,4]]	0
7	[[1,2],[2,7],[3,7],[3,4],[4,5],[6,7]]	1
*/




#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int p[101]; // 전역 변수로 어떤 최고 부모와 연결되었는지 최고 부모는 얼마나 많은 자식들이 있는지 확인할 수 있는 배열 선언

// 재귀를 통해서 최고 부모가 누군지 반환하는 union-find algorithm에서 find 역할
int find(int idx){
    if(p[idx] < 0) return idx;
    return p[idx] = find(p[idx]);
}

// 연결되어 있는 노드들을 하나로 합치는 union-find algorithm에서 union 역할
bool uni(int u, int v){

    // u, v의 최고 부모가 누군지 찾는다
    u = find(u);
    v = find(v);

    // 최고의 부모가 같다면 false 반환
    if(u == v) return false;

    // 누가 더 높은 트리인지 확인하고 v가 더 높으면 u와 값 교환 이유는 마지막에 p[v] = u 하기 때문
    if(p[v] < p[u]){
        int tmp = u;
        u = v;
        v = tmp;
    }

    // 만약 트리의 높이가 같으면 u의 트리 높이를 더 높인다. 
    if(p[u] == p[v]) p[u]--;
    p[v] == u;
    return true;
}


// wires_rows는 2차원 배열 wires의 행 길이, wires_cols는 2차원 배열 wires의 열 길이입니다.
int solution(int n, int**wires, size_t wires_rows, size_t wires_cols){
    int answer = 100;
    for(int i = 0; i < 101; i++) p[i] = -1;
    
    // i는 나누는 기준이다. 예로 i = 0 일때 첫번째 전선을 나누어 각 계산을 한다.
    for(int i = 0; i < wires_rows; i++){
        int cnt = 0;
        
        // wires에 0~i 번째까지 union 함수를 통해서 한 팀으로 묶는다.
        for(int j = 0; j < i; j++){
            uni(wires[j][0], wires[j][1]);
        }

        // wires에 i+1~n 번째까지 union 함수를 통해서 한 팀으로 묶는다.
        for(int j = i+1; j < wires_rows; j++){
            uni(wires[j][0], wires[j][1]);
        }

        // 모든 노드를 돌면서 노드 1번과 몇개 연결되었는지 개수를 센다. 
        // 노드 1번과 하는 이유는 무조건 하나의 숫자는 항상 어느 팀에 속해있다. 그래서 그 기준을 1로 잡은것이다.
        // 기준으로 잡은 숫자의 속한 팀의 노드 개수를 센다.
        for(int j = 1; j <= n; j++){
            if(find(j) == find(1)) cnt++;
        }

        // i로 나누었을 때의 1번 노드가 속한 노드의 개수와 다른 팀의 노드 개수의 차이를 계산 
        cnt = abs(cnt - (n - cnt));
        if(answer > cnt) answer = cnt;

        // p 배열 -1로 초기화
        for(int j = 0; j <= n; j++) p[j] = -1;
    }

    return answer;
}
