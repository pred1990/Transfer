#include "Util"

size_t Util::toInt(const std::string string)
{
	char* end;
	long int value = strtol(string.c_str(), &end, 10);
	return (size_t)value;
}
