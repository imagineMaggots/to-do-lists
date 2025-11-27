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
 * 
 * ISSUES:
 * - the vector i use to store user strings does not hold entered strings at the end
 * - likely easily fixable by giving it a global scope for now
 * - tired from too little sleep over a longer time span
 */
#include "colors.cxx"
#include <regex>
#include <iterator>
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

bool feed = false;

/**
 * let's try to interpret a random user input string of characters. how fun. what could go wrong?
 * 
 * @brief Returns a command interpretation of the user cli input
 * @param user The user input string of random characters
 * 
 * // pretty straight forward
 * @return 0 for project management
 * @return 1 for schedule management
 * 
 * // these will be tricky
 * @return 2 for venting purposes (for random diary/journal entries; logged with timestamp)
 * @return 3 for contemplating life descisions (use ai to write summaries of the diary; with random notable quotes?)
 */
void interpret(std::vector<std::string> user)
{
    std::cout << terminalColor(yellow,foreground,bright) << "hello from interpretion module\n" << terminal_reset;
    /* just matching the user input to fixed commands won't help */
    std::regex word ("\\w+");
    // every string that the user may input
    for(std::string value : user)
    {
        std::cout << "\nread: "<< value;
    }
    for(std::string value : user)
    {
        // gets split into seperate words
        std::copy(
            std::sregex_token_iterator(value.begin(),value.end(),word,0),
            std::sregex_token_iterator(),
            // and put out word for word
            std::ostream_iterator<std::string>(std::cout, "\n")
        );
    }
    // to do
    return;
}

/**
 *  @brief Workflow for handling project-access
 */
void project () {
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
}


void userFeedback(std::vector<std::string> user)
{
    // no feedback yet
    feed = false;
    // but we're prepared
    std::string input;
    std::cin >> input;
    user.push_back(input);
    // there has been feedback, so let's reset the timer
    feed = true;
    // let's wait for more feedback?
    userFeedback(user);
}

/**
 * @brief waits for a specified amount of time after feedback has been received
 * @param time in seconds
 */
void waitForFeedback(int time)
{
    // we wait for some unspecified time, but at least three please
    if(time>2) 
        std::this_thread::sleep_for(std::chrono::seconds(time-3)); 
    
    // there has been feedback since the last call for wait?
    if(feed) {
        std::cout << terminalColor(cyan,foreground,bright) << "\n\treset timer" << terminal_reset;// to be removed
        waitForFeedback(time); // we obviously have to wait again
    }
    // we're waiting to evaluate the input. let's inform the user
    else {
        // count down from five
        for(int x = 5; x >0; x--) {
            // give the user a chance to intersect
            if(feed) {
                std::cout << terminalColor(cyan,foreground,bright) << "\n\treset timer" << terminal_reset;// to be removed
                waitForFeedback(time); // we obviously have to wait again
            }
            // last chance. we're counting down
            else{
                std::cout << "\rtime left: " << x << " seconds" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
            } 
        }
    }
    // we're done. return is implied here
    std::cout << terminalColor(cyan,foreground,bright) << "\n\tstopped waiting\n\n\n" << terminal_reset;// to be removed
}


void wait (int second)
{
    std::this_thread::sleep_for(std::chrono::seconds(second));
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

    // await user prompt
    std::cout << terminal_reset << "Whats next? ";
    std::vector<std::string> user;
    
    // to do: manage multiple user prompts!
    // userFeedback(user);
    // waitForFeedback(7);

    std::string cli;
    std::cin >> cli;
    user.push_back(cli);

    

    
    
    

    // we're impatiently waiting for the user to be done
    // since we're slower the user has the chance to reset the timer
    


    
    std::cout << "do we get here?\n";
    

    interpret(user); // what does he want/mean?
    /*
    switch(i)
    {
        case 0:
            project();
    }
    */


    std::cout << terminal_reset;
    return 0;
}
