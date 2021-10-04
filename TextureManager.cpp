#include "TextureManager.h"

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer)
{
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
  
	if(pTempSurface == 0)
  {
		retrun false;
	}

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_freeSurface(pTempSurface);
	
	if(pTexture != 0)
	{
		m_textureMap[id] = pTexture;
		return true;
	}

	return false;
}

bool TextureManager::draw(std::string id, int x, int y, int width, int height,
SDL_Renderer * pRenderer, SDL_RendererFlip filp)
{
  SDL_Rect srcRect;
  SDL_Rect destRect;

  srcRect.x = 0;
  srcRect.y = 0;
  srcRect.w = destRect.w = width;
  srcRect.h = destRect.h = height;
  desRect.x = x;
  desRect.y = y;

  SDL_RendererCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0 , 0 , filp);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width,
int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
  SDL_Rect srcRect; //원본상자
  SDL_Rect destRect; //대상상자

  srcRect.x = width * currentFrame; //위치지정
  srcRect.y = height * currentRow; //두개의 current변수를 이용하여 특정 프레임 그리기
  srcRect.w = destRect.w = width; 
  srcRect.h = destRect.h = height;
  desRect.x = x;
  desRect.y = y;

 SDL_RendererCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0 , 0 , filp);
}