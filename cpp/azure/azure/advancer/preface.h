#pragma once
namespace anx{
	namespace aze{
		class preface final : public advancer{
			camera shot;
			wnt::logger log;
			wnt::s_r<image> tiny;
			wnt::s_r<image> tiny2;
			preface() :
				log(wnt::logger::direct("log", "preface")),
				tiny(image::create("tiny.x")),
				tiny2(image::create("tiny.x")){
				log.log(">>>>start>>>>", wnt::clock, wnt::endl);
			}
		public:
			static wnt::u_r<preface> create();
			bool advance(float time,
				const wnt::di8::kbd_dev &keyboard,
				const wnt::di8::mus_dev &mouse,
				projector &screen)final;
			std::string submit()final;
		};
	}
}