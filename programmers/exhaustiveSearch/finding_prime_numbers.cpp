// 문제 설명
// 한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.

// 각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.

// 제한사항
// numbers는 길이 1 이상 7 이하인 문자열입니다.
// numbers는 0~9까지 숫자만으로 이루어져 있습니다.
// "013"은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.
// 입출력 예
// numbers	return
// "17"	      3
// "011"	  2


/*
 현재 코드에서는 사용을 안했지만 순열을 구하는 함수인 next_permutation이 있다. 
 이 함수는 do-while문과 함께 사용을 하고 반드시 오름차순 정렬된 상태에서 시작해야 모든 순열을 뽑을 수 있다. 
 예)
 int main() {
    vector<int> v = {1, 2, 3};

    // 1. 반드시 오름차순 정렬된 상태에서 시작해야 모든 순열을 뽑음
    sort(v.begin(), v.end());

    do {
        for(int i : v) cout << i << " ";
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));

    return 0;
 }
출력 결과
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/



#include <string>
#include <vector>
#include <set> 

using namespace std;

bool isPrime(int n) {
    // 1 이하의 숫자는 소수가 아님
    if (n <= 1) return false;
    
    // 2와 3은 소수
    if (n <= 3) return true;

    // 2나 3으로 나누어떨어지는지 미리 체크 (루프 횟수 감소)
    if (n % 2 == 0 || n % 3 == 0) return false;

    // 5부터 시작해서 제곱근까지만 확인
    // 6k ± 1 규칙을 사용하면 더 빠르지만, 보통 i * i <= n 만으로 충분
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

void backTracking(vector<bool>& check, 
                  vector<int>& unitNum, 
                  int size, 
                  int len, 
                  int value,
                  set<int>& foundNum){

    // 소수인지 체크
    if(isPrime(value)){
        foundNum.insert(value);  
    }

    // 새로 만든 숫자의 길이가 가지고 있는 숫자의 개수보다 크면 리턴
    if(len == size){        
        return;
    }

    for(int i = 0; i < size; i++){
        if(check[i] == false){
            check[i] = true;
            // 먼저 뽑은 숫자에 10를 곱해서 다음 숫자를 더해서 모든 숫자가 소수인지 체크를 한다.
            backTracking(check, unitNum, size, len+1, value * 10 + unitNum[i], foundNum);
            check[i] = false;
        }
    }   
}

int solution(string numbers) {
    int answer = 0;
    int size = numbers.size(); 
    vector<int> unitNum;    // 문자열의 숫자를 쪼개서 int형으로 변환해서 배열에 넣기 위한 vector
    vector<bool> check(size, false); // 숫자를 중복해서 사용하지 못하게 하기 위한 check용 vector
    set<int> foundNum;  // 중복으로 나오는 숫자를 막기 위한 set

    // 문자열을 쪼개서 숫자로 변환한다.
    for(char c : numbers){
        unitNum.push_back(c - '0');
    }
    
    for(int i = 0; i < size; i++){
        // 숫자를 중복으로 사용했는지 안했는지 확인을 한다.
        if(check[i] == false){
            check[i] = true;
            backTracking(check, unitNum, size, 1, unitNum[i], foundNum);
            check[i] = false;
        }
    }

    answer = foundNum.size();
    
    return answer;
}
