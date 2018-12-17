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


	//GETTERS & SETTER
	inline const std::string name() const{return _name;}
	inline const unsigned int price() const{return _price;}
	inline const std::string texture() const{return _texture;}


	//PUBLICS FUNCTIONS

	//@return List of skins who are present in SKIN_LIST_FILE
	static std::vector<Skin> loadSkins();


	//OPERATORS
	friend std::ostream& operator<<(std::ostream &os, const Skin &p);

};

#endif