
#include <iostream>
#include "Sea_battle.h"
#include <cmath>
using namespace std;



void output_ship(char any_array[][27], int arr[][27])
{
    int any_size1 = 12, any_size2 = 27;
    

    cout << "       Your Warships       " << "        Bot's Warships       " << endl;

    for (int i = 0; i < any_size1; i++)
    {
        for (int j = 0; j < any_size2; j++)
        {
            cout << " " << any_array[i][j];
        }
        cout << endl;
    }

    /*for (int i = 0; i < any_size1; i++)
    {
        for (int j = 0; j < any_size2; j++)
        {
            cout << " " << arr[i][j];
        }
        cout << endl;
    }*/
}

void Set_my_ship(char any_array[][27], int arr[][27], int sq)
{
    
    int i, j, i2, j2, change, finder = 0, Ok = 0, y1, y2, x1, x2;
    char  symbol;

    
  
    do
    {
        cout << " Enter the first coordinates of the ship " << endl;
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



        if (sq != 1)
        {
            cout << " Enter the second coordinates of the ship " << endl;
            do {

                cout << " Any letter from 'a' to 'j' ";
                cin >> symbol;
                if (symbol == 'a') j2 = 2;
                if (symbol == 'b') j2 = 3;
                if (symbol == 'c') j2 = 4;
                if (symbol == 'd') j2 = 5;
                if (symbol == 'e') j2 = 6;
                if (symbol == 'f') j2 = 7;
                if (symbol == 'g') j2 = 8;
                if (symbol == 'h') j2 = 9;
                if (symbol == 'i') j2 = 10;
                if (symbol == 'j') j2 = 11;

            } while (symbol < char(97) || symbol > char(106));

            do {

                if (j2 == j)
                {
                    cout << " Any number from 1 to 10 ";
                    cin >> i2;
                    if (i > i2)
                    {
                        change = i;
                        i = i2;
                        i2 = change;
                    }
                    if (i2 - i + 1 > sq) i2 = i + sq - 1;
                    if (i2 - i + 1 < sq) i2 = i + sq - 1;

                }
                else
                {
                    i2 = i;
                    if (j > j2)
                    {
                        change = j;
                        j = j2;
                        j2 = change;
                    }
                    if (j2 - j + 1 > sq) j2 = j + sq - 1;
                    if (j2 - j + 1 < sq) j2 = j + sq - 1;

                }

            } while (i2 < 1 || i2 > 10);

        }
        else
        {
            j2 = j;
            i2 = i;
        }


       
        x1 = j;
        x2 = j2;
        y1 = i;
        y2 = i2;

        finder = (sq - 1 + 3) * 3;
        

        if (y1 == y2)
        {
            for (i = y1 - 1; i < y1 + 2; i++)
            {
                for (j = x1 - 1; j < x1 + (finder / 3) - 1; j++)
                {

                    if ((any_array[i][j] == ' ' ||
                        any_array[i][j] == '#' ||
                        (any_array[i][j] >= char(48) && any_array[i][j] <= char(57)) ||
                        (any_array[i][j] >= char(97) && any_array[i][j] <= char(106))) && any_array[i][j] != 'W')

                    {
                        Ok++;
                    }
                    else
                    {
                        Ok = 0;
                        cout << " Enter new correct coordinates of the ship. \n ";
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
                    any_array[y1][x1 + set_ship] = 'W';
                    arr[y1][x1 + set_ship] = set_ship + 1;
                }
                // for (j; j < j2 + 1; j++) any_array[i][j] = 'W';
            }

        }

        if (x1 == x2 && sq != 1)
        {
            for (i = y1 - 1; i < y1 + (finder / 3) - 1; i++)
            {
                for (j = x1 - 1; j < x1 + 2; j++)
                {
                    if ((any_array[i][j] == ' ' ||
                        any_array[i][j] == '#' ||
                        (any_array[i][j] >= char(48) && any_array[i][j] <= char(57)) ||
                        (any_array[i][j] >= char(97) && any_array[i][j] <= char(106))) && any_array[i][j] != 'W')
                    {
                        Ok++;
                    }
                    else
                    {
                        Ok = 0;
                        cout << " Enter new correct coordinates of the ship. \n " ;
                        y1 = i + 1; // go down
                        break;
                    }
                }
                if (Ok == 0) break;
            }
            if (Ok == finder && sq != 1)
            {
                for (int set_ship = 0; set_ship < (finder / 3 - 2); set_ship++)
                {
                    any_array[y1 + set_ship][x1] = 'W';
                    arr[y1 + set_ship][x1] = (finder / 3 - 2);
                }
            }
        }
    }while (Ok != finder);

        
   
}
    

void Set_my_ship_bot(char any_arr[][27], int arr[][27], int ship_size)
{

    int any_direction, x1, x2, y1, y2; 

    int Ok = 0,
        finder,


        change, i, j;


    finder = (ship_size - 1 + 3) * 3;
    while (Ok != finder)
    {
        any_direction = rand() % 2;
        x1 = rand() % 10 + 2; //!
        y1 = rand() % 10 + 1;
        if (any_direction == 0)
        {
            if (y1 < 5) y2 = y1 + ship_size;
            if (y1 >= 5) y2 = y1 - ship_size;
            x2 = x1;
        }

        if (any_direction == 1)
        {
            if (x1 < 7) x2 = x1 + ship_size;
            if (x1 >= 7) x2 = x1 - ship_size;
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

       
        if (y1 == y2)
        {
            for (i = y1 - 1; i < y1 + 2; i++)
            {
                for (j = x1 - 1; j < x1 + (finder / 3) - 1; j++)
                {

                    if ((any_arr[i][j] == ' ' ||
                        any_arr[i][j] == '#' ||
                        (any_arr[i][j] >= char(48) && any_arr[i][j] <= char(57)) ||
                        (any_arr[i][j] >= char(97) && any_arr[i][j] <= char(106))) && any_arr[i][j] != 'W')

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
                    if ((any_arr[i][j] == ' ' ||
                        any_arr[i][j] == '#' ||
                        (any_arr[i][j] >= char(48) && any_arr[i][j] <= char(57)) ||
                        (any_arr[i][j] >= char(97) && any_arr[i][j] <= char(106))) && any_arr[i][j] != 'W')
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