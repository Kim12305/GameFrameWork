#include "Game.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* argv[])
{
  if(TheGame::Instance()->init("Chapter1", 100, 100, 640, 480, false))
  {
    Uint32 frameStart, frameTime;
    while (TheGame::Instance()->running())
    {
      frameStart = SDL_GetTicks(); //매 프레임 시작 시각 저장

      TheGame::Instance()->handleEvents();
      TheGame::Instance()->update();
      TheGame::Instance()->render();

      frameTime = SDL_GetTicks() - frameStart; //입력, 갱신, 렌더링 처리 후 소요시간 계산
      if(frameTime < DELAY_TIME)
      {
        SDL_Delay((int)(DELAY_TIME - frameTime)); //소요시간이 DELAY_TIME보다 크면 해당 차이만큼 Delay를 인위적으로 추가
      }
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





