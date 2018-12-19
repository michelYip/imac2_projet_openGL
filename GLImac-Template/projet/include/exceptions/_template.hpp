#ifndef _EXCEPTION_TEMPLATE_ 
#define _EXCEPTION_TEMPLATE_

#include "exceptions/Game_exception.hpp"
#include <iostream>

class Exception_template : public Game_exception
{
private:
	//Put any parameters you need
	std::string _param;	

public:
	//Call Game_exception by giving him a message
	Exception_template(const std::string &param, const std::string &file, const int line)
	:Game_exception("Exception_template throwed with parameter ["+_param+"] ", file, line),_param(param){}
	
	~Exception_template() = default;


	//If needed you can override what() function 
	virtual const char* what() const noexcept override{return Game_exception::what();}
	
};

//Creating a macro to skip givin filename and line every time 
#define EXCEPTION_TEMPLATE(param) Exception_template(param, __FILE__, __LINE__);


//	HOW TO USE IT : 
//	throw EXCEPTION_TEMPLATE("whatever you want");


#endif
