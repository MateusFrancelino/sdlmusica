#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
using namespace std;
#undef main
int main()
{
 SDL_Init(SDL_INIT_EVERYTHING);
 SDL_Surface *tela;


 int frequencia = 22050;
 Uint16 formato = AUDIO_S16SYS;
 int canal = 2;//1 mono 2 stereo
 int buffer = 4096;

 Mix_OpenAudio(frequencia,formato,canal,buffer);//inicia o audio
 //Mix_Chunk *som;// para efeitos
 Mix_Music *musica;// para musicas


 //som= Mix_LoadWAV("Pow.wav");
 musica= Mix_LoadMUS("fundo.mp3");

//Mix_PlayChannel(-1,som,0);
Mix_PlayMusic(musica,0);
while(1){


}


 Mix_CloseAudio();
 //Mix_FreeChunk(som);
Mix_FreeMusic(musica);
}
