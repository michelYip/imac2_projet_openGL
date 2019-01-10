#ifndef _MUSIC_
#define _MUSIC_

/// \class Music
/// \brief Plays music during the game
class Music{
	private:
		Mix_Music* _music; ///< the music to play
	public:
		Music():_music(NULL){}
		~Music(){}

		/// \param: musicName : name of the wanted music
		/// \brief: creates the music object and plays it infinitely
		void play(const std::string &musicName){
			std::string path = "./main/assets/audio/" + musicName + ".mp3";
			_music = Mix_LoadMUS(path.c_str());
			if(_music == NULL)
				std::cerr << "ERROR LOAD MUSIC" << std::endl;
			Mix_PlayMusic(_music, -1);
		}
		/// \brief clears the pointer
		void clear(){
			Mix_FreeMusic(_music);
		}
};

#endif