#include "SDL.h"
#include <map>

class TextureManager 
{
  private:
    TextureManager() {}
    //~TextureManager() {}

  public:
    bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

    void draw(std::string id, int x, int y, int width, int height,
        SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    void drawFrame(std::string id, int x, int y, int width, int height,
        int currentRow, int currentFrame,
        SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

  private:
    std::map<std::string, SDL_Texture*> m_textureMap;
  
  private:
    static TextureManager* s_pInstance; //유일 객체를 저장하기 위한 정적 멤버변수 선언
  
  public:
    static TextureManager* Instance() //함수만 이용하여 생성자 접근과 객체생성
    {
      if(s_pInstance == 0)
        s_pInstance = new TextureManager(); 
        //생성자 없으면 호출하고 s_pInstance에 객체할당 후 반환
      
      return s_pInstance;
    }

    typedef TextureManager TheTextureManager;
    
};
