#ifndef LUMENAURA_MATERIAL_H
#define LUMENAURA_MATERIAL_H

#include <Lumenaura/Helper/Lumenaura_Vec3.h>
#include <string>
#include <cstdint>

namespace Lumenaura::Scene {

    class Material {
    public:
        Material() noexcept;
        Material(Vec3 diffuseColor, Vec3 specularColor = Vec3(), 
                Vec3 lightEmission = Vec3(),
                float smoothness = 0, float fuzziness = 0, float refractiveIndex = 0) noexcept;

        // Setters
        void setDiffuseColor(Vec3 newDiffuseColor) noexcept;
        void setSpecularColor(Vec3 newSpecularColor) noexcept;
        void setLightEmission(Vec3 newLightEmission) noexcept;
        void setSmoothness(float newSmoothness) noexcept;
        void setFuzziness(float newFuzziness) noexcept;
        void setRefractiveIndex(float newRefractiveIndex) noexcept;
        void markOutOfSync() noexcept;

        // Getters
        Vec3 getDiffuseColor() const noexcept;
        Vec3 getSpecularColor() const noexcept;
        Vec3 getLightEmission() const noexcept;
        float getSmoothness() const noexcept;
        float getFuzziness() const noexcept;
        float getRefractiveIndex() const noexcept;
        bool isOutOfSync() const noexcept;

        // Utility
        uint8_t* toGPUFormat() const;

    private:
        bool outOfSync;
        Vec3 diffuseColor;
        Vec3 specularColor;
        Vec3 lightEmission;
        float smoothness;
        float fuzziness;
        float refractiveIndex;
    };

    enum MaterialReference : uint8_t {
        // Diffuse Materials
        DEFAULT_MATERIAL_1 = 0, BASIC_WHITE = 0,
        DEFAULT_MATERIAL_2 = 1, BASIC_RED = 1,
        DEFAULT_MATERIAL_3 = 2, BASIC_GREEN = 2,
        DEFAULT_MATERIAL_4 = 3, BASIC_BLUE = 3,
        DEFAULT_MATERIAL_5 = 4, BASIC_YELLOW = 4,
        DEFAULT_MATERIAL_6 = 5, BASIC_PURPLE = 5,
        DEFAULT_MATERIAL_7 = 6, BASIC_ORANGE = 6,
        DEFAULT_MATERIAL_8 = 7, BASIC_GRAY = 7,
        DEFAULT_MATERIAL_9 = 8, BASIC_BROWN = 8,
        DEFAULT_MATERIAL_10 = 9, BASIC_CYAN = 9,
        DEFAULT_MATERIAL_11 = 10, BASIC_MAGENTA = 10,

        // Metallic Materials
        DEFAULT_MATERIAL_12 = 11, METALLIC_WHITE = 11,
        DEFAULT_MATERIAL_13 = 12, METALLIC_RED = 12,
        DEFAULT_MATERIAL_14 = 13, METALLIC_GREEN = 13,
        DEFAULT_MATERIAL_15 = 14, METALLIC_BLUE = 14,
        DEFAULT_MATERIAL_16 = 15, METALLIC_YELLOW = 15,
        DEFAULT_MATERIAL_17 = 16, METALLIC_PURPLE = 16,
        DEFAULT_MATERIAL_18 = 17, METALLIC_ORANGE = 17,
        DEFAULT_MATERIAL_19 = 18, METALLIC_GRAY = 18,

        // Light Emissive Materials
        DEFAULT_MATERIAL_20 = 19, WHITE_LIGHT = 19,
        DEFAULT_MATERIAL_21 = 20, RED_LIGHT = 20,
        DEFAULT_MATERIAL_22 = 21, GREEN_LIGHT = 21,
        DEFAULT_MATERIAL_23 = 22, BLUE_LIGHT = 22,
        DEFAULT_MATERIAL_24 = 23, YELLOW_LIGHT = 23,
        DEFAULT_MATERIAL_25 = 24, CYAN_LIGHT = 24,
        DEFAULT_MATERIAL_26 = 25, PURPLE_LIGHT = 25,
        DEFAULT_MATERIAL_27 = 26, ORANGE_LIGHT = 26,

        // Neon Emissive Materials
        DEFAULT_MATERIAL_28 = 27, NEON_WHITE = 27,
        DEFAULT_MATERIAL_29 = 28, NEON_RED = 28,
        DEFAULT_MATERIAL_30 = 29, NEON_GREEN = 29,
        DEFAULT_MATERIAL_31 = 30, NEON_BLUE = 30,
        DEFAULT_MATERIAL_32 = 31, NEON_YELLOW = 31,
        DEFAULT_MATERIAL_33 = 32, NEON_CYAN = 32,
        DEFAULT_MATERIAL_34 = 33, NEON_PURPLE = 33,
        DEFAULT_MATERIAL_35 = 34, NEON_ORANGE = 34,

        // Glow Materials
        DEFAULT_MATERIAL_36 = 35, GLOW_WHITE = 35,
        DEFAULT_MATERIAL_37 = 36, GLOW_RED = 36,
        DEFAULT_MATERIAL_38 = 37, GLOW_GREEN = 37,
        DEFAULT_MATERIAL_39 = 38, GLOW_BLUE = 38,
        DEFAULT_MATERIAL_40 = 39, GLOW_YELLOW = 39,
        DEFAULT_MATERIAL_41 = 40, GLOW_PURPLE = 40,

        // Transparent Materials
        DEFAULT_MATERIAL_42 = 41, TRANSPARENT_WHITE = 41,
        DEFAULT_MATERIAL_43 = 42, TRANSPARENT_RED = 42,
        DEFAULT_MATERIAL_44 = 43, TRANSPARENT_GREEN = 43,
        DEFAULT_MATERIAL_45 = 44, TRANSPARENT_BLUE = 44,
        DEFAULT_MATERIAL_46 = 45, TRANSPARENT_YELLOW = 45,
        DEFAULT_MATERIAL_47 = 46, TRANSPARENT_CYAN = 46,

        // Diffuse Glow Materials
        DEFAULT_MATERIAL_48 = 47, DIFFUSE_GLOW_WHITE = 47,
        DEFAULT_MATERIAL_49 = 48, DIFFUSE_GLOW_RED = 48,
        DEFAULT_MATERIAL_50 = 49, DIFFUSE_GLOW_GREEN = 49,
        DEFAULT_MATERIAL_51 = 50, DIFFUSE_GLOW_BLUE = 50,
        DEFAULT_MATERIAL_52 = 51, DIFFUSE_GLOW_YELLOW = 51,

        // Fuzzy Materials
        DEFAULT_MATERIAL_53 = 52, FUZZY_WHITE = 52,
        DEFAULT_MATERIAL_54 = 53, FUZZY_RED = 53,
        DEFAULT_MATERIAL_55 = 54, FUZZY_GREEN = 54,
        DEFAULT_MATERIAL_56 = 55, FUZZY_BLUE = 55,
        DEFAULT_MATERIAL_57 = 56, FUZZY_YELLOW = 56,
        DEFAULT_MATERIAL_58 = 57,
        DEFAULT_MATERIAL_59 = 58,
        DEFAULT_MATERIAL_60 = 59,
        DEFAULT_MATERIAL_61 = 60,
        DEFAULT_MATERIAL_62 = 61,
        DEFAULT_MATERIAL_63 = 62,
        DEFAULT_MATERIAL_64 = 63,
        


        NULL_MATERIAL = 255
        
    };

};

#endif
