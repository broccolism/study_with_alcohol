#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string INPUT = "";
bool PALINDROM[2500][2500] = {};
int NUM_OF_PAL[2500] = {};

void fill_num(int len)
{
    for (int i = 0; i < len; ++i)
        {
            PALINDROM[i][i] = 1;
            if (i < len - 1)
                PALINDROM[i][i + 1] = INPUT[i] == INPUT[i + 1];
        }

        int extend;
        /*채우려는 칸 기준으로 ↙ 방향 칸의 정보가 필요하기 때문에
        for loop의 조건이 이모양임*/
        for (int i = len - 1; i > -1; --i)
        {
            for (int j = i + 2; j < len; ++j)
            {
                extend = INPUT[i] == INPUT[j];
                PALINDROM[i][j] = PALINDROM[i + 1][j - 1] && extend;
            }
        }
}

int minimum(int len)
{
    //initialize!
    NUM_OF_PAL[0] = 1;
    for (int i = 1; i < len; ++i)
        NUM_OF_PAL[i] = 2501;

    for (int i = 1; i < len; ++i)
    {
        for (int j = 0; j <= i; ++j)
            if (PALINDROM[j][i]) //can make new palindrom
                NUM_OF_PAL[i] = min(NUM_OF_PAL[i], NUM_OF_PAL[j - 1] + 1);

    }

    return NUM_OF_PAL[len - 1];
}

int main()
{
    //get input.
    cin >> INPUT;

    fill_num(INPUT.length());
    
    cout << minimum(INPUT.length()) << endl;
}