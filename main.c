#include <windows.h>
#include <stdio.h>

int main() {

    HWND hwnd = GetForegroundWindow();

    // Get the screen resolution
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN) - 40;

    /*RECT rect;
    GetWindowRect(hwnd, &rect);
    int windowWidth = rect.right - rect.left;
    int windowHeight = rect.bottom - rect.top;*/

    RECT rect;
    RECT rect2;

    // Get the title of the window
    char title[256];
    GetWindowText(hwnd, title, 256);
    printf("Window title: %s\n", title);

    // printf("Window position: x=%d, y=%d\n", rect.left, rect.top);
    // printf("Window size: width=%d, height=%d\n", (rect.right - rect.left), (rect.bottom - rect.top) );
    // printf("Get the screen resolution: width=%d, height=%d\n", screenWidth, screenHeight );

    int max = 1;
    int counter = 0;
    int margin = 7;

    int offset = 15;
    int default_X = 0 + ( offset - margin );
    int default_Y = offset;
    int default_W = ((1927-margin)+14) - (offset)*2;
    int default_H = ((1040-margin)+14) - (offset)*2;

    MoveWindow( hwnd, default_X, default_Y, default_W , default_H , TRUE );

    // printf("default_W:%d\n", default_W );
    // printf("default_H:%d\n", default_H );

    GetWindowRect(hwnd, &rect);
    GetClientRect(hwnd, &rect2);

    /*MoveWindow( hwnd, rect.left , rect.top , default_W, default_H, TRUE );

    Sleep(1000);

    GetWindowRect(hwnd, &rect);

    MoveWindow( hwnd, default_X, default_Y, (rect.right - rect.left), (rect.bottom - rect.top), TRUE );*/

    while ( counter < max ) {

        GetWindowRect( hwnd, &rect );
        int window_width = rect.right - rect.left;
        int window_height = rect.bottom - rect.top;
        printf( "Window position: x=%d, y=%d\n", rect.left+7, rect.top/*, rect.right, rect.bottom*/ );

        int client_width  = (rect2.right - rect2.left) + 19;
        int client_height = (rect2.bottom - rect2.top) + 32;

        printf( "Print the size of the window area: width:%d, height:%d\n", window_width , window_height  );
        printf( "Print the size of the client area: width:%d, height:%d\n", client_width , client_height );
        printf( "Print the size of diff           : width:%d, height:%d\n", window_width-(client_width), window_height-(client_height) );
        printf( "Print the size of screen         : width:%d, height:%d\n", screenWidth, screenHeight );

        int TOP = rect.top + client_height;
        int LEFT = rect.left + client_width;

        // -17px height, detect horizontal scroll bar

        printf( "%d,%d\n", LEFT, TOP );
        printf( "margin: %d, margin right: %d\n", (screenWidth - LEFT)-7 , (screenHeight - TOP) - 17 );

        Sleep(1000);counter++;

    }

    return 0;
}

// MoveWindow( hwnd, screenWidth/2-(500/2) , screenHeight/2-(500/2) , 500 , 500 , TRUE );
