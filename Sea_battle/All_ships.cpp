#include <iostream>
#include "Sea_battle.h"
using namespace std;

void set_ship_bot(char any_arr[][27], int arr[][27], int ship_size)
{
    
    int any_direction, x1, x2, y1, y2, delta_x = 15;

    int Ok = 0,
        finder,
        
        
        change, i, j;

    
    finder = (ship_size - 1 + 3) * 3;
    while (Ok != finder)
    {
        any_direction = rand() % 2;
        x1 = rand() % 10 + 1;
        y1 = rand() % 10 + 1;
        if (any_direction == 0)
        {
            if (y1 < 5) y2 = y1 + ship_size;
            if (y1 >= 5) y2 = y1 - ship_size;
            x2 = x1;
        }

        if (any_direction == 1)
        {
            if (x1 < 5) x2 = x1 + ship_size;
            if (x1 >= 5) x2 = x1 - ship_size;
            y2 = y1;
        }

        if (x1 > x2)
        {
            change = x1;
            x1 = x2;
            x2 = change;
        }

        if (y1 > y2)
        {
            change = y1;
            y1 = y2;
            y2 = change;
        }
        
        x1 += delta_x;
        x2 += delta_x;

        if (y1 == y2)
        {
            for (i = y1 - 1; i < y1 + 2; i++)
            {
                for (j = x1 - 1; j < x1 + (finder / 3) - 1; j++)
                {
                    
                    if ((arr[i][j] == 0 || arr[i][j] == 9) && 
                           (arr[i][j] != 1 || arr[i][j] != 2 || arr[i][j] != 3 || arr[i][j] != 4))

                    {
                        Ok++;
                    }
                    else
                    {
                        Ok = 0;
                        y1 = i + 1; // go down
                        break;
                    }
                    
                }
                if (Ok == 0) break;
            }

            if (Ok == finder)
            {
                for (int set_ship = 0; set_ship < (finder / 3 - 2); set_ship++)
                {
                    any_arr[y1][x1 + set_ship] = 'W';
                    //arr[y1][x1 + set_ship] = set_ship + 1;
                    arr[y1][x1 + set_ship] = (finder / 3 - 2);
                }
            }

        }

        if (x1 == x2)
        {
            for (i = y1 - 1; i < y1 + (finder / 3) - 1; i++)
            {
                for (j = x1 - 1; j < x1 + 2; j++)
                {
                    if  ((arr[i][j] == 0 || arr[i][j] == 9) &&
                            (arr[i][j] != 1 || arr[i][j] != 2 || arr[i][j] != 3 || arr[i][j] != 4))
                    {
                        
                        Ok++;
                    }
                   
                    else
                    {
                        Ok = 0;
                        y1 = i + 1; // go down
                        break;
                    }
                }
                if (Ok == 0) break;
            }

            if (Ok == finder)
            {
                for (int set_ship = 0; set_ship < (finder / 3 - 2); set_ship++)
                {
                    any_arr[y1 + set_ship][x1] = 'W';
                  
                    arr[y1 + set_ship][x1] = (finder / 3 - 2);
                }
            }
        }
    }
           
            
}