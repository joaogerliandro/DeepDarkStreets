#include <mesh.h>

namespace DeepDarkStreets
{
    Mesh::Mesh(std::string_view meshpath)
    {
        std::ifstream filestream{ meshpath.data() };

        if (!filestream || !filestream.is_open())
            throw "ERRO: Can't open the file !";

        std::vector<glm::fvec3> vertex_list;
        std::vector<glm::fvec3> normal_list;
        std::vector<glm::fvec2> texcoord_list;

        glm::fvec3 vertex{};
        glm::fvec3 normal{};
        glm::fvec3 indice{};
        glm::fvec2 texcoord{};

        //Read each line of the OBJ
        for (std::string line; std::getline(filestream, line); )
        {
            if (line.empty())
                continue;

            size_t index{ line.find_first_of(' ') };

            std::string_view line_view = line;

            //First letter of the line
            std::string_view prefix = line_view.substr(0, index);
            //Get X, Y and Z that comes after the prefix
            std::string_view target = line_view.substr(index);

            std::istringstream stream{ target.data() };

            //Add each vertice to the object
            if (prefix == "v")
            {
                if (stream >> vertex.x >> vertex.y >> vertex.z)
                    vertex_list.push_back(std::move(vertex));

                stream.ignore('\n');
                if (stream)
                    throw "Vertex Coordinates must be 3D";
            }
            else if (prefix == "vt")
            {
                if (stream >> texcoord.s >> texcoord.t)
                    texcoord_list.push_back(std::move(texcoord));

                stream.ignore('\n');
                if (stream)
                    throw "Texture Coordinates must be 2D";
            }
            else if (prefix == "vn")
            {
                if (stream >> normal.x >> normal.y >> normal.z)
                    normal_list.push_back(std::move(normal));

                stream.ignore('\n');
                if (stream)
                    throw "Normal Coordinates must be 3D";
            }
            //Set each polygon of the object
            else if (prefix == "f")
            {
                std::size_t vertex_index{};
                std::size_t tex_index{};
                std::size_t norm_index{};
                char delim{};

                while (stream >> vertex_index >> delim >> tex_index >> delim >> norm_index)
                {
                    m_vertices.emplace_back(std::move(vertex_list[vertex_index - 1u]));
                    m_normals.emplace_back(std::move(normal_list[norm_index - 1u]));
                    m_texture.emplace_back(std::move(texcoord_list[tex_index - 1u]));
                }
            }
        }
    }
}