#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <windows.h>
#include <dirent.h>
#include <fstream>
using namespace std;
#undef main

void ler_playlist(string *local){
    ifstream ler;
    string linha;
    int i=0;
    int g=0;
    ler.open("lista_musica.txt");
    if(ler.is_open()){
        while(getline(ler,linha)){
            if(g>2){
                cout<<linha<<endl;
               local[i]=linha;
               i++;
}
            else{g++;}
        }
    }cout<<endl<<endl<<endl<<endl<<endl;

}

















int main()
{
 SDL_Init(SDL_INIT_EVERYTHING);
 SDL_Window* janela =SDL_CreateWindow("Player",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,0);
 SDL_Renderer* render= SDL_CreateRenderer(janela,-1,0);
 SDL_SetRenderDrawColor(render,100,100,100,0);


 int frequencia = 22050;
 Uint16 formato = AUDIO_S16SYS;
 int canal = 2;//1 mono 2 stereo
 int buffer = 4096;

 Mix_OpenAudio(frequencia,formato,canal,buffer);//inicia o audio
 //Mix_Chunk *som;// para efeitos
 Mix_Music *musica;// para musicas


 //som= Mix_LoadWAV("Pow.wav");


 DIR* dir;
 struct dirent *lsdir;
 dir= opendir("C:\\teste");
 fstream arquivosom;
 if(!arquivosom.is_open()){
     arquivosom.open("lista_musica.txt",std::fstream::out);
 }
 while ((lsdir=readdir(dir))!=NULL)
 {

     cout<<endl<<lsdir->d_name;
     arquivosom<<endl<<"C:/teste/"<<lsdir->d_name;

 }



string local[8];
/*local[0]="C:/teste/athe-muffin-song-asdfmovie-feat-schmoyoho.mp3";
local[1]="C:/teste/camila-cabello-living-proof-live-from-the-2019-amas.mp3";
local[2]="C:/teste/i-like-trains-asdfmovie-song.mp3";
local[3]="C:/teste/shawn-mendes-camila-cabello-senorita-live-from-the-amas-2019.mp3";
// char *caminho="musica.mp3";*/
ler_playlist(local);

musica= Mix_LoadMUS(local[0].c_str());

 closedir(dir);
int aux=0;
//Mix_PlayChannel(-1,som,0);
Mix_PlayMusic(musica,0);


while(1){

    SDL_Event evento;
    while(SDL_PollEvent(&evento)){
    switch (evento.type) {
        case SDL_QUIT:

                    break;

                  case SDL_MOUSEBUTTONDOWN:
                      aux++;
                      if(aux>4){
                          aux=0;
                      }




                      cout<<local[aux]<<endl;
                      musica= Mix_LoadMUS(local[aux].c_str());
                      Mix_PlayMusic(musica,0);

                    break;
        }


}

}

 Mix_CloseAudio();
 //Mix_FreeChunk(som);
Mix_FreeMusic(musica);
}
