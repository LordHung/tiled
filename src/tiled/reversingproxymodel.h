/*
 * reversingproxymodel.h
 * Copyright 2016, Thorbjørn Lindeijer <bjorn@lindeijer.nl>
 *
 * This file is part of Tiled.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef REVERSINGPROXYMODEL_H
#define REVERSINGPROXYMODEL_H

#include <QIdentityProxyModel>

namespace Tiled {
namespace Internal {

class ReversingProxyModel : public QIdentityProxyModel
{
public:
    ReversingProxyModel(QObject *parent = nullptr);

public:
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

private:
    QModelIndex reversedIndex(const QModelIndex &proxyIndex) const;
};

} // namespace Tiled
} // namespace Internal

#endif // REVERSINGPROXYMODEL_H
