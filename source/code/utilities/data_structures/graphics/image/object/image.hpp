#pragma once

#include <string>
#include <iostream>
#include "code/utilities/image/stb_image.hpp"
#include "code/utilities/data_structures/position/position.hpp"



//This is lifetime mangaged imgui aware image
//You can construct it with a filepath and draw it by passing an imgui drawlist.
class Image
{

private:
    unsigned char *img_data = nullptr;
    GLuint         texture  = 0;
    int            width    = 0;
    int            height   = 0;
    int            rows     = 0;

public:
    Image() {}
    void set_image(std::string path)
    {
        free(img_data);
        img_data = stbi_load(path.c_str(), &width, &height, &rows, 4);
        // stbir_resize_uint8(img_data, width, height, 0)
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img_data);
    }

    ~Image() { free(img_data); }

    void imgui_image() { ImGui::Image((void *) (intptr_t) texture, ImVec2(width, height)); }
    void imgui_drawlist(ImDrawList *draw_list, Position pos)
    {
        draw_list->AddImage((void *) (intptr_t) texture, ImVec2(pos.x, pos.y), ImVec2(pos.x + width, pos.y + height));
    }
};
