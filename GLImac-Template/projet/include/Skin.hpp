#ifndef _SKIN_ 
#define _SKIN_

#include <iostream>
#include <vector>

const std::string SKIN_LIST_FILE = "Game/skins/list_skins";

class Skin
{
private:
	std::string _name;
	unsigned int _price;
	std::string _texture;
public:
	Skin()
	:_price(0),_texture()
	{}

	Skin(const std::string name, const unsigned int &price, const std::string &texture)
	:_name(name),_price(price),_texture(texture)
	{}
	
	~Skin() = default;

	//@return List of skins who are present in SKIN_LIST_FILE
	static std::vector<Skin> loadSkins();

	friend std::ostream& operator<<(std::ostream &os, const Skin &p);

};

#endif