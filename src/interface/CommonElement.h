//
// Created by Deer on 2022/6/14.
//

#ifndef CPPMCSERVERMANAGER_COMMONELEMENT_H
#define CPPMCSERVERMANAGER_COMMONELEMENT_H

#include "../main.h"

using namespace ftxui;
using namespace std;

/*!
 * @brief 静态原素基类
 * @details body存放静态原素结构与内容，
 * 调用Render()方法将body渲染为一帧(Component 类型)
 */
class CommonElement {
public:
    Component Render();

protected:
    shared_ptr<Element> body;

};


#endif //CPPMCSERVERMANAGER_COMMONELEMENT_H
