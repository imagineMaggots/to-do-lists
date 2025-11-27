/**
 * progress tracking system
 * 
 * will hopefully turn out very pretty in the terminal
 * 
 * important to do:
 * - clean up code
 * - proper documentation
 * - sewerslide
 * 
 * GENERAL REMARKS
 * - any to do will follow a certain structure, for easier understanding later
 * - will likely use an ai or other model for that
 * - why? to make sure a "to do" isn't just a random string, but something like "do this (like this)" later (in order to not mix notes and to-do's)
 */
#include "colors.cxx"
#include <regex>
#include <time.h>
#include <chrono>
#include <thread>
#include <fstream>
#include <cstdlib>
#define terminal_reset      "\x1b[0m"
#define bold                "\x1B[1m"
#define reset_bold          "\x1B[22m"
#define cursive             "\x1b[3m"
#define reset_cursive       "\x1b[23m"


class projects {
    public:
        std::string alias;
        int updateTime ()
        {
            auto now = std::chrono::system_clock::now();
            auto nows = std::chrono::time_point_cast<std::chrono::seconds>(now);

            // expand the stored time to seconds 
            

            std::cout << "it's been " << getTime() << getPeriod() << " since you started working on this" << std::endl;

            return 0;
        }
        // stores the time in seconds
        int setTime (unsigned long long value)
        {
            this->time=value;
            std::cout << terminalColor(yellow,foreground,bright) << "updated some time" << terminal_reset;
            return 0;
        }
        // returns the passed time in seconds
        unsigned long long getTime ()
        {
            std::cout << terminalColor(yellow,foreground,bright) << "retrieved some time" << terminal_reset;
            return this->time;
        }
        int setPeriod (std::string p)
        {
            this->period = p;
        }
        std::string getPeriod ()
        {
            return this->period;
        }
    private:
        std::string name;
        unsigned long long time;// how much time has passed since the beginning. will hold the longest time spans only, i.e. days over hours, hours over minutes, ... to not store "20491203948414280984" seconds but the years passed (in this case. i doubt i'll be living for 20491203948414280984 more seconds though)
        std::string period;
};

int project () {
    std::cout << cursive << terminalColor(cyan,foreground,normal) << "\nproject editing\n" << reset_cursive;
    std::cout << terminalColor(blue,foreground,normal) << "do you want to add, edit or finish a project?\n" << terminal_reset;

    std::string user;
    std::cin >> user;

    if(user == "add")
    {
        std::cout << "\tcool! you got a name for it already?";
    }
    else if (user == "edit")
    {
        std::cout << "\tcool! which one?";
    }
    else 
    {
        std::cout << "\tyou actually finished something?";
    }

    return 0;
}

int main(int argc, char** argv)
{
    std::cout << terminal_reset << "starting" << terminalColor(cyan,foreground,normal) << " " << argv[0] << terminalColor(black,foreground,bright) << ".exe\n" << terminal_reset << std::endl;

    // try to load existing to do list, if it exists
    std::ifstream existing("current.todo");
    if(existing.eof()) {
        std::cout << terminalColor(green, background, normal) << std::endl << "Nothing left to do! ";// this could indicate initial startup or new setup, but also: an error could've occured
    }
    else {
        std::cout << terminalColor(yellow, foreground, normal) << std::endl << "Your current projects: \n";// this could indicate initial startup or new setup, but also: an error could've occured
    }

    std::cout << terminal_reset << "Whats next? ";
    std::string user;
    std::cin >> user;

    


    std::cout << terminal_reset;
    return 0;
}
