#pragma once
#include "Component.h"

class GameObject 
{
public:

	explicit GameObject(string const& name_ = "default_name") : name(name_) {}
	Transform get_transform() const;
	void set_transform(Transform const& new_transform);
	void add_component(Component const& c);
	GameObject get_game_object(string const& name); //gets the first game object in the active scenes game object list with matching name
	GameObject get_game_objects(string const& name); // gets all game objects in active scenes game object list with matching name
	GameObject find(string const& name);
	Component get_component(string const& name);
	void destroy();
	void do_not_destroy();
	void instansiate(GameObject g);

private:

	string name = "";
	vector<Component> component_list;
	bool started = false;
	bool marked_for_destroy = false;
	bool marked_do_not_destroy_on_load = false;
	int layer = 0;
	Transform game_object_transform;

};