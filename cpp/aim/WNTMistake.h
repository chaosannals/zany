#ifndef AIM_WNTMISTAKE_H
#define AIM_WNTMISTAKE_H
#include <Windows.h>
#include <string>
#include "Mistake.h"
namespace Aim{
	class WNTMistake : public Mistake{
		DWORD sign;
		std::string report;
		static std::string Format(DWORD sign);
	public:
		WNTMistake(DWORD sign,
			const char *text) :
			Mistake(text),
			sign(sign),
			report(Format(sign)){}
		const char *why()const final{
			return report.c_str();
		}
		static void Check(DWORD sign,
			const char *text = "check"){
			if (sign != ERROR_SUCCESS)
				throw WNTMistake(sign, text);
		}
	};
}
#endif
