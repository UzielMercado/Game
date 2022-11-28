#include <iostream>

using namespace std;

void DrawMap(int HeroPos, char GameMap[5])
{
    for(int i = 0; i < 5; i = i + 1)
    {
        if(i != HeroPos)
        {
            cout << GameMap[i];
        }
        else
        {
            cout << 'H';
        }
    }
}

int main()
{
    int HeroPos = 1;
    bool IsGameOver = false;
    char Input = ' '; 
    char GameMap[5] = {'1','1','1','1','1'};

    while (IsGameOver == false)
    {
        cin >> Input;

        if(Input == 'd')
        {
            HeroPos = HeroPos + 1;
        }
        else if(Input == 'a')
        {
            HeroPos = HeroPos + 1;HeroPos = HeroPos - 1;
        }
        DrawMap(HeroPos, GameMap);
    }
    return 0;
}