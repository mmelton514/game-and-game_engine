#include "GameObject.h"

Transform GameObject::get_transform() const
{
	return game_object_transform;
}

void GameObject::set_transform(Transform const& new_transform)
{
	game_object_transform = new_transform;
}

void GameObject::add_component(Component const& c)
{
	component_list.push_back(c);
}

GameObject GameObject::get_game_object(string const& name)
{
	GameObject g;
	return g;
}

GameObject GameObject::get_game_objects(string const& name)
{
	GameObject g;
	return g;
}

GameObject GameObject::find(string const& name)
{
	return get_game_object(name);
}

Component GameObject::get_component(string const& name)
{
	for (auto& cl : component_list)
	{
		if (cl.get_name() == name)
		{
			return cl;
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