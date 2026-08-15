#pragma once

#include "baremetal/io/terminal.hpp"

namespace baremetal
{

class ConsoleTerminal final : public Terminal
{
public:
    // Write text to the host terminal.
    void write(const std::string& text) override;

    // Write a complete line to the host terminal.
    void writeLine(const std::string& text) override;

    // Clear an ANSI-compatible host terminal.
    void clear() override;
};

}
