#ifndef __Game__
#define __Game__

#include "SDL.h"
//#include "TextureManager.h"

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

  // SDL 그리기를 위한 멤버변수 선언
  SDL_Texture* m_pTexture;
  SDL_Rect m_sourceRectangle; //원본 사각형
  SDL_Rect m_destinationRectangle; //대상사각형

  /*
  */

  TextureManager m_textureManager; //TextureManager 인스턴스
  int m_currentFrame; //스프라이트 애니메이션 구현을 위해 선언

};




#endif