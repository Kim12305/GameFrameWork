//https://youtu.be/IHWav3Mu7V8
//loom에는 시간제한이 있어서 유튜브로 녹화했습니다
#include "Game.h"

int main(int argc, char* argv[])
{
  if(TheGame::Instance()->init("Chapter1", 100, 100, 640, 480, false))
  {
    while (TheGame::Instance()->running())
    {
      TheGame::Instance()->handleEvents();
      TheGame::Instance()->update();
      TheGame::Instance()->render();
      SDL_Delay(10);
    }

  }
  else 
  {
    std::cout << "game init failure" << SDL_GetError() <<"\n";
    return -1;
  }

  TheGame::Instance()->clean();

  return 0;
}





