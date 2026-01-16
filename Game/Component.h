#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Transform.h"

using namespace std;

class Component
{
public:

	explicit Component(string const& name_ = "default_name", bool update_ = false) : name(name_), update(update_) {}
	void addListener(Component const& listener);
	void updateListeners(string const& event_name);
	Transform get_transform() const;
	string get_name() const;
	void handle_update(Component const& c, string const& event_name);

private:

	string name = "";
	bool update = false;
	bool started = false;
	vector<Component> listener_vec;

};