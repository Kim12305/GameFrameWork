#ifndef __Game__ //중복 선언
#define __Game__
#include "SDL.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"


class Game
{
  public:
    Game() {} //생성자
    ~Game() {} //소멸자

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

    GameObject m_go;
    Player m_player;


};


#endif