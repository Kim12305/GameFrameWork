#include "SDLGameObject.h"
#include "Game.h"

SDLGameObject::SDLGameObject (const LoaderParams* pParams): GameObject(pParams), m_position(pParams -> getX(), pParams -> getY()),m_velocity(0,0), m_acceleration(0,0)
{
  //m_x = pParams -> getX();
 // m_y = pParams -> getY();
  m_width = pParams->getWidth();
  m_height = pParams -> getHeight();
  m_textureID = pParams -> getTextureID();
  m_currentRow = 0;
  m_currentFrame = 0;
}

void SDLGameObject::update()
{
  //m_position.setX(m_position.getX() + 1);
  //m_position.setY(m_position.getY() + 1);
//---------------------------------------------
  //좌표 + 속도(벡터) = 새로운 좌표 -> 벡터의 크기 만큼 이동
  //좌표에 벡터 합해서 새로운 좌표 계산
  m_velocity += m_acceleration;
  m_position += m_velocity;

}
//Game싱글톤을 이용하여 직접 Renderer획득한다
void SDLGameObject::draw()
{
  TextureManager::Instance() -> drawFrame(m_textureID, (int) m_position.getX(), (int) m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance() -> getRenderer());
};