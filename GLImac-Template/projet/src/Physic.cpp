#include "Physic.hpp"

Physic * Physic::physic = new Physic();

Physic::Physic(){}

Physic::~Physic(){
    delete physic;
}

Physic * Physic::getInstance() noexcept{
    return physic;
}

bool Physic::checkCollision(const Character & a, const Object & b){
    Collider bbA = a.boundingBox(), bbB = b.boundingBox();
    return bbA.isColliding(bbB);
}

bool Physic::isGrounded(const Collider & a, const Collider & other){
    Collider raycast(glm::vec3(0, -RAYCAST_LENGTH, 0), glm::vec3(0));
    glm::vec3 low = a.lower();
    glm::vec3 up = a.upper();
    Collider b = raycast + a.lower() + glm::vec3(RAYCAST_LENGTH, 0, RAYCAST_LENGTH);
    Collider c = raycast + glm::vec3(low.x,low.y,up.z) + glm::vec3(RAYCAST_LENGTH, 0, -RAYCAST_LENGTH);
    Collider d = raycast + glm::vec3(up.x,low.y,low.z) + glm::vec3(-RAYCAST_LENGTH, 0, RAYCAST_LENGTH);
    Collider e = raycast + glm::vec3(up.x,low.y,up.z) + glm::vec3(-RAYCAST_LENGTH, 0, -RAYCAST_LENGTH);

    return b.isColliding(other) || c.isColliding(other) || d.isColliding(other) || e.isColliding(other);

}