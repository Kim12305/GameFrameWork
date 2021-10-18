//5초 딜레이를 주면서 랜덤으로 색 변경하기

#include <SDL.h>
#include <cstdlib>
#include <time.h>

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
bool g_bRunning = false;

bool init(const char* title, int xpos, int ypos, int height, int width, int flags) //초기화
{
  if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
  {
    g_pWindow = SDL_CreateWindow( title, xpos, ypos, height, width, flags); //윈도우 속성 설정

    if(g_pWindow != 0)
    {
      g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0); //렌더러 생성해서 설정한 윈도우 보여주기
    }
  }

  else
  {
    return false;
  }

  SDL_SetRenderDrawColor(g_pRenderer, 36, 0, 255, 255); //색 변경 255,255,255
  //생성한 랜더러의 색을 변경한다.
  
  return true;
}

void Ramdom()
{
  //랜덤으로 색 변경하기
  SDL_SetRenderDrawColor(g_pRenderer, rand()% 256, rand()% 256, rand()% 256, 255);
  SDL_Delay(5000);//5초 딜레이

}

void render()
{
  SDL_RenderClear(g_pRenderer); //지정한 색으로 렌더러 지우기
  SDL_RenderPresent(g_pRenderer);//지운 색을 실질적으로 표시하기
}

int main(int argc, char* argv[])
{
  //srand(time(NULL)); //랜덤함수로 범위를 고정하기

  if(init("Hello SDL", SDL_WINDOWPOS_CENTERED,
     SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN))//윈도우 이름, 위치, 크기 
  {
    g_bRunning = true; //준비가 됐다라는 뜻
  }

  else
  {
    return 1; //아니면 안됨
  }

  while(g_bRunning)//돌아가면서 화면에 나와야하는 함수
  {
    Ramdom();
    render();
  }

  SDL_Quit();

  return 0;
}





