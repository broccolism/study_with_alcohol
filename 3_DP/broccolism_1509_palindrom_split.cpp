#include <iostream>
#include <string>

using namespace std;

string IM_STRING = "";
bool PALINDROM[2500][2500] = { 0, };

void fill_true_false_table(int len)
{

    for (int i = 0; i < len; ++i)
    {
        PALINDROM[i][i] = 1;
        if (i < len - 1)
            PALINDROM[i][i + 1] = IM_STRING[i] == IM_STRING[i + 1];
    }

    bool extend;
    for (int i = len - 1; i > -1; --i)
    {
        for (int j = i + 2; j < len; ++j)
        {
            extend = IM_STRING[i] == IM_STRING[j];
            PALINDROM[i][j] = extend && PALINDROM[i + 1][j - 1];
        }
    }

    for (int i  =0; i < len; ++i)
    {
        cout << IM_STRING[i] << " ";
        for (int j  = 0; j < len; ++j)
            cout << PALINDROM[i][j] << " ";
        cout << endl;
    }
}

int find_the_best(int len)
{
    int return_me = 2500;
    
    int row = 0;
    int col = len - 1;
    while (row < len)
    {

    }

    return return_me;
}

int main()
{
    cin >> IM_STRING;
    int len = IM_STRING.length();

    fill_true_false_table(len);

    cout << find_the_best(len) << '\n';
}