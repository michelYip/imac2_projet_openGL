#ifndef _SKIN_ 
#define _SKIN_

#include <iostream>
#include <vector>
#include <regex>
#include <string>
#include "exceptions/Unreachable_file.hpp"


const std::string SKIN_LIST_FILE = "main/assets/skins/list_skins";

class Skin
{
private:
	std::string _name;
	unsigned int _price;
	std::string _texture;
public:
	Skin()
	:_name(""),_price(0),_texture()
	{}

	Skin(const std::string name, const unsigned int &price, const std::string &texture)
	:_name(name),_price(price),_texture(texture)
	{}
	
	// Skin(const Skin &s)
	// :_name(s._name),_price(s._price),_texture(s._texture)
	// {}

	~Skin() = default;


	//GETTERS & SETTER
	inline const std::string name() const{return _name;}
	inline std::string name() {return _name;}

	inline const unsigned int &price() const{return _price;}
	inline unsigned int &price() {return _price;}
	
	inline const std::string texture() const{return _texture;}
	inline std::string texture() {return _texture;}


	//PUBLICS FUNCTIONS

	
	//@throws std::runtime_error if file cannot be open
	//@throws std::invalid_argument if the loaded file has one line without the good number of parameters
	//@return vector of skins who are present in SKIN_LIST_FILE
	static std::vector<Skin> loadSkins();

	//@return the skin saved in the string
	static Skin load(const std::string &couted_skin);

	//OPERATORS
	friend std::ostream& operator<<(std::ostream &os, const Skin &p);
	friend std::ostream& operator<<(std::ostream &os, const std::vector<Skin> &p);

};

#endif