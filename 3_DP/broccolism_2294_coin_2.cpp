#include <iostream>
#define INF 9999999;

using namespace std;

int NUM_COINS;
int GOAL;
int COINS[101] = {};
int CASE[100001] = {};

int dp()
{
    CASE[0] = 1;
    for (int i = 0; i < NUM_COINS; ++i)
        CASE[COINS[i]] = 1;

    int tmp_case;
    for (int i = 0; i <= GOAL; ++i)
    {
        for (int j = 0; j < NUM_COINS; ++j)
        {
            if (i - COINS[j] > -1)
            {
                tmp_case = CASE[i - COINS[j]] + CASE[COINS[j]];
                if (tmp_case <= CASE[i])
                    CASE[i] = tmp_case;
            }
        }       
    }

    if (CASE[GOAL] == 9999999/*INF 왜 안되지???? 오ㅒ? !?!*/) 
        return -1;
    else
        return CASE[GOAL];
}

int main()
{
    //get input!
    cin >> NUM_COINS >> GOAL;    
    for (int i = 0; i < NUM_COINS; ++i)
        cin >> COINS[i];

    //initialize!
    for (int i = 0; i <= GOAL; ++i)
        CASE[i] = INF;

    cout << dp() << endl;
}