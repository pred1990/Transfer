#include "Validate.h"


// TODO BA Check if the Ip Adress is valid. Maybe with REGEX?
bool Validate::ipAdress(std::string adress)
{
    return true;
}

// TODO BA Check if the filename is a valid path and a valid file
bool Validate::file(std::string fileName)
{
    struct stat s;
    int status;

    status = stat(fileName.c_str(), &s);

    if(status != 0) {
        printf ("Error with stat(), errno = %d\n", errno);
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
