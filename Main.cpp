#include "Main"
int main(int length, char** argv)
{
	
	Transfer::TransferRequest request = Transfer::getTransferRequest(argv, (size_t)length);

	if(Transfer::isEmpty(request))
	{
		request = Transfer::getTransferRequest(&std::cin);
	}

	std::cout << "This is a Simple Test please enter a number and the porgramm will exit" << std::endl;
	int a = 0;
	std::cin >> a; 
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

	//start parsing 
	std::stringstream stream;
	std::string inputString(input[0]);
	

	return request;

}

Transfer::TransferRequest Transfer::getTransferRequest(std::istream* input)
{
	return {};
}

bool Transfer::isEmpty(Transfer::TransferRequest request)
{
	if(!request.ipAdress.empty() ||
		 !request.file.empty())
	{
			return true;
	}
	return false;

}




