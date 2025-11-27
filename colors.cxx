#include "colors.h"

/**
 * @brief Change the color of the terminal output
 * @param c Any ANSI color
 * @param l Foreground or Background
 * @param b Normal or bright color
 */
std::string terminalColor(color c, layer l, brightness b)
{
    std::string out = "\x1b[";

    switch(l)
    {
        case foreground:
            switch (b)
            {
                case normal:
                    out.append("3");
                    break;
                case bright:
                    out.append("9");
                    break;
                default:
                    break;
            }
            break;
        case background:
            switch (b)
            {
                case normal:
                    out.append("4");
                    break;
                case bright:
                    out.append("10");
                    break;
                default:
                    break;
            }
            break;
    }

    switch(c)
    {
        case black:
            out.append("0");
            break;
        case red:
            out.append("1");
            break;
        case green:
            out.append("2");
            break;
        case yellow:
            out.append("3");
            break;
        case blue:
            out.append("4");
            break;
        case magenta:
            out.append("5");
            break;
        case cyan:
            out.append("6");
            break;
        case white:
            out.append("7");
            break;
    }
    out.append("m");
    return out;
}