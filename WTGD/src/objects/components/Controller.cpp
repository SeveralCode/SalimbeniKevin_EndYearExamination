#include "Controller.h"

WTGD::Controller::Controller() : Component("Base Controller")
{
	fw_movement = false;
	right_movement = false;
	x_axis = 0;
	y_axis = 0;
}

WTGD::Controller::~Controller() = default;

void WTGD::Controller::on_update(const float delta)
{
}


