#include "NetworkClient.hpp"
#include "common/dataIdentifiers.hpp"
#include "common/converters/listConverters.hpp"

#include <QGeoCoordinate>

namespace io::network
{

bool NetworkClient::readMfdData()
{
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

            Converters::convert(d_socket, newLat);
            Converters::convert(d_socket, newLon);

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
            Converters::convert(d_socket, newValue);
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
            int64_t byteSize = 0;
            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(byteSize))
            {
                d_socket.rollbackTransaction();
                return false;
            }
            Converters::convert(d_socket, byteSize);

            if (d_socket.bytesAvailable() < byteSize)
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();

            emit receivedFlightplan(Converters::convertList<pages::mfd::FlightPlanWaypoint>(d_socket));
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
            Converters::convert(d_socket, newValue);
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
            Converters::convert(d_socket, newValue);
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
            Converters::convert(d_socket, newValue);
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
            Converters::convert(d_socket, newValue);
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
            Converters::convert(d_socket, newValue);
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
            Converters::convert(d_socket, engineIdx);
            Converters::convert(d_socket, newValue);
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
            Converters::convert(d_socket, engineIdx);
            Converters::convert(d_socket, newValue);
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
            Converters::convert(d_socket, engineIdx);
            Converters::convert(d_socket, newValue);
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
            Converters::convert(d_socket, engineIdx);
            Converters::convert(d_socket, newValue);
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
            Converters::convert(d_socket, engineIdx);
            Converters::convert(d_socket, newValue);
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
            Converters::convert(d_socket, engineIdx);
            Converters::convert(d_socket, newValue);
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
            Converters::convert(d_socket, engineIdx);
            Converters::convert(d_socket, newValue);
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
            Converters::convert(d_socket, engineIdx);
            Converters::convert(d_socket, newValue);
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
            Converters::convert(d_socket, newValue);
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
            Converters::convert(d_socket, totalFuelQty);
            Converters::convert(d_socket, totalFuelFlow);
            Converters::convert(d_socket, groundSpeed);
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
            Converters::convert(d_socket, newValue);
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
            Converters::convert(d_socket, newValue);
            emit spoilersPctChanged(newValue);
            break;
        }
        case MfdIdentifier::ELEV_TRIM_POSITION:
        {
            double newPct = 0;
            int8_t newAngle = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newPct) + sizeof(newAngle))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            Converters::convert(d_socket, newPct);
            Converters::convert(d_socket, newAngle);
            emit elevTrimChanged(newPct, newAngle);
            break;
        }
        case MfdIdentifier::RUDD_TRIM_POSITION:
        {
            double newPct = 0;
            int8_t newAngle = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newPct) + sizeof(newAngle))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            Converters::convert(d_socket, newPct);
            Converters::convert(d_socket, newAngle);
            emit ruddTrimChanged(newPct, newAngle);
            break;
        }
        case MfdIdentifier::AIL_TRIM_POSITION:
        {
            double newPct = 0;
            int8_t newAngle = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newPct) + sizeof(newAngle))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            Converters::convert(d_socket, newPct);
            Converters::convert(d_socket, newAngle);
            emit ailTrimChanged(newPct, newAngle);
            break;
        }
    }

    return true;
}

}  // namespace io::network
