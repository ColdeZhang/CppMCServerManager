//
// Created by Deer on 2022/6/14.
//

#include "CommonElement.h"

Component CommonElement::Render() {
    return Renderer([this](){
        return *body;
    });
}
