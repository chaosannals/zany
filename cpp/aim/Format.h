#ifndef AIM_FORMAT_H
#define AIM_FORMAT_H
#include <cstddef>
#include <ostream>
namespace Aim{
	size_t Count(const char *text);
	size_t Count(const wchar_t *text);
	char *Clone(const char *text);
	wchar_t *Clone(const wchar_t *text);
	//换行
	inline std::ostream &EndLine(
		std::ostream &stream){
		return std::endl(stream);
	}
	//字符串0结尾
	inline std::ostream &EndString(
		std::ostream &stream){
		return std::ends(stream);
	}
	//刷新
	inline std::ostream &Flush(
		std::ostream &stream){
		return std::flush(stream);
	}
	//输出时间
	std::ostream &Date(std::ostream &);
	std::ostream &Clock(std::ostream &);
}
#endif
