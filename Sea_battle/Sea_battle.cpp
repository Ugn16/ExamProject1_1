// Sea_battle.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include "Sea_battle.h"
using namespace std;




int main()
{
    setlocale(0, "rus");
    srand(time(NULL));
    const int size1 = 12;
    const int size2 = 27;
    int choice;
    int x1 = 2, y1 = 2, x2 = 2, y2 = 5, any_size;
    char field1[size1][size2];
    int field2[size1][size2];

    output_field(field1, field2);
    cout << " 1 - Arrange your warships using the keyboard" << endl;
    cout << " 2 - Arrange your warships randomly " << endl;
    cout << " ";
    cin >> choice;
    switch (choice)
    { 
        case 1:
            any_size = 4;
            Set_my_ship(field1, field2, any_size);
            system("cls");
            output_ship(field1, field2);

            any_size = 3;
            Set_my_ship(field1, field2, any_size);
            system("cls");
            output_ship(field1, field2);

            any_size = 3;
            Set_my_ship(field1, field2, any_size);
            system("cls");
            output_ship(field1, field2);

            any_size = 2;
            Set_my_ship(field1, field2, any_size);
            system("cls");
            output_ship(field1, field2);

            any_size = 2;
            Set_my_ship(field1, field2, any_size);
            system("cls");
            output_ship(field1, field2);

            any_size = 2;
            Set_my_ship(field1, field2, any_size);
            system("cls");
            output_ship(field1, field2);

            any_size = 1;
            Set_my_ship(field1, field2, any_size);
            system("cls");
            output_ship(field1, field2);

            any_size = 1;
            Set_my_ship(field1, field2, any_size);
            system("cls");
            output_ship(field1, field2);

            any_size = 1;
            Set_my_ship(field1, field2, any_size);
            system("cls");
            output_ship(field1, field2);

            any_size = 1;
            Set_my_ship(field1, field2, any_size);
            system("cls");
            output_ship(field1, field2);

            break;

        case 2:
            any_size = 4;
            Set_my_ship_bot(field1, field2, any_size);
            any_size = 3;
            Set_my_ship_bot(field1, field2, any_size);
            any_size = 3;
            Set_my_ship_bot(field1, field2, any_size);
            any_size = 2;
            Set_my_ship_bot(field1, field2, any_size);
            any_size = 2;
            Set_my_ship_bot(field1, field2, any_size);
            any_size = 2;
            Set_my_ship_bot(field1, field2, any_size);
            any_size = 1;
            Set_my_ship_bot(field1, field2, any_size);
            any_size = 1;
            Set_my_ship_bot(field1, field2, any_size);
            any_size = 1;
            Set_my_ship_bot(field1, field2, any_size);
            any_size = 1;
            Set_my_ship_bot(field1, field2, any_size);

            system("cls");
            output_ship(field1, field2);
            break;
    default:
        break;
    }
    system("pause");
    system("cls");
    any_size = 4;
    set_ship_bot(field1, field2, any_size);
    any_size = 3;
    set_ship_bot(field1, field2, any_size);
    any_size = 3;
    set_ship_bot(field1, field2, any_size);
    any_size = 2;
    set_ship_bot(field1, field2, any_size);
    any_size = 2;
    set_ship_bot(field1, field2, any_size);
    any_size = 2;
    set_ship_bot(field1, field2, any_size);
    any_size = 1;
    set_ship_bot(field1, field2, any_size);
    any_size = 1;
    set_ship_bot(field1, field2, any_size);
    any_size = 1;
    set_ship_bot(field1, field2, any_size);
    any_size = 1;
    set_ship_bot(field1, field2, any_size);

    output_ship(field1, field2);

    cout << " 1 - Let the bot shoot randomly " << endl;
    cout << " 2 - Let the bot shoot like a player " << endl;
    cout << " ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << " Who shoots first? " << endl;
        cout << " 1 - The player shoots first " << endl;
        cout << " 2 - The bot shoots first " << endl;
        cin >> choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            ship_shot(field1, field2);
            break;
        case 2: 
            cout << " Sorry " << endl;
            break;
        default:
            break;
        }
        
        break;
    case 2: 
        ship_shot(field1, field2);
        break;
    default:
        break;
    }
    
   
    cout << "\n";
}

