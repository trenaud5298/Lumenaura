#ifndef LUMENAURA_TRIANGLE_H
#define LUMENAURA_TRIANGLE_H

#include <Lumenaura/Helper/Lumenaura_Vec3.h>
#include <cstdint>

class Triangle {
public:
    Triangle();
    Triangle(Vec3 vertexA, Vec3 vertexB, Vec3 vertexC);
    Triangle(float ax, float ay, float az, float bx, float by, float bz, float cx, float cy, float cz);

    // Setters
    void setVertexA(Vec3 newVertexA);
    void setVertexB(Vec3 newVertexB);
    void setVertexC(Vec3 newVertexC);
    void setLinearVelocity(Vec3 newLinearVelocity);
    void setAngularVelocity(Vec3 newAngularVelocity);

    // Getters
    Vec3 getVertexA() const;
    Vec3 getVertexB() const;
    Vec3 getVertexC() const;
    Vec3 getLinearVelocity() const;
    Vec3 getAngularVelocity() const;

    // Utility
    uint8_t* toGPUFormat() const;

private:
    bool outOfSync;
    bool materialOutOfSync;
    uint8_t materialID;
    Vec3 vertexA, vertexB, vertexC;
    Vec3 linearVelocit, angularVelocity;
};

#endif // LUMENAURA_TRIANGLE_H


//////////NEED TO ADD MATERIAL
