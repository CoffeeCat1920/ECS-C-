#pragma once

#include "commons.h"
#include "definations.h"
#include <array>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <unordered_map>

// To manage all the components each entity has
// The Inherited virtual class
class IComponentArray {

public:
  virtual ~IComponentArray() = default;
  virtual void EntityDestroy( Entity entity ) = 0;

};

// The actual Implementation
template<typename T>
class ComponentArray : public IComponentArray {

private:
  
  // The actual array to which componenets are added
  std::array<T, MAX_ENTITIES> mComponentArray;

  // Map from Entity->Id to Array Indexes
  std::unordered_map<Entity, size_t> mEntityToIndexMap;

  // Map from Array Indexes to Entity->Id
  std::unordered_map<size_t, Entity> mIndexToEntityMap;
  
  // Size of the array
  size_t mSize;

public:

  // Init Array from Index 0
  ComponentArray() : mSize(0) {}

  void InsertData( Entity entity, T component ) {

    // Check if the Entity->Id is mapped to an Index in the map before
    assert(mEntityToIndexMap.find(entity) == mEntityToIndexMap.end() && "ERROR: Componenet Added to same Entity More Than once");
    
    // Map the Entity->Id at the end of the map
    size_t newIndex = mSize;
    mEntityToIndexMap[entity] = newIndex;
    mIndexToEntityMap[newIndex] = entity;
    mComponentArray[newIndex] = component;
    mSize++;

  }
  
  // To Remove the Entity->Componenets from the mComponentArray and reseting it to be packed
  void RemoveData( Entity entity ) {
    
    // Check is the Entity->Id is not mapped to an Index in the map before  
    assert(mEntityToIndexMap.find(entity) != mEntityToIndexMap.end() && "ERROR: Removing a non-existing componenet.");
    
    // Put the Entity on the Last Index on the Index of the Removed
    size_t indexOfRemovedEntity = mEntityToIndexMap[entity];
    size_t indexOfLastEntity = mSize - 1;
    mComponentArray[indexOfRemovedEntity] = mComponentArray[indexOfLastEntity];

    // Updating the map to point to the correct position
    Entity entityOfLastElement = mIndexToEntityMap[indexOfLastEntity];
    mEntityToIndexMap[entityOfLastElement] = indexOfRemovedEntity;
    mIndexToEntityMap[indexOfRemovedEntity] = entityOfLastElement;

    // Remove the Other values
    mEntityToIndexMap.erase(entity);
    mIndexToEntityMap.erase(indexOfLastEntity);

    --mSize;

  }

  T& GetData(Entity entity) {

    assert(mEntityToIndexMap.find(entity) != mEntityToIndexMap.end() && "ERROR: Readin the Data of non-existing componenet.");

    return (mComponentArray[mEntityToIndexMap[entity]]);

  }

  void EntityDestroy(Entity entity) override {

    if (mEntityToIndexMap.find(entity) != mEntityToIndexMap.end()) {

      RemoveData(entity);

    }

  }

};

class ComponentManager {

private:
  
  // A Map that points from String names to ComponenetType   
  std::unordered_map<const char*, ComponentType> mComponentType{};

  // A Map that points from String names to IComponentArray-es
  std::unordered_map<const char*, std::shared_ptr<IComponentArray>> mComponentArray;

  // The component type to be assigned to the next component
  ComponentType mNextComponentType;

  // Helper function to get statically casted pointer t ComponentArray of type T
  template<typename T>
  std::shared_ptr<ComponentArray<T>> GetComponentArray() {
    const char* typeName = typeid(T).name();
    assert ( mComponentType.find(typeName) != mComponentType.end() && "Component Not Rigistered before use." );

    // we are converting mComponentArray entry to ComponentArray 
    return std::static_pointer_cast<ComponentArray<T>>(mComponentArray[typeName]);
  }

public:

template <typename T>
  void RegisterComponent() {
    
    const char* typeName = typeid(T).name();

    assert( mComponentType.find(typeName) == mComponentType.end() && "Registering Already Registered Componenet" );

  }

};
