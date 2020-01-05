#pragma once
namespace anx{
	struct advancer{
		virtual ~advancer(){}
		virtual bool advance(
			float time,
			const wnt::di8::kbd_dev &keyboard,
			const wnt::di8::mus_dev &mouse,
			projector &screen) = 0;
		virtual std::string submit() = 0;
	};
}