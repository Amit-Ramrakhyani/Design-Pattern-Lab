#include <iostream>
#include <string>
using namespace std;

class MediaPlayer{
    public:
        virtual void play(string audioType, string fileName) = 0;
};

class AdvancedMediaPlayer{
    public:
        virtual void playVlc(string fileName) = 0;
        virtual void playMp4(string fileName) = 0;
};

class VlcPlayer : public AdvancedMediaPlayer{
    public:
        void playVlc(string fileName){
            cout << "Playing vlc file. Name: " << fileName << endl;
        }
        void playMp4(string fileName){
            //do nothing
        }
};

class Mp4Player : public AdvancedMediaPlayer{
    public:
        void playVlc(string fileName){
            //do nothing
        }
        void playMp4(string fileName){
            cout << "Playing mp4 file. Name: " << fileName << endl;
        }
};

class MediaAdapter : public MediaPlayer{
    
    AdvancedMediaPlayer *advancedMusicPlayer;
    
    public:
        MediaAdapter(string audioType){
            if(audioType=="vlc"){
                advancedMusicPlayer = new VlcPlayer();
            } else if (audioType=="mp4"){
                advancedMusicPlayer = new Mp4Player();
            }
        }
        void play(string audioType, string fileName){
            if(audioType=="vlc"){
                advancedMusicPlayer->playVlc(fileName);
            } else if(audioType=="mp4"){
                advancedMusicPlayer->playMp4(fileName);
            }
        }
};

class AudioPlayer : public MediaPlayer{

    MediaAdapter *mediaAdapter;
    
    public:
        void play(string audioType, string fileName){
            //inbuilt support to play mp3 music files
            if(audioType=="mp3"){
                cout << "Playing mp3 file. Name: " << fileName << endl;
            }
            //mediaAdapter is providing support to play other file formats
            else if(audioType=="vlc" || audioType=="mp4"){
                mediaAdapter = new MediaAdapter(audioType);
                mediaAdapter->play(audioType, fileName);
            }
            else{
                cout << "Invalid media. " << audioType << " format not supported" << endl;
            }
        }
};

int main(){
    
    AudioPlayer *audioPlayer = new AudioPlayer();
    
    audioPlayer->play("mp4", "TedX.mp4");
    audioPlayer->play("vlc", "Far far away.vlc");
    audioPlayer->play("mp3", "Alone.mp3");
    audioPlayer->play(".pdf", "Design Pattern.pdf");
    
    return 0;
}