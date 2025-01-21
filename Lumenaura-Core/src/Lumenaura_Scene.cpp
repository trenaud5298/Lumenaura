#include <Lumenaura/Lumenaura_Scene.h>
#include <Lumenaura_Internal/Lumenaura_HostMemory.h>

namespace Lumenaura::Scene {

    bool loadScene(const std::filesystem::path& filePath) {
        return false;
    }

    bool saveScene(const std::filesystem::path& filePath) {
        return false;
    }

    bool loadNewEmptyScene() {
        return false;
    }
    
    bool loadDefaultScene() {
        Memory::sceneCamera = Camera();
        Lumenaura::Scene::Memory::sceneMaterials[0] = Material();

        float halfRoomHeight = 2;
        float halfRoomWidth = 2;
        float halfRoomLength = 2;


        Vec3 frontTopLeftCorner(-halfRoomWidth,halfRoomHeight,-halfRoomLength);
        Vec3 frontTopRightCorner(halfRoomWidth,halfRoomHeight,-halfRoomLength);
        Vec3 frontBottomLeftCorner(-halfRoomWidth,-halfRoomHeight,-halfRoomLength);
        Vec3 frontBottomRightCorner(halfRoomWidth,-halfRoomHeight,-halfRoomLength);

        Vec3 backTopLeftCorner(-halfRoomWidth,halfRoomHeight,halfRoomLength);
        Vec3 backTopRightCorner(halfRoomWidth,halfRoomHeight,halfRoomLength);
        Vec3 backBottomLeftCorner(-halfRoomWidth,-halfRoomHeight,halfRoomLength);
        Vec3 backBottomRightCorner(halfRoomWidth,-halfRoomHeight,halfRoomLength);

        //Front Wall
        Memory::sceneTriangles.emplace_back(frontTopLeftCorner, frontTopRightCorner, frontBottomLeftCorner);
        Memory::sceneTriangles.emplace_back(frontBottomLeftCorner, frontBottomRightCorner, frontTopRightCorner);

        //Back Wall
        Memory::sceneTriangles.emplace_back(backTopLeftCorner, backTopRightCorner, backBottomLeftCorner);
        Memory::sceneTriangles.emplace_back(backBottomLeftCorner, backBottomRightCorner, backTopRightCorner);

        //Left Wall
        Memory::sceneTriangles.emplace_back(frontBottomLeftCorner, frontTopLeftCorner, backBottomLeftCorner);
        Memory::sceneTriangles.emplace_back(backBottomLeftCorner, backTopLeftCorner, frontTopLeftCorner);

        //Right Wall
        Memory::sceneTriangles.emplace_back(frontBottomRightCorner, frontTopRightCorner, backBottomRightCorner);
        Memory::sceneTriangles.emplace_back(backBottomRightCorner, backTopRightCorner, frontTopRightCorner);

        //Top Wall
        Memory::sceneTriangles.emplace_back(frontTopLeftCorner, frontTopRightCorner, backTopRightCorner);
        Memory::sceneTriangles.emplace_back(backTopLeftCorner, backTopRightCorner, frontTopLeftCorner);

        //Bottom Wall
        Memory::sceneTriangles.emplace_back(frontBottomLeftCorner, frontBottomRightCorner, backBottomRightCorner);
        Memory::sceneTriangles.emplace_back(backBottomLeftCorner, backBottomRightCorner, frontBottomLeftCorner);

        //Create Sphere
        Memory::sceneSpheres.emplace_back(1.0f, Vec3(-0.5,0,0.5));
        



        return false;
    }

    bool clearScene() {
        return false;
    }

    bool updateScene(int targetFramesPerSecond) {
        return false;
    }

    bool syncSceneToGPU() {
        return false;
    }

    template <typename SceneObject>
    ObjectID addToScene(const SceneObject& newSceneObject) {
        return 0;
    }

    bool removeFromScene(ObjectID objectID) {
        return false;
    }

    std::vector<ObjectID> getAllObjectsInScene() {
        return {};
    }

};