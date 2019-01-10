#ifndef _GOTOCREATEPLAYERMENU_ 
#define _GOTOCREATEPLAYERMENU_

/// \class GoToCreatePlayerMenu
/// \brief Use by the interfaces folder to throw the info to change view's Rendering to CreatePlayerMenu   
class GoToCreatePlayerMenu
{

private:
	int _playerNum;
public:
	GoToCreatePlayerMenu(const int playerNum)
	:_playerNum(playerNum){}
	~GoToCreatePlayerMenu() = default;

	const int playerNum() const{ return _playerNum; }
	int playerNum(){ return _playerNum; }
};

#endif