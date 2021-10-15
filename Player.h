#include "GameObject.h"

class Player : public GameObject //GameObject 상속받아 Player 선언
{
  public:

  void load(int x, int y, int width, int height, std::string textureID);
  void draw(SDL_Renderer* pRenderer);
  void update();
  void clean() {};
};

