#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <wincon.h>
#include "fwarcaby.h"




int main()
{


SMALL_RECT okno = {0, 0, 29,19};//ustawienia okna konsoli
SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &okno);
COORD z;
    z.X = 30;
    z.Y = 20;
    SetConsoleScreenBufferSize( GetStdHandle( STD_OUTPUT_HANDLE ), z );//ustawia bufor konsoli
CONSOLE_CURSOR_INFO cciInfo;//wylacza kursor migajacy
   cciInfo.dwSize = 1;
   cciInfo.bVisible = 0;
   SetConsoleCursorInfo( GetStdHandle(STD_OUTPUT_HANDLE), &cciInfo );
   system( "chcp 852" );
   system( "cls" );
printf("\n\t!UWAGA!\nDla najlepszego efektu \nzmien czcionke na 10x18");
Sleep(3000);
system("cls");printf("efekt graficzny w konsoli xD");
Sleep(50);
for(;;){menu();}
    return 0;
}
