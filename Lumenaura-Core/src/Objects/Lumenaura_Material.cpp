#include <Lumenaura/Objects/Lumenaura_Material.h>
#include <Lumenaura_Internal/Lumenaura_HostMemory.h>

namespace Lumenaura::Scene {

    Material::Material() noexcept
        : diffuseColor(), specularColor(), lightEmission(), 
        smoothness(0.0f), fuzziness(0.0f), refractiveIndex(0.0f), 
        outOfSync(false) {}

    Material::Material(Vec3 diffuseColor, Vec3 specularColor, Vec3 lightEmission,
                    float smoothness, float fuzziness, float refractiveIndex) noexcept
        : diffuseColor(diffuseColor), specularColor(specularColor), lightEmission(lightEmission),
        smoothness(smoothness), fuzziness(fuzziness), refractiveIndex(refractiveIndex),
        outOfSync(true) {}

    // Setters
    void Material::setDiffuseColor(Vec3 newDiffuseColor) noexcept {
        diffuseColor = newDiffuseColor;
        outOfSync = true;
    }

    void Material::setSpecularColor(Vec3 newSpecularColor) noexcept {
        specularColor = newSpecularColor;
        outOfSync = true;
    }

    void Material::setLightEmission(Vec3 newLightEmission) noexcept {
        lightEmission = newLightEmission;
        outOfSync = true;
    }

    void Material::setSmoothness(float newSmoothness) noexcept {
        smoothness = newSmoothness;
        outOfSync = true;
    }

    void Material::setFuzziness(float newFuzziness) noexcept {
        fuzziness = newFuzziness;
        outOfSync = true;
    }

    void Material::setRefractiveIndex(float newRefractiveIndex) noexcept {
        refractiveIndex = newRefractiveIndex;
        outOfSync = true;
    }

    // Getters
    Vec3 Material::getDiffuseColor() const noexcept {
        return diffuseColor;
    }

    Vec3 Material::getSpecularColor() const noexcept {
        return specularColor;
    }

    Vec3 Material::getLightEmission() const noexcept {
        return lightEmission;
    }

    float Material::getSmoothness() const noexcept {
        return smoothness;
    }

    float Material::getFuzziness() const noexcept {
        return fuzziness;
    }

    float Material::getRefractiveIndex() const noexcept {
        return refractiveIndex;
    }

    bool Material::isOutOfSync() const noexcept {
        return outOfSync;
    }

    // Utility
    uint8_t* Material::toGPUFormat() const {
        uint8_t* data = new uint8_t[64];
        return data;
    }




};

Lumenaura::Scene::Memory::sceneMaterials[0] = Material();