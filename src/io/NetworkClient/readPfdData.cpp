#include "NetworkClient.hpp"
#include "common/dataIdentifiers.hpp"

namespace io::network
{

bool NetworkClient::readPfdData()
{
    PfdIdentifier id = PfdIdentifier::AIRSPEED;
    d_socket.read(reinterpret_cast<char *>(&id), sizeof(id));


    switch (id)
    {
        // airspeed
        case PfdIdentifier::AIRSPEED:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit airspeedChanged(newValue);
            break;
        }
        case PfdIdentifier::MAX_SPEED:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit maxSpeedChanged(newValue);
            break;
        }
        case PfdIdentifier::TRUE_AIRSPEED:
        {
            int32_t newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit trueAirspeedChanged(newValue);
            break;
        }
        case PfdIdentifier::REF_SPEED:
        {
            int32_t newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit refSpeedChanged(newValue);
            break;
        }

        // altimeter
        case PfdIdentifier::ALTITUDE:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit altitudeChanged(newValue);
            break;
        }
        case PfdIdentifier::RADAR_ALTITUDE:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit radarAltitudeChanged(newValue);
            break;
        }
        case PfdIdentifier::REF_ALTITUDE:
        {
            int32_t newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit refAltitudeChanged(newValue);
            break;
        }
        case PfdIdentifier::PRESSURE:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit pressureChanged(newValue);
            break;
        }

        case PfdIdentifier::VSPEED:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit vspeedChanged(newValue);
            break;
        }
        case PfdIdentifier::REF_VSPEED:
        {
            int32_t newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit refVspeedChanged(newValue);
            break;
        }
        case PfdIdentifier::VERT_DEV_MODE:
        {
            VerticalDeviationMode newValue = VerticalDeviationMode::NONE;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit vDevModeChanged(newValue);
            break;
        }
        case PfdIdentifier::VERT_DEV_VALUE:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit vDevValueChanged(newValue);
            break;
        }

        // attitude
        case PfdIdentifier::ATTITUDE:
        {
            double bank = 0;
            double pitch = 0;
            double slipskid = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(bank) + sizeof(pitch) + sizeof(slipskid))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&bank), sizeof(bank));
            d_socket.read(reinterpret_cast<char *>(&pitch), sizeof(pitch));
            d_socket.read(reinterpret_cast<char *>(&slipskid), sizeof(slipskid));
            emit attitudeChanged(bank, pitch, slipskid);
            break;
        }
        case PfdIdentifier::FD_ATTITUDE:
        {
            double bank = 0;
            double pitch = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(bank) + sizeof(pitch))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&bank), sizeof(bank));
            d_socket.read(reinterpret_cast<char *>(&pitch), sizeof(pitch));
            emit fdAttitudeChanged(bank, pitch);
            break;
        }
        // aoa
        case PfdIdentifier::ANGLE_OF_ATTACK:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit angleOfAttackChanged(newValue);
            break;
        }

        // hsi
        case PfdIdentifier::ROTATION:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit rotationChanged(newValue);
            break;
        }
        case PfdIdentifier::HEADING:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit headingChanged(newValue);
            break;
        }
        case PfdIdentifier::COURSE:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit courseChanged(newValue);
            break;
        }
        case PfdIdentifier::COURSE_DEVIATION:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit courseDeviationChanged(newValue);
            break;
        }
        case PfdIdentifier::DISPLAY_DEVIATION:
        {
            bool newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit displayDeviationChanged(newValue);
            break;
        }
        case PfdIdentifier::TURN_RATE:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit turnRateChanged(newValue);
            break;
        }
        case PfdIdentifier::NAV_SOURCE:
        {
            HsiNavSource newValue = HsiNavSource::NONE;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit navSourceChanged(newValue);
            break;
        }
        case PfdIdentifier::CURRENT_TRACK:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit currentTrackChanged(newValue);
            break;
        }
        case PfdIdentifier::TO_FROM:
        {
            uint32_t newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit toFromChanged(newValue);
            break;
        }

        // bottombar
        case PfdIdentifier::ZULU_SECONDS:
        {
            uint32_t newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit zuluSecondsChanged(newValue);
            break;
        }
        case PfdIdentifier::LOCAL_SECONDS:
        {
            uint32_t newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit localSecondsChanged(newValue);
            break;
        }
        case PfdIdentifier::GROUND_SPEED:
        {
            int32_t newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit groundSpeedChanged(newValue);
            break;
        }
        case PfdIdentifier::TOTAL_AIR_TEMP:
        {
            float newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit totalAirTempChanged(newValue);
            break;
        }
        case PfdIdentifier::OUTSIDE_AIR_TEMP:
        {
            float newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit outsideAirTempChanged(newValue);
            break;
        }
        case PfdIdentifier::ISA_AIR_TEMP:
        {
            float newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit isaTempChanged(newValue);
            break;
        }

        // bearings
        case PfdIdentifier::NAV1_IDENT:
        {
            uint8_t size = 0;
            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(size))
            {
                d_socket.rollbackTransaction();
                return false;
            }
            d_socket.read(reinterpret_cast<char *>(&size), sizeof(size));

            if (d_socket.bytesAvailable() < static_cast<int64_t>(size))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();

            emit nav1IdentChanged(size == 0 ? "" : QString::fromUtf8(d_socket.read(size)));

            break;
        }
        case PfdIdentifier::NAV1_DME:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit nav1DmeChanged(newValue);
            break;
        }
        case PfdIdentifier::NAV1_BEARING:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit nav1BearingChanged(newValue);
            break;
        }
        case PfdIdentifier::NAV1_HAS_NAV:
        {
            bool newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit nav1HasNavChanged(newValue);
            break;
        }
        case PfdIdentifier::NAV1_HAS_SIGNAL:
        {
            bool newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit nav1HasSignalChanged(newValue);
            break;
        }
        case PfdIdentifier::NAV1_HAS_DME:
        {
            bool newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit nav1HasDmeChanged(newValue);
            break;
        }
        case PfdIdentifier::NAV2_IDENT:
        {
            uint8_t size = 0;
            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(size))
            {
                d_socket.rollbackTransaction();
                return false;
            }
            d_socket.read(reinterpret_cast<char *>(&size), sizeof(size));

            if (d_socket.bytesAvailable() < static_cast<int64_t>(size))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();

            emit nav2IdentChanged(size == 0 ? "" : QString::fromUtf8(d_socket.read(size)));

            break;
        }
        case PfdIdentifier::NAV2_DME:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit nav2DmeChanged(newValue);
            break;
        }
        case PfdIdentifier::NAV2_BEARING:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit nav2BearingChanged(newValue);
            break;
        }
        case PfdIdentifier::NAV2_HAS_NAV:
        {
            bool newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit nav2HasNavChanged(newValue);
            break;
        }
        case PfdIdentifier::NAV2_HAS_SIGNAL:
        {
            bool newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit nav2HasSignalChanged(newValue);
            break;
        }
        case PfdIdentifier::NAV2_HAS_DME:
        {
            bool newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit nav2HasDmeChanged(newValue);
            break;
        }
        case PfdIdentifier::GPS_DISTANCE:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit gpsDistanceChanged(newValue);
            break;
        }
        case PfdIdentifier::GPS_BEARING:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit gpsBearingChanged(newValue);
            break;
        }
        case PfdIdentifier::ADF_HAS_SIGNAL:
        {
            bool newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit adfHasSignalChanged(newValue);
            break;
        }
        case PfdIdentifier::ADF_FREQ:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit adfFreqChanged(newValue);
            break;
        }
        case PfdIdentifier::ADF_RADIAL:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit adfRadialChanged(newValue);
            break;
        }

        // nav info
        case PfdIdentifier::GPS_IS_ACTIVE_FLIGHTPLAN:
        {
            bool newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit gpsIsActiveFlightplanChanged(newValue);
            break;
        }
        case PfdIdentifier::LEG_IS_DIRECT_TO:
        {
            bool newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit legIsDirectToChanged(newValue);
            break;
        }
        case PfdIdentifier::CURRENT_LEG_TO:
        {
            uint8_t size = 0;
            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(size))
            {
                d_socket.rollbackTransaction();
                return false;
            }
            d_socket.read(reinterpret_cast<char *>(&size), sizeof(size));

            if (d_socket.bytesAvailable() < static_cast<int64_t>(size))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();

            emit currentLegToChanged(size == 0 ? "" : QString::fromUtf8(d_socket.read(size)));

            break;
        }
        case PfdIdentifier::CURRENT_LEG_FROM:
        {
            uint8_t size = 0;
            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(size))
            {
                d_socket.rollbackTransaction();
                return false;
            }
            d_socket.read(reinterpret_cast<char *>(&size), sizeof(size));

            if (d_socket.bytesAvailable() < static_cast<int64_t>(size))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();

            emit currentLegFromChanged(size == 0 ? "" : QString::fromUtf8(d_socket.read(size)));

            break;
        }

        // wind
        case PfdIdentifier::WIND_DIRECTION:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit windDirectionChanged(newValue);
            break;
        }
        case PfdIdentifier::WIND_STRENGTH:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit windStrengthChanged(newValue);
            break;
        }
        case PfdIdentifier::WIND_TRUE_DIRECTION:
        {
            double newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit windTrueDirectionChanged(newValue);
            break;
        }

        // ap info
        case PfdIdentifier::AP_AVAILABLE:
        {
            bool newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit apAvailableChanged(newValue);
            break;
        }
        case PfdIdentifier::AP_LATERAL_ACTIVE:
        {
            uint8_t size = 0;
            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(size))
            {
                d_socket.rollbackTransaction();
                return false;
            }
            d_socket.read(reinterpret_cast<char *>(&size), sizeof(size));

            if (d_socket.bytesAvailable() < static_cast<int64_t>(size))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();

            emit apLateralActiveChanged(size == 0 ? "" : QString::fromUtf8(d_socket.read(size)));

            break;
        }
        case PfdIdentifier::AP_LATERAL_ARMED:
        {
            uint8_t size = 0;
            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(size))
            {
                d_socket.rollbackTransaction();
                return false;
            }
            d_socket.read(reinterpret_cast<char *>(&size), sizeof(size));

            if (d_socket.bytesAvailable() < static_cast<int64_t>(size))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();

            emit apLateralArmedChanged(size == 0 ? "" : QString::fromUtf8(d_socket.read(size)));

            break;
        }
        case PfdIdentifier::AP_STATUS:
        {
            bool newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit apStatusChanged(newValue);
            break;
        }
        case PfdIdentifier::AP_YD_STATUS:
        {
            bool newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit apYdStatusChanged(newValue);
            break;
        }
        case PfdIdentifier::AP_FD_STATUS:
        {
            bool newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit apFdStatusChanged(newValue);
            break;
        }
        case PfdIdentifier::AP_FLC:
        {
            bool newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit apFlcChanged(newValue);
            break;
        }
        case PfdIdentifier::AP_VERTICAL_ACTIVE:
        {
            uint8_t size = 0;
            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(size))
            {
                d_socket.rollbackTransaction();
                return false;
            }
            d_socket.read(reinterpret_cast<char *>(&size), sizeof(size));

            if (d_socket.bytesAvailable() < static_cast<int64_t>(size))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();

            emit apVerticalActiveChanged(size == 0 ? "" : QString::fromUtf8(d_socket.read(size)));

            break;
        }
        case PfdIdentifier::AP_MODE_REFERENCE:
        {
            uint8_t size = 0;
            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(size))
            {
                d_socket.rollbackTransaction();
                return false;
            }
            d_socket.read(reinterpret_cast<char *>(&size), sizeof(size));

            if (d_socket.bytesAvailable() < static_cast<int64_t>(size))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();

            emit apModeReferenceChanged(size == 0 ? "" : QString::fromUtf8(d_socket.read(size)));

            break;
        }
        case PfdIdentifier::AP_ARMED:
        {
            uint8_t size = 0;
            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(size))
            {
                d_socket.rollbackTransaction();
                return false;
            }
            d_socket.read(reinterpret_cast<char *>(&size), sizeof(size));

            if (d_socket.bytesAvailable() < static_cast<int64_t>(size))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();

            emit apArmedChanged(size == 0 ? "" : QString::fromUtf8(d_socket.read(size)));

            break;
        }
        case PfdIdentifier::AP_ARMED_REFERENCE:
        {
            uint8_t size = 0;
            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(size))
            {
                d_socket.rollbackTransaction();
                return false;
            }
            d_socket.read(reinterpret_cast<char *>(&size), sizeof(size));

            if (d_socket.bytesAvailable() < static_cast<int64_t>(size))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();

            emit apArmedReferenceChanged(size == 0 ? "" : QString::fromUtf8(d_socket.read(size)));

            break;
        }
    }

    return true;
}

}  // namespace io::network
