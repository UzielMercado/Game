#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

void SaveMap(int HeroPosY, int HeroPosX, char GameMap[10][10])
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
                    MyFile << GameMap[p][i];
                }
                else
                {
                    if(p != HeroPosY)
                    {
                        MyFile << GameMap[p][i];
                    }
                    else
                    {
                        MyFile << '3';
                        HeroPosX = p;
                        HeroPosY = i;
                    }
                }
                HeroPosY = i;
                HeroPosX = p;
            }
            MyFile << endl;
        }
    }
    MyFile.close();
}

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

    string MapFile;
    ifstream MyFile("MapSave.txt");

    while (!MyFile.eof())
    {
        getline(MyFile, MapFile);
        cout << MapFile << endl;

    }
    
    int HeroPosX = 0;
    int HeroPosY = 0;
    bool IsGameOver = false;
    char Input = ' '; 
    char GameMap[10][10] = 
    {
        {'o','o','o','o','o','o','o','o','o','o'},
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
    SaveMap(HeroPosY, HeroPosX, GameMap);
    DrawMap(HeroPosY, HeroPosX, GameMap);

    while (IsGameOver == false)
    {
        cout << endl;
        cin >> Input;
        cout << endl;

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
            SaveMap(HeroPosY, HeroPosX, GameMap);
            IsGameOver = true;
        }
        DrawMap(HeroPosX, HeroPosY, GameMap);
    }
    return 0;
}