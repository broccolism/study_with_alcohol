#include <iostream>
#define INF 999999999
/*파일 하나의 크기 최대값은 1만이지만 더해지면 아닐 수 있으니까 이렇게 해주자*/
/*초기화 하는거 { -1, } 적기*/
/*ios::sync_with_stdio(false);
        cin.tie(0); 찾아적기*/

using namespace std;

int FILES[500] = {};
int MERGING_MEMORY[500][500] = {};
int MERGING_FILE[500][500] = {};

int dp(int num)
{
    //initialize first!
    for (int i = 0; i < num; ++i)
    {
        MERGING_MEMORY[i][i] = FILES[i];
        MERGING_FILE[i][i] = FILES[i];
        for (int j = i + 1; j < num; ++j)
        {
            MERGING_MEMORY[i][j] = INF;
        }
    }   

    int tmp_size;
    for (int diff = 0; diff < num; ++diff)
    {
        for (int i = 0; i < num - diff; ++i)
        {
            for (int mid = i; mid < i + diff; ++mid)
            {
                tmp_size = MERGING_MEMORY[i][mid] + MERGING_MEMORY[mid + 1][i + diff];
                if (mid - i > 0)
                    tmp_size += MERGING_FILE[i][mid];
                if (i + diff - mid - 1 > 0)
                    tmp_size += MERGING_FILE[mid + 1][i + diff];

                if (tmp_size < MERGING_MEMORY[i][i + diff])
                {
                    MERGING_FILE[i][i + diff] = MERGING_FILE[i][mid] + MERGING_FILE[mid + 1][i + diff];
                    MERGING_MEMORY[i][i + diff] = tmp_size;
                }
            }
/*
            cout << "================" << endl;
            for (int i = 0; i < num; ++i)
            {
                for (int j = 0; j < num; ++j)
                    cout << MERGING_MEMORY[i][j] << " ";
                cout << endl;
            }
            cout << "================" << endl;
            */
        }
    }

    int return_me = MERGING_MEMORY[0][num - 1];
    if (num == 1)
        return_me = 0;
        
    return return_me;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int REPEAT;
    int num_of_files;
    
    cin >> REPEAT;
    while (REPEAT > 0)
    {
        //get input!
        cin >> num_of_files;
        for (int i = 0; i < num_of_files; ++i)
            cin >> FILES[i];

        cout << dp(num_of_files) << '\n';
        --REPEAT;
    }
}