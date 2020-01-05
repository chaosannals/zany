#ifndef AIM_LOGGER_H
#define AIM_LOGGER_H
#include <utility>
#include "Format.h"
#include "Interface.h"
#include "Implement.h"
#include "Pointer.h"
namespace Aim{
	class Logger final{
		struct LogStream : public Implement<Interface>{
			std::ostream *stream;
			LogStream(std::ostream *stream) :stream(stream){}
			virtual ~LogStream(){}
		};
		struct OwnStream : public LogStream{
			OwnStream(std::ostream *stream) :LogStream(stream){}
			virtual ~OwnStream(){ delete stream; }
		};
		Pointer<LogStream> stream;
		Logger(LogStream *stream) :stream(Appoint(stream)){}
	public:
		static Logger Manage(std::ostream *stream){
			return new OwnStream(stream);
		}
		static Logger Depend(std::ostream *stream){
			return new LogStream(stream);
		}
		static Logger Direct(const char *directory, const char *name);

		template<typename A, typename... AL> void Log(A a, AL... al){
			Log(std::forward<A>(a));
			Log(std::forward<AL>(al)...);
		}
		template<typename A> void Log(A a){
			*stream->stream << std::forward<A>(a);
		}
		template<typename A, typename... AL> void RTLog(A a, AL... al){
			Log(Clock, std::forward<A>(a), std::forward<AL>(al)...);
		}
	};
}
#endif
