#include <stdio.h>
#include <windows.h>
#include <queue>//1
using namespace std;//2

bool getconchar( KEY_EVENT_RECORD& krec )
{
    DWORD cc;
    INPUT_RECORD irec;
    HANDLE h = GetStdHandle( STD_INPUT_HANDLE );
    if (h == NULL)
        return false; // console not found
    for( ; ; )
    {
        ReadConsoleInput( h, &irec, 1, &cc );
        if( irec.EventType == KEY_EVENT
            &&  ((KEY_EVENT_RECORD&)irec.Event).bKeyDown
            )//&& ! ((KEY_EVENT_RECORD&)irec.Event).wRepeatCount )
        {
            krec= (KEY_EVENT_RECORD&)irec.Event;
            return true;
        }
    }
    return false; //future ????
}

int main( )
{
    KEY_EVENT_RECORD key;
    queue<KEY_EVENT_RECORD> Q;//3
    for( ; ; )
    {
        getconchar( key );
        Q.push(key);//4
        printf("%c;wVirtualKeyCode=%i\n",key.uChar.AsciiChar,key.wVirtualKeyCode);
    }
    //5
    while(Q.empty()==false)
	{
		key=Q.front();
		printf("%c;wVirtualKeyCode=%i\n",key.uChar.AsciiChar,key.wVirtualKeyCode);
    	Q.pop();
	}
}
