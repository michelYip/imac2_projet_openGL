#ifndef _SKIN_ 
#define _SKIN_

#include <iostream>

class Skin
{
private:
	unsigned int _price;
	std::string _texture;
public:
	Skin()
	:_price(0),_texture()
	{}

	Skin(const unsigned int &price, const std::string &texture)
	:_price(price),_texture(texture)
	{}
	
	~Skin() = default;
	
};

#endif