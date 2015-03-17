#ifndef CONSOLEAPPENDER_H
#define CONSOLEAPPENDER_H

#include <QObject>
#include <QtGlobal>

#ifdef Q_OS_WIN
#include <Windows.h>
#include <iostream>
#endif

/**
 * @brief Helper for display message in console on color
 */
class ConsoleAppender : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief All color available for the console
     */
    enum eColor
    {
        BLACK = 0,
        BLUE = 1,
        GREEN = 2,
        CYAN = 3,
        RED = 4,
        MAGENTA = 5,
        BROWN = 6,
        LIGHTGREY = 7,
        DARKGREY = 8,
        LIGHTBLUE = 9,
        LIGHTGREEN = 10,
        LIGHTCYAN = 11,
        LIGHTRED = 12,
        LIGHTMAGENTA = 13,
        YELLOW = 14,
        WHITE = 15
    };

    /**
     * @brief Write message on console
     * @param color wanted color
     * @param message wanted message
     */
    static void Write(eColor color, QString message);
    static void WriteLine(eColor color, QString message) { Write(color, message.append('\n')); }
};

#endif // CONSOLEAPPENDER_H
