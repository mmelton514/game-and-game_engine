#include "Component.h"

void Component::addListener(Component const& listener)
{
	listener_vec.push_back(listener);
}

void Component::updateListeners(string const& event_name)
{
	for (auto& lv : listener_vec)
	{
		if (lv.update)
		{
			lv.handle_update(lv, event_name);
		}
	}
}

void Component::handle_update(Component const& c, string const& event_name)
{

}

Transform Component::get_transform() const
{
	Transform t;
	return t;
}

string Component::get_name() const
{
	return name;
}