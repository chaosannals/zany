#pragma once

namespace anx{
	namespace aze{
		class environment{
			wnt::wnd_cls type;
			HWND window;
			advancer *worker;
			wnt::u_r<advancer> preface;
			wnt::u_r<advancer> content;
			wnt::u_r<advancer> context;
			wnt::di8::dev_fty device_factory;
			wnt::u_r<wnt::di8::kbd_dev> keyboard;
			wnt::u_r<wnt::di8::mus_dev> mouse;
			wnt::u_r<projector> screen;
			wnt::clocker clock;
			wnt::logger log;
			environment(
				wnt::wnd_cls type,
				HWND window,
				advancer *preface,
				wnt::di8::dev_fty device,
				wnt::di8::kbd_dev *keyboard,
				wnt::di8::mus_dev *mouse,
				projector *screen) :
				type(type), window(window),
				worker(preface), preface(preface),
				device_factory(device),
				keyboard(keyboard),
				mouse(mouse),
				screen(screen),
				clock(wnt::clocker::create()),
				log(wnt::logger::direct("log","environment")){
				log.log(">>>>start>>>>", wnt::clock, wnt::endl);
			}
			void adjust(std::string description);
		public:
			static wnt::u_r<environment> create(
				HINSTANCE instance, int visibility);
			void execute();
		};
	}
}