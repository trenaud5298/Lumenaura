#ifndef LUMENAURA_CAMERA_H
#define LUMENAURA_CAMERA_H

#include <Lumenaura/Helper/Lumenaura_Vec3.h>
#include <cstdint>

class Camera {
public:
    Camera();
    Camera(Vec3 position, Vec3 rotationAngles = Vec3(), Vec3 linearVelocity = Vec3(), Vec3 angularVelocity = Vec3());

    // Setters
    void setPosition(Vec3 newPosition) noexcept;
    void setRotationAngles(Vec3 newRotationAngles) noexcept;
    void setLinearVelocity(Vec3 newLinearVelocity) noexcept;
    void setAngularVelocity(Vec3 newAngularVelocity) noexcept;
    void markOutOfSync() noexcept;

    // Getters
    Vec3 getPosition() const noexcept;
    Vec3 getRotationAngles() const noexcept;
    Vec3 getLinearVelocity() const noexcept;
    Vec3 getAngularVelocity() const noexcept;
    bool isOutOfSync() const noexcept;

    // Utility
    uint8_t* toGPUFormat() const;

private:
    bool outOfSync;
    Vec3 position;
    Vec3 rotationAngles;
    Vec3 linearVelocity;
    Vec3 angularVelocity;
};

#endif // LUMENAURA_CAMERA_H
