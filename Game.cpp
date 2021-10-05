#include "Game.h"
#include "SDL_image.h"
#include "TextureManager.h"

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags) //초기화
{
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    m_pWindow = SDL_CreateWindow( title, xpos, ypos, height, width, flags); //윈도우 속성 설정

    if(m_pWindow != 0)
    {
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0); //렌더러 생성해서 설정한 윈도우 보여주기

      if(m_pRenderer != 0)
      {
         SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
        //생성한 랜더러의 색을 변경한다.
      }

      else
      {
        return false; //랜더러 생성 실패
      }

      if(!TheTextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer))
      {
        return false;
      }

    }

    else //윈도우 생성 실패
    {
      return false;
    } 
  
  }

  else //SDL 초기화 실패
  {
    return false;
  }

  m_bRunning = true;
  return true;  
}

void Game::update()
{
  m_currentFrame = ( (SDL_GetTicks() / 100) % 6);
}

void Game::render() 
{
  SDL_RenderClear(m_pRenderer); //지정색으로 랜더러 지우기
  TheTextureManager::Instance()->draw("animate", 0,0, 128, 82, 
     m_pRenderer);

  TheTextureManager::Instance()->drawFrame("animate", 100,100, 128, 
    82, 0, m_currentFrame, m_pRenderer);
    
  SDL_RenderPresent(m_pRenderer);//실질적으로 표시하기
}

bool Game::running()
{
  return m_bRunning;
}

void Game::handleEvents()
{
  SDL_Event event;
  if(SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_QUIT:
      m_bRunning = false; //x버튼 클릭 시 게임 루프 종료
      break;

      default:
      break;
    }
  }
}

void Game::clean() 
{
  //윈도우, 랜더러 삭제
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  //SDL 서브 시스템 종료
  SDL_Quit();
}