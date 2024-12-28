#pragma once
#include <iostream>
#include <chrono>
#include <ctime>   

#ifdef WINDOWS
#include <windows.h>

#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#define DISABLE_NEWLINE_AUTO_RETURN  0x0008

#endif

namespace MP::DebugConsole
{
    enum class ConsoleColors
    {
        NC = -1,
        BLACK,
        RED,
        GREEN,
        YELLOW,
        BLUE,
        MAGENTA,
        CYAN,
        WHITE,
    };

    class DebugLog
    {
        public:
            static const std::string currentDateTime();
            static const char* colorize(ConsoleColors fontColor, int back = -1, int style = -1);
    };


    #define LOG(x) std::cout<< MP::DebugConsole::DebugLog::colorize(MP::DebugConsole::ConsoleColors::GREEN) << MP::DebugConsole::DebugLog::currentDateTime() << "[LOG]::" << x << MP::DebugConsole::DebugLog::colorize(MP::DebugConsole::ConsoleColors::NC) << std::endl;
    #define LOG_WARNING(x) std::cerr<< MP::DebugConsole::DebugLog::colorize(MMP::DebugConsole::ConsoleColors::YELLOW) << MP::DebugConsole::DebugLog::currentDateTime() << "[WARNING]::" << x << MP::DebugConsole::DebugLog::colorize(MP::DebugConsole::ConsoleColors::NC) << std::endl;
    #define LOG_ERROR(x) std::cerr<< MP::DebugConsole::DebugLog::colorize(MP::DebugConsole::ConsoleColors::RED) << MP::DebugConsole::DebugLog::currentDateTime() << "[ERROR]::" << x << MP::DebugConsole::DebugLog::colorize(MP::DebugConsole::ConsoleColors::NC) << std::endl;
    #define LOG_ERROR_THROW(x) LOG_ERROR(x) throw std::runtime_error(x);
}