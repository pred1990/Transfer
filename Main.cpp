#include "Main"
int main(int length, char** argv)
{
	
	Transfer::TransferRequest request = Transfer::getTransferRequest(argv, (size_t)length);

	if(Transfer::isEmpty(request))
	{
		request = Transfer::getTransferRequest(&std::cin, &std::cout);
	}

	std::cout << "Target machine: " << request.ipAdress << std::endl;
}

/* 
 *	Reades the parameter of the programm and creates a TransferRequest 
*/
Transfer::TransferRequest Transfer::getTransferRequest(char** input, size_t length)
{
	Transfer::TransferRequest request = {}; 

	//check empty parameter
	if(length <= 0)
		return request;

	//convert the strings into a request
	for(size_t i = 0; i < length; ++i)
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

			 case NONE : 
				std::cout << "found CRAP" << std::endl;
			break;
		}
	}
	

	return request;

}

Transfer::TransferRequest Transfer::getTransferRequest(std::istream* input, std::ostream* output) { 
	Transfer::TransferRequest request = {};

	//TODO MSK pull this out to somthing that make sense 
	*output << "Please input the target machine adress" << std::endl;

	std::string adressMessage;
	*input >> adressMessage;

	//TODO MSK veryfy that the adress is valid
	request.ipAdress = adressMessage;
	request.fileName = ""; 


	return request;
}

bool Transfer::isEmpty(Transfer::TransferRequest request)
{
	
	if(request.ipAdress.empty() ||
	   request.fileName.empty())
	{
		return true;
	}
	return false;

}

Transfer::Parameter Transfer::convertToParameter(std::string input)
{
	Parameter parameter = {};
	parameter.type = NONE;

	std::istringstream stream(input);

	std::string type;


	//get Type specifyer
	std::getline(stream, type, '='); 
	std::transform(type.begin(), type.end(), type.begin(), ::toupper);


	//convert string to enum 
	// TODO MSK check if there is a better way 
	if(type.compare(IpAdress) == 0)
		parameter.type = IPADRESS;
	if(type.compare(FileName) == 0)
		parameter.type = FILENAME;

	if(parameter.type != NONE) 
		stream >> parameter.value;
	
	return parameter;
}
