#include <sstream>
#include "COMMistake.h"

std::string Aim::COMMistake::Format(HRESULT sign){
	std::stringstream result;
	result << "COM mistake sign:" << sign;
	return result.str();
}

