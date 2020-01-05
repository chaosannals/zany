#ifndef AIM_COMMISTAKE_H
#define AIM_COMMISTAKE_H
#include <Windows.h>
#include <string>
#include "Mistake.h"
namespace Aim{
	class COMMistake : public Mistake{
		HRESULT sign;
		std::string report;
		static std::string Format(HRESULT sign);
	public:
		COMMistake(HRESULT sign,
			const char *text) :
			Mistake(text),
			sign(sign),
			report(Format(sign)){}
		const char *why()const final{
			return report.c_str();
		}
		static void Check(HRESULT sign,
			const char *text = "check"){
			if (FAILED(sign))
				throw COMMistake(sign, text);
		}
	};
}
#endif
