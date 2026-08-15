#include "baremetal/io/console_terminal.hpp"
#include "baremetal/shell/shell.hpp"

#include <iostream>
#include <string>

int main()
{
    // Create the host terminal adapter.
    baremetal::ConsoleTerminal terminal;

    // Create the operating environment shell.
    baremetal::Shell shell(terminal);

    shell.printBanner();

    std::string input;

    while (true)
    {
        terminal.write("> ");

        // Read input only in the standalone host application.
        if (!std::getline(std::cin, input))
        {
            break;
        }

        if (shell.executeLine(input) == baremetal::ShellAction::Exit)
        {
            break;
        }
    }

    return 0;
}
