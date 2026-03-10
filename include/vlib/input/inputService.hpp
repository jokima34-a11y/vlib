#pragma once
#include "vlib/core/defines.hpp"
#include "vlib/input/inputConfig.hpp"


//Check if either a key, or mouse button has been pressed
//for an extended duration
V_API bool vIsDown(Input::Key key);
V_API bool vIsDown(Input::Mouse button);

//Check if either a key, or mouse button has been pressed
V_API bool vWasPressed(Input::Key key);
V_API bool vWasPressed(Input::Mouse button);