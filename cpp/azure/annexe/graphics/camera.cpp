#include "../graphics.h"

void anx::camera::change()const{
	(*raw)(0, 0) = right.x;
	(*raw)(0, 1) = top.x;
	(*raw)(0, 2) = front.x;
	(*raw)(0, 3) = 0.0f;
	(*raw)(1, 0) = right.y;
	(*raw)(1, 1) = top.y;
	(*raw)(1, 2) = front.y;
	(*raw)(1, 3) = 0.0f;
	(*raw)(2, 0) = right.z;
	(*raw)(2, 1) = top.z;
	(*raw)(2, 2) = front.z;
	(*raw)(2, 3) = 0.0f;
	(*raw)(3, 0) = -D3DXVec3Dot(&right, &position);
	(*raw)(3, 1) = -D3DXVec3Dot(&top, &position);
	(*raw)(3, 2) = -D3DXVec3Dot(&front, &position);
	(*raw)(3, 3) = 1.0f;
}
