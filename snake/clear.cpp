#ifdef  linux
#define OS_Windows 0
#elif defined (__unix__)
#define OS_Windows 0
#else
#define OS_Windows 1
#include <windows.h>
#endif

#ifdef linux
#define CLEAR system("clear");
#elif defined(__unix__ )
#define CLEAR system("clear");
#else
void clrscr()
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    DWORD count;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hStdOut, &csbi);

    FillConsoleOutputCharacter(hStdOut, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

    SetConsoleCursorPosition(hStdOut, coord);
}
#define CLEAR clrscr();
#endif