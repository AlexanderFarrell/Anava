//
// Created by Alexander Farrell on 6/25/22.
//

#ifndef ANAVA_T_THREE_TEXTUREFILTERS_H
#define ANAVA_T_THREE_TEXTUREFILTERS_H


#include <glm/vec3.hpp>
#include "../../io/visual/texture.h"
#include "../data/swizzle.h"
#include "../data/random/random.h"

class TextureFilters {
public:
    static void ApplyNoise(Texture * texture);
    static void ApplyNoise(Texture *texture, float min, float max);
    static void ApplyNoiseUnit(Texture *texture, float min, float max);
    static void BlendMultiply(Texture* texture, float r, float g, float b);
    static Texture* CreateGradient(glm::vec3 start, glm::vec3 end);
    static Texture* CreateSpace(int width, int height, float starChance);
    static Texture* CreateCornerGradient(glm::vec3 lt,
                                         glm::vec3 rt,
                                         glm::vec3 lb,
                                         glm::vec3 rb);
};


#endif //ANAVA_T_THREE_TEXTUREFILTERS_H
