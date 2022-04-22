#include <iostream>
#include "Sea_battle.h"
#include <windows.h>
#include <cmath>
using namespace std;

void ship_shot(char any_arr[][27], int arr[][27])
{
	int delta_x = 14, 
		i, j, finder = 0, destroyed1 = 0, destroyed2 = 0, destroyed = 0, 
        x_hit, y_hit, must_shot, count_hit_bot = 0, count_miss_bot = 0;
    bool hit_player = 1, hit_bot = 1, v = 0, h = 0, south = 0, north = 0, east = 0, west = 0;
    char symbol;
    

    //int* any_count = &count_shot;

	while(destroyed < 10)
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
                system("cls");
               
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
                    for (int n = x_hit ; n > x_hit - 4; n--)
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

                    for (int n = x_hit ; n < x_hit + 4; n++)
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
                    cout << " must_shot = " << must_shot;
                    if (must_shot == 0)
                    {
                        //system("cls");
                        destroyed1++;
                        //if (destroyed1 == 10)
                        if (destroyed1 == 2)
                        {
                            hit_player = 0;
                            hit_bot = 0;
                            destroyed = destroyed1;
                        }
                        system("cls");
                        output_ship(any_arr, arr);
                        cout << " The Warship is DESTROYED\n\a\a\a";
                        //count_player = 0;
                        //finder = 0;
                        system("pause");
                    }
                    else
                    {
                        system("cls");
                        output_ship(any_arr, arr);
                        cout << " You HIT!\a " << endl;
                        system("pause");
                    }
 
            }                   
            
        }
        

        while (hit_bot)
        {
            if (count_hit_bot == 0) //после уничтожения корабля или игра заново
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
                    west = 0;
                }
                else if (arr[i][j] != 0)
                {
                    any_arr[i][j] = 'X';


                    x_hit = j; // очередное попадание 
                    y_hit = i;

                    count_hit_bot = 1;
                    cout << "count_hit_bot >> " << count_hit_bot << endl;
                    if (arr[y_hit][x_hit] == 1)
                    {
                        //cout << " The Warship is destroyed\n\a\a\a";// корабль потоплен, ничего больше не проверяем, потому что все стороны проверены
                        destroyed2++;
                        destroyed = destroyed2;
                        hit_player = 0;
                        hit_bot = 1;

                        system("cls");
                        output_ship(any_arr, arr);
                        cout << " The Warship is destroyed\n\a\a\a";
                        arr[i][j] = 8;
                        system("pause");

                        west = 0;

                        count_hit_bot = 0;


                    }
                    else
                    {

                        system("cls");
                        output_ship(any_arr, arr);
                        cout << " The bot hit\a " << endl;
                        cout << " count_hit_bot++ " << count_hit_bot << endl;
                        arr[i][j] = 8;
                        system("pause");

                        hit_player = 0;
                        hit_bot = 1;
                        west = 1;
                    }

                }
            }
            
            if (west)
            {
                for (int n = x_hit; n > x_hit - 4; n--)
                {
                    if (arr[y_hit][n] == 0 || arr[y_hit][n] == 9)
                    {
                        if (arr[y_hit][n] == 9)
                        {
                            //count_miss_bot += 1;
                            west = 0;
                            east = 1;
                            break;
                        }
                        if (arr[y_hit][n] == 0) any_arr[y_hit][n] = '*'; // не попал
                        //any_arr[i][j] = '*';
                        hit_player = 1;
                        hit_bot = 0; //условие выхода из цикла

                        //count_miss_bot += 1; //считаем промахи
                        west = 0;
                        east = 1; // разворот на восток !!!! Это надо изменить

                        system("cls");
                        output_ship(any_arr, arr);
                        cout << " The bot missed \n ";
                        cout << " Now your shot... \n ";


                        break;
                    }

                    if (arr[y_hit][n] == 1 || arr[y_hit][n] == 2 ||
                        arr[y_hit][n] == 3 || arr[y_hit][n] == 4)
                    {
                        count_hit_bot++; //считаем попадания


                        any_arr[y_hit][n] = 'X'; //попал

                        if (arr[y_hit][n] != count_hit_bot)
                        {
                            west = 1; //продолжаем стрелять в том же направлении

                            system("cls");
                            output_ship(any_arr, arr);
                            cout << " The bot hit\a " << endl;
                            /*cout << " count_hit_bot++ " << count_hit_bot << endl;
                            cout << "arr[y_hit][n] >> " << arr[y_hit][n] << endl;*/
                            arr[y_hit][n] = 8;
                            system("pause");

                            hit_player = 0;
                            hit_bot = 1;
                        }
                        else if (arr[y_hit][n] == count_hit_bot)
                        {
                            system("cls");
                            output_ship(any_arr, arr);
                            cout << " The Warship is destroyed\n\a\a\a";
                            /*cout << " count_hit_bot++ " << count_hit_bot << endl;
                            cout << "arr[y_hit][n] >> " << arr[y_hit][n] << endl;*/
                            arr[y_hit][n] = 8;
                            system("pause");

                            destroyed2++;
                            destroyed = destroyed2; //считаем подбитые корабли
                            hit_player = 0;
                            hit_bot = 1;

                            west = 1; //при попадании в новый корабль снова нацеливаемся на запад
                            east = 0;
                            count_hit_bot = 0; // обнуляем счётчик попаданий
                            break;
                        }
                    }
                    //else must_shot_bot = 0;

                }

            }
            if (east && hit_bot)
            {
                for (int n = x_hit; n < x_hit + 4; n++)
                {
                    if (arr[y_hit][n] == 0 || arr[y_hit][n] == 9)
                    {
                        if (arr[y_hit][n] == 9)
                        {
                            count_miss_bot += 1;
                            north = 1;
                            east = 0;
                            break;
                        }
                        if (arr[y_hit][n] == 0) any_arr[y_hit][n] = '*'; // не попал
                                                
                        hit_player = 1;
                        hit_bot = 0; //выходим из цикла

                        east = 0;
                        north = 1; //разворачиваемся на север

                        system("cls");
                        output_ship(any_arr, arr);
                        cout << " The bot missed \n ";
                        cout << " Now your shot... \n ";

                        break;
                    }

                    if (arr[y_hit][n] == 1 || arr[y_hit][n] == 2 ||
                        arr[y_hit][n] == 3 || arr[y_hit][n] == 4)
                    {
                        
                        count_hit_bot++;


                        any_arr[y_hit][n] = 'X'; //попал

                        if (arr[y_hit][n] != count_hit_bot)
                        {
                            east = 1; //продолжаем стрелять в том же направлении

                            system("cls");
                            output_ship(any_arr, arr);
                            cout << " The bot hit\a " << endl;
                            /*cout << " count_hit_bot++ " << count_hit_bot << endl;
                            cout << "arr[y_hit][n] >> " << arr[y_hit][n] << endl;*/
                            system("pause");

                            hit_player = 0;
                            hit_bot = 1;
                            arr[y_hit][n] = 8;

                        }
                        else if (arr[y_hit][n] == count_hit_bot)
                        {
                            system("cls");
                            output_ship(any_arr, arr);
                            cout << " The Warship is destroyed\n\a\a\a";
                            /*cout << " count_hit_bot++ " << count_hit_bot << endl;
                            cout << "arr[y_hit][n] >> " << arr[y_hit][n] << endl;*/
                            system("pause");

                            destroyed2++;
                            destroyed = destroyed2; //считаем подбитые корабли
                            hit_player = 0;
                            hit_bot = 1;

                            west = 1; //при попадании в новый корабль снова нацеливаемся на запад
                            east = 0;
                            count_hit_bot = 0; // обнуляем счётчик попаданий
                            arr[y_hit][n] = 8;
                            break;
                        }

                    }

                }
            }

            if (north && hit_bot)
            {
                for (int n = y_hit; n > y_hit - 4; n--)
                {
                    if (arr[n][x_hit] == 0 || arr[n][x_hit] == 9)
                    {
                        if (arr[n][x_hit] == 9)
                        {
                            north = 0;
                            south = 1;
                            break;
                        }

                        if (arr[n][x_hit] == 0) any_arr[n][x_hit] = '*'; // не попал
                        //any_arr[i][j] = '*';
                        hit_player = 1;
                        hit_bot = 0;

                        system("cls");
                        output_ship(any_arr, arr);
                        cout << " The bot missed \n ";
                        cout << " Now your shot... \n ";

                        north = 0;
                        south = 1;
                        break;
                    }

                    if (arr[n][x_hit] == 1 || arr[n][x_hit] == 2 ||
                        arr[n][x_hit] == 3 || arr[n][x_hit] == 4)
                    {
                        any_arr[n][x_hit] = 'X';
                        count_hit_bot++;
                        if (arr[n][x_hit] != count_hit_bot)
                        {
                            //продолжаем стрелять в том же направлении

                            system("cls");
                            output_ship(any_arr, arr);
                            cout << " The bot hit\a " << endl;
                            /*cout << " count_hit_bot++ " << count_hit_bot << endl;
                            cout << "arr[n][x_hit] >> " << arr[n][x_hit] << endl;*/
                            system("pause");

                            hit_player = 0;
                            hit_bot = 1;
                            arr[n][x_hit] = 8;
                        }
                        else if (arr[n][x_hit] == count_hit_bot)
                        {
                            system("cls");
                            output_ship(any_arr, arr);
                            cout << " The Warship is destroyed\n\a\a\a";
                            /*cout << " count_hit_bot++ " << count_hit_bot << endl;
                            cout << "arr[n][x_hit] >> " << arr[n][x_hit] << endl;*/
                            system("pause");

                            destroyed2++;
                            destroyed = destroyed2; //считаем подбитые корабли
                            hit_player = 0;
                            hit_bot = 1;

                            west = 1; //при попадании в новый корабль снова нацеливаемся на запад
                            north = 0;
                            arr[n][x_hit] = 8;
                            count_hit_bot = 0;
                            //count_hit_bot = 0; // обнуляем счётчик попаданий
                            break;
                        }

                    }
                }
            }


            if (south && hit_bot)
            {
                for (int n = y_hit; n < y_hit + 4; n++)
                {

                    if (arr[n][x_hit] == 1 || arr[n][x_hit] == 2 ||
                        arr[n][x_hit] == 3 || arr[n][x_hit] == 4)
                    {
                        any_arr[n][x_hit] = 'X';
                        count_hit_bot++;
                        if (arr[n][x_hit] != count_hit_bot)
                        {
                            //продолжаем стрелять в том же направлении

                            system("cls");
                            output_ship(any_arr, arr);
                            cout << " The bot hit\a " << endl;
                            /*cout << " count_hit_bot++ " << count_hit_bot << endl;
                            cout << "arr[n][x_hit] >> " << arr[n][x_hit] << endl;*/
                            system("pause");

                            hit_player = 0;
                            hit_bot = 1;
                            arr[n][x_hit] == 8;
                        }
                        else if (arr[n][x_hit] == count_hit_bot)
                        {
                            system("cls");
                            output_ship(any_arr, arr);
                            cout << " The Warship is destroyed\n\a\a\a";
                            /*cout << " count_hit_bot++ " << count_hit_bot << endl;
                            cout << "arr[n][x_hit] >> " << arr[n][x_hit] << endl;*/
                            system("pause");

                            destroyed2++;
                            destroyed = destroyed2; //считаем подбитые корабли
                            hit_player = 0;
                            hit_bot = 1;

                            west = 1; //при попадании в новый корабль снова нацеливаемся на запад
                            south = 0;
                            count_hit_bot = 0; // обнуляем счётчик попаданий
                            arr[n][x_hit] = 8;
                            
                            break;
                        }

                    }
                    //else must_shot_bot = 0;
                }
            }


        }
    }

        
}
            

           

