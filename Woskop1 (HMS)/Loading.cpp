#include"Header.h"

void Header::loading() 
{
    system("color 0a");
    cout << "\n\n\n\t\t\t\tPlease wait while loading\n\n";
    const char a = 177, b = 219;
    cout << "\t\t      ";
    for (int i = 0; i <= 50; i++) {
        cout << a;
    }

    cout << "\r";
    cout << "\t\t      ";
    for (int i = 0; i <= 50; i++)
    {
        cout << b;
        for (int j = 0; j <= 1e8; j++); //You can also use sleep function instead of for loop
    }
}