/*
 * reversingproxymodel.cpp
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

#include "reversingproxymodel.h"

namespace Tiled {
namespace Internal {

ReversingProxyModel::ReversingProxyModel(QObject *parent)
    : QIdentityProxyModel(parent)
{
}

QVariant ReversingProxyModel::data(const QModelIndex &index, int role) const
{
    return QIdentityProxyModel::data(reversedIndex(index), role);
}

bool ReversingProxyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    return QIdentityProxyModel::setData(reversedIndex(index), value, role);
}

Qt::ItemFlags ReversingProxyModel::flags(const QModelIndex &index) const
{
    return QIdentityProxyModel::flags(reversedIndex(index));
}

QModelIndex ReversingProxyModel::reversedIndex(const QModelIndex &proxyIndex) const
{
    const int rows = rowCount(proxyIndex.parent());
    return createIndex(rows - proxyIndex.row() - 1,
                       proxyIndex.column(),
                       proxyIndex.internalPointer());
}

} // namespace Tiled
} // namespace Internal
