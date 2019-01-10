#ifndef _AUDIO_
#define _AUDIO_

#include <glimac/SDLWindowManager.hpp>

/// \class Audio
/// \brief Allows the game to have music and possibly sounds
class Audio{
	public:
		Audio(){}
		~Audio(){}
		/// \brief plays music loaded
		virtual void play(){}
};

#endif