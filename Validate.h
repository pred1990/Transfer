#pragma once

#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <iostream>
#include <fstream>


namespace Validate
{
    bool ipAdress(std::string adress);
    bool file(std::string fileName);
}
