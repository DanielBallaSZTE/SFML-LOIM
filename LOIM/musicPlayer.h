#ifndef _MUSICPLAYER
#define _MUSICPLAYER

#include <SFML/Audio.hpp>
#define MAX_MUSIC 2


typedef struct musicStruct{
	std::string name;
	sf::Music	musicFile;
} musicStruct;

class MusicPlayer {

private:
	musicStruct *musicList[MAX_MUSIC];
	int totalMusic;

public:
	MusicPlayer();
	void		loadAllMusic();
	void		loadSingleMusic(std::string filename, std::string name);
	void		playMusic(std::string name);
	bool		getMusicStatus(std::string name);
};

#endif