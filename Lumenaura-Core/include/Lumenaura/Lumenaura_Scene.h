#ifndef LUMENAURA_SCENE_H
#define LUMENAURA_SCENE_H

//C++ Includes
#include <filesystem>

//Lumenaura Includes
#include <Lumenaura/Objects/Lumenaura_Camera.h>
#include <Lumenaura/Objects/Lumenaura_Cube.h>
#include <Lumenaura/Objects/Lumenaura_Material.h>
#include <Lumenaura/Objects/Lumenaura_Quadrilateral.h>
#include <Lumenaura/Objects/Lumenaura_Sphere.h>
#include <Lumenaura/Objects/Lumenaura_Triangle.h>


namespace Lumenaura::Scene {

    typedef unsigned long long ObjectID;

    bool loadScene(const std::filesystem::path& filePath);

    bool saveScene(const std::filesystem::path& filePath);

    bool loadNewEmptyScene();
    
    bool loadDefaultScene();

    bool clearScene();

    bool updateScene(int targetFramesPerSecond = 30);

    bool syncSceneToGPU();

    template <typename SceneObject>
    ObjectID addToScene(const SceneObject& newSceneObject);

    bool removeFromScene(ObjectID objectID);

    std::vector<ObjectID> getAllObjectsInScene();

};

#endif