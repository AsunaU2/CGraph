/***************************
@Author: Chunel
@Contact: chunel@foxmail.com
@File: GDaemonManager.h
@Time: 2022/2/2 11:17 下午
@Desc: 
***************************/

#ifndef CGRAPH_GDAEMONMANAGER_H
#define CGRAPH_GDAEMONMANAGER_H

#include "GDaemon.h"
#include "../GraphManager.h"

CGRAPH_NAMESPACE_BEGIN

class GDaemonManager : public GDaemonObject, public GraphManager<GDaemon> {
public:
    explicit GDaemonManager() = default;

    ~GDaemonManager() override;

    CStatus init() override;

    CStatus destroy() override;

    CStatus add(GDaemonPtr daemon) override;

    CStatus remove(GDaemonPtr daemon) override;

    CStatus clear() final;

    [[nodiscard]] CSize getSize() const override;

private:
    GDaemonSet daemons_;                    // daemon信息集合
};

using GDaemonManagerPtr = GDaemonManager *;

CGRAPH_NAMESPACE_END

#endif //CGRAPH_GDAEMONMANAGER_H
