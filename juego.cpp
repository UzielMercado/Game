#include <iostream>

using namespace std;

void DrawMap(int HeroPosX, int HeroPosY, char GameMap[5][5])
{
    for(int i = 0; i < 5; i = i + 1)
    {
        for(int p = 0; p < 5; p = p + 1)
        {
            if(i != HeroPosX)
            {
                cout << GameMap[p][i];
            }
            else
            {
                if(p != HeroPosY)
                {
                    cout << GameMap[p][i];
                }
                else
                {
                    cout << 'H';
                }
            }
        }
        cout << endl;
    }
}

int main()
{
    int HeroPosX = 1;
    int HeroPosY = 1;
    bool IsGameOver = false;
    char Input = ' '; 
    char GameMap[5][5] = 
    {
        {'1','1','1','1','1'},
        {'1','1','1','1','1'},
        {'1','1','1','1','1'},
        {'1','1','1','1','1'},
        {'1','1','1','1','1'}
    };

    DrawMap(HeroPosX, HeroPosY, GameMap);

    while (IsGameOver == false)
    {
        cin >> Input;

        if(Input == 'd')
        {
            HeroPosX = HeroPosX + 1;
        }
        else if(Input == 'a')
        {
            HeroPosX = HeroPosX + 1; HeroPosX = HeroPosX - 1;
        }
        else if(Input == 'w')
        {
            HeroPosY = HeroPosY + 1; HeroPosY = HeroPosY - 1;
        }
        else if(Input == 's')
        {
            HeroPosY = HeroPosY - 1; HeroPosY = HeroPosY - 1;
        }
        DrawMap(HeroPosX, HeroPosY, GameMap);
    }
    return 0;
}