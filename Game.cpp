#include "Game.h"

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
        SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
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
  SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/Monk.bmp");
  m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
  SDL_FreeSurface(pTempSurface);

  //원본상자(m_sourceRectangle)의 너비/높이
  SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h); //SDL_QueryTecture의 함수를 이용하여 Texture크기 구하기

  //대상상자(m_destinationRectangle))의 너비/높이
  m_destinationRectangle.w = m_sourceRectangle.w;
  m_destinationRectangle.h = m_sourceRectangle.h; //원본 상자와 동일한 크기로 설정

  m_destinationRectangle.x = m_sourceRectangle.x = 0;
  m_destinationRectangle.y = m_sourceRectangle.y = 0;

  //Texture1 생성ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
  SDL_Surface* pTempSurface1 = SDL_LoadBMP("Assets/icon.bmp");
  m_pTexture1 = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface1);
  SDL_FreeSurface(pTempSurface1);

  SDL_QueryTexture(m_pTexture1, NULL, NULL, &m_sourceRectangle1.w, &m_sourceRectangle1.h); 

  m_destinationRectangle1.w = m_sourceRectangle1.w /2;
  m_destinationRectangle1.h = m_sourceRectangle1.h /2;  //원본 상자와 동일한 크기로 

 //대상상자를 오른쪽 맨끝에 붙히려면?
  m_destinationRectangle1.x = m_sourceRectangle1.x + 400;
  m_destinationRectangle1.y = m_sourceRectangle1.y + 400;

  return true;
}

void Game::update()
{

}

void Game::render() 
{
  SDL_RenderClear(m_pRenderer); //지정색으로 랜더러 지우기

  SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);

  SDL_RenderCopy(m_pRenderer, m_pTexture1, &m_sourceRectangle1, &m_destinationRectangle1);

  SDL_RenderPresent(m_pRenderer);
  //지운 색을 실질적으로 표시하기
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