//
// Created by Deer on 2022/6/12.
//

#ifndef CPPMCSERVERMANAGER_COMMONCOMPONENT_H
#define CPPMCSERVERMANAGER_COMMONCOMPONENT_H

#include "../main.h"

using namespace ftxui;

/*!
 * @brief UI组件基类
 * @details 使用类中的虚函数对第三方库的组件进行二次封装
 */
class CommonComponent {
public:
    Component GetComponent();

protected:
    Component body;
};


#endif //CPPMCSERVERMANAGER_COMMONCOMPONENT_H
