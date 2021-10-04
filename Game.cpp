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
         SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 0, 255);
        //생성한 랜더러의 색을 변경한다.
      }

      else
      {
        return false; //랜더러 생성 실패
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

  //Texture 생성

  //png
  SDL_Surface* pTempSurface = IMG_Load("Assets/Player_2.png");
  m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface); //경로 불러오기
  SDL_FreeSurface(pTempSurface);

  //원본의 크기를 원하는 만큼 잘라준다
  m_sourceRectangle.w = 128;
  m_sourceRectangle.h = 82;

  //대상상자(m_destinationRectangle))의 너비/높이
  m_destinationRectangle.w = m_sourceRectangle.w;
  m_destinationRectangle.h = m_sourceRectangle.h; //원본 상자와 동일한 크기로 설정

  m_destinationRectangle.x = m_sourceRectangle.x = 0;
  m_destinationRectangle.y = m_sourceRectangle.y = 0;
  /*
  */
 // m_textureManager.load("Assets/animate-alpha.png", "animate", m_pRenderer);
  

  return true;
}

void Game::update()
{
  //SDL_GetTicks()는 계속 올라가는 함수
 //m_currentFrame = ((SDL_GetTicks() / 100) % 6);
}

void Game::render() 
{
  SDL_RenderClear(m_pRenderer); //지정색으로 랜더러 지우기

  SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
 //전체 화 보여주기
 // SDL_RenderCopy(m_pRenderer, m_pTexture, NULL, NULL);

  SDL_RenderPresent(m_pRenderer);
  //지운 색을 실질적으로 표시하기
  /*
  */

 // m_textureManager.draw("animate" 0,0,128,82, m_pRenderer);
 // m_textureManager.drawFrame("animate", 100, 100, 128, 82, 0, m_currentFrame, m_pRenderer);
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