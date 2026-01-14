#include "GameObject.h"

Transform GameObject::get_transform()
{
	return game_object_transform;
}

void GameObject::set_transform(Transform new_transform)
{
	game_object_transform = new_transform;
}

void GameObject::add_component(Component& c)
{
	component_list.push_back(c);
}

GameObject GameObject::get_game_object(string name)
{
	GameObject g;
	return g;
}

GameObject GameObject::get_game_objects(string name)
{
	GameObject g;
	return g;
}

GameObject GameObject::find(string name)
{
	return get_game_object(name);
}

Component GameObject::get_component(string name)
{
	for (int i = 0; i < component_list.size(); i++)
	{
		if (component_list[i].get_name() == name)
		{
			return component_list[i];
		}
	}
}

void GameObject::destroy()
{
	marked_for_destroy = true;
}

void GameObject::do_not_destroy()
{
	marked_do_not_destroy_on_load = true;
}