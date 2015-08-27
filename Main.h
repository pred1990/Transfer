#pragma once

typedef long long int a;

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include "Types.h"
#include "Validate.h"
#include "Util.h"
#include "Network.h"


namespace Transfer
{
	const std::string IpAdress = "-IPADRESS";
	const std::string FileName = "-FILENAME";
	const std::string Listen   = "-LISTEN";
	const std::string Port     = "-PORT";

	enum Type {IPADRESS, FILENAME, Server, PORT, NONE};

	struct TransferRequest
	{
		std::string ipAdress;
		std::string fileName;

	//listen for incoming connections
		bool isServer;
		size_t port;
	};

	struct Parameter
	{
		Type type;
		std::string value;
	};


	TransferRequest completeRequest(Transfer::TransferRequest request, std::istream* input, std::ostream* output);
	TransferRequest getTransferRequest(char** input, size_t length);

	bool isMissingParameters(Transfer::TransferRequest request);
	Parameter convertToParameter(std::string input);
}


