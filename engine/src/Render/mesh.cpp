#include "mesh.h"

namespace valk 
{
	void Mesh::init()
	{
        GLuint VBOId[3];

        /*glGenVertexArrays(1, &vaoId);
        glBindVertexArray(vaoId);
        glGenBuffers(3, VBOId);
        // specify position attribute
        glBindBuffer(GL_ARRAY_BUFFER, VBOId[0]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertPos), vertPos, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
        glEnableVertexAttribArray(0);
        // specify color attribute
        glBindBuffer(GL_ARRAY_BUFFER, VBOId[1]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertColor), vertColor, GL_STATIC_DRAW);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
        glEnableVertexAttribArray(1);
        // specify texture coordinate attribute
        glBindBuffer(GL_ARRAY_BUFFER, VBOId[2]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertTextCoord), vertTextCoord, GL_STATIC_DRAW);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, NULL);
        glEnableVertexAttribArray(2);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);*/
	}
}
