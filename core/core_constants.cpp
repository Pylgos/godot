/*************************************************************************/
/*  core_constants.cpp                                                   */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2020 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2020 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#include "core_constants.h"

#include "core/input/input_event.h"
#include "core/object/class_db.h"
#include "core/os/keyboard.h"
#include "core/variant/variant.h"

struct _CoreConstant {
#ifdef DEBUG_METHODS_ENABLED
	StringName enum_name;
	bool ignore_value_in_docs = false;
#endif
	const char *name;
	int value = 0;

	_CoreConstant() {}

#ifdef DEBUG_METHODS_ENABLED
	_CoreConstant(const StringName &p_enum_name, const char *p_name, int p_value, bool p_ignore_value_in_docs = false) :
			enum_name(p_enum_name),
			ignore_value_in_docs(p_ignore_value_in_docs),
			name(p_name),
			value(p_value) {
	}
#else
	_CoreConstant(const char *p_name, int p_value) :
			name(p_name),
			value(p_value) {
	}
#endif
};

static Vector<_CoreConstant> _global_constants;

#ifdef DEBUG_METHODS_ENABLED

#define BIND_CORE_CONSTANT(m_constant) \
	_global_constants.push_back(_CoreConstant(StringName(), #m_constant, m_constant));

#define BIND_CORE_ENUM_CONSTANT(m_constant) \
	_global_constants.push_back(_CoreConstant(__constant_get_enum_name(m_constant, #m_constant), #m_constant, m_constant));

#define BIND_CORE_ENUM_CONSTANT_CUSTOM(m_custom_name, m_constant) \
	_global_constants.push_back(_CoreConstant(__constant_get_enum_name(m_constant, #m_constant), m_custom_name, m_constant));

#define BIND_CORE_CONSTANT_NO_VAL(m_constant) \
	_global_constants.push_back(_CoreConstant(StringName(), #m_constant, m_constant, true));

#define BIND_CORE_ENUM_CONSTANT_NO_VAL(m_constant) \
	_global_constants.push_back(_CoreConstant(__constant_get_enum_name(m_constant, #m_constant), #m_constant, m_constant, true));

#define BIND_CORE_ENUM_CONSTANT_CUSTOM_NO_VAL(m_custom_name, m_constant) \
	_global_constants.push_back(_CoreConstant(__constant_get_enum_name(m_constant, #m_constant), m_custom_name, m_constant, true));

#else

#define BIND_CORE_CONSTANT(m_constant) \
	_global_constants.push_back(_CoreConstant(#m_constant, m_constant));

#define BIND_CORE_ENUM_CONSTANT(m_constant) \
	_global_constants.push_back(_CoreConstant(#m_constant, m_constant));

#define BIND_CORE_ENUM_CONSTANT_CUSTOM(m_custom_name, m_constant) \
	_global_constants.push_back(_CoreConstant(m_custom_name, m_constant));

#define BIND_CORE_CONSTANT_NO_VAL(m_constant) \
	_global_constants.push_back(_CoreConstant(#m_constant, m_constant));

#define BIND_CORE_ENUM_CONSTANT_NO_VAL(m_constant) \
	_global_constants.push_back(_CoreConstant(#m_constant, m_constant));

#define BIND_CORE_ENUM_CONSTANT_CUSTOM_NO_VAL(m_custom_name, m_constant) \
	_global_constants.push_back(_CoreConstant(m_custom_name, m_constant));

#endif

VARIANT_ENUM_CAST(KeyList);
VARIANT_ENUM_CAST(KeyModifierMask);
VARIANT_ENUM_CAST(ButtonList);
VARIANT_ENUM_CAST(JoyButtonList);
VARIANT_ENUM_CAST(JoyAxisList);
VARIANT_ENUM_CAST(MidiMessageList);

void register_global_constants() {
	BIND_CORE_ENUM_CONSTANT(MARGIN_LEFT);
	BIND_CORE_ENUM_CONSTANT(MARGIN_TOP);
	BIND_CORE_ENUM_CONSTANT(MARGIN_RIGHT);
	BIND_CORE_ENUM_CONSTANT(MARGIN_BOTTOM);

	BIND_CORE_ENUM_CONSTANT(CORNER_TOP_LEFT);
	BIND_CORE_ENUM_CONSTANT(CORNER_TOP_RIGHT);
	BIND_CORE_ENUM_CONSTANT(CORNER_BOTTOM_RIGHT);
	BIND_CORE_ENUM_CONSTANT(CORNER_BOTTOM_LEFT);

	BIND_CORE_ENUM_CONSTANT(VERTICAL);
	BIND_CORE_ENUM_CONSTANT(HORIZONTAL);

	BIND_CORE_ENUM_CONSTANT(HALIGN_LEFT);
	BIND_CORE_ENUM_CONSTANT(HALIGN_CENTER);
	BIND_CORE_ENUM_CONSTANT(HALIGN_RIGHT);
	BIND_CORE_ENUM_CONSTANT(HALIGN_FILL);

	BIND_CORE_ENUM_CONSTANT(VALIGN_TOP);
	BIND_CORE_ENUM_CONSTANT(VALIGN_CENTER);
	BIND_CORE_ENUM_CONSTANT(VALIGN_BOTTOM);

	// huge list of keys
	BIND_CORE_CONSTANT(SPKEY);

	BIND_CORE_ENUM_CONSTANT(KEY_ESCAPE);
	BIND_CORE_ENUM_CONSTANT(KEY_TAB);
	BIND_CORE_ENUM_CONSTANT(KEY_BACKTAB);
	BIND_CORE_ENUM_CONSTANT(KEY_BACKSPACE);
	BIND_CORE_ENUM_CONSTANT(KEY_ENTER);
	BIND_CORE_ENUM_CONSTANT(KEY_KP_ENTER);
	BIND_CORE_ENUM_CONSTANT(KEY_INSERT);
	BIND_CORE_ENUM_CONSTANT(KEY_DELETE);
	BIND_CORE_ENUM_CONSTANT(KEY_PAUSE);
	BIND_CORE_ENUM_CONSTANT(KEY_PRINT);
	BIND_CORE_ENUM_CONSTANT(KEY_SYSREQ);
	BIND_CORE_ENUM_CONSTANT(KEY_CLEAR);
	BIND_CORE_ENUM_CONSTANT(KEY_HOME);
	BIND_CORE_ENUM_CONSTANT(KEY_END);
	BIND_CORE_ENUM_CONSTANT(KEY_LEFT);
	BIND_CORE_ENUM_CONSTANT(KEY_UP);
	BIND_CORE_ENUM_CONSTANT(KEY_RIGHT);
	BIND_CORE_ENUM_CONSTANT(KEY_DOWN);
	BIND_CORE_ENUM_CONSTANT(KEY_PAGEUP);
	BIND_CORE_ENUM_CONSTANT(KEY_PAGEDOWN);
	BIND_CORE_ENUM_CONSTANT(KEY_SHIFT);
	BIND_CORE_ENUM_CONSTANT(KEY_CONTROL);
	BIND_CORE_ENUM_CONSTANT(KEY_META);
	BIND_CORE_ENUM_CONSTANT(KEY_ALT);
	BIND_CORE_ENUM_CONSTANT(KEY_CAPSLOCK);
	BIND_CORE_ENUM_CONSTANT(KEY_NUMLOCK);
	BIND_CORE_ENUM_CONSTANT(KEY_SCROLLLOCK);
	BIND_CORE_ENUM_CONSTANT(KEY_F1);
	BIND_CORE_ENUM_CONSTANT(KEY_F2);
	BIND_CORE_ENUM_CONSTANT(KEY_F3);
	BIND_CORE_ENUM_CONSTANT(KEY_F4);
	BIND_CORE_ENUM_CONSTANT(KEY_F5);
	BIND_CORE_ENUM_CONSTANT(KEY_F6);
	BIND_CORE_ENUM_CONSTANT(KEY_F7);
	BIND_CORE_ENUM_CONSTANT(KEY_F8);
	BIND_CORE_ENUM_CONSTANT(KEY_F9);
	BIND_CORE_ENUM_CONSTANT(KEY_F10);
	BIND_CORE_ENUM_CONSTANT(KEY_F11);
	BIND_CORE_ENUM_CONSTANT(KEY_F12);
	BIND_CORE_ENUM_CONSTANT(KEY_F13);
	BIND_CORE_ENUM_CONSTANT(KEY_F14);
	BIND_CORE_ENUM_CONSTANT(KEY_F15);
	BIND_CORE_ENUM_CONSTANT(KEY_F16);
	BIND_CORE_ENUM_CONSTANT(KEY_KP_MULTIPLY);
	BIND_CORE_ENUM_CONSTANT(KEY_KP_DIVIDE);
	BIND_CORE_ENUM_CONSTANT(KEY_KP_SUBTRACT);
	BIND_CORE_ENUM_CONSTANT(KEY_KP_PERIOD);
	BIND_CORE_ENUM_CONSTANT(KEY_KP_ADD);
	BIND_CORE_ENUM_CONSTANT(KEY_KP_0);
	BIND_CORE_ENUM_CONSTANT(KEY_KP_1);
	BIND_CORE_ENUM_CONSTANT(KEY_KP_2);
	BIND_CORE_ENUM_CONSTANT(KEY_KP_3);
	BIND_CORE_ENUM_CONSTANT(KEY_KP_4);
	BIND_CORE_ENUM_CONSTANT(KEY_KP_5);
	BIND_CORE_ENUM_CONSTANT(KEY_KP_6);
	BIND_CORE_ENUM_CONSTANT(KEY_KP_7);
	BIND_CORE_ENUM_CONSTANT(KEY_KP_8);
	BIND_CORE_ENUM_CONSTANT(KEY_KP_9);
	BIND_CORE_ENUM_CONSTANT(KEY_SUPER_L);
	BIND_CORE_ENUM_CONSTANT(KEY_SUPER_R);
	BIND_CORE_ENUM_CONSTANT(KEY_MENU);
	BIND_CORE_ENUM_CONSTANT(KEY_HYPER_L);
	BIND_CORE_ENUM_CONSTANT(KEY_HYPER_R);
	BIND_CORE_ENUM_CONSTANT(KEY_HELP);
	BIND_CORE_ENUM_CONSTANT(KEY_DIRECTION_L);
	BIND_CORE_ENUM_CONSTANT(KEY_DIRECTION_R);
	BIND_CORE_ENUM_CONSTANT(KEY_BACK);
	BIND_CORE_ENUM_CONSTANT(KEY_FORWARD);
	BIND_CORE_ENUM_CONSTANT(KEY_STOP);
	BIND_CORE_ENUM_CONSTANT(KEY_REFRESH);
	BIND_CORE_ENUM_CONSTANT(KEY_VOLUMEDOWN);
	BIND_CORE_ENUM_CONSTANT(KEY_VOLUMEMUTE);
	BIND_CORE_ENUM_CONSTANT(KEY_VOLUMEUP);
	BIND_CORE_ENUM_CONSTANT(KEY_BASSBOOST);
	BIND_CORE_ENUM_CONSTANT(KEY_BASSUP);
	BIND_CORE_ENUM_CONSTANT(KEY_BASSDOWN);
	BIND_CORE_ENUM_CONSTANT(KEY_TREBLEUP);
	BIND_CORE_ENUM_CONSTANT(KEY_TREBLEDOWN);
	BIND_CORE_ENUM_CONSTANT(KEY_MEDIAPLAY);
	BIND_CORE_ENUM_CONSTANT(KEY_MEDIASTOP);
	BIND_CORE_ENUM_CONSTANT(KEY_MEDIAPREVIOUS);
	BIND_CORE_ENUM_CONSTANT(KEY_MEDIANEXT);
	BIND_CORE_ENUM_CONSTANT(KEY_MEDIARECORD);
	BIND_CORE_ENUM_CONSTANT(KEY_HOMEPAGE);
	BIND_CORE_ENUM_CONSTANT(KEY_FAVORITES);
	BIND_CORE_ENUM_CONSTANT(KEY_SEARCH);
	BIND_CORE_ENUM_CONSTANT(KEY_STANDBY);
	BIND_CORE_ENUM_CONSTANT(KEY_OPENURL);
	BIND_CORE_ENUM_CONSTANT(KEY_LAUNCHMAIL);
	BIND_CORE_ENUM_CONSTANT(KEY_LAUNCHMEDIA);
	BIND_CORE_ENUM_CONSTANT(KEY_LAUNCH0);
	BIND_CORE_ENUM_CONSTANT(KEY_LAUNCH1);
	BIND_CORE_ENUM_CONSTANT(KEY_LAUNCH2);
	BIND_CORE_ENUM_CONSTANT(KEY_LAUNCH3);
	BIND_CORE_ENUM_CONSTANT(KEY_LAUNCH4);
	BIND_CORE_ENUM_CONSTANT(KEY_LAUNCH5);
	BIND_CORE_ENUM_CONSTANT(KEY_LAUNCH6);
	BIND_CORE_ENUM_CONSTANT(KEY_LAUNCH7);
	BIND_CORE_ENUM_CONSTANT(KEY_LAUNCH8);
	BIND_CORE_ENUM_CONSTANT(KEY_LAUNCH9);
	BIND_CORE_ENUM_CONSTANT(KEY_LAUNCHA);
	BIND_CORE_ENUM_CONSTANT(KEY_LAUNCHB);
	BIND_CORE_ENUM_CONSTANT(KEY_LAUNCHC);
	BIND_CORE_ENUM_CONSTANT(KEY_LAUNCHD);
	BIND_CORE_ENUM_CONSTANT(KEY_LAUNCHE);
	BIND_CORE_ENUM_CONSTANT(KEY_LAUNCHF);

	BIND_CORE_ENUM_CONSTANT(KEY_UNKNOWN);
	BIND_CORE_ENUM_CONSTANT(KEY_SPACE);
	BIND_CORE_ENUM_CONSTANT(KEY_EXCLAM);
	BIND_CORE_ENUM_CONSTANT(KEY_QUOTEDBL);
	BIND_CORE_ENUM_CONSTANT(KEY_NUMBERSIGN);
	BIND_CORE_ENUM_CONSTANT(KEY_DOLLAR);
	BIND_CORE_ENUM_CONSTANT(KEY_PERCENT);
	BIND_CORE_ENUM_CONSTANT(KEY_AMPERSAND);
	BIND_CORE_ENUM_CONSTANT(KEY_APOSTROPHE);
	BIND_CORE_ENUM_CONSTANT(KEY_PARENLEFT);
	BIND_CORE_ENUM_CONSTANT(KEY_PARENRIGHT);
	BIND_CORE_ENUM_CONSTANT(KEY_ASTERISK);
	BIND_CORE_ENUM_CONSTANT(KEY_PLUS);
	BIND_CORE_ENUM_CONSTANT(KEY_COMMA);
	BIND_CORE_ENUM_CONSTANT(KEY_MINUS);
	BIND_CORE_ENUM_CONSTANT(KEY_PERIOD);
	BIND_CORE_ENUM_CONSTANT(KEY_SLASH);
	BIND_CORE_ENUM_CONSTANT(KEY_0);
	BIND_CORE_ENUM_CONSTANT(KEY_1);
	BIND_CORE_ENUM_CONSTANT(KEY_2);
	BIND_CORE_ENUM_CONSTANT(KEY_3);
	BIND_CORE_ENUM_CONSTANT(KEY_4);
	BIND_CORE_ENUM_CONSTANT(KEY_5);
	BIND_CORE_ENUM_CONSTANT(KEY_6);
	BIND_CORE_ENUM_CONSTANT(KEY_7);
	BIND_CORE_ENUM_CONSTANT(KEY_8);
	BIND_CORE_ENUM_CONSTANT(KEY_9);
	BIND_CORE_ENUM_CONSTANT(KEY_COLON);
	BIND_CORE_ENUM_CONSTANT(KEY_SEMICOLON);
	BIND_CORE_ENUM_CONSTANT(KEY_LESS);
	BIND_CORE_ENUM_CONSTANT(KEY_EQUAL);
	BIND_CORE_ENUM_CONSTANT(KEY_GREATER);
	BIND_CORE_ENUM_CONSTANT(KEY_QUESTION);
	BIND_CORE_ENUM_CONSTANT(KEY_AT);
	BIND_CORE_ENUM_CONSTANT(KEY_A);
	BIND_CORE_ENUM_CONSTANT(KEY_B);
	BIND_CORE_ENUM_CONSTANT(KEY_C);
	BIND_CORE_ENUM_CONSTANT(KEY_D);
	BIND_CORE_ENUM_CONSTANT(KEY_E);
	BIND_CORE_ENUM_CONSTANT(KEY_F);
	BIND_CORE_ENUM_CONSTANT(KEY_G);
	BIND_CORE_ENUM_CONSTANT(KEY_H);
	BIND_CORE_ENUM_CONSTANT(KEY_I);
	BIND_CORE_ENUM_CONSTANT(KEY_J);
	BIND_CORE_ENUM_CONSTANT(KEY_K);
	BIND_CORE_ENUM_CONSTANT(KEY_L);
	BIND_CORE_ENUM_CONSTANT(KEY_M);
	BIND_CORE_ENUM_CONSTANT(KEY_N);
	BIND_CORE_ENUM_CONSTANT(KEY_O);
	BIND_CORE_ENUM_CONSTANT(KEY_P);
	BIND_CORE_ENUM_CONSTANT(KEY_Q);
	BIND_CORE_ENUM_CONSTANT(KEY_R);
	BIND_CORE_ENUM_CONSTANT(KEY_S);
	BIND_CORE_ENUM_CONSTANT(KEY_T);
	BIND_CORE_ENUM_CONSTANT(KEY_U);
	BIND_CORE_ENUM_CONSTANT(KEY_V);
	BIND_CORE_ENUM_CONSTANT(KEY_W);
	BIND_CORE_ENUM_CONSTANT(KEY_X);
	BIND_CORE_ENUM_CONSTANT(KEY_Y);
	BIND_CORE_ENUM_CONSTANT(KEY_Z);
	BIND_CORE_ENUM_CONSTANT(KEY_BRACKETLEFT);
	BIND_CORE_ENUM_CONSTANT(KEY_BACKSLASH);
	BIND_CORE_ENUM_CONSTANT(KEY_BRACKETRIGHT);
	BIND_CORE_ENUM_CONSTANT(KEY_ASCIICIRCUM);
	BIND_CORE_ENUM_CONSTANT(KEY_UNDERSCORE);
	BIND_CORE_ENUM_CONSTANT(KEY_QUOTELEFT);
	BIND_CORE_ENUM_CONSTANT(KEY_BRACELEFT);
	BIND_CORE_ENUM_CONSTANT(KEY_BAR);
	BIND_CORE_ENUM_CONSTANT(KEY_BRACERIGHT);
	BIND_CORE_ENUM_CONSTANT(KEY_ASCIITILDE);
	BIND_CORE_ENUM_CONSTANT(KEY_NOBREAKSPACE);
	BIND_CORE_ENUM_CONSTANT(KEY_EXCLAMDOWN);
	BIND_CORE_ENUM_CONSTANT(KEY_CENT);
	BIND_CORE_ENUM_CONSTANT(KEY_STERLING);
	BIND_CORE_ENUM_CONSTANT(KEY_CURRENCY);
	BIND_CORE_ENUM_CONSTANT(KEY_YEN);
	BIND_CORE_ENUM_CONSTANT(KEY_BROKENBAR);
	BIND_CORE_ENUM_CONSTANT(KEY_SECTION);
	BIND_CORE_ENUM_CONSTANT(KEY_DIAERESIS);
	BIND_CORE_ENUM_CONSTANT(KEY_COPYRIGHT);
	BIND_CORE_ENUM_CONSTANT(KEY_ORDFEMININE);
	BIND_CORE_ENUM_CONSTANT(KEY_GUILLEMOTLEFT);
	BIND_CORE_ENUM_CONSTANT(KEY_NOTSIGN);
	BIND_CORE_ENUM_CONSTANT(KEY_HYPHEN);
	BIND_CORE_ENUM_CONSTANT(KEY_REGISTERED);
	BIND_CORE_ENUM_CONSTANT(KEY_MACRON);
	BIND_CORE_ENUM_CONSTANT(KEY_DEGREE);
	BIND_CORE_ENUM_CONSTANT(KEY_PLUSMINUS);
	BIND_CORE_ENUM_CONSTANT(KEY_TWOSUPERIOR);
	BIND_CORE_ENUM_CONSTANT(KEY_THREESUPERIOR);
	BIND_CORE_ENUM_CONSTANT(KEY_ACUTE);
	BIND_CORE_ENUM_CONSTANT(KEY_MU);
	BIND_CORE_ENUM_CONSTANT(KEY_PARAGRAPH);
	BIND_CORE_ENUM_CONSTANT(KEY_PERIODCENTERED);
	BIND_CORE_ENUM_CONSTANT(KEY_CEDILLA);
	BIND_CORE_ENUM_CONSTANT(KEY_ONESUPERIOR);
	BIND_CORE_ENUM_CONSTANT(KEY_MASCULINE);
	BIND_CORE_ENUM_CONSTANT(KEY_GUILLEMOTRIGHT);
	BIND_CORE_ENUM_CONSTANT(KEY_ONEQUARTER);
	BIND_CORE_ENUM_CONSTANT(KEY_ONEHALF);
	BIND_CORE_ENUM_CONSTANT(KEY_THREEQUARTERS);
	BIND_CORE_ENUM_CONSTANT(KEY_QUESTIONDOWN);
	BIND_CORE_ENUM_CONSTANT(KEY_AGRAVE);
	BIND_CORE_ENUM_CONSTANT(KEY_AACUTE);
	BIND_CORE_ENUM_CONSTANT(KEY_ACIRCUMFLEX);
	BIND_CORE_ENUM_CONSTANT(KEY_ATILDE);
	BIND_CORE_ENUM_CONSTANT(KEY_ADIAERESIS);
	BIND_CORE_ENUM_CONSTANT(KEY_ARING);
	BIND_CORE_ENUM_CONSTANT(KEY_AE);
	BIND_CORE_ENUM_CONSTANT(KEY_CCEDILLA);
	BIND_CORE_ENUM_CONSTANT(KEY_EGRAVE);
	BIND_CORE_ENUM_CONSTANT(KEY_EACUTE);
	BIND_CORE_ENUM_CONSTANT(KEY_ECIRCUMFLEX);
	BIND_CORE_ENUM_CONSTANT(KEY_EDIAERESIS);
	BIND_CORE_ENUM_CONSTANT(KEY_IGRAVE);
	BIND_CORE_ENUM_CONSTANT(KEY_IACUTE);
	BIND_CORE_ENUM_CONSTANT(KEY_ICIRCUMFLEX);
	BIND_CORE_ENUM_CONSTANT(KEY_IDIAERESIS);
	BIND_CORE_ENUM_CONSTANT(KEY_ETH);
	BIND_CORE_ENUM_CONSTANT(KEY_NTILDE);
	BIND_CORE_ENUM_CONSTANT(KEY_OGRAVE);
	BIND_CORE_ENUM_CONSTANT(KEY_OACUTE);
	BIND_CORE_ENUM_CONSTANT(KEY_OCIRCUMFLEX);
	BIND_CORE_ENUM_CONSTANT(KEY_OTILDE);
	BIND_CORE_ENUM_CONSTANT(KEY_ODIAERESIS);
	BIND_CORE_ENUM_CONSTANT(KEY_MULTIPLY);
	BIND_CORE_ENUM_CONSTANT(KEY_OOBLIQUE);
	BIND_CORE_ENUM_CONSTANT(KEY_UGRAVE);
	BIND_CORE_ENUM_CONSTANT(KEY_UACUTE);
	BIND_CORE_ENUM_CONSTANT(KEY_UCIRCUMFLEX);
	BIND_CORE_ENUM_CONSTANT(KEY_UDIAERESIS);
	BIND_CORE_ENUM_CONSTANT(KEY_YACUTE);
	BIND_CORE_ENUM_CONSTANT(KEY_THORN);
	BIND_CORE_ENUM_CONSTANT(KEY_SSHARP);

	BIND_CORE_ENUM_CONSTANT(KEY_DIVISION);
	BIND_CORE_ENUM_CONSTANT(KEY_YDIAERESIS);

	BIND_CORE_ENUM_CONSTANT(KEY_CODE_MASK);
	BIND_CORE_ENUM_CONSTANT(KEY_MODIFIER_MASK);

	BIND_CORE_ENUM_CONSTANT(KEY_MASK_SHIFT);
	BIND_CORE_ENUM_CONSTANT(KEY_MASK_ALT);
	BIND_CORE_ENUM_CONSTANT(KEY_MASK_META);
	BIND_CORE_ENUM_CONSTANT(KEY_MASK_CTRL);
	BIND_CORE_ENUM_CONSTANT_NO_VAL(KEY_MASK_CMD);
	BIND_CORE_ENUM_CONSTANT(KEY_MASK_KPAD);
	BIND_CORE_ENUM_CONSTANT(KEY_MASK_GROUP_SWITCH);

	// mouse
	BIND_CORE_ENUM_CONSTANT(BUTTON_LEFT);
	BIND_CORE_ENUM_CONSTANT(BUTTON_RIGHT);
	BIND_CORE_ENUM_CONSTANT(BUTTON_MIDDLE);
	BIND_CORE_ENUM_CONSTANT(BUTTON_XBUTTON1);
	BIND_CORE_ENUM_CONSTANT(BUTTON_XBUTTON2);
	BIND_CORE_ENUM_CONSTANT(BUTTON_WHEEL_UP);
	BIND_CORE_ENUM_CONSTANT(BUTTON_WHEEL_DOWN);
	BIND_CORE_ENUM_CONSTANT(BUTTON_WHEEL_LEFT);
	BIND_CORE_ENUM_CONSTANT(BUTTON_WHEEL_RIGHT);
	BIND_CORE_ENUM_CONSTANT(BUTTON_MASK_LEFT);
	BIND_CORE_ENUM_CONSTANT(BUTTON_MASK_RIGHT);
	BIND_CORE_ENUM_CONSTANT(BUTTON_MASK_MIDDLE);
	BIND_CORE_ENUM_CONSTANT(BUTTON_MASK_XBUTTON1);
	BIND_CORE_ENUM_CONSTANT(BUTTON_MASK_XBUTTON2);

	// Joypad buttons
	BIND_CORE_ENUM_CONSTANT(JOY_BUTTON_INVALID);
	BIND_CORE_ENUM_CONSTANT(JOY_BUTTON_A);
	BIND_CORE_ENUM_CONSTANT(JOY_BUTTON_B);
	BIND_CORE_ENUM_CONSTANT(JOY_BUTTON_X);
	BIND_CORE_ENUM_CONSTANT(JOY_BUTTON_Y);
	BIND_CORE_ENUM_CONSTANT(JOY_BUTTON_BACK);
	BIND_CORE_ENUM_CONSTANT(JOY_BUTTON_GUIDE);
	BIND_CORE_ENUM_CONSTANT(JOY_BUTTON_START);
	BIND_CORE_ENUM_CONSTANT(JOY_BUTTON_LEFT_STICK);
	BIND_CORE_ENUM_CONSTANT(JOY_BUTTON_RIGHT_STICK);
	BIND_CORE_ENUM_CONSTANT(JOY_BUTTON_LEFT_SHOULDER);
	BIND_CORE_ENUM_CONSTANT(JOY_BUTTON_RIGHT_SHOULDER);
	BIND_CORE_ENUM_CONSTANT(JOY_BUTTON_DPAD_UP);
	BIND_CORE_ENUM_CONSTANT(JOY_BUTTON_DPAD_DOWN);
	BIND_CORE_ENUM_CONSTANT(JOY_BUTTON_DPAD_LEFT);
	BIND_CORE_ENUM_CONSTANT(JOY_BUTTON_DPAD_RIGHT);
	BIND_CORE_ENUM_CONSTANT(JOY_BUTTON_SDL_MAX);
	BIND_CORE_ENUM_CONSTANT(JOY_BUTTON_MAX);

	// Joypad axes
	BIND_CORE_ENUM_CONSTANT(JOY_AXIS_INVALID);
	BIND_CORE_ENUM_CONSTANT(JOY_AXIS_LEFT_X);
	BIND_CORE_ENUM_CONSTANT(JOY_AXIS_LEFT_Y);
	BIND_CORE_ENUM_CONSTANT(JOY_AXIS_RIGHT_X);
	BIND_CORE_ENUM_CONSTANT(JOY_AXIS_RIGHT_Y);
	BIND_CORE_ENUM_CONSTANT(JOY_AXIS_TRIGGER_LEFT);
	BIND_CORE_ENUM_CONSTANT(JOY_AXIS_TRIGGER_RIGHT);
	BIND_CORE_ENUM_CONSTANT(JOY_AXIS_SDL_MAX);
	BIND_CORE_ENUM_CONSTANT(JOY_AXIS_MAX);

	// midi
	BIND_CORE_ENUM_CONSTANT(MIDI_MESSAGE_NOTE_OFF);
	BIND_CORE_ENUM_CONSTANT(MIDI_MESSAGE_NOTE_ON);
	BIND_CORE_ENUM_CONSTANT(MIDI_MESSAGE_AFTERTOUCH);
	BIND_CORE_ENUM_CONSTANT(MIDI_MESSAGE_CONTROL_CHANGE);
	BIND_CORE_ENUM_CONSTANT(MIDI_MESSAGE_PROGRAM_CHANGE);
	BIND_CORE_ENUM_CONSTANT(MIDI_MESSAGE_CHANNEL_PRESSURE);
	BIND_CORE_ENUM_CONSTANT(MIDI_MESSAGE_PITCH_BEND);

	// error list

	BIND_CORE_ENUM_CONSTANT(OK); // (0)
	BIND_CORE_ENUM_CONSTANT(FAILED);
	BIND_CORE_ENUM_CONSTANT(ERR_UNAVAILABLE);
	BIND_CORE_ENUM_CONSTANT(ERR_UNCONFIGURED);
	BIND_CORE_ENUM_CONSTANT(ERR_UNAUTHORIZED);
	BIND_CORE_ENUM_CONSTANT(ERR_PARAMETER_RANGE_ERROR); // (5)
	BIND_CORE_ENUM_CONSTANT(ERR_OUT_OF_MEMORY);
	BIND_CORE_ENUM_CONSTANT(ERR_FILE_NOT_FOUND);
	BIND_CORE_ENUM_CONSTANT(ERR_FILE_BAD_DRIVE);
	BIND_CORE_ENUM_CONSTANT(ERR_FILE_BAD_PATH);
	BIND_CORE_ENUM_CONSTANT(ERR_FILE_NO_PERMISSION); // (10)
	BIND_CORE_ENUM_CONSTANT(ERR_FILE_ALREADY_IN_USE);
	BIND_CORE_ENUM_CONSTANT(ERR_FILE_CANT_OPEN);
	BIND_CORE_ENUM_CONSTANT(ERR_FILE_CANT_WRITE);
	BIND_CORE_ENUM_CONSTANT(ERR_FILE_CANT_READ);
	BIND_CORE_ENUM_CONSTANT(ERR_FILE_UNRECOGNIZED); // (15)
	BIND_CORE_ENUM_CONSTANT(ERR_FILE_CORRUPT);
	BIND_CORE_ENUM_CONSTANT(ERR_FILE_MISSING_DEPENDENCIES);
	BIND_CORE_ENUM_CONSTANT(ERR_FILE_EOF);
	BIND_CORE_ENUM_CONSTANT(ERR_CANT_OPEN);
	BIND_CORE_ENUM_CONSTANT(ERR_CANT_CREATE); // (20)
	BIND_CORE_ENUM_CONSTANT(ERR_QUERY_FAILED);
	BIND_CORE_ENUM_CONSTANT(ERR_ALREADY_IN_USE);
	BIND_CORE_ENUM_CONSTANT(ERR_LOCKED);
	BIND_CORE_ENUM_CONSTANT(ERR_TIMEOUT);
	BIND_CORE_ENUM_CONSTANT(ERR_CANT_CONNECT); // (25)
	BIND_CORE_ENUM_CONSTANT(ERR_CANT_RESOLVE);
	BIND_CORE_ENUM_CONSTANT(ERR_CONNECTION_ERROR);
	BIND_CORE_ENUM_CONSTANT(ERR_CANT_ACQUIRE_RESOURCE);
	BIND_CORE_ENUM_CONSTANT(ERR_CANT_FORK);
	BIND_CORE_ENUM_CONSTANT(ERR_INVALID_DATA); // (30)
	BIND_CORE_ENUM_CONSTANT(ERR_INVALID_PARAMETER);
	BIND_CORE_ENUM_CONSTANT(ERR_ALREADY_EXISTS);
	BIND_CORE_ENUM_CONSTANT(ERR_DOES_NOT_EXIST);
	BIND_CORE_ENUM_CONSTANT(ERR_DATABASE_CANT_READ);
	BIND_CORE_ENUM_CONSTANT(ERR_DATABASE_CANT_WRITE); // (35)
	BIND_CORE_ENUM_CONSTANT(ERR_COMPILATION_FAILED);
	BIND_CORE_ENUM_CONSTANT(ERR_METHOD_NOT_FOUND);
	BIND_CORE_ENUM_CONSTANT(ERR_LINK_FAILED);
	BIND_CORE_ENUM_CONSTANT(ERR_SCRIPT_FAILED);
	BIND_CORE_ENUM_CONSTANT(ERR_CYCLIC_LINK); // (40)
	BIND_CORE_ENUM_CONSTANT(ERR_INVALID_DECLARATION);
	BIND_CORE_ENUM_CONSTANT(ERR_DUPLICATE_SYMBOL);
	BIND_CORE_ENUM_CONSTANT(ERR_PARSE_ERROR);
	BIND_CORE_ENUM_CONSTANT(ERR_BUSY);
	BIND_CORE_ENUM_CONSTANT(ERR_SKIP); // (45)
	BIND_CORE_ENUM_CONSTANT(ERR_HELP);
	BIND_CORE_ENUM_CONSTANT(ERR_BUG);
	BIND_CORE_ENUM_CONSTANT(ERR_PRINTER_ON_FIRE);

	BIND_CORE_ENUM_CONSTANT(PROPERTY_HINT_NONE);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_HINT_RANGE);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_HINT_EXP_RANGE);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_HINT_ENUM);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_HINT_EXP_EASING);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_HINT_LENGTH);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_HINT_KEY_ACCEL);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_HINT_FLAGS);

	BIND_CORE_ENUM_CONSTANT(PROPERTY_HINT_LAYERS_2D_RENDER);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_HINT_LAYERS_2D_PHYSICS);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_HINT_LAYERS_3D_RENDER);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_HINT_LAYERS_3D_PHYSICS);

	BIND_CORE_ENUM_CONSTANT(PROPERTY_HINT_FILE);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_HINT_DIR);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_HINT_GLOBAL_FILE);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_HINT_GLOBAL_DIR);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_HINT_RESOURCE_TYPE);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_HINT_MULTILINE_TEXT);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_HINT_PLACEHOLDER_TEXT);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_HINT_COLOR_NO_ALPHA);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_HINT_IMAGE_COMPRESS_LOSSY);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_HINT_IMAGE_COMPRESS_LOSSLESS);

	BIND_CORE_ENUM_CONSTANT(PROPERTY_USAGE_STORAGE);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_USAGE_EDITOR);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_USAGE_NETWORK);

	BIND_CORE_ENUM_CONSTANT(PROPERTY_USAGE_EDITOR_HELPER);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_USAGE_CHECKABLE);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_USAGE_CHECKED);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_USAGE_INTERNATIONALIZED);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_USAGE_GROUP);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_USAGE_CATEGORY);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_USAGE_SUBGROUP);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_USAGE_NO_INSTANCE_STATE);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_USAGE_RESTART_IF_CHANGED);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_USAGE_SCRIPT_VARIABLE);

	BIND_CORE_ENUM_CONSTANT(PROPERTY_USAGE_DEFAULT);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_USAGE_DEFAULT_INTL);
	BIND_CORE_ENUM_CONSTANT(PROPERTY_USAGE_NOEDITOR);

	BIND_CORE_ENUM_CONSTANT(METHOD_FLAG_NORMAL);
	BIND_CORE_ENUM_CONSTANT(METHOD_FLAG_EDITOR);
	BIND_CORE_ENUM_CONSTANT(METHOD_FLAG_NOSCRIPT);
	BIND_CORE_ENUM_CONSTANT(METHOD_FLAG_CONST);
	BIND_CORE_ENUM_CONSTANT(METHOD_FLAG_REVERSE);
	BIND_CORE_ENUM_CONSTANT(METHOD_FLAG_VIRTUAL);
	BIND_CORE_ENUM_CONSTANT(METHOD_FLAG_FROM_SCRIPT);
	BIND_CORE_ENUM_CONSTANT(METHOD_FLAGS_DEFAULT);

	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_NIL", Variant::NIL);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_BOOL", Variant::BOOL);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_INT", Variant::INT);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_REAL", Variant::FLOAT);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_STRING", Variant::STRING);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_VECTOR2", Variant::VECTOR2);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_VECTOR2I", Variant::VECTOR2I);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_RECT2", Variant::RECT2);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_RECT2I", Variant::RECT2I);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_VECTOR3", Variant::VECTOR3);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_VECTOR3I", Variant::VECTOR3I);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_TRANSFORM2D", Variant::TRANSFORM2D);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_PLANE", Variant::PLANE);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_QUAT", Variant::QUAT);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_AABB", Variant::AABB);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_BASIS", Variant::BASIS);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_TRANSFORM", Variant::TRANSFORM);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_COLOR", Variant::COLOR);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_STRING_NAME", Variant::STRING_NAME);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_NODE_PATH", Variant::NODE_PATH);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_RID", Variant::RID);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_OBJECT", Variant::OBJECT);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_CALLABLE", Variant::CALLABLE);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_SIGNAL", Variant::SIGNAL);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_DICTIONARY", Variant::DICTIONARY);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_ARRAY", Variant::ARRAY);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_RAW_ARRAY", Variant::PACKED_BYTE_ARRAY);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_INT32_ARRAY", Variant::PACKED_INT32_ARRAY);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_INT64_ARRAY", Variant::PACKED_INT64_ARRAY);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_FLOAT32_ARRAY", Variant::PACKED_FLOAT32_ARRAY);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_FLOAT64_ARRAY", Variant::PACKED_FLOAT64_ARRAY);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_STRING_ARRAY", Variant::PACKED_STRING_ARRAY);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_VECTOR2_ARRAY", Variant::PACKED_VECTOR2_ARRAY);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_VECTOR3_ARRAY", Variant::PACKED_VECTOR3_ARRAY);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_COLOR_ARRAY", Variant::PACKED_COLOR_ARRAY);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("TYPE_MAX", Variant::VARIANT_MAX);

	//comparison
	BIND_CORE_ENUM_CONSTANT_CUSTOM("OP_EQUAL", Variant::OP_EQUAL);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("OP_NOT_EQUAL", Variant::OP_NOT_EQUAL);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("OP_LESS", Variant::OP_LESS);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("OP_LESS_EQUAL", Variant::OP_LESS_EQUAL);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("OP_GREATER", Variant::OP_GREATER);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("OP_GREATER_EQUAL", Variant::OP_GREATER_EQUAL);
	//mathematic
	BIND_CORE_ENUM_CONSTANT_CUSTOM("OP_ADD", Variant::OP_ADD);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("OP_SUBTRACT", Variant::OP_SUBTRACT);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("OP_MULTIPLY", Variant::OP_MULTIPLY);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("OP_DIVIDE", Variant::OP_DIVIDE);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("OP_NEGATE", Variant::OP_NEGATE);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("OP_POSITIVE", Variant::OP_POSITIVE);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("OP_MODULE", Variant::OP_MODULE);
	//bitwise
	BIND_CORE_ENUM_CONSTANT_CUSTOM("OP_SHIFT_LEFT", Variant::OP_SHIFT_LEFT);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("OP_SHIFT_RIGHT", Variant::OP_SHIFT_RIGHT);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("OP_BIT_AND", Variant::OP_BIT_AND);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("OP_BIT_OR", Variant::OP_BIT_OR);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("OP_BIT_XOR", Variant::OP_BIT_XOR);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("OP_BIT_NEGATE", Variant::OP_BIT_NEGATE);
	//logic
	BIND_CORE_ENUM_CONSTANT_CUSTOM("OP_AND", Variant::OP_AND);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("OP_OR", Variant::OP_OR);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("OP_XOR", Variant::OP_XOR);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("OP_NOT", Variant::OP_NOT);
	//containment
	BIND_CORE_ENUM_CONSTANT_CUSTOM("OP_IN", Variant::OP_IN);
	BIND_CORE_ENUM_CONSTANT_CUSTOM("OP_MAX", Variant::OP_MAX);
}

void unregister_global_constants() {
	_global_constants.clear();
}

int CoreConstants::get_global_constant_count() {
	return _global_constants.size();
}

#ifdef DEBUG_METHODS_ENABLED
StringName CoreConstants::get_global_constant_enum(int p_idx) {
	return _global_constants[p_idx].enum_name;
}

bool CoreConstants::get_ignore_value_in_docs(int p_idx) {
	return _global_constants[p_idx].ignore_value_in_docs;
}
#else
StringName CoreConstants::get_global_constant_enum(int p_idx) {
	return StringName();
}

bool CoreConstants::get_ignore_value_in_docs(int p_idx) {
	return false;
}
#endif

const char *CoreConstants::get_global_constant_name(int p_idx) {
	return _global_constants[p_idx].name;
}

int CoreConstants::get_global_constant_value(int p_idx) {
	return _global_constants[p_idx].value;
}
