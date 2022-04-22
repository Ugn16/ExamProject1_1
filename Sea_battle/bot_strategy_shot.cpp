#include <iostream>
#include "Sea_battle.h"
#include <windows.h>
#include <cmath>
using namespace std;

void bot_shot(char any_arr[][27], int arr[][27])
{
    int delta_x = 14, choice,
        i, j, x, y, finder = 0, destroyed1 = 0, destroyed2 = 0, destroyed = 0, count_shot = 0,
        x_hit, y_hit,  must_shot = 0;
    bool hit_player = 1, hit_bot = 1, v = 0, h = 0, north = 0, south = 0, west = 0, east = 0;
    char symbol;


    //int* any_count = &count_shot;

    cout << " 1 - Let the bot shoot randomly " << endl;
    cout << " 2 - Let the bot shoot like a player " << endl;
    cout << " ";
    cin >> choice;

    while (destroyed != 2)//10
    {
        while (hit_player) //выход в случае промаха
        {
            // ввод координат выстрела

            cout << " Take aim! Enter the coordinates " << endl;
            do {
                cout << " Any letter from 'a' to 'j' ";
                cin >> symbol;
                if (symbol == 'a') j = 2;
                if (symbol == 'b') j = 3;
                if (symbol == 'c') j = 4;
                if (symbol == 'd') j = 5;
                if (symbol == 'e') j = 6;
                if (symbol == 'f') j = 7;
                if (symbol == 'g') j = 8;
                if (symbol == 'h') j = 9;
                if (symbol == 'i') j = 10;
                if (symbol == 'j') j = 11;
            } while (symbol < char(97) || symbol > char(106));

            do {
                cout << " Any number from 1 to 10 ";
                cin >> i;

            } while (i < 1 || i > 10);

            system("cls");

            j += delta_x;

            // проверка попал-не попал

            // если не попал
            if (arr[i][j] == 0)
            {
                any_arr[i][j] = '*';
                hit_player = 0;
                hit_bot = 1;
                system("cls");
                output_ship(any_arr, arr);
                cout << " You missed \n ";
                cout << " Now bot... \n ";
                system("pause");
            }
            //если попал
            else if (arr[i][j] == 1 || arr[i][j] == 2 || arr[i][j] == 3 || arr[i][j] == 4)
            {
                //system("cls");
                hit_player = 1; //?
                hit_bot = 0;
                //count_player++; //счётчик попаданий


                x_hit = j; // очередное попадание 
                y_hit = i;


                any_arr[y_hit][x_hit] = 'X';
                arr[y_hit][x_hit] = 8;

                //count_player = 0;
                must_shot = 0;
                for (int n = x_hit; n > x_hit - 4; n--)
                {
                    if (arr[y_hit][n] == 0 || arr[y_hit][n] == 9)
                    {
                        break;
                    }

                    if (arr[y_hit][n] == 1 || arr[y_hit][n] == 2 ||
                        arr[y_hit][n] == 3 || arr[y_hit][n] == 4)
                    {
                        must_shot++;
                    }


                }

                for (int n = x_hit; n < x_hit + 4; n++)
                {
                    if (arr[y_hit][n] == 0 || arr[y_hit][n] == 9)
                    {
                        break;
                    }

                    if (arr[y_hit][n] == 1 || arr[y_hit][n] == 2 ||
                        arr[y_hit][n] == 3 || arr[y_hit][n] == 4)
                    {
                        must_shot++;
                    }

                }


                for (int n = y_hit; n > y_hit - 4; n--)
                {
                    if (arr[n][x_hit] == 0 || arr[n][x_hit] == 9)
                    {
                        break;
                    }

                    if (arr[n][x_hit] == 1 || arr[n][x_hit] == 2 ||
                        arr[n][x_hit] == 3 || arr[n][x_hit] == 4)
                    {
                        must_shot++;
                    }

                }

                for (int n = y_hit; n < y_hit + 4; n++)
                {
                    if (arr[n][x_hit] == 0 || arr[n][x_hit] == 9)
                    {
                        break;
                    }

                    if (arr[n][x_hit] == 1 || arr[n][x_hit] == 2 ||
                        arr[n][x_hit] == 3 || arr[n][x_hit] == 4)
                    {
                        must_shot++;
                    }

                }

                if (must_shot == 0)
                {
                    //system("cls");
                    destroyed1++;
                    //if (destroyed1 == 10)
                    if (destroyed1 == 2)
                    {
                        hit_player = 0;
                        hit_bot = 0;
                    }
                    output_ship(any_arr, arr);
                    cout << " The Warship is DESTROYED\n\a\a ";
                    //count_player = 0;
                    //finder = 0;
                    system("pause");
                }
                else
                {
                    system("cls");
                    output_ship(any_arr, arr);
                    cout << " You HIT! " << endl;
                    system("pause");
                }

            }

        }
        //if (destroyed1 == 10)
        if (destroyed1 == 2)
        {
            destroyed = destroyed1;
        }

        while (hit_bot)
        {
            switch (choice)
            {
            case 1:
                // ввод координат выстрела
                j = rand() % 10 + 2;
                i = rand() % 10 + 1;
                if (arr[i][j] == 0)
                {
                    any_arr[i][j] = '*';
                    hit_player = 1;
                    hit_bot = 0;
                    system("cls");
                    output_ship(any_arr, arr);
                    cout << " The bot missed \n ";
                    cout << " Now your shot... \n ";

                }
                else
                {
                    any_arr[i][j] = 'X';
                    arr[i][j] = 8;

                    x_hit = j; // очередное попадание 
                    y_hit = i;
                    for (int n = x_hit; n > x_hit - 4; n--)
                    {
                        if (arr[y_hit][n] == 0 || arr[y_hit][n] == 9)
                        {
                            break;
                        }

                        if (arr[y_hit][n] == 1 || arr[y_hit][n] == 2 ||
                            arr[y_hit][n] == 3 || arr[y_hit][n] == 4)
                        {
                            must_shot++;
                        }


                    }

                    for (int n = x_hit; n < x_hit + 4; n++)
                    {
                        if (arr[y_hit][n] == 0 || arr[y_hit][n] == 9)
                        {
                            break;
                        }

                        if (arr[y_hit][n] == 1 || arr[y_hit][n] == 2 ||
                            arr[y_hit][n] == 3 || arr[y_hit][n] == 4)
                        {
                            must_shot++;
                        }

                    }


                    for (int n = y_hit; n > y_hit - 4; n--)
                    {
                        if (arr[n][x_hit] == 0 || arr[n][x_hit] == 9)
                        {
                            break;
                        }

                        if (arr[n][x_hit] == 1 || arr[n][x_hit] == 2 ||
                            arr[n][x_hit] == 3 || arr[n][x_hit] == 4)
                        {
                            must_shot++;
                        }

                    }

                    for (int n = y_hit; n < y_hit + 4; n++)
                    {
                        if (arr[n][x_hit] == 0 || arr[n][x_hit] == 9)
                        {
                            break;
                        }

                        if (arr[n][x_hit] == 1 || arr[n][x_hit] == 2 ||
                            arr[n][x_hit] == 3 || arr[n][x_hit] == 4)
                        {
                            must_shot++;
                        }

                    }

                    if (must_shot == 0)
                    {
                        //system("cls");
                        destroyed2++;
                        if (destroyed2 == 10)
                        {
                            hit_player = 0;
                            hit_bot = 0;
                        }
                        output_ship(any_arr, arr);
                        cout << " The Warship is DESTROYED\n\a\a ";
                        //count_player = 0;
                        //finder = 0;
                        system("pause");
                    }
                    else
                    {
                        system("cls");
                        output_ship(any_arr, arr);
                        cout << " The bot hit " << endl;
                        system("pause");
                    }

                    if (destroyed1 == 10)
                    {
                        destroyed = destroyed1;

                    }
                }

                break;

            case 2:

                if (!north && !south && !west && !east)
                {
                    j = rand() % 10 + 2;
                    i = rand() % 10 + 1;

                    if (arr[i][j] == 0)
                    {
                        any_arr[i][j] = '*';
                        hit_player = 1;
                        hit_bot = 0;
                        system("cls");
                        output_ship(any_arr, arr);
                        cout << " The bot missed \n ";
                        cout << " Now your shot... \n ";
                        system("pause");
                    }
                    else if (count_shot == 0)
                    {
                        hit_player = 0; //?
                        hit_bot = 1;
                        //count_player++; //счётчик попаданий

                        x_hit = j; // очередное попадание 
                        y_hit = i;
                        west = 1; //считаем попадания

                    }
                }
                else if (north || south || west || east)
                {
                    any_arr[y_hit][x_hit] = 'X';
                    arr[y_hit][x_hit] = 8;
                    hit_player = 0; //?
                    hit_bot = 1;

                    if (arr[y_hit][x_hit - 1] == 9 || arr[y_hit][x_hit - 2] == 8)
                    {
                        if (count_shot == 0) west = 0;
                        else if (count_shot > 0)
                        {
                            east = 1;
                            x_hit = x_hit + count_shot;
                        }

                    }
                    else
                    {
                        west = 1;
                        x_hit = x_hit - 1;
                    }

                }

                else if (east) //(north || south || west || east)
                {
                    if (arr[y_hit][x_hit + 1] == 9 || arr[y_hit][x_hit + 2] == 8)
                    {
                        if (count_shot == 0) east = 0;
                        else if (count_shot > 0)
                        {
                            west = 1;
                            x_hit = x_hit - count_shot;
                            count_shot++;
                        }

                    }
                    else
                    {
                        east = 1;
                        x_hit = x_hit + 1;
                    }
                }

                else if (north) //(north || south || west || east)
                {
                    if (arr[y_hit - 1][x_hit] == 9 || arr[y_hit - 2][x_hit] == 8)
                    {
                        if (count_shot == 0) north = 0;
                        else if (count_shot > 0)
                        {
                            south = 1;
                            y_hit = y_hit + count_shot;
                            count_shot++;
                        }

                    }
                    else
                    {
                        north = 1;
                        y_hit = y_hit - 1;
                    }
                }

                else if (south) //(north || south || west || east)
                {
                    if (arr[y_hit + 1][x_hit] == 9 || arr[y_hit + 1][x_hit] == 8)
                    {
                        if (count_shot == 0) south = 0;
                        else if (count_shot > 0)
                        {
                            north = 1;
                            y_hit = y_hit - count_shot;
                            count_shot++;
                        }

                    }
                    else
                    {
                        south = 1;
                        y_hit = y_hit + 1;
                    }
                }

                //count_shot += 1;

                if (!south || !north || !east || !west)
                {
                    count_shot = 0;
                    cout << " The Warship is destroyed\n\a\a ";
                    system("pause");

                }
                else
                {
                    system("cls");
                    output_ship(any_arr, arr);
                    cout << " The bot hit! " << endl;
                    system("pause");
                }
                break;

            default:
                break;



            }
        }

    }

}
