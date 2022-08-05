#include "NetworkClient.hpp"
#include "common/dataIdentifiers.hpp"

#include <QGeoCoordinate>

namespace io::network
{

bool NetworkClient::readMfdData()
{
    QByteArray allData = d_socket.peek(d_socket.bytesAvailable());
    MfdIdentifier id = MfdIdentifier::COORDINATES;
    d_socket.read(reinterpret_cast<char *>(&id), sizeof(id));

    switch (id)
    {
        // map
        case MfdIdentifier::COORDINATES:
        {
            double newLat = 0;
            double newLon = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newLat) + sizeof(newLon))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();

            d_socket.read(reinterpret_cast<char *>(&newLat), sizeof(newLat));
            d_socket.read(reinterpret_cast<char *>(&newLon), sizeof(newLon));

            emit coordinatesChanged(QGeoCoordinate(newLat, newLon));
            break;
        }
        case MfdIdentifier::TRUE_HEADING:
        {
            double newValue = 0;
            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit trueHeadingChanged(newValue);
            break;
        }

        // flightplan
        case MfdIdentifier::CLEAR_FLIGHTPLAN:
        {
            d_socket.commitTransaction();
            emit clearFlightplanReceived();
            break;
        }
        case MfdIdentifier::FLIGHTPLAN_LIST:
        {
            uint64_t size = 0;
            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(size))
            {
                d_socket.rollbackTransaction();
                return false;
            }
            d_socket.read(reinterpret_cast<char *>(&size), sizeof(size));

            if (d_socket.bytesAvailable() < size)
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();

            d_socket.read(reinterpret_cast<char *>(&size), sizeof(size));
            QList<pages::mfd::FlightPlanWaypoint> waypoints;
            waypoints.reserve(size);

            while (size--)
            {
                waypoints.append(pages::mfd::FlightPlanWaypoint::fromBinary(d_socket));
            }

            emit receivedFlightplan(waypoints);
            break;
        }
        case MfdIdentifier::FLIGHTPLAN_LEG_IDX:
        {
            int32_t newIdx = 0;
            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newIdx))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();

            d_socket.read(reinterpret_cast<char *>(&newIdx), sizeof(newIdx));

            emit activeLegIdxChanged(newIdx);
            break;
        }
        case MfdIdentifier::GPS_WP_DTK:
        {
            double newValue = 0;
            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit gpsWpDtkChanged(newValue);
            break;
        }
        case MfdIdentifier::GPS_WP_ETE:
        {
            uint32_t newValue = 0;
            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit gpsWpEteChanged(newValue);
            break;
        }
        case MfdIdentifier::GPS_DEST_ETE:
        {
            uint32_t newValue = 0;
            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit gpsDestEteChanged(newValue);
            break;
        }

        // fuel
        case MfdIdentifier::FUEL_LEFT_QTY:
        {
            double newValue = 0;
            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit fuelLeftQtyChanged(newValue);
            break;
        }
        case MfdIdentifier::FUEL_RIGHT_QTY:
        {
            double newValue = 0;
            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit fuelRightQtyChanged(newValue);
            break;
        }

        // engine (indexed)
        case MfdIdentifier::ENGINE_FIRST_GAUGE:
        {
            uint8_t engineIdx = 0;
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(engineIdx) + sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&engineIdx), sizeof(engineIdx));
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit engineGauge1Changed(newValue, engineIdx);
            break;
        }
        case MfdIdentifier::ENGINE_SECOND_GAUGE:
        {
            uint8_t engineIdx = 0;
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(engineIdx) + sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&engineIdx), sizeof(engineIdx));
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit engineGauge2Changed(newValue, engineIdx);
            break;
        }
        case MfdIdentifier::ENGINE_THIRD_GAUGE:
        {
            uint8_t engineIdx = 0;
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(engineIdx) + sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&engineIdx), sizeof(engineIdx));
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit engineGauge3Changed(newValue, engineIdx);
            break;
        }
        case MfdIdentifier::ENGINE_FOURTH_GAUGE:
        {
            uint8_t engineIdx = 0;
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(engineIdx) + sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&engineIdx), sizeof(engineIdx));
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit engineGauge4Changed(newValue, engineIdx);
            break;
        }
        case MfdIdentifier::ENGINE_FUEL_FLOW:
        {
            uint8_t engineIdx = 0;
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(engineIdx) + sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&engineIdx), sizeof(engineIdx));
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit engineFuelFlowChanged(newValue, engineIdx);
            break;
        }
        case MfdIdentifier::ENGINE_OIL_TEMP:
        {
            uint8_t engineIdx = 0;
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(engineIdx) + sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&engineIdx), sizeof(engineIdx));
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit engineOilTempChanged(newValue, engineIdx);
            break;
        }
        case MfdIdentifier::ENGINE_SECONDARY_TEMP:
        {
            uint8_t engineIdx = 0;
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(engineIdx) + sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&engineIdx), sizeof(engineIdx));
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit engineSecondaryTempChanged(newValue, engineIdx);
            break;
        }
        case MfdIdentifier::ENGINE_OIL_PRESS:
        {
            uint8_t engineIdx = 0;
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(engineIdx) + sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&engineIdx), sizeof(engineIdx));
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit engineOilPressChanged(newValue, engineIdx);
            break;
        }

        // misc engine display
        case MfdIdentifier::APU_N1:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit apuN1Changed(newValue);
            break;
        }
        case MfdIdentifier::FUEL_TEXT_DATA:
        {
            float totalFuelQty = 0;
            float totalFuelFlow = 0;
            float groundSpeed = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable())
                < sizeof(totalFuelQty) + sizeof(totalFuelFlow) + sizeof(groundSpeed))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&totalFuelQty), sizeof(totalFuelQty));
            d_socket.read(reinterpret_cast<char *>(&totalFuelFlow), sizeof(totalFuelFlow));
            d_socket.read(reinterpret_cast<char *>(&groundSpeed), sizeof(groundSpeed));
            emit fuelTextDataChanged(totalFuelQty, totalFuelFlow, groundSpeed);
            break;
        }
        case MfdIdentifier::FLAPS_ANGLE:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit flapsAngleChanged(newValue);
            break;
        }
        case MfdIdentifier::SPOILERS_PCT:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit spoilersPctChanged(newValue);
            break;
        }
        case MfdIdentifier::ELEV_TRIM_POSITION:
        {
            double newPct = 0;
            int32_t newAngle = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newPct) + sizeof(newAngle))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newPct), sizeof(newPct));
            d_socket.read(reinterpret_cast<char *>(&newAngle), sizeof(newAngle));
            emit elevTrimChanged(newPct, newAngle);
            break;
        }
        case MfdIdentifier::RUDD_TRIM_POSITION:
        {
            double newPct = 0;
            int32_t newAngle = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newPct) + sizeof(newAngle))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newPct), sizeof(newPct));
            d_socket.read(reinterpret_cast<char *>(&newAngle), sizeof(newAngle));
            emit ruddTrimChanged(newPct, newAngle);
            break;
        }
        case MfdIdentifier::AIL_TRIM_POSITION:
        {
            double newPct = 0;
            int32_t newAngle = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newPct) + sizeof(newAngle))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newPct), sizeof(newPct));
            d_socket.read(reinterpret_cast<char *>(&newAngle), sizeof(newAngle));
            emit ailTrimChanged(newPct, newAngle);
            break;
        }
    }

    return true;
}

}  // namespace io::network
