#include "Game.h"

Game * Game::s_pInstance = 0;

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

      
      if(!TheTextureManager::Instance()->load("Assets/Player_3.png", "player", m_pRenderer))
      {
        return false;
      }

      m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
      m_gameObjects.push_back(new Enemy (new LoaderParams(100, 200, 64, 64, "player")));
/*
      GameObject* m_go = new GameObject();
      GameObject* m_player = new Player();

      m_go->load(100, 100, 128, 82, "animate");
      m_player->load(300, 300, 128, 82,  "animate");

      m_gameObjects.push_back(m_go);
      m_gameObjects.push_back(m_player);
*/


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

  for(int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->update();
  }

}

void Game::render() 
{
  SDL_RenderClear(m_pRenderer); //지정색으로 랜더러 지우기

  for(int i = 0; i != m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->draw();

  }

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