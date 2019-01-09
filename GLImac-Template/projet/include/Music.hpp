#ifndef _MUSIC_
#define _MUSIC_

class Music{
	private:
		Mix_Music* _music;
	public:
		Music():_music(NULL){}
		~Music(){}

		void play(const std::string &musicName){
			std::string path = "./main/assets/audio/" + musicName + ".mp3";
			_music = Mix_LoadMUS(path.c_str());
			if(_music == NULL)
				std::cerr << "ERROR LOAD MUSIC" << std::endl;
			Mix_PlayMusic(_music, -1);
		}
		void clear(){
			Mix_FreeMusic(_music);
		}
};

#endif