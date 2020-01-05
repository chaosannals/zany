#pragma once

#include <DirectXMath.h>


namespace anx{
	class field;
	class force;
	class particle;
	void interact(particle &l, particle &r);
}
#include "physics/particle.h"
