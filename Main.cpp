#include "Main.h"

//trying to figure out how git works
int main(int length, char** argv)
{
	Transfer::TransferRequest request = Transfer::getTransferRequest(argv, (size_t)length);

	if(Transfer::isMissingParameters(request))
	{
		request = Transfer::completeRequest(request, &std::cin, &std::cout);
	}

	std::cout << "### Target machine: " << request.ipAdress << std::endl;
	std::cout << "### File to transfer " << request.fileName << std::endl;
	std::cout << "### Starting as server: " << request.isServer << std::endl;
	std::cout << "### Port: " << request.port << std::endl;
        std::cout << "Basti was here... lol...xD...hacked.." << std::endl;
}

/*
 *	Reads the parameter of the programm and creates a TransferRequest
*/
Transfer::TransferRequest Transfer::getTransferRequest(char** input, size_t length)
{
	Transfer::TransferRequest request = {};

	//check empty parameter
	if(length <= 1)
		return request;

	//convert the strings into a request
	for(size_t i = 1; i < length; ++i)
	{
		//start parsing
		std::string inputString(input[i]);

		Parameter parameter = convertToParameter(inputString);

		switch(parameter.type)
		{
			case IPADRESS :
				std::cout << "found IPADRESS" << std::endl;
				request.ipAdress = parameter.value;
		     	break;

			case FILENAME :
				std::cout << "found FILENAME" << std::endl;
				request.fileName = parameter.value;
			break;

			case Server:
				std::cout << "found LISTEN" << std::endl;
				request.isServer = true;
			break;

			case PORT : 
				std::cout << "found PORT" << std::endl;
				request.port = Util::toInt(parameter.value);
			break;

			 case NONE :
				std::cout << "found CRAP: " << inputString << std::endl;
			break;
		}
	}

	return request;
}

Transfer::TransferRequest Transfer::completeRequest(Transfer::TransferRequest request, std::istream* input, std::ostream* output) {

    // Ask for Ip Adress
    if(request.ipAdress.empty())
    {
        std::string adress;

        do
        {
            *output << "Please input a valid adress to the target machine" << std::endl;
            *input >> adress;

        } while(!Validate::ipAdress(adress));

        request.ipAdress = adress;
    }

    // Ask for File Name
    if(request.fileName.empty())
    {
        std::string fileName;

        do
        {
            *output << "Please input a valid file" << std::endl;
            *input >> fileName;

        } while(!Validate::file(fileName));

        request.fileName = fileName;
    }

	return request;
}

bool Transfer::isMissingParameters(Transfer::TransferRequest request)
{
	//NOTE MSK should we consider -listen or -port?
    bool isMissing = false;

    // Is the Ip Adress missing?
	if(request.ipAdress.empty())
	{
		isMissing = true;
	}

    // Is the File Name missing?
	if(request.fileName.empty())
	{
		isMissing = true;
	}

    // if the programm is requested to listen as Server no other option applies
	if(request.isServer == true)
		isMissing = false;

	return isMissing;
}

Transfer::Parameter Transfer::convertToParameter(std::string input)
{
	Parameter parameter = {};
	parameter.type = NONE;

	std::istringstream stream(input);

	std::string type;


	//get Type specifier
	std::getline(stream, type, '=');
	std::transform(type.begin(), type.end(), type.begin(), ::toupper);


	//convert string to enum
	// TODO MSK check if there is a better way
	if(type.compare(IpAdress) == 0)
		parameter.type = IPADRESS;
	if(type.compare(FileName) == 0)
		parameter.type = FILENAME;
	if(type.compare(Listen) == 0)
		parameter.type = Server;
	if(type.compare(Port) == 0)
		parameter.type = PORT;

	if(parameter.type != NONE)
		stream >> parameter.value;
	std::cout << parameter.value;

	return parameter;
}
