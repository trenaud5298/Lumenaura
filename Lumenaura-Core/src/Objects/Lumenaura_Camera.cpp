#include <Lumenaura/Objects/Lumenaura_Camera.h>
#include <cstring> // For memcpy

Camera::Camera()
    : outOfSync(false),
      position(Vec3()),
      rotationAngles(Vec3()),
      linearVelocity(Vec3()),
      angularVelocity(Vec3()) {}

Camera::Camera(Vec3 position, Vec3 rotationAngles, Vec3 linearVelocity, Vec3 angularVelocity)
    : outOfSync(false),
      position(position),
      rotationAngles(rotationAngles),
      linearVelocity(linearVelocity),
      angularVelocity(angularVelocity) {}

// Setters
void Camera::setPosition(Vec3 newPosition) noexcept {
    position = newPosition;
    outOfSync = true;
}

void Camera::setRotationAngles(Vec3 newRotationAngles) noexcept {
    rotationAngles = newRotationAngles;
    outOfSync = true;
}

void Camera::setLinearVelocity(Vec3 newLinearVelocity) noexcept {
    linearVelocity = newLinearVelocity;
    outOfSync = true;
}

void Camera::setAngularVelocity(Vec3 newAngularVelocity) noexcept {
    angularVelocity = newAngularVelocity;
    outOfSync = true;
}

void Camera::markOutOfSync() noexcept {
    outOfSync = true;
}

// Getters
Vec3 Camera::getPosition() const noexcept {
    return position;
}

Vec3 Camera::getRotationAngles() const noexcept {
    return rotationAngles;
}

Vec3 Camera::getLinearVelocity() const noexcept {
    return linearVelocity;
}

Vec3 Camera::getAngularVelocity() const noexcept {
    return angularVelocity;
}

bool Camera::isOutOfSync() const noexcept {
    return outOfSync;
}

// Utility
uint8_t* Camera::toGPUFormat() const {
    uint8_t* test = new uint8_t[64];
    return test;
}
