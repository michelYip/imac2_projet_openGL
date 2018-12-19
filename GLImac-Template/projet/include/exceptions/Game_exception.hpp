#ifndef _GAME_EXCEPTION_	 
#define _GAME_EXCEPTION_

#include <iostream>
#include <exception>


class Game_exception : public std::exception
{
private:
	std::string _msg;
	std::string _file;
	int _line;


	//Prepend file,function and line to message
	void prepend_message(){
		std::string str;
		str.append("[ERROR THROWED] ");
		str.append(_file);
		str.append(":");
		str.append(std::to_string(_line));
		if(_msg.size() != 0){
			str.append(" : ");
			str.append(_msg);
		}
		_msg = str;
	}

public:	
	Game_exception(const std::string &msg, const std::string &file, const int line)
	:_msg(msg), _file(file), _line(line)
	{prepend_message();}

	~Game_exception() = default;

	virtual const char* what() const noexcept override{return _msg.c_str();}
	

};

#define GAME_EXCEPTION(str) Game_exception(str, __FILE__, __LINE__);

#endif
