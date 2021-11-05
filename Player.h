#pragma once
#include "GameObject.h"
#include "SDLGameObject.h"
//#include "Vector2D.h"

class Player : public SDLGameObject //GameObject 상속받아 Player 선언
{
  public:

  Player(const LoaderParams* pParams);
  virtual void draw();
  virtual void update();
  virtual void clean();

};

