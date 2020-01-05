#pragma once

#define DIRECTINPUT_VERSION 0X0800

#include <Windows.h>

#include <stack>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <exception>
#include <algorithm>
#include <initializer_list>
#include <awntk.h>
#include <adi8k/adi8k.h>

#include "../annexe/graphics.h"

#include "detail/date.h"
#include "advancer.h"
#include "advancer/preface.h"
#include "advancer/context.h"
#include "advancer/content.h"
#include "environment.h"

#pragma comment(lib,"dinput8")
#pragma comment(lib,"dxguid")
#pragma comment(lib,"d3d9")
#pragma comment(lib,"d3dx9")
