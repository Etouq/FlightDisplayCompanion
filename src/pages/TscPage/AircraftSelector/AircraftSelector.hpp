#ifndef __AIRCRAFT_SELECTOR_HPP__
#define __AIRCRAFT_SELECTOR_HPP__

#include "common/definitions/AircraftDefinition/AircraftDefinition.hpp"

#include "ThumbnailProvider/ThumbnailProvider.hpp"

#include <QImage>
#include <QList>
#include <QObject>

namespace pages::tsc
{

struct ThumbnailPair
{
    QImage image;
    definitions::AircraftDefinition *definition;
};

class AircraftSelector : public QObject
{
    Q_OBJECT


public:

    explicit AircraftSelector(QObject *parent = nullptr)
    : QObject(parent)
    {}

    void clear()
    {
        d_jetAircraft.clear();
        d_propAircraft.clear();
        d_turbopropAircraft.clear();
        d_thumbnailProvider.clear();
    }

    Q_INVOKABLE int jetCount() const
    {
        return d_jetAircraft.size();
    }

    Q_INVOKABLE const QString &jetName(int idx) const
    {
        return d_jetAircraft.at(idx).name;
    }

    Q_INVOKABLE int propCount() const
    {
        return d_propAircraft.size();
    }

    Q_INVOKABLE const QString &propName(int idx) const
    {
        return d_propAircraft.at(idx).name;
    }

    Q_INVOKABLE int turbopropCount() const
    {
        return d_turbopropAircraft.size();
    }

    Q_INVOKABLE const QString &turbopropName(int idx) const
    {
        return d_turbopropAircraft.at(idx).name;
    }

    Q_INVOKABLE void selectJet(int idx)
    {
        emit loadAircraft(d_jetAircraft.at(idx));
    }
    Q_INVOKABLE void selectProp(int idx)
    {
        emit loadAircraft(d_propAircraft.at(idx));
    }
    Q_INVOKABLE void selectTurboprop(int idx)
    {
        emit loadAircraft(d_turbopropAircraft.at(idx));
    }

signals:

    void loadAircraft(const definitions::AircraftDefinition &definition);
    void jetAircraftChanged();
    void propAircraftChanged();
    void turbopropAircraftChanged();

    void requestServerAircraftSelection();

public slots:

    // send request for definitions and thumbnails to server
    void requestAircraftSelection()
    {
        emit requestServerAircraftSelection();
    }

    void receivedNewAircraft(const QImage &thumbnail, const definitions::AircraftDefinition &definition)
    {
        d_thumbnailProvider.storeImage(definition.name, thumbnail);


        if (definition.type == AircraftType::JET)
        {
            d_jetAircraft.append(definition);
            emit jetAircraftChanged();
            return;
        }

        if (definition.type == AircraftType::PROP)
        {
            d_propAircraft.append(definition);
            emit propAircraftChanged();
            return;
        }
        if (definition.type == AircraftType::TURBOPROP)
        {
            d_turbopropAircraft.append(definition);
            emit turbopropAircraftChanged();
            return;
        }
    }

private:

    QList<definitions::AircraftDefinition> d_jetAircraft;
    QList<definitions::AircraftDefinition> d_propAircraft;
    QList<definitions::AircraftDefinition> d_turbopropAircraft;

    ThumbnailProvider d_thumbnailProvider;
};

}  // namespace pages::tsc


#endif  // __AIRCRAFT_SELECTOR_HPP__