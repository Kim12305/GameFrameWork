#include "SDL.h"
#include <map>

class TextureManager
{
  public:

  TextureManager() {} //필드초기화하기
  ~TextureManager() {}

 //이용할 이미지 파일이름, 텍스처 참조하기 위해 이용할 이름, 이용하기 원하는 렌더러 받기
  bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

 //그리기 원하는 텍스쳐 아이디, 화면의 위치, 프레임/이미지크기, 복사하려는 렌더러
  void draw(std::string id, int x, int y, int width, int height, 
  SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

 //currentRow : 이미지의 줄
 //currentFrame : 나타낼 프레임
 void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame,
 SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

 private:
 //m_textureMap 멤버변수
 //std::map  :  많은 자료 저장, 검색 빨라야한다 빈번하게 삽입, 삭제하지 않는다 키와 값을 쌍으로 저장
 //<std::string, SDL_Texture* > : 키: std::string 값: SDL_Texture의 포인터
 std::map<std::string, SDL_Texture* > m_textureMap;
};