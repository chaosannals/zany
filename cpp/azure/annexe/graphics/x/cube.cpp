#include "../../graphics.h"

using namespace anx;

void x::cube::correct(
	D3DXVECTOR3 &top,
	D3DXVECTOR3 &front,
	D3DXVECTOR3 &right){
	D3DXVec3Normalize(&front, &front);
	D3DXVec3Cross(&top, &front, &right);
	D3DXVec3Normalize(&top, &top);
	D3DXVec3Cross(&right, &top, &front);
	D3DXVec3Normalize(&right, &right);
}

void x::cube::rotation(
	float angle,
	const D3DXVECTOR3 &axis,
	D3DXVECTOR3 &first,
	D3DXVECTOR3 &second){
	D3DXMATRIX matrix;
	D3DXMatrixRotationAxis(&matrix, &axis, angle);
	D3DXVec3TransformCoord(&first, &first, &matrix);
	D3DXVec3TransformCoord(&second, &second, &matrix);
}

void x::cube::change()const{
	(*raw)(0, 0) = right.x;
	(*raw)(0, 1) = right.y;
	(*raw)(0, 2) = right.z;
	(*raw)(0, 3) = 0.0f;
	(*raw)(1, 0) = top.x;
	(*raw)(1, 1) = top.y;
	(*raw)(1, 2) = top.z;
	(*raw)(1, 3) = 0.0f;
	(*raw)(2, 0) = front.x;
	(*raw)(2, 1) = front.y;
	(*raw)(2, 2) = front.z;
	(*raw)(2, 3) = 0.0f;
	(*raw)(3, 0) = right.x * position.x + top.x * position.y + front.x *position.z;
	(*raw)(3, 1) = right.y * position.x + top.y * position.y + front.y *position.z;
	(*raw)(3, 2) = right.z * position.x + top.z * position.y + front.z *position.z;
	(*raw)(3, 3) = 1.0f;
	D3DXMatrixMultiply(raw.get(), raw.get(), &size);
}

const D3DXMATRIX *x::cube::peek(){
	if (!changed)return raw.get();
	correct(top, front, right);
	change();
	changed = false;
	return raw.get();
}

void x::cube::nod(float angle){
	changed = true;
	rotation(angle, right, top, front);
}

void x::cube::yaw(float angle){
	changed = true;
	rotation(angle, top, right, front);
}

void x::cube::roll(float angle){
	changed = true;
	rotation(angle, front, right, top);
}

void x::cube::walk(float value){
	changed = true;
	position += front * value;
}

void x::cube::strafe(float value){
	changed = true;
	position += right * value;
}

void x::cube::fly(float value){
	changed = true;
	position += top * value;
}

void x::cube::adjust(float value){
	changed = true;
	D3DXMatrixIdentity(&size);
	size(0, 0) = value;
	size(1, 1) = value;
	size(2, 2) = value;
	size(3, 3) = 1.0f;
}

void x::cube::adjust(float x, float y, float z){
	changed = true;
	D3DXMatrixIdentity(&size);
	size(0, 0) = x;
	size(1, 1) = y;
	size(2, 2) = z;
	size(3, 3) = 1.0f;
}

void x::cube::face(float x, float y, float z){
	changed = true;
	front.x = x;
	front.y = y;
	front.z = z;
}

void x::cube::move(float x, float y, float z){
	changed = true;
	position.x += x;
	position.y += y;
	position.z += z;
}

void x::cube::place(float x, float y, float z){
	changed = true;
	position.x = x;
	position.y = y;
	position.z = z;
}