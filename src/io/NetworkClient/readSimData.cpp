#include "NetworkClient.hpp"
#include "common/binaryconverter.hpp"
#include "common/dataIdentifiers.hpp"
#include <QGeoCoordinate>


namespace io::network
{

void NetworkClient::readSimData()
{
    SimconnectIds id = SimconnectIds::QUIT;
    while (!d_socket.atEnd())
    {
        d_socket.startTransaction();
        d_socket.read(reinterpret_cast<char *>(&id), sizeof(id));

        switch (id)
        {
            // flightplan
            case SimconnectIds::CLEAR_FLIGHTPLAN:
            {
                d_socket.commitTransaction();
                emit clearFlightplanReceived();
                break;
            }
            case SimconnectIds::FLIGHTPLAN_LIST:
            {
                int64_t byteSize = 0;
                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(byteSize))
                {
                    d_socket.rollbackTransaction();
                    return;
                }
                BinaryConverter::convert(d_socket, byteSize);

                if (d_socket.bytesAvailable() < byteSize)
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();

                emit receivedFlightplan(BinaryConverter::convertList<FlightPlanWaypoint>(d_socket));
                break;
            }

            // simconnect server
            case SimconnectIds::QUIT:
            {
                d_socket.commitTransaction();
                emit newErrorMessage("Sim closed");
                d_socket.disconnectFromHost();
                break;
            }
            case SimconnectIds::SIM_START_EVENT:
            {
                d_socket.commitTransaction();
                emit simStartReceived();
                break;
            }
            case SimconnectIds::SIM_STOP_EVENT:
            {
                d_socket.commitTransaction();
                emit simStopReceived();
                break;
            }
            case SimconnectIds::SIM_STARTUP_FAILED:
            {
                d_socket.commitTransaction();
                emit newErrorMessage("Could not connect to sim");
                emit simStartupFailed();
                break;
            }
            case SimconnectIds::ERROR_MSG:
            {
                uint8_t size = 0;
                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(size))
                {
                    d_socket.rollbackTransaction();
                    return;
                }
                BinaryConverter::convert(d_socket, size);

                if (d_socket.bytesAvailable() < static_cast<int64_t>(size))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();

                if (size > 0) [[likely]]
                {
                    emit newErrorMessage(BinaryConverter::convertWithSize(d_socket, size));
                }

                break;
            }


            // mfd
            case SimconnectIds::COORDINATES:
            {
                double newLat = 0;
                double newLon = 0;
                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newLat) + sizeof(newLon))
                {
                    d_socket.rollbackTransaction();
                    return;
                }
                d_socket.commitTransaction();

                BinaryConverter::convert(d_socket, newLat);
                BinaryConverter::convert(d_socket, newLon);

                emit coordinatesChanged(QGeoCoordinate(newLat, newLon));
                break;
            }
            case SimconnectIds::TRUE_HEADING:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit trueHeadingChanged(newValue);
                break;
            }
            case SimconnectIds::GPS_WP_DTK:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit gpsWpDtkChanged(newValue);
                break;
            }
            case SimconnectIds::GPS_WP_ETE:
            {
                uint32_t newValue = 0;
                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit gpsWpEteChanged(newValue);
                break;
            }
            case SimconnectIds::GPS_ETE:
            {
                uint32_t newValue = 0;
                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit gpsEteChanged(newValue);
                break;
            }
            case SimconnectIds::FUEL_LEFT_QTY:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit fuelLeftQtyChanged(newValue);
                break;
            }
            case SimconnectIds::FUEL_RIGHT_QTY:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit fuelRightQtyChanged(newValue);
                break;
            }

            // engines
            case SimconnectIds::ENGINE_N1:
            {
                uint8_t engineIdx = 0;
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(engineIdx) + sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, engineIdx);
                BinaryConverter::convert(d_socket, newValue);
                emit engineN1Changed(newValue, engineIdx);
                break;
            }
            case SimconnectIds::ENGINE_N2:
            {
                uint8_t engineIdx = 0;
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(engineIdx) + sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, engineIdx);
                BinaryConverter::convert(d_socket, newValue);
                emit engineN2Changed(newValue, engineIdx);
                break;
            }
            case SimconnectIds::ENGINE_ITT:
            {
                uint8_t engineIdx = 0;
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(engineIdx) + sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, engineIdx);
                BinaryConverter::convert(d_socket, newValue);
                emit engineIttChanged(newValue, engineIdx);
                break;
            }
            case SimconnectIds::ENGINE_RPM:
            {
                uint8_t engineIdx = 0;
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(engineIdx) + sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, engineIdx);
                BinaryConverter::convert(d_socket, newValue);
                emit engineRpmChanged(newValue, engineIdx);
                break;
            }
            case SimconnectIds::ENGINE_POWER:
            {
                uint8_t engineIdx = 0;
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(engineIdx) + sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, engineIdx);
                BinaryConverter::convert(d_socket, newValue);
                emit enginePowerChanged(newValue, engineIdx);
                break;
            }
            case SimconnectIds::ENGINE_MANIFOLD_PRESSURE:
            {
                uint8_t engineIdx = 0;
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(engineIdx) + sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, engineIdx);
                BinaryConverter::convert(d_socket, newValue);
                emit engineManPressChanged(newValue, engineIdx);
                break;
            }
            case SimconnectIds::ENGINE_TRQ:
            {
                uint8_t engineIdx = 0;
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(engineIdx) + sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, engineIdx);
                BinaryConverter::convert(d_socket, newValue);
                emit engineTrqChanged(newValue, engineIdx);
                break;
            }
            case SimconnectIds::ENGINE_CHT:
            {
                uint8_t engineIdx = 0;
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(engineIdx) + sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, engineIdx);
                BinaryConverter::convert(d_socket, newValue);
                emit engineChtChanged(newValue, engineIdx);
                break;
            }
            case SimconnectIds::ENGINE_FUEL_FLOW:
            {
                uint8_t engineIdx = 0;
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(engineIdx) + sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, engineIdx);
                BinaryConverter::convert(d_socket, newValue);
                emit engineFuelFlowChanged(newValue, engineIdx);
                break;
            }
            case SimconnectIds::ENGINE_EGT:
            {
                uint8_t engineIdx = 0;
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(engineIdx) + sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, engineIdx);
                BinaryConverter::convert(d_socket, newValue);
                emit engineEgtChanged(newValue, engineIdx);
                break;
            }
            case SimconnectIds::ENGINE_OIL_TEMP:
            {
                uint8_t engineIdx = 0;
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(engineIdx) + sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, engineIdx);
                BinaryConverter::convert(d_socket, newValue);
                emit engineOilTempChanged(newValue, engineIdx);
                break;
            }
            case SimconnectIds::ENGINE_OIL_PRESS:
            {
                uint8_t engineIdx = 0;
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(engineIdx) + sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, engineIdx);
                BinaryConverter::convert(d_socket, newValue);
                emit engineOilPressChanged(newValue, engineIdx);
                break;
            }

            // misc engine display
            case SimconnectIds::APU_N1:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit apuN1Changed(newValue);
                break;
            }
            case SimconnectIds::FUEL_TEXT_DATA:
            {
                float totalFuelQty = 0;
                float totalFuelFlow = 0;
                float groundSpeed = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(totalFuelQty) + sizeof(totalFuelFlow) + sizeof(groundSpeed))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, totalFuelQty);
                BinaryConverter::convert(d_socket, totalFuelFlow);
                BinaryConverter::convert(d_socket, groundSpeed);
                emit fuelTextDataChanged(totalFuelQty, totalFuelFlow, groundSpeed);
                break;
            }
            case SimconnectIds::FLAPS_ANGLE:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit flapsAngleChanged(newValue);
                break;
            }
            case SimconnectIds::SPOILERS_PCT:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit spoilersPctChanged(newValue);
                break;
            }
            case SimconnectIds::ELEV_TRIM_PCT:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit elevTrimChanged(newValue);
                break;
            }
            case SimconnectIds::RUDD_TRIM_PCT:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit ruddTrimChanged(newValue);
                break;
            }
            case SimconnectIds::AIL_TRIM_PCT:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit ailTrimChanged(newValue);
                break;
            }


            // pfd
            // airspeed
            case SimconnectIds::AIRSPEED:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit airspeedChanged(newValue);
                break;
            }
            case SimconnectIds::MAX_SPEED:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit maxSpeedChanged(newValue);
                break;
            }
            case SimconnectIds::TRUE_AIRSPEED:
            {
                uint32_t newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit trueAirspeedChanged(newValue);
                break;
            }
            case SimconnectIds::REF_SPEED:
            {
                uint32_t newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit refSpeedChanged(newValue);
                break;
            }

            // altimeter
            case SimconnectIds::ALTITUDE:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit altitudeChanged(newValue);
                break;
            }
            case SimconnectIds::RADAR_ALTITUDE:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit radarAltitudeChanged(newValue);
                break;
            }
            case SimconnectIds::REF_ALTITUDE:
            {
                uint32_t newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit refAltitudeChanged(newValue);
                break;
            }
            case SimconnectIds::PRESSURE:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit pressureChanged(newValue);
                break;
            }

            case SimconnectIds::VSPEED:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit vspeedChanged(newValue);
                break;
            }
            case SimconnectIds::REF_VSPEED:
            {
                uint32_t newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit refVspeedChanged(newValue);
                break;
            }
            case SimconnectIds::VERT_DEV_MODE:
            {
                VerticalDeviationMode newValue = VerticalDeviationMode::NONE;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit vDevModeChanged(newValue);
                break;
            }
            case SimconnectIds::VERT_DEV_VALUE:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit vDevValueChanged(newValue);
                break;
            }

            // attitude
            case SimconnectIds::ATTITUDE:
            {
                double bank = 0;
                double pitch = 0;
                double slipskid = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(bank) + sizeof(pitch) + sizeof(slipskid))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, bank);
                BinaryConverter::convert(d_socket, pitch);
                BinaryConverter::convert(d_socket, slipskid);
                emit attitudeChanged(bank, pitch, slipskid);
            }
            case SimconnectIds::FD_ATTITUDE:
            {
                double bank = 0;
                double pitch = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(bank) + sizeof(pitch))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, bank);
                BinaryConverter::convert(d_socket, pitch);
                emit fdAttitudeChanged(bank, pitch);
            }
            // aoa
            case SimconnectIds::ANGLE_OF_ATTACK:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit angleOfAttackChanged(newValue);
                break;
            }

            // hsi
            case SimconnectIds::ROTATION:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit rotationChanged(newValue);
                break;
            }
            case SimconnectIds::HEADING:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit headingChanged(newValue);
                break;
            }
            case SimconnectIds::COURSE:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit courseChanged(newValue);
                break;
            }
            case SimconnectIds::COURSE_DEVIATION:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit courseDeviationChanged(newValue);
                break;
            }
            case SimconnectIds::DISPLAY_DEVIATION:
            {
                bool newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit displayDeviationChanged(newValue);
                break;
            }
            case SimconnectIds::TURN_RATE:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit turnRateChanged(newValue);
                break;
            }
            case SimconnectIds::NAV_SOURCE:
            {
                HsiNavSource newValue = HsiNavSource::NONE;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit navSourceChanged(newValue);
                break;
            }
            case SimconnectIds::CURRENT_TRACK:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit currentTrackChanged(newValue);
                break;
            }
            case SimconnectIds::TO_FROM:
            {
                uint32_t newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit toFromChanged(newValue);
                break;
            }

            // bottombar
            case SimconnectIds::ZULU_SECONDS:
            {
                uint32_t newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit zuluSecondsChanged(newValue);
                break;
            }
            case SimconnectIds::LOCAL_SECONDS:
            {
                uint32_t newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit localSecondsChanged(newValue);
                break;
            }
            case SimconnectIds::GROUND_SPEED:
            {
                uint32_t newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit groundSpeedChanged(newValue);
                break;
            }
            case SimconnectIds::TOTAL_AIR_TEMP:
            {
                float newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit totalAirTempChanged(newValue);
                break;
            }
            case SimconnectIds::OUTSIDE_AIR_TEMP:
            {
                float newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit outsideAirTempChanged(newValue);
                break;
            }
            case SimconnectIds::ISA_AIR_TEMP:
            {
                float newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit isaTempChanged(newValue);
                break;
            }

            // bearings
            case SimconnectIds::NAV1_IDENT:
            {
                uint8_t size = 0;
                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(size))
                {
                    d_socket.rollbackTransaction();
                    return;
                }
                BinaryConverter::convert(d_socket, size);

                if (d_socket.bytesAvailable() < static_cast<int64_t>(size))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();

                emit nav1IdentChanged(size == 0 ? "" : BinaryConverter::convertWithSize(d_socket, size));

                break;
            }
            case SimconnectIds::NAV1_DME:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit nav1DmeChanged(newValue);
                break;
            }
            case SimconnectIds::NAV1_BEARING:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit nav1BearingChanged(newValue);
                break;
            }
            case SimconnectIds::NAV1_HAS_NAV:
            {
                bool newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit nav1HasNavChanged(newValue);
                break;
            }
            case SimconnectIds::NAV1_HAS_SIGNAL:
            {
                bool newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit nav1HasSignalChanged(newValue);
                break;
            }
            case SimconnectIds::NAV1_HAS_DME:
            {
                bool newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit nav1HasDmeChanged(newValue);
                break;
            }
            case SimconnectIds::NAV2_IDENT:
            {
                uint8_t size = 0;
                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(size))
                {
                    d_socket.rollbackTransaction();
                    return;
                }
                BinaryConverter::convert(d_socket, size);

                if (d_socket.bytesAvailable() < static_cast<int64_t>(size))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();

                emit nav2IdentChanged(size == 0 ? "" : BinaryConverter::convertWithSize(d_socket, size));

                break;
            }
            case SimconnectIds::NAV2_DME:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit nav2DmeChanged(newValue);
                break;
            }
            case SimconnectIds::NAV2_BEARING:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit nav2BearingChanged(newValue);
                break;
            }
            case SimconnectIds::NAV2_HAS_NAV:
            {
                bool newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit nav2HasNavChanged(newValue);
                break;
            }
            case SimconnectIds::NAV2_HAS_SIGNAL:
            {
                bool newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit nav2HasSignalChanged(newValue);
                break;
            }
            case SimconnectIds::NAV2_HAS_DME:
            {
                bool newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit nav2HasDmeChanged(newValue);
                break;
            }
            case SimconnectIds::GPS_DISTANCE:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit gpsDistanceChanged(newValue);
                break;
            }
            case SimconnectIds::GPS_BEARING:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit gpsBearingChanged(newValue);
                break;
            }
            case SimconnectIds::ADF_HAS_SIGNAL:
            {
                bool newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit adfHasSignalChanged(newValue);
                break;
            }
            case SimconnectIds::ADF_FREQ:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit adfFreqChanged(newValue);
                break;
            }
            case SimconnectIds::ADF_RADIAL:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit adfRadialChanged(newValue);
                break;
            }

            // nav info
            case SimconnectIds::GPS_IS_ACTIVE_FLIGHTPLAN:
            {
                bool newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit gpsIsActiveFlightplanChanged(newValue);
                break;
            }
            case SimconnectIds::LEG_IS_DIRECT_TO:
            {
                bool newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit legIsDirectToChanged(newValue);
                break;
            }
            case SimconnectIds::CURRENT_LEG_TO:
            {
                uint8_t size = 0;
                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(size))
                {
                    d_socket.rollbackTransaction();
                    return;
                }
                BinaryConverter::convert(d_socket, size);

                if (d_socket.bytesAvailable() < static_cast<int64_t>(size))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();

                emit currentLegToChanged(size == 0 ? "" : BinaryConverter::convertWithSize(d_socket, size));

                break;
            }
            case SimconnectIds::CURRENT_LEG_FROM:
            {
                uint8_t size = 0;
                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(size))
                {
                    d_socket.rollbackTransaction();
                    return;
                }
                BinaryConverter::convert(d_socket, size);

                if (d_socket.bytesAvailable() < static_cast<int64_t>(size))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();

                emit currentLegFromChanged(size == 0 ? "" : BinaryConverter::convertWithSize(d_socket, size));

                break;
            }

            // radio info
            case SimconnectIds::COM1_AVAIL:
            {
                bool newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit com1AvailChanged(newValue);
                break;
            }
            case SimconnectIds::COM2_AVAIL:
            {
                bool newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit com2AvailChanged(newValue);
                break;
            }
            case SimconnectIds::NAV1_AVAIL:
            {
                bool newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit nav1AvailChanged(newValue);
                break;
            }
            case SimconnectIds::NAV2_AVAIL:
            {
                bool newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit nav2AvailChanged(newValue);
                break;
            }
            case SimconnectIds::COM1_FREQ:
            {
                float newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit com1FreqChanged(newValue);
                break;
            }
            case SimconnectIds::COM2_FREQ:
            {
                float newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit com2FreqChanged(newValue);
                break;
            }
            case SimconnectIds::NAV1_FREQ:
            {
                float newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit nav1FreqChanged(newValue);
                break;
            }
            case SimconnectIds::NAV2_FREQ:
            {
                float newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit nav2FreqChanged(newValue);
                break;
            }
            case SimconnectIds::COM1_STBY:
            {
                float newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit com1StbyChanged(newValue);
                break;
            }
            case SimconnectIds::COM2_STBY:
            {
                float newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit com2StbyChanged(newValue);
                break;
            }
            case SimconnectIds::NAV1_STBY:
            {
                float newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit nav1StbyChanged(newValue);
                break;
            }
            case SimconnectIds::NAV2_STBY:
            {
                float newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit nav2StbyChanged(newValue);
                break;
            }
            case SimconnectIds::XPDR_CODE:
            {
                uint32_t newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit xpdrCodeChanged(newValue);
                break;
            }
            case SimconnectIds::XPDR_STATE:
            {
                uint32_t newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit xpdrStateChanged(newValue);
                break;
            }

            // wind
            case SimconnectIds::WIND_DIRECTION:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit windDirectionChanged(newValue);
                break;
            }
            case SimconnectIds::WIND_STRENGTH:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit windStrengthChanged(newValue);
                break;
            }
            case SimconnectIds::WIND_TRUE_DIRECTION:
            {
                double newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit windTrueDirectionChanged(newValue);
                break;
            }

            // ap info
            case SimconnectIds::AP_AVAILABLE:
            {
                bool newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit apAvailableChanged(newValue);
                break;
            }
            case SimconnectIds::AP_LATERAL_ACTIVE:
            {
                uint8_t size = 0;
                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(size))
                {
                    d_socket.rollbackTransaction();
                    return;
                }
                BinaryConverter::convert(d_socket, size);

                if (d_socket.bytesAvailable() < static_cast<int64_t>(size))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();

                emit apLateralActiveChanged(size == 0 ? "" : BinaryConverter::convertWithSize(d_socket, size));

                break;
            }
            case SimconnectIds::AP_LATERAL_ARMED:
            {
                uint8_t size = 0;
                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(size))
                {
                    d_socket.rollbackTransaction();
                    return;
                }
                BinaryConverter::convert(d_socket, size);

                if (d_socket.bytesAvailable() < static_cast<int64_t>(size))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();

                emit apLateralArmedChanged(size == 0 ? "" : BinaryConverter::convertWithSize(d_socket, size));

                break;
            }
            case SimconnectIds::AP_STATUS:
            {
                bool newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit apStatusChanged(newValue);
                break;
            }
            case SimconnectIds::AP_YD_STATUS:
            {
                bool newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit apYdStatusChanged(newValue);
                break;
            }
            case SimconnectIds::AP_FD_STATUS:
            {
                bool newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit apFdStatusChanged(newValue);
                break;
            }
            case SimconnectIds::AP_FLC:
            {
                bool newValue = 0;

                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();
                BinaryConverter::convert(d_socket, newValue);
                emit apFlcChanged(newValue);
                break;
            }
            case SimconnectIds::AP_VERTICAL_ACTIVE:
            {
                uint8_t size = 0;
                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(size))
                {
                    d_socket.rollbackTransaction();
                    return;
                }
                BinaryConverter::convert(d_socket, size);

                if (d_socket.bytesAvailable() < static_cast<int64_t>(size))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();

                emit apVerticalActiveChanged(size == 0 ? "" : BinaryConverter::convertWithSize(d_socket, size));

                break;
            }
            case SimconnectIds::AP_MODE_REFERENCE:
            {
                uint8_t size = 0;
                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(size))
                {
                    d_socket.rollbackTransaction();
                    return;
                }
                BinaryConverter::convert(d_socket, size);

                if (d_socket.bytesAvailable() < static_cast<int64_t>(size))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();

                emit apModeReferenceChanged(size == 0 ? "" : BinaryConverter::convertWithSize(d_socket, size));

                break;
            }
            case SimconnectIds::AP_ARMED:
            {
                uint8_t size = 0;
                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(size))
                {
                    d_socket.rollbackTransaction();
                    return;
                }
                BinaryConverter::convert(d_socket, size);

                if (d_socket.bytesAvailable() < static_cast<int64_t>(size))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();

                emit apArmedChanged(size == 0 ? "" : BinaryConverter::convertWithSize(d_socket, size));

                break;
            }
            case SimconnectIds::AP_ARMED_REFERENCE:
            {
                uint8_t size = 0;
                if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(size))
                {
                    d_socket.rollbackTransaction();
                    return;
                }
                BinaryConverter::convert(d_socket, size);

                if (d_socket.bytesAvailable() < static_cast<int64_t>(size))
                {
                    d_socket.rollbackTransaction();
                    return;
                }

                d_socket.commitTransaction();

                emit apArmedReferenceChanged(size == 0 ? "" : BinaryConverter::convertWithSize(d_socket, size));

                break;
            }





        }
    }
}

}  // namespace io::network
