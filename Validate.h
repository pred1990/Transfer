#pragma once

#include <string>
#include <errno.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>



namespace Validate
{
    bool ipAdress(std::string adress);
    bool file(std::string fileName);
}
