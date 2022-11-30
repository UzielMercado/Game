#include <iostream>
#include <fstream>

using namespace std;

void DrawMap(int HeroPosY, int HeroPosX, char GameMap[10][10])
{
    ofstream MyFile("MapSave.txt");

    if(MyFile.is_open())
    {
        for(int i = 0; i < 10; i = i + 1)
        {
            for(int p = 0; p < 10; p = p + 1)
            {
                if(i != HeroPosX)
                {
                    cout << GameMap[p][i];
                    MyFile << GameMap[p][i];
                }
                else
                {
                    if(p != HeroPosY)
                    {
                        cout << GameMap[p][i];
                        MyFile << GameMap[p][i];
                    }
                    else
                    {
                        cout << 'H';
                        MyFile << 'H';
                    }
                }
            }
            cout << endl;
            MyFile << endl;
        }
    }
    MyFile.close();
}

int main()
{
    int HeroPosX = 0;
    int HeroPosY = 0;
    bool IsGameOver = false;
    char Input = ' '; 
    char GameMap[10][10] = 
    {
        {'3','o','o','o','o','o','o','o','o','o'},
        {'o','o','o','o','o','o','o','o','o','o'},
        {'o','o','o','o','o','o','o','o','o','o'},
        {'o','o','o','o','o','o','o','o','o','o'},
        {'o','o','o','o','o','o','o','o','o','o'},
        {'o','o','o','o','o','o','o','o','o','o'},
        {'o','o','o','o','o','o','o','o','o','o'},
        {'o','o','o','o','o','o','o','o','o','o'},
        {'o','o','o','o','o','o','o','o','o','o'},
        {'o','o','o','o','o','o','o','o','o','o'}
    };

    DrawMap(HeroPosY, HeroPosX, GameMap);

    while (IsGameOver == false)
    {
        cin >> Input;

        if(Input == 'd')
        {
            HeroPosX = HeroPosX + 1;
        }
        else if(Input == 'a')
        {
            HeroPosX = HeroPosX - 1;
        }
        else if(Input == 'w')
        {
            HeroPosY = HeroPosY - 1;
        }
        else if(Input == 's')
        {
            HeroPosY = HeroPosY + 1;
        }
        else if(Input == 'p')
        {
            IsGameOver = true;
        }
        DrawMap(HeroPosX, HeroPosY, GameMap);
    }
    return 0;
}