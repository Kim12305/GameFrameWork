#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"
//#include <stdio.h>

class GameObject
{

  public:
 //GameObject를 기본 클래스로 활용하기위해
 //Game 클래스에서 다형성을 이용하여 GameObject의 하위 클래스 접근 가능
  virtual void load(int x, int y, int width, int height, std::string textureID);

  virtual void draw(SDL_Renderer* pRenderer);  
  virtual void update();

  virtual void clean() {};

  protected:
    std::string m_textureID;

    int m_x;
    int m_y;
    int m_width;
    int m_height;

    int m_currentFrame;
    int m_currentRow;
};