#include <iostream>
#include <bits/stdc++.h> 
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
                    
                }
                else
                {
                    if(p != HeroPosY)
                    {
                        
                    }
                    else
                    {
                        MyFile << p;
                        MyFile << i;
                    }
                }
            }
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
                        MyFile << p;
                        MyFile << i;
                    }
                }
            }
            cout << endl;
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
        //cout << MapFile << endl;

        string test = MapFile;

        char arr[test.length()+1]; 

        strcpy(arr, test.c_str()); 
        cout << endl;
        for (int i = 0; i < test.length(); i++) 
		    cout << arr[i]; 

    }
    cout << endl;
    
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

    while (IsGameOver == false)
    {
        DrawMap(HeroPosX, HeroPosY, GameMap);
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
    }
    return 0;
}