#include "DebugConsole.h"

namespace MP::DebugConsole
{
    const std::string DebugLog::currentDateTime()
    {
        time_t     now = time(0);
        struct tm  tstruct;
        char       buf[80];
        localtime_s(&tstruct, &now);
        strftime(buf, sizeof(buf), "(%Y-%m-%d)-(%X)::", &tstruct);

        return buf;
    }

    const char* DebugLog::colorize(ConsoleColors fontColor, int back, int style)
    {
        static char code[20];
        int font = (int)fontColor;

        if (font >= 0)
            font += 30;
        else
            font = 0;
        if (back >= 0)
            back += 40;
        else
            back = 0;

        if (back > 0 && style > 0) {
            sprintf_s(code, "\033[%d;%d;%dm", font, back, style);
        }
        else if (back > 0) {
            sprintf_s(code, "\033[%d;%dm", font, back);
        }
        else {

            sprintf_s(code, "\033[%dm", font);
        }

        return code;
    }
}