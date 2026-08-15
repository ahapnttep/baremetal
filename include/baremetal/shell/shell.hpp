#pragma once

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

    // Execute a single line submitted to the shell.
    ShellAction executeLine(const std::string& input);

private:
    Terminal& terminal_;
};

}
