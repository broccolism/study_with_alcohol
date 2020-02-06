#include <iostream>

using namespace std;

int NUM_COINS, GOAL;
/* input이 1부터 100, 1부터 10000까지이고
내 코드에선 0부터 시작하지 않았는데
100, 10000칸씩만 할당해줘서 틀림ㅋㅋ*/
int COINS[101] = {};
int CASE[10001] = {};

int dp()
{
    CASE[0] = 1;

    /*아래 for loop에서 i, j 역할을 바꿔버리면 중복을 처리하지 못하고 계속 더한다.
    이처럼 중복 제거의 방식으로 for loop의 순서를 바꾸는 방식도 있음!*/
    for (int i = 0; i < NUM_COINS; ++i)
        for (int j = COINS[i]; j <= GOAL; ++j)
            CASE[j] += CASE[j - COINS[i]];

    return CASE[GOAL];
}

int main()
{
    ios::sync_with_stdio(false);

    //get input!
    cin >> NUM_COINS >> GOAL;
    for (int i = 0; i < NUM_COINS; ++i)
        cin >> COINS[i];

    cout << dp() << '\n';
}