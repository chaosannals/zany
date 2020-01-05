#include "..\entirety.h"

using namespace aze;
using namespace std;

const map<string, tuple<bool, bool>> di8::status::factor_map{
		{ "PRESS", tuple<bool, bool>(false, true) },
		{ "LOOSE", tuple<bool, bool>(true, false) },
		{ "DENTED", tuple<bool, bool>(false, false) },
		{ "RAISED", tuple<bool, bool>(true, true) }
};