#include "dynamic.h"

using namespace anx;

long py::as_long(const py::handle &aim){
	return PyLong_AsLong(aim);
}

double py::as_double(const py::handle &aim){
	return PyFloat_AsDouble(aim);
}
