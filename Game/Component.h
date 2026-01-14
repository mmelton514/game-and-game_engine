#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Transform.h"

using namespace std;

class Component
{
public:

	Component(string name_ = "default_name", bool update_ = false) : name(name_), update(update_) {}
	void addListener(Component listener);
	void updateListeners(string event_name);
	Transform get_transform();
	string get_name();
	void handle_update(Component c, string event_name);

private:

	string name = "";
	bool update = false;
	bool started = false;
	vector<Component> listener_vec;

};