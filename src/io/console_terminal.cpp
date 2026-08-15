#include "baremetal/io/console_terminal.hpp"

#include <iostream>

namespace baremetal
{

void ConsoleTerminal::write(const std::string& text)
{
    std::cout << text;
}

void ConsoleTerminal::writeLine(const std::string& text)
{
    std::cout << text << '\n';
}

void ConsoleTerminal::clear()
{
    // Clear the screen and move the cursor to the top-left corner.
    std::cout << "\033[2J\033[H";
}

}
