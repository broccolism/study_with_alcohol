#include <iostream>
#include <algorithm>

using namespace std;

int INPUT[1000][1000] = {};
int DP[1000][1000] = {};
int R, C;

int moving()
{
    int put_me;

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            put_me = 0;

            if (i > 0 && j > 0)
                put_me = INPUT[i - 1][j - 1];
            if (i > 0)
                put_me = max(put_me, INPUT[i - 1][j]);
            if (j > 0)
                put_me = max(put_me, INPUT[i][j - 1]);

            INPUT[i][j] += put_me;            
        }
    }

    return INPUT[R - 1][C - 1];
}

int main()
{
    //get input.
    cin >> R >> C;

    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            cin >> INPUT[i][j];

    cout << moving() << endl;
}