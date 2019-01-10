#ifndef _TEXT_
#define _TEXT_

#include <glimac/Image.hpp>
#include <glimac/SDLWindowManager.hpp>
#include <glimac/glm.hpp>
#include <GL/glew.h>
#include <iostream>

#include "Element2D.hpp"

/// \ Class Text
/// \ brief displays text (string converted to image)
class Text: public Element2D{
	private:
		SDL_Color _color;
		unsigned int _size;
		TTF_Font* _font;
	public:
		Text(){}
		Text(const char* text, const Uint8 &r, const Uint8 &g, const Uint8 &b, const char* fontPath, const unsigned int &size, const float &x, const float &y):_color({r, g, b}), _size(size){
			TTF_Init();
			_font = TTF_OpenFont(fontPath, size);
			if(_font == NULL) std::cerr << "ERROR FONT" << std::endl;
			SDL_Surface* surface = TTF_RenderText_Blended(_font, text, _color);
			if(surface == NULL) std::cerr << "ERROR TXT : " << fontPath << std::endl;
			_position = glm::vec2(x, y);
			_dimension = glm::vec2((float)surface->w * 2 / 1600, (float)surface->h * 2 / 1200);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glGenTextures(1, &_texture);
			glBindTexture(GL_TEXTURE_2D, _texture);
			glTexImage2D(
				GL_TEXTURE_2D,
				0,
				GL_RGBA,
				surface->w,
				surface->h,
				0,
				GL_RGBA,
				GL_UNSIGNED_BYTE,
				surface->pixels
			);
		    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
		    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
		    glBindTexture(GL_TEXTURE_2D, 0);
		    SDL_FreeSurface(surface);
		    TTF_CloseFont(_font);
		    glDisable(GL_BLEND);
		}
		~Text(){}

		inline TTF_Font* font() const{
			return _font;
		}
		inline GLuint texture() const{
			return _texture;
		}
};

#endif