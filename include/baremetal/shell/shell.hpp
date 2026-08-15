#pragma once

#include "baremetal/shell/parser.hpp"

#include <string>

namespace baremetal
{

class Terminal;

enum class ShellAction
{
    Continue,
    Exit
};

class Shell
{
public:
    // Create a shell connected to a terminal frontend.
    explicit Shell(Terminal& terminal);

    // Display the initial system banner.
    void printBanner();

    // Parse and execute one line of shell input.
    ShellAction executeLine(const std::string& input);

private:
    Terminal& terminal;
    CommandParser parser;
};

}