#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include "LoaderParams.h"
//#include <stdio.h>

class GameObject
{

  public:
 //GameObject를 기본 클래스로 활용하기위해
 //Game 클래스에서 다형성을 이용하여 GameObject의 하위 클래스 접근 가능
 //순수가상함수가 하나라도 있을 경우 추상클래스라고 한다
 // virtual void load() = 0; //순수가상함수는 = 0;이 붙었을 때
  virtual void draw() = 0;  
  virtual void update() = 0;
  virtual void clean() = 0;
  virtual ~GameObject() {}

  //게임오브젝트는 따른 클래스에서도 사용할 수 있게 인자값을 삭제해 준 것을 알 수 있다

  protected:
   GameObject(const LoaderParams* pParams) {}
   //load를 LoaderParams으로 대체해주었다
};

//추상클래스는 객체를 만들 수 없다
//오롯이 부모만 될 수 있다