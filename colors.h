/**
 * stuff for terminal color manipulation
 */
#include <iostream>
#include <string>

enum layer {
    foreground, 
    background,
};
enum color {
    black, 
    red,
    green,
    yellow,
    blue,
    magenta,
    cyan,
    white,
};
enum brightness {
    normal,
    bright,
};


/**
 * @brief Change the color of the terminal output
 * @param c Any ANSI color
 * @param l Foreground or Background
 * @param b Normal or bright color
 */
std::string terminalColor(color c, layer l, brightness b);