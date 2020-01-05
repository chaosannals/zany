#include <string>
#include <memory>
#include <sstream>
#include <fstream>
#include "Logger.h"
#include "Format.h"
#include "Mistake.h"
namespace{
	std::string MakePath(
		const char *directory,
		const char *name){
		std::stringstream date;
		Aim::Date(date);
		std::string path(directory);
		path += '\\' + date.str()
			+ name + ".log";
		return path;
	}
	std::unique_ptr<std::ofstream> OpenFile(
		const std::string &path){
		using std::ios;
		std::unique_ptr<std::ofstream> file(new std::ofstream);
		file->open(path, ios::out | ios::ate | ios::app);
		if (file->is_open())return file;
		auto reason = "fail to open file:" + path;
		throw Aim::Mistake(reason.c_str());
	}
}

Aim::Logger Aim::Logger::Direct(
	const char *directory,
	const char *name){
	auto path = ::MakePath(directory, name);
	auto file = ::OpenFile(path);
	return Manage(file.release());
}