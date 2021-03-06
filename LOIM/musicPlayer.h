#ifndef _MUSICPLAYER
#define _MUSICPLAYER

#include <SFML/Audio.hpp>
#include "structs.h"

#define MAX_MUSIC 2

class MusicPlayer {

private:
	musicStruct *musicList[MAX_MUSIC];
	int			totalMusic;
	float		globalVolume;

public:
	MusicPlayer();
	void		loadAllMusic();
	void		loadSingleMusic(std::string filename, std::string name);
	void		playMusic(std::string name);
	bool		getMusicStatus(std::string name);
	void		setMusicVolume(std::string name, float volume);
	void		stopMusic(std::string name);
	void		setGlobalVolume(float volume);
};

#endif