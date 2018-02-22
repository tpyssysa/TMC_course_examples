/***************************************************************************
*                                                                          *
*                salesaccount.cpp for 04_object_properties                 *
*                Created on  : Fri Mar 10 2017 09:50                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "salesaccount.h"

SalesAccount::SalesAccount(QObject *parent) :
    QObject(parent),
    m_regions(Africa | Europe)
{

}

SalesAccount::Regions SalesAccount::regions() const
{
    return m_regions;
}

void SalesAccount::setRegions(Regions regions)
{
    if (m_regions != regions) {
        m_regions = regions;
        emit regionsChanged();
    }
}
