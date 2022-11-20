#pragma once

// Standard Headers
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <exception>

// GLM Headers
#include <glm/glm.hpp>
#include <glm/ext.hpp>

// SFML Headers
#include <SFML/Graphics/RenderWindow.hpp>

#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Event.hpp>

#include <SFML/OpenGL.hpp>

#define PI 3.14159265359

namespace DeepDarkStreets
{   
    class Config
    {
        public:
            Config(std::string_view file_stream = { "config.cfg" })
            {
                load_default_setting();

                std::fstream config_file(file_stream.data());

                if(!config_file.is_open())
                {
                    std::cout << "[WARNING]: Could not read configuration file ! Creating a new ..." << std::endl;

                    config_file.open(file_stream.data(), std::fstream::in | std::fstream::out | std::fstream::trunc);
                    
                    if(!config_file.is_open())
                        throw "[ERROR]: Unable to create settings file ! Leaving the program ...";

                    write_cfg_template(config_file);

                    std::cout << "[INFO]: Configuration file created !" << std::endl;
                }
                
                read_config(config_file);

                config_file.close();
            }

            inline sf::ContextSettings get_settings()
            {
                return m_settings;
            }

        private:
            void load_default_setting()
            {
                m_settings.depthBits         = 24;
                m_settings.stencilBits       =  8;
                m_settings.antialiasingLevel =  4;
                m_settings.majorVersion      =  3;
                m_settings.minorVersion      =  0;
                m_settings.sRgbCapable       =  0;
            }

            void write_cfg_template(std::fstream& cfg_file)
            {
                cfg_file << "DepthBits = "         << m_settings.depthBits         << "\n";
                cfg_file << "StencilBits = "       << m_settings.stencilBits       << "\n";
                cfg_file << "AntialiasingLevel = " << m_settings.antialiasingLevel << "\n";
                cfg_file << "GlMajorVersion = "    << m_settings.majorVersion      << "\n";
                cfg_file << "GlMinorVersion = "    << m_settings.minorVersion      << "\n";
                cfg_file << "SRgbCapable = "       << m_settings.sRgbCapable       << "\n";
            }

            void read_config(std::fstream& cfg_file)
            {
                std::string file_line;
                std::string line_content;

                std::stringstream str_stream;

                while(std::getline(cfg_file, file_line))
                {
                    str_stream.clear();
                    str_stream.str(file_line);

                    str_stream >> line_content;        

                    if(line_content == "DepthBits")
                        try
                        {
                            m_settings.depthBits = read_value(str_stream, line_content);
                        }
                        catch(const std::exception& e)
                        {
                            std::cerr << e.what() << '\n';
                        }
                    else if(line_content == "StencilBits")
                        try
                        {
                            m_settings.stencilBits = read_value(str_stream, line_content);
                        }
                        catch(const std::exception& e)
                        {
                            std::cerr << e.what() << '\n';
                        }
                    else if(line_content == "AntialiasingLevel")
                        try
                        {
                            m_settings.antialiasingLevel = read_value(str_stream, line_content);
                        }
                        catch(const std::exception& e)
                        {
                            std::cerr << e.what() << '\n';
                        }
                    else if(line_content == "GlMajorVersion")
                        try
                        {
                            m_settings.majorVersion = read_value(str_stream, line_content);
                        }
                        catch(const std::exception& e)
                        {
                            std::cerr << e.what() << '\n';
                        }
                    else if(line_content == "GlMinorVersion")
                        try
                        {
                            m_settings.minorVersion = read_value(str_stream, line_content);
                        }
                        catch(const std::exception& e)
                        {
                            std::cerr << e.what() << '\n';
                        }
                    else if(line_content == "SRgbCapable")
                        try
                        {
                            m_settings.sRgbCapable = read_value(str_stream, line_content);
                        }
                        catch(const std::exception& e)
                        {
                            std::cerr << e.what() << '\n';
                        }
                }
            }

            static bool is_number(const std::string& str)
            {
                std::string::const_iterator str_iterator = str.begin();

                while (str_iterator != str.end() && std::isdigit(*str_iterator)) 
                    ++str_iterator;

                return !str.empty() && str_iterator == str.end();
            }

            static uint32_t read_value(std::stringstream& str_stream, std::string option)
            {
                std::string line_content;
                str_stream >> line_content;

                if(line_content == "=")
                {
                    str_stream >> line_content;
                    if(is_number(line_content))
                        return std::atoi(line_content.c_str());
                    else
                    {
                        std::string ex = "WARNING: The " + option + " value must be valid ! The default value will be kept.\n";
                        throw std::invalid_argument(ex);
                    }
                }
                else
                {
                    std::string ex = "WARNING: Could not load " + option + " configuration ! The default configuration will be kept.\n";
                    throw std::invalid_argument(ex);
                }
            }
        
        protected: 
            sf::ContextSettings m_settings;
    };
}