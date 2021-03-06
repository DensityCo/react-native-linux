
/**
 * Copyright (C) 2016, Canonical Ltd.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 *
 * Author: Justin McPherson <justin.mcpherson@canonical.com>
 *
 */

#ifndef NETWORKING_H
#define NETWORKING_H

#include <functional>

#include <QObject>
#include <QVariant>

#include "moduleinterface.h"

class NetworkingPrivate;
class Networking : public QObject, public ModuleInterface {
    Q_OBJECT
    // Q_PLUGIN_METADATA(IID ReactModuleInterface_IID)
    Q_INTERFACES(ModuleInterface)

    Q_INVOKABLE void sendRequest(
        int requestId, const QString& method, const QUrl& url, const QVariantMap& headers, const QByteArray& data);
    Q_INVOKABLE void abortRequest(int requestId);

    Q_DECLARE_PRIVATE(Networking);

public:
    Networking(QObject* parent = 0);
    ~Networking();

    void setBridge(Bridge* bridge) override;

    // TODO: this doesnt seem right
    ViewManager* viewManager() override;

    QString moduleName() override;
    QList<ModuleMethod*> methodsToExport() override;
    QVariantMap constantsToExport() override;

private:
    QScopedPointer<NetworkingPrivate> d_ptr;
};

#endif // NETWORKING_H
