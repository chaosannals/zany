#include <sstream>
#include "WNTMistake.h"

std::string Aim::WNTMistake::Format(DWORD sign){
	HLOCAL local = nullptr;
	if (!FormatMessage(
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS |
		FORMAT_MESSAGE_ALLOCATE_BUFFER,
		nullptr, sign,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL),
		(PTSTR)&local, 0, nullptr))
		return "fail to format";
	if (local == nullptr)
		return "no text found for this error number";
	std::stringstream result;
	result << (PCTSTR)LocalLock(local);
	LocalFree(local);
	return result.str().c_str();
}
