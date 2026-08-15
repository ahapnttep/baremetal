#include "baremetal/shell/shell.hpp"

#include "baremetal/io/terminal.hpp"

namespace baremetal
{

Shell::Shell(Terminal& terminal)
    : terminal_(terminal)
{
}

void Shell::printBanner()
{
    terminal_.writeLine("BAREMETAL SYSTEM 0.0.1");
    terminal_.writeLine("Type 'help' for available commands.");
    terminal_.writeLine("");
}

ShellAction Shell::executeLine(const std::string& input)
{
    if (input.empty())
    {
        return ShellAction::Continue;
    }

    if (input == "help")
    {
        terminal_.writeLine("Built-in commands:");
        terminal_.writeLine("  help");
        terminal_.writeLine("  version");
        terminal_.writeLine("  clear");
        terminal_.writeLine("  exit");

        return ShellAction::Continue;
    }

    if (input == "version")
    {
        terminal_.writeLine("BAREMETAL SYSTEM 0.0.1");
        return ShellAction::Continue;
    }

    if (input == "clear")
    {
        terminal_.clear();
        return ShellAction::Continue;
    }

    if (input == "exit")
    {
        return ShellAction::Exit;
    }

    terminal_.write("Unknown command: ");
    terminal_.writeLine(input);

    return ShellAction::Continue;
}

}
