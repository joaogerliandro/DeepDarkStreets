#pragma once

#include <config.hpp>

namespace DeepDarkStreets
{
    class Material
    {
        public:
            Material(std::string_view mtl_path)
            {               
                // if (!m_texture.loadFromFile(mtl_path.data()))
                //     throw "ERRO: Can't open the file !";

                // m_texture.setSmooth(true);
                // m_texture.setRepeated(true);

                // sf::Texture::bind(&m_texture);

                glGenTextures(1, &txt_id);
                glBindTexture(GL_TEXTURE_2D, txt_id);

                sf::Image texture;

                if(!texture.loadFromFile(mtl_path.data()))
                    throw "ERRO: Can't open the file !";

                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture.getSize().x, texture.getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture.getPixelsPtr());
                
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

                
            }

            // sf::Texture* get_txt_ref()
            // {
            //     return &m_texture;
            // }

            unsigned int get_txt_id()
            {
                return txt_id;
            }

        protected:
            //sf::Texture m_texture;
            unsigned int txt_id;
    };
}