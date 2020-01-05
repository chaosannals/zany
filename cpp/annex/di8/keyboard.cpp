#include "..\entirety.h"

using namespace aze;
using namespace std;

const map<string, DWORD> di8::keyboard::key_map{
		{ "ESCAPE", DIK_ESCAPE },

		{ "F1", DIK_F1 }, { "F2", DIK_F2 }, { "F3", DIK_F3 }, { "F4", DIK_F4 },
		{ "F5", DIK_F5 }, { "F6", DIK_F6 }, { "F7", DIK_F7 }, { "F8", DIK_F8 },
		{ "F9", DIK_F9 }, { "F10", DIK_F10 }, { "F11", DIK_F11 }, { "F12", DIK_F12 },

		{ "0", DIK_0 }, { "1", DIK_1 }, { "2", DIK_2 }, { "3", DIK_3 }, { "4", DIK_4 },
		{ "5", DIK_5 }, { "6", DIK_6 }, { "7", DIK_7 }, { "8", DIK_8 }, { "9", DIK_9 },

		{ "Q", DIK_Q }, { "W", DIK_W }, { "E", DIK_E }, { "R", DIK_R }, { "T", DIK_T },
		{ "Y", DIK_Y }, { "U", DIK_U }, { "I", DIK_I }, { "O", DIK_O }, { "P", DIK_P },

		{ "A", DIK_A }, { "S", DIK_S }, { "D", DIK_D }, { "F", DIK_F }, { "G", DIK_G },
		{ "H", DIK_H }, { "J", DIK_J }, { "K", DIK_K }, { "L", DIK_L },

		{ "Z", DIK_Z }, { "X", DIK_X }, { "C", DIK_C }, { "V", DIK_V },
		{ "B", DIK_B }, { "N", DIK_N }, { "M", DIK_M },

		{ "LEFT_CONTROL", DIK_LCONTROL }, { "RIGHT_CONTROL", DIK_RCONTROL },
		{ "LEFT_ALTER", DIK_LALT }, { "RIGHT_ALTER", DIK_RALT },
		{ "LEFT_SHIFT", DIK_LSHIFT }, { "RIGHT_SHIFT", DIK_RSHIFT },
		{ "SPACE", DIK_SPACE }, { "TABLE", DIK_TAB }, { "CAPS_LOCK", DIK_CAPSLOCK },
		{ "BACK_SPACE", DIK_BACKSPACE }
};

inline bool di8::keyboard::update(){
	return device->GetDeviceState(sizeof(byte) * amount, now_status.get());
}

void di8::keyboard::sense(){
	now_status.swap(old_status);
	for (int i = 0; i != time && update(); ++i)
		device->Acquire();
	for (auto itor = status_group.begin(); itor != status_group.end(); ++itor){
		(*itor)->sense(now_status.get(), old_status.get());
	}
}

censor<source, bool> di8::keyboard::access_key(const char *desc){
	string factor, key;
	istringstream description(desc);
	description >> factor >> key;
}