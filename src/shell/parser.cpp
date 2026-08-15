#include "baremetal/shell/parser.hpp"

#include <sstream>

namespace baremetal
{

ParsedCommand CommandParser::parse(const std::string& input) const
{
    ParsedCommand result;

    std::istringstream stream(input);

    // Read the command name.
    stream >> result.name;

    std::string argument;

    // Read whitespace-separated command arguments.
    while (stream >> argument)
    {
        result.arguments.push_back(argument);
    }

    return result;
}

}