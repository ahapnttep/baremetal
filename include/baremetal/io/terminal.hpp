#pragma once

#include <string>

namespace baremetal
{

class Terminal
{
public:
    virtual ~Terminal() = default;

    // Write text without automatically appending a newline.
    virtual void write(const std::string& text) = 0;

    // Write text followed by a newline.
    virtual void writeLine(const std::string& text) = 0;

    // Clear the active terminal frontend.
    virtual void clear() = 0;
};

}
