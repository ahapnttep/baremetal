#include "baremetal/shell/shell.hpp"

#include "baremetal/io/terminal.hpp"

namespace baremetal
{

Shell::Shell(Terminal& terminal)
    : terminal(terminal)
{
}

void Shell::printBanner()
{
    terminal.writeLine("BAREMETAL SYSTEM 0.0.1");
    terminal.writeLine("Type 'help' for available commands.");
    terminal.writeLine("");
}

ShellAction Shell::executeLine(const std::string& input)
{
    const ParsedCommand command = parser.parse(input);

    if (command.name.empty())
    {
        return ShellAction::Continue;
    }

    if (command.name == "help")
    {
        terminal.writeLine("Built-in commands:");
        terminal.writeLine("  help");
        terminal.writeLine("  version");
        terminal.writeLine("  clear");
        terminal.writeLine("  exit");

        return ShellAction::Continue;
    }

    if (command.name == "version")
    {
        terminal.writeLine("BAREMETAL SYSTEM 0.0.1");
        return ShellAction::Continue;
    }

    if (command.name == "clear")
    {
        terminal.clear();
        return ShellAction::Continue;
    }

    if (command.name == "exit")
    {
        return ShellAction::Exit;
    }

    terminal.write("Unknown command: ");
    terminal.writeLine(command.name);

    return ShellAction::Continue;
}

}