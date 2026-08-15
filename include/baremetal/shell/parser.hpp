#pragma once

#include <string>
#include <vector>

namespace baremetal
{

struct ParsedCommand
{
    std::string name;
    std::vector<std::string> arguments;
};

class CommandParser
{
public:
    // Parse raw shell input into a command name and arguments.
    ParsedCommand parse(const std::string& input) const;
};

}