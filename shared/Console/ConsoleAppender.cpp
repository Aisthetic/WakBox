#include "consoleappender.h"

void ConsoleAppender::Write(ConsoleAppender::eColor color, QString message)
{ 
#ifdef Q_OS_WIN
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)color);
   WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), message.constData(), message.size(), NULL, NULL);
#else
    switch(color)
    {
        case ConsoleAppender::eColor::BLACK : message.prepend("\e[0;30m"); break;
        case ConsoleAppender::eColor::BLUE : message.prepend("\e[0;34m"); break;
        case ConsoleAppender::eColor::GREEN : message.prepend("\e[0;32m"); break;
        case ConsoleAppender::eColor::CYAN : message.prepend("\e[0;36m"); break;
        case ConsoleAppender::eColor::RED : message.prepend("\e[0;31m"); break;
        case ConsoleAppender::eColor::MAGENTA : message.prepend("\e[0;35m"); break;
        case ConsoleAppender::eColor::BROWN : message.prepend("\e[0;33m"); break;
        case ConsoleAppender::eColor::DARKGREY : message.prepend("\e[0;30m"); break;
        case ConsoleAppender::eColor::LIGHTGREY : message.prepend("\e[1;37m"); break;,
        case ConsoleAppender::eColor::LIGHTBLUE : message.prepend("\e[1;34m"); break;
        case ConsoleAppender::eColor::LIGHTGREEN : message.prepend("\e[1;32m"); break;
        case ConsoleAppender::eColor::LIGHTCYAN : message.prepend("\e[1;36m"); break;
        case ConsoleAppender::eColor::LIGHTRED : message.prepend("\e[1;31m"); break;
        case ConsoleAppender::eColor::LIGHTMAGENTA : message.prepend("\e[1;35m");break;
        case ConsoleAppender::eColor::YELLOW : message.prepend("\e[1;33m"); break;
        case ConsoleAppender::eColor::WHITE : message.prepend("\e[1;37m"); break;
    }

    message.append("\[\e[m\]");
    std::cout << message;
#endif
}
