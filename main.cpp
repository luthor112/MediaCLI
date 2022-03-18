#include <windows.h>
#include <stdio.h>

#define RELEASE

int wmain(int argc, wchar_t* argv[])
{
    if (argc != 2)
        return 1;

    INPUT ip = { 0 };
    ip.type = INPUT_KEYBOARD;
    if (argv[1][0] == 'p')
        ip.ki.wVk = VK_MEDIA_PREV_TRACK;
    else if (argv[1][0] == 'x')
        ip.ki.wVk = VK_MEDIA_PLAY_PAUSE;
    else if (argv[1][0] == 'n')
        ip.ki.wVk = VK_MEDIA_NEXT_TRACK;
    else
        ip.ki.wVk = VK_VOLUME_MUTE;
    SendInput(1, &ip, sizeof(INPUT));
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));

    return 0;
}
