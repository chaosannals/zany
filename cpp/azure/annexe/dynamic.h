#pragma once

#include <string>
#include <Python.h>

namespace anx{
	namespace py{
		class handle;
		class object;
		class module;
		class attribution;
		long as_long(const handle &aim);
		double as_double(const handle &aim);
	}
}
#include "dynamic/handle.h"
#include "dynamic/object.h"
#include "dynamic/module.h"
