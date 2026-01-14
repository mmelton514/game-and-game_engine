#include "Component.h"

void Component::addListener(Component listener)
{
	listener_vec.push_back(listener);
}

void Component::updateListeners(string event_name)
{
	for (int i = 0; i < listener_vec.size(); i++)
	{
		if (listener_vec[i].update)
		{
			listener_vec[i].handle_update(listener_vec[i], event_name);
		}
	}
}

void Component::handle_update(Component c, string event_name)
{

}

Transform Component::get_transform()
{
	Transform t;
	return t;
}

string Component::get_name()
{
	return name;
}