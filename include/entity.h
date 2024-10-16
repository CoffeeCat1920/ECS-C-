#pragma once 

#include <array>
#include <cassert>
#include <cstdint>
#include <queue>

#include "commons.h"

// The class to manage all the entities in the memory
class EntityManager {

private:

  // All the Ids that are available for Entities
  std::queue<Entity> mAvailableEntities{};

  // All the Signatures assigned
  std::array<Signature, MAX_ENTITIES> mSignatures{};

  // All the Entities living
  std::uint32_t mLivingEntityCount{};

public:
  
  EntityManager() {
    
    // Push all the available Signatures in the array
    for ( Entity e = 0; e < MAX_ENTITIES; e++ ) {
      mAvailableEntities.push(e);
    }
    
  }

  Entity CreateEntity() {

    // Check if the mLivingEntityCount is higher that MAX_ENTITIES allowed
    assert( mLivingEntityCount < MAX_ENTITIES && "ERROR: Too many entites in existance" );
    

    // Get the available Id from the mAvailableEntities queue
    Entity entity = mAvailableEntities.front();
    mAvailableEntities.pop();
    ++mLivingEntityCount;
    
    return entity; 

  }

  void DestroyEntity( Entity entity ) {
    
    // Check if the entity given is out of the MAX_ENTITIES limit
    assert(entity < MAX_ENTITIES && "ERROR: Entity out of range");

    mSignatures[entity].reset();

    mAvailableEntities.push(entity);
    --mLivingEntityCount;

  }

  void SetSignature( Entity entity, Signature signature ) {

    // Check if the entity given is out of the MAX_ENTITIES limit
    assert( entity < MAX_ENTITIES && "ERROR: Entity out of range" );

    // Put the Signature at the Entity's Id
    mSignatures[entity] = signature;

  }

  Signature GetSignature( Entity entity ) {

    // Check if the entity given is out of the MAX_ENTITIES limit
    assert( entity < MAX_ENTITIES && "ERROR: Entity out of range" );
    
    // Return the Signature 
    return mSignatures[entity];

  }

};
