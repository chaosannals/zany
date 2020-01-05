#pragma once
namespace anx{
	class particle{
		DirectX::XMVECTOR speed;
		DirectX::XMVECTOR position;
	public:
		virtual ~particle(){}
		virtual void affect(particle &other) = 0;
	};
}