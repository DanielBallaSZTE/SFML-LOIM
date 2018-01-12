#include "musicPlayer.h"
#include <iostream>


/**
 * Constructor for MusicPlayer.
 * Creates musicStructs based on MAX_MUSIC and loads all musictracks.
 */
MusicPlayer::MusicPlayer()
{
	for (int i = 0; i < MAX_MUSIC; i++)
	{
		musicList[i] = new musicStruct;
	}
	totalMusic = 0;
	loadAllMusic();
} /* MusicPlayer */


/**
 * Loads every musictracks by calling loadSingleMusic with given parameters.
 */
void MusicPlayer::loadAllMusic()
{
	// Main theme
	loadSingleMusic("music/focimdal.wav", "mainTheme");
	// Easy Questions
	loadSingleMusic("music/100to1000.wav", "easyQuestions");

	std::cout << "\nMusicPlayer::Successfuly loaded " << totalMusic << " musictracks.";
} /* loadAllMusic */


/**
 * Loads a single musictrack.
 * @filename Filename of the given track.
 * @name Identifier name of the track.
 */
void MusicPlayer::loadSingleMusic(std::string filename, std::string name)
{
	musicList[totalMusic]->name = name;
	musicList[totalMusic]->musicFile.openFromFile(filename);
	totalMusic++;
} /* loadSingleMusic */


/**
 * Plays a music identified by name.
 * @name Identifier name of the track.
 */
void MusicPlayer::playMusic(std::string name)
{
	for (int i = 0; i < totalMusic; i++)
	{
		if (musicList[i]->name == name)
		{
			musicList[i]->musicFile.play();
		}
	}
} /* playMusic */


/**
* Plays a music identified by name.
* @name Identifier name of the track.
* @return Returns true if the song is playing, false otherwise.
*/
bool MusicPlayer::getMusicStatus(std::string name)
{
	for (int i = 0; i < totalMusic; i++)
	{
		if (musicList[i]->name == name)
		{
			return musicList[i]->musicFile.getStatus() ? true : false;
		}
	}

	return false;
} /* getMusicStatus */