#include <Windows.h>
#include <strsafe.h>
#include <memory>
#include "Format.h"
#include "COMMistake.h"
#include "NilMistake.h"

namespace{
	template<typename F, typename T>
	size_t CountBy(F function, T text){
		size_t length = 0;
		Aim::NilMistake::Aver(text);
		Aim::COMMistake::Check(
			function(text, STRSAFE_MAX_CCH, &length),
			"fail to count text");
		return length + 1;
	}
	template<typename F, typename T>
	T *CloneBy(F function, const T *text){
		size_t size = Aim::Count(text);
		std::unique_ptr<T[]> result(new T[size]);
		Aim::COMMistake::Check(
			function(result.get(), size, text),
			"fail to clone text");
		return result.release();
	}
}

size_t Aim::Count(const char *text){
	return CountBy(StringCchLengthA, text);
}

size_t Aim::Count(const wchar_t *text){
	return CountBy(StringCchLengthW, text);
}

char *Aim::Clone(const char *text){
	return CloneBy(StringCchCopyA, text);
}

wchar_t *Aim::Clone(const wchar_t *text){
	return CloneBy(StringCchCopyW, text);
}

//打印本地日期[年-月-日]
std::ostream &Aim::Date(
	std::ostream &stream){
	SYSTEMTIME time;
	GetLocalTime(&time);
	return stream << '['
		<< time.wYear << '-'
		<< time.wMonth << '-'
		<< time.wDay << ']';
}

//打印本地时间[时:分:秒:毫秒]
std::ostream &Aim::Clock(
	std::ostream &stream){
	SYSTEMTIME time;
	GetLocalTime(&time);
	return stream << '['
		<< time.wHour << ':'
		<< time.wMinute << ':'
		<< time.wSecond << '.'
		<< time.wMilliseconds << ']';
}
