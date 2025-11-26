/**
 * a simple to-do list program.
 * 
 * will hopefully turn out very pretty in the terminal
 * 
 * important to do:
 * - clean up code
 * - proper documentation
 * 
 * GENERAL REMARKS
 * - any to do will follow a certain structure, for easier understanding later
 * - will likely use an ai or other model for that
 * - why? to make sure a "to do" isn't just a random string, but something like "do this (like this)" later (in order to not mix notes and to-do's)
 */
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <fstream>
#include <cstdlib>
#define color_reset         "\x1b[0m"
#define bold                "\x1B[1m"
#define reset_bold          "\x1B[22m"
#define cursive             "\x1b[3m"
#define reset_cursive       "\x1b[23m"

/* reference for colors and indentation for terminal outputs, see ANSI color codes 

// foreground
#define black               "\x1b[30m"
#define red                 "\x1b[31m"
#define green               "\x1b[32m"
#define yellow              "\x1b[33m"
#define blue                "\x1b[34m"
#define magenta             "\x1b[35m"
#define cyan                "\x1b[36m"
#define white               "\x1b[37m"
// background
#define background_black    "\x1b[40m"
#define background_red      "\x1b[41m"
#define background_green    "\x1b[42m"
#define background_yellow   "\x1b[43m"
#define background_blue     "\x1b[44m"
#define background_magenta  "\x1b[45m"
#define background_cyan     "\x1b[46m"
#define background_white    "\x1b[47m"
// foreground bright, 90s
// background bright, 100s
*/

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

/**
 * @brief Main function
 * @param argc Number of passed Arguments
 * @param argv The arguments (argv[0] holds the name of the program)
 */
int main(int argc, char** argv)
{
    // puts out name of program
    std::cout << std::endl << bold                  << terminalColor(cyan, foreground, bright)  << "starting: " << terminalColor(blue,foreground,bright) << reset_bold << argv[0] << terminalColor(cyan, foreground, bright) << ".exe" << color_reset;
    // notes for usage to user
    std::cout << std::endl                          << terminalColor(black,foreground,normal)   << terminalColor(white,background,normal)           << cursive     << bold << "\n\n\tNotes for usage:\n\n";
    std::cout << reset_cursive                      << terminalColor(red,foreground,normal)     << bold << "\tAvailable commands are: \n"           << color_reset << std::endl;
    std::cout << std::endl << "\t\tadd\t"           << terminalColor(black,foreground,normal)   << " (in order to add new \"to do\" entries)"       << color_reset << std::endl;
    std::cout << std::endl << "\t\tedit\t"          << terminalColor(black,foreground,normal)   << " (in order to edit some \"to do\" entries)"     << color_reset << std::endl;
    std::cout << std::endl << "\t\tdelete\t"        << terminalColor(black,foreground,normal)   << " (in order to delete some \"to do\" entries)"   << color_reset << std::endl;
    std::cout << color_reset;
    // NEXT STEP IMPLEMENT THESE THREE FEATURES FIRST YOU LACK OF ATTENTION SPAN / MOTIVATON / DEDICATION

    
    // Edit To-Do's
    // Add notes to To-Do's
    // Create/Save some To-Do's
    //// if no to-do's exist, ask to add the first
    std::ifstream existing("current.todo");
    if(existing.eof()) {
        std::cout << terminalColor(green, background, normal) << std::endl << "seems like there's nothing to do left for now!";// this could indicate initial startup or new setup, but also: an error could've occured
    }
    else {
        std::cout << terminalColor(yellow, background, normal) << std::endl << "seems like there's some stuff left over!";// this could indicate initial startup or new setup, but also: an error could've occured
    }
    std::cout << terminalColor(white, foreground, normal) << std::endl << "what do you want to do? ";
    std::string response;
    std::cin >> response;
    // consider: spelling mistakes could happen
    
    // consider: entered to-do's will be linguistically adjusted for later ease of reading/understanding
    // include: a feedback like "non interpretable"
    

    // Finish/Restore some old To-Do's
    //// for documentation of finished projects
    // Further assistment tools?

    std::cout << color_reset;
    return 0;
}
//
// leftover garbage. works but isnt't pretty
//
/**
     * PLAYING AROUND WITH ANSI COLOURS
     
    int reset = 13;// reset line background after 13 ~w~
    std::cout << color_reset << std::endl;
    // add some crazy, spectacular animations next
    for(int x = 0; x < 13000; x++)
    {   
        switch(x%2)
        {
            case 0:
                std::cout << terminalColor(black,foreground,normal);
                break;
            case 1:
                std::cout << terminalColor(white,foreground,normal);
                break;
        }
        switch(x%7)
        {
            case 0:
                std::cout << terminalColor(red,background,normal);
                std::cout << std:: flush << " ~w~  ~w~ ";
                break;
            case 1:
                std::cout << terminalColor(yellow,background,normal);
                std::cout << std:: flush << " ~w~  ~w~ ";
                break;
            case 2:
                std::cout << terminalColor(green,background,normal);
                std::cout << std:: flush << " ~w~  ~w~ ";
                break;
            case 3:
                std::cout << terminalColor(cyan,background,normal);
                std::cout << std:: flush << " ~w~  ~w~ ";
                break;
            case 4:
                std::cout << terminalColor(blue,background,normal);
                std::cout << std:: flush << " ~w~  ~w~ ";
                break;
            case 5:
                std::cout << terminalColor(magenta,background,normal);
                std::cout << std:: flush << " ~w~  ~w~ ";
                break;
            case 6:
                std::cout << terminalColor(white,background,bright);
                std::cout << std:: flush << " ~w~  ~w~ ";
                break;
        }
        std::this_thread::sleep_for(std::chrono::microseconds(130));
        if(x%reset==0) std::cout << std::endl;
        
    }
    
    std::cout << color_reset << std::endl << std::endl << std::endl;


    
    // Fake load time
    std::cout << terminalColor(magenta,foreground,normal) << "Fetching current to-do list.\r";
    std::this_thread::sleep_for(std::chrono::milliseconds(1300));
    std::cout << terminalColor(red,foreground,normal)  << "Fetching current to-do list..\r";
    std::this_thread::sleep_for(std::chrono::milliseconds(1300));
    std::cout << terminalColor(magenta,foreground,normal) << "Fetching current to-do list..." << std::endl << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1300));

     * STOP PLAYING AROUND WITH ANSI COLOURS
     */