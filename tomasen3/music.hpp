#ifndef INCLUDED_MUSIC_HPP
#define INCLUDED_MUSIC_HPP

#include <sstream>
#include "common.hpp"

class Music
{
public:
	/*コンストラクタ*/
	inline Music();
	/*デストラクタ*/
	inline ~Music();
	/*楽曲ファイルのオープン*/
	inline int Open(std::string filename);
	/*楽曲ファイルの再生*/
	inline void Play(int ID);		//0～読み込み順番に

private:
	int OpenFile;//開いているファイル数
};

Music::Music(){
	OpenFile = 0;
}
Music::~Music(){
	for(int cnt = 0; cnt < OpenFile; cnt++){
		std::ostringstream IDstr;
		IDstr << (cnt+1);
		mciSendString(("close " + IDstr.str()).c_str(), NULL, 0, NULL);
	}
}
int Music::Open(std::string filename){
	std::ostringstream IDstr;
	OpenFile++;
	IDstr << OpenFile;
	if(mciSendString( ("open " + filename + " type waveaudio alias " + IDstr.str()).c_str(), NULL, 0, NULL) != 0 ) {
		MessageBox(NULL, TEXT("音楽ファイルのオープンに失敗"), TEXT("エラー"), MB_OK | MB_ICONWARNING);
	}
	return OpenFile;
}
void Music::Play(int ID){
	std::ostringstream IDstr;
	IDstr << ID;
	mciSendString(("play " + IDstr.str() + " from 0").c_str(), NULL, 0, NULL);
}

#endif//INCLUDED_IMAGE_HPP