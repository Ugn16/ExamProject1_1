#include <iostream>
#include "Sea_battle.h"
using namespace std;



void output_field(char any_array[][27], int arr[][27])
{
    int any_size1 = 12, any_size2 = 27;

    cout << "       Your Warships       " << "        Bot's Warships       " << endl;
    for (int i = 0; i < any_size1; i++)
    {
        for (int j = 0; j < any_size2; j++)
        {
            any_array[i][j] = ' ';
            arr[i][j] = 0;
        }
    }

    for (int i = any_size1 - 1, j = 0; j < any_size2; j++)
    {
        any_array[i][j] = '#';
        arr[i][j] = 9;
    }
    for (int i = 0, j = 0; i < any_size1 - 1; i++) 
    {
        any_array[i][j] = '#';
        arr[i][j] = 9;
    }
    for (int i = 0, j = any_size1; i < any_size1 - 1; i++) 
    {
        any_array[i][j] = '#';
        arr[i][j] = 9;
    }
    for (int i = 0, j = any_size1 + 1; i < any_size1 - 1; i++) 
    {
        any_array[i][j] = '#';
        arr[i][j] = 9;
    }
    for (int i = 0, j = any_size1 + 2; i < any_size1 - 1; i++) 
    {
        any_array[i][j] = '#';
        arr[i][j] = 9;
    }
    for (int i = 0, j = any_size2 - 1; i < any_size1 - 1; i++) 
    {
        any_array[i][j] = '#';
        arr[i][j] = 9;
    }
    any_array[1][1] = '1';
    any_array[2][1] = '2';
    any_array[3][1] = '3';
    any_array[4][1] = '4';
    any_array[5][1] = '5';
    any_array[6][1] = '6';
    any_array[7][1] = '7';
    any_array[8][1] = '8';
    any_array[9][1] = '9';
    any_array[10][1] = '0';
    any_array[10][0] = '1';

    arr[0][1] = 9;
    arr[1][1] = 9;
    arr[2][1] = 9;
    arr[3][1] = 9;
    arr[4][1] = 9;
    arr[5][1] = 9;
    arr[6][1] = 9;
    arr[7][1] = 9;
    arr[8][1] = 9;
    arr[9][1] = 9;
    arr[10][1] = 9;
    arr[10][1] = 9;


    any_array[1][15] = '1';
    any_array[2][15] = '2';
    any_array[3][15] = '3';
    any_array[4][15] = '4';
    any_array[5][15] = '5';
    any_array[6][15] = '6';
    any_array[7][15] = '7';
    any_array[8][15] = '8';
    any_array[9][15] = '9';
    any_array[10][15] = '0';
    any_array[10][14] = '1';

    arr[0][15] = 9;
    arr[1][15] = 9;
    arr[2][15] = 9;
    arr[3][15] = 9;
    arr[4][15] = 9;
    arr[5][15] = 9;
    arr[6][15] = 9;
    arr[7][15] = 9;
    arr[8][15] = 9;
    arr[9][15] = 9;
    arr[10][15] = 9;
    arr[10][14] = 9;

    any_array[0][2] = 'a';
    any_array[0][3] = 'b';
    any_array[0][4] = 'c';
    any_array[0][5] = 'd';
    any_array[0][6] = 'e';
    any_array[0][7] = 'f';
    any_array[0][8] = 'g';
    any_array[0][9] = 'h';
    any_array[0][10] = 'i';
    any_array[0][11] = 'j';

    arr[0][2] = 9;
    arr[0][3] = 9;
    arr[0][4] = 9;
    arr[0][5] = 9;
    arr[0][6] = 9;
    arr[0][7] = 9;
    arr[0][8] = 9;
    arr[0][9] = 9;
    arr[0][10] = 9;
    arr[0][11] = 9;

    any_array[0][16] = 'a';
    any_array[0][17] = 'b';
    any_array[0][18] = 'c';
    any_array[0][19] = 'd';
    any_array[0][20] = 'e';
    any_array[0][21] = 'f';
    any_array[0][22] = 'g';
    any_array[0][23] = 'h';
    any_array[0][24] = 'i';
    any_array[0][25] = 'j';

    arr[0][15] = 9;
    arr[0][16] = 9;
    arr[0][17] = 9;
    arr[0][18] = 9;
    arr[0][19] = 9;
    arr[0][20] = 9;
    arr[0][21] = 9;
    arr[0][22] = 9;
    arr[0][23] = 9;
    arr[0][24] = 9;
    arr[0][25] = 9;

    /*any_array[0][16] = 'À';
    any_array[0][17] = 'Á';
    any_array[0][18] = 'Â';
    any_array[0][19] = 'Ã';
    any_array[0][20] = 'Ä';
    any_array[0][21] = 'Å';
    any_array[0][22] = 'Æ';
    any_array[0][23] = 'Ç';
    any_array[0][24] = 'È';
    any_array[0][25] = 'Ê';*/


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