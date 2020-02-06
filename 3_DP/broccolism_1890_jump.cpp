#include <iostream>

using namespace std;

int BOARD[101][101] = {};
long long CASE[101][101] = {};
int N;

/*dp() return type을 int로 해서 제출하니까 자꾸 틀림ㅋㅋ
으악*/
long long dp()
{
    CASE[0][0] = (long long)1;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int x = 1; x < 10; ++x)
            {
                //check vertical line first
                if (i - x > -1 && BOARD[i - x][j] == x)
                    CASE[i][j] += CASE[i - x][j];
                
                //check horizontal line
                if (j - x > -1 && BOARD[i][j - x] == x)
                    CASE[i][j] += CASE[i][j - x];                
            }
        }
    }

    return CASE[N - 1][N - 1];
}

int main()
{
    //get input!
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> BOARD[i][j];

    printf("%ld\n", dp());
}