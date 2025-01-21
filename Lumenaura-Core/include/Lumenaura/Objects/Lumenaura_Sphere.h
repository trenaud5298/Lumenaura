#ifndef LUMENAURA_SPHERE_H
#define LUMENAURA_SPHERE_H

#include <Lumenaura/Helper/Lumenaura_Vec3.h>
#include <Lumenaura/Objects/Lumenaura_Material.h>
#include <cstdint>

class Sphere {
public:
    Sphere();
    Sphere(float radius, Vec3 position = Vec3(), Vec3 linearVelocity = Vec3(), Vec3 angularVelocity = Vec3());

    // Setters
    void setMaterial(uint8_t newMaterialID);
    void setMaterial(const char* newMaterialReference);
    void setRadius(float newRadius);
    void setPosition(Vec3 newPosition);
    void setLinearVelocity(Vec3 newLinearVelocity);
    void markOutOfSync();

    // Getters
    MaterialReference getMaterial();
    float getRadius() const;
    Vec3 getPosition() const;
    Vec3 getLinearVelocity() const;
    bool isOutOfSync();

    // Utility
    uint8_t* toGPUFormat() const;

private:
    bool sphereOutOfSync;
    bool materialOutOfSync;
    uint8_t materialID;
    float radius;
    Vec3 position;
    Vec3 linearVelocity;
};

#endif // LUMENAURA_SPHERE_H


//////////NEED TO ADD MATERIAL