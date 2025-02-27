/*************************************************************************/
/*  shortcut.cpp                                                         */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2021 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2021 Godot Engine contributors (cf. AUTHORS.md).   */
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

#include "shortcut.h"

#include "core/os/keyboard.h"

void Shortcut::set_event(const Ref<InputEvent> &p_event) {
	event = p_event;
	emit_changed();
}

Ref<InputEvent> Shortcut::get_event() const {
	return event;
}

bool Shortcut::matches_event(const Ref<InputEvent> &p_event) const {
	return event.is_valid() && event->is_match(p_event, true);
}

String Shortcut::get_as_text() const {
	if (event.is_valid()) {
		return event->as_text();
	} else {
		return "None";
	}
}

bool Shortcut::has_valid_event() const {
	return event.is_valid();
}

void Shortcut::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_event", "event"), &Shortcut::set_event);
	ClassDB::bind_method(D_METHOD("get_event"), &Shortcut::get_event);

	ClassDB::bind_method(D_METHOD("has_valid_event"), &Shortcut::has_valid_event);

	ClassDB::bind_method(D_METHOD("matches_event", "event"), &Shortcut::matches_event);
	ClassDB::bind_method(D_METHOD("get_as_text"), &Shortcut::get_as_text);

	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "event", PROPERTY_HINT_RESOURCE_TYPE, "InputEvent"), "set_event", "get_event");
}
