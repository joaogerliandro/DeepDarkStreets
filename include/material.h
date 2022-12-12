#pragma once

#include <config.hpp>

namespace DeepDarkStreets
{
    class Material
    {
        public:
            Material(std::string_view mtl_path)
            {               
                glGenTextures(1, &m_txt_id);
                glBindTexture(GL_TEXTURE_2D, m_txt_id);

                sf::Image texture;

                if(!texture.loadFromFile(mtl_path.data()))
                    throw "ERRO: Can't open the file !";

                texture.flipVertically();

                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture.getSize().x, texture.getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture.getPixelsPtr());

                glBindTexture(GL_TEXTURE_2D, 0);
            }

            unsigned int get_txt_id()
            {
                return m_txt_id;
            }

        protected:
            unsigned int m_txt_id;
    };
}