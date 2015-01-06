//
//  UI.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 05/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "UI.h"

void UI::load_png_texture(const char *file_name)
{
    unsigned int error;
    unsigned char *data;
    unsigned int width, height;
    error = lodepng_decode32_file(&data, &width, &height, file_name);
    if (error) {
        fprintf(stderr, "error %u: %s\n", error, lodepng_error_text(error));
    }
    flip_image_vertical(data, width, height);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    free(data);
}

void UI::flip_image_vertical(unsigned char *data, unsigned int width, unsigned int height)
{
    unsigned int size = width * height * 4;
    unsigned int stride = sizeof(char) * width * 4;
    unsigned char *new_data = (unsigned char *)malloc(sizeof(unsigned char) * size);
    for (unsigned int i = 0; i < height; i++) {
        unsigned int j = height - i - 1;
        memcpy(new_data + j * stride, data + i * stride, stride);
    }
    memcpy(data, new_data, size);
    free(new_data);
}

void UI::render()
{
    glUseProgram(programID);
    
    glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);
    
    glBindBuffer(GL_ARRAY_BUFFER, bufferID);
    
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer( 0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0 );
    
    glDrawArrays(GL_TRIANGLES, 0, buffer->getData()->size());
    
    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    for(int i = 0; i < controls.size(); i++)
    {
        if(dynamic_cast<Label*>(controls[i]) != 0)
            this->printText(dynamic_cast<Label*>(controls[i])->getCaption(), controls[i]->getX(), controls[i]->getY(), 10);
    }
}

void UI::printText(const char * text, int x, int y, int size)
{
    
    unsigned int length = strlen(text);
    
    // Fill buffers
    std::vector<glm::vec2> vertices;
    std::vector<glm::vec2> UVs;
    for ( unsigned int i=0 ; i<length ; i++ )
    {
        glm::vec2 vertex_up_left    = glm::vec2( x+i*size     , -4+y+size );
        glm::vec2 vertex_up_right   = glm::vec2( x+i*size+size, -4+y+size );
        glm::vec2 vertex_down_right = glm::vec2( x+i*size+size, -12+y      );
        glm::vec2 vertex_down_left  = glm::vec2( x+i*size     , -12+y      );
        
        vertices.push_back(vertex_up_left   );
        vertices.push_back(vertex_down_left );
        vertices.push_back(vertex_up_right  );
        
        vertices.push_back(vertex_down_right);
        vertices.push_back(vertex_up_right);
        vertices.push_back(vertex_down_left);
        
        char character = text[i]-32;
        float uv_x = (character%16)/16.0f;
        float uv_y = (character/16)/8.0f;
        
        glm::vec2 uv_up_left    = glm::vec2( uv_x           , -1*uv_y );
        glm::vec2 uv_up_right   = glm::vec2( uv_x+1.0f/16.0f, -1*uv_y );
        glm::vec2 uv_down_right = glm::vec2( uv_x+1.0f/16.0f, -1*(uv_y + 1.0f/8.0f) );
        glm::vec2 uv_down_left  = glm::vec2( uv_x           , -1*(uv_y + 1.0f/8.0f) );
        UVs.push_back(uv_up_left   );
        UVs.push_back(uv_down_left );
        UVs.push_back(uv_up_right  );
        
        UVs.push_back(uv_down_right);
        UVs.push_back(uv_up_right);
        UVs.push_back(uv_down_left);
    }
    glBindBuffer(GL_ARRAY_BUFFER, fontVertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec2), &vertices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, fontUVBufferID);
    glBufferData(GL_ARRAY_BUFFER, UVs.size() * sizeof(glm::vec2), &UVs[0], GL_STATIC_DRAW);
    
    // Bind shader
    glUseProgram(programID);
    
    // Bind texture
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, fontID);
    // Set our "myTextureSampler" sampler to user Texture Unit 0
    glUniform1i(textUniformID, 0);
    
    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, fontVertexBufferID);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0 );
    
    // 2nd attribute buffer : UVs
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, fontUVBufferID);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0 );
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    // Draw call
    glDrawArrays(GL_TRIANGLES, 0, vertices.size() );
    
    glDisable(GL_BLEND);
    
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    
}