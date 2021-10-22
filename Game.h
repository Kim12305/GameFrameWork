#ifndef __Game__ //중복 선언
#define __Game__
#include "SDL.h"
#include <vector> //리스트와 비슷하다 항목을 넣고 삭제가능
#include <iostream>

#include "TextureManager.h"
#include "GameObject.h"
#include "SDLGameObject.h"
#include "Player.h"
#include "Enemy.h"


class Game
{
  private:
    Game() {} //생성자
    static Game* s_pInstance; //정적 멤버 변수

  public:
    static Game * Instance()
    {
      if(s_pInstance == 0)
      {
        s_pInstance = new Game();
          return s_pInstance;
      }

      return s_pInstance;

    }

    SDL_Renderer* getRenderer() const {return m_pRenderer;}

    //초기화 함수
    bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
    void render(); //렌더링 하는 함수
    void update();

    //추가함수들
    bool running();
    void handleEvents();
    void clean();
    
  private:
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    bool m_bRunning;

    int m_currentFrame;

    std::vector<GameObject*> m_gameObjects;


};

typedef Game TheGame;
#endif