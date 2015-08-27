#include "Validate.h"

// TODO SW - implement to another place
bool Validate::ipAdress(std::string adress)
{
    return true;
}

bool Validate::file(std::string fileName)
{
    struct stat s;
    int status;

    status = stat(fileName.c_str(), &s);

    if(status != 0) {
        printf ("Error %s is not a File or either a File", fileName.c_str());
        return false;
    }

    if (S_ISREG (s.st_mode)) {
        //printf ("%s is a regular file.\n", fileName.c_str());
        return true;
    }
    if (S_ISDIR (s.st_mode)) {
        printf ("Error, %s is a directory.\n", fileName.c_str());
        return false;
    }

    return false;
}
