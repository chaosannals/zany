#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#include <set>
#include <map>
#include <vector>
#include <codecvt>
#include <exception>
#include <awntk.h>

namespace anx{
	class image;
	class light;
	class board;
	class effect;
	class camera;
	class projector;
	namespace x{
		struct frame;
		struct container;
		class allocator;
		class animation;
		class particle;
		class model;
		class cube;
	}
}
#include "graphics/x/cube.h"
#include "graphics/x/frame.h"
#include "graphics/x/container.h"
#include "graphics/x/allocator.h"
#include "graphics/x/animation.h"
#include "graphics/x/particle.h"
#include "graphics/x/model.h"

#include "graphics/image.h"
#include "graphics/light.h"
#include "graphics/board.h"
#include "graphics/effect.h"
#include "graphics/camera.h"
#include "graphics/projector.h"
