    /* *****************************
    으악
    cin 처리하는거랑 묶어서 출력하는거 main 함수 안에 있음
    확인할 것!
    */
    
    #include <iostream>

    using namespace std;

    int SEQUENCE[2000] = {};
    bool PALINDROM[2000][2000] = {};

    int LEN, QUESTIONS, S, E;

    void dp()
    {
        for (int i = 0; i < LEN; ++i)
        {
            PALINDROM[i][i] = 1;
            if (i < LEN - 1)
                PALINDROM[i][i + 1] = (SEQUENCE[i] == SEQUENCE[i + 1]);
        }

        int prev;
        for (int i = LEN - 1; i > -1; --i)
        {
            for (int j = i + 2; j < LEN; ++j)
            {
                prev = (SEQUENCE[i] == SEQUENCE[j]);
                PALINDROM[i][j] = (PALINDROM[i + 1][j - 1] && prev);
            }
        }
    }

    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);

        cin >> LEN;
        for (int i = 0; i < LEN; ++i)
            cin >> SEQUENCE[i];
        
        dp();    
    /*
        cout << "=============" << '\n';
        for (int i = 0; i < LEN; ++i)
        {
            for (int j = 0; j < LEN; ++j)
                cout << PALINDROM[i][j] << " ";
            cout << '\n';
        }
        cout << "=============" << '\n';
    */    
        cin >> QUESTIONS;
        while (QUESTIONS > 0)
        {
            cin >> S >> E;
            
            //hoxy...몰라서...
            if (E < S)
            {
                int tmp = E;
                E = S;
                S = tmp;
            }
            
            cout << PALINDROM[S - 1][E - 1] << '\n';
            --QUESTIONS;
        }
    }