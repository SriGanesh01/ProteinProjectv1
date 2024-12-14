#include "AllHeader.h"
#include <array>
using namespace std;

void render(double c1, double c2, double c3, double c4, double c5, double c6) {
    static GLuint VAO = 0, VBO = 0;
    if (VAO == 0) {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
    }

    GLfloat vertices[] = {
        static_cast<GLfloat>(c1), static_cast<GLfloat>(c2), static_cast<GLfloat>(c3),
        static_cast<GLfloat>(c4), static_cast<GLfloat>(c5), static_cast<GLfloat>(c6)
    };

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAO);
    glDrawArrays(GL_LINES, 0, 2);
    glBindVertexArray(0);
}
