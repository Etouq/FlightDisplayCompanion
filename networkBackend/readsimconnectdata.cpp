#include <QGeoCoordinate>
#include <QImage>
#include <QString>

#include "networkclient.h"
#include "aircraftManager/aircraftfile.h"
#include "dataIdentifiers.h"
#include "mfdbackend.h"

void NetworkClient::readSimconnectData()
{
    bool reading = true;
    while (reading && !tcpSocket.atEnd())
    {
        tcpSocket.startTransaction();

        SimconnectIds identifier = SimconnectIds::AIRSPEED;
        tcpSocket.read(reinterpret_cast<char *>(&identifier), sizeof(identifier));

        switch (identifier)
        {
            // airspeed
            case SimconnectIds::AIRSPEED:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit airspeedChanged(newValue);
                break;
            }
            case SimconnectIds::MAX_SPEED:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit max_speedChanged(newValue);
                break;
            }
            case SimconnectIds::TRUE_AIRSPEED:
            {
                int32_t newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit true_airspeedChanged(newValue);
                break;
            }
            case SimconnectIds::REF_SPEED:
            {
                int32_t newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit ref_speedChanged(newValue);
                break;
            }
            case SimconnectIds::AP_FLC:
            {
                bool newValue = false;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit ap_flcChanged(newValue);
                break;
            }

            // altitude
            case SimconnectIds::ALTITUDE:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit altitudeChanged(newValue);
                break;
            }
            case SimconnectIds::RADAR_ALTITUDE:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit radar_altitudeChanged(newValue);
                break;
            }
            case SimconnectIds::REF_ALTITUDE:
            {
                int32_t newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit ref_altitudeChanged(newValue);
                break;
            }
            case SimconnectIds::PRESSURE:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit pressureChanged(newValue);
                break;
            }

            // vspeed
            case SimconnectIds::VSPEED:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit vspeedChanged(newValue);
                break;
            }
            case SimconnectIds::REF_VSPEED:
            {
                int32_t newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit ref_vspeedChanged(newValue);
                break;
            }

            // vert dev
            case SimconnectIds::VERT_DEV_MODE:
            {
                int32_t newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit vert_dev_modeChanged(newValue);
                break;
            }
            case SimconnectIds::VERT_DEV_VALUE:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit vert_dev_valueChanged(newValue);
                break;
            }

            // aoa
            case SimconnectIds::ANGLE_OF_ATTACK:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit angle_of_attackChanged(newValue);
                break;
            }

            // ap info
            case SimconnectIds::AP_LATERAL_ACTIVE:
            {
                uint8_t size = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(size))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&size), sizeof(size));
                QString newValue = "";
                if (size == 0)
                {
                    tcpSocket.commitTransaction();
                    emit ap_lateral_activeChanged(newValue);
                    break;
                }
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < size)
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                newValue = tcpSocket.read(size);
                tcpSocket.commitTransaction();
                emit ap_lateral_activeChanged(newValue);

                break;
            }
            case SimconnectIds::AP_LATERAL_ARMED:
            {
                uint8_t size = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(size))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&size), sizeof(size));
                QString newValue = "";
                if (size == 0)
                {
                    tcpSocket.commitTransaction();
                    emit ap_lateral_armedChanged(newValue);
                    break;
                }
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < size)
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                newValue = tcpSocket.read(size);
                emit ap_lateral_armedChanged(newValue);
                tcpSocket.commitTransaction();
                break;
            }
            case SimconnectIds::AP_AVAILABLE:
            {
                bool newValue = false;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit ap_availableChanged(newValue);
                break;
            }
            case SimconnectIds::AP_STATUS:
            {
                bool newValue = false;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit ap_statusChanged(newValue);
                break;
            }
            case SimconnectIds::AP_YD_STATUS:
            {
                bool newValue = false;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit ap_yd_statusChanged(newValue);
                break;
            }
            case SimconnectIds::AP_FD_STATUS:
            {
                bool newValue = false;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit ap_fd_statusChanged(newValue);
                break;
            }
            case SimconnectIds::AP_VERTICAL_ACTIVE:
            {
                uint8_t size = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(size))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&size), sizeof(size));
                QString newValue = "";
                if (size == 0)
                {
                    tcpSocket.commitTransaction();
                    emit ap_vertical_activeChanged(newValue);
                    break;
                }
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < size)
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                newValue = tcpSocket.read(size);
                emit ap_vertical_activeChanged(newValue);
                tcpSocket.commitTransaction();
                break;
            }
            case SimconnectIds::AP_MODE_REFERENCE:
            {
                uint8_t size = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(size))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&size), sizeof(size));
                QString newValue = "";
                if (size == 0)
                {
                    tcpSocket.commitTransaction();
                    emit ap_mode_referenceChanged(newValue);
                    break;
                }
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < size)
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                newValue = tcpSocket.read(size);
                emit ap_mode_referenceChanged(newValue);
                tcpSocket.commitTransaction();
                break;
            }
            case SimconnectIds::AP_ARMED:
            {
                uint8_t size = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(size))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&size), sizeof(size));
                QString newValue = "";
                if (size == 0)
                {
                    tcpSocket.commitTransaction();
                    emit ap_armedChanged(newValue);
                    break;
                }
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < size)
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                newValue = tcpSocket.read(size);
                emit ap_armedChanged(newValue);
                tcpSocket.commitTransaction();
                break;
            }
            case SimconnectIds::AP_ARMED_REFERENCE:
            {
                uint8_t size = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(size))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&size), sizeof(size));
                QString newValue = "";
                if (size == 0)
                {
                    tcpSocket.commitTransaction();
                    emit ap_armed_referenceChanged(newValue);
                    break;
                }
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < size)
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                newValue = tcpSocket.read(size);
                emit ap_armed_referenceChanged(newValue);
                tcpSocket.commitTransaction();
                break;
            }

            // attitude
            case SimconnectIds::BANK:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit bankChanged(newValue);
                break;
            }
            case SimconnectIds::PITCH:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit pitchChanged(newValue);
                break;
            }
            case SimconnectIds::SLIPSKID:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit slipskidChanged(newValue);
                break;
            }
            case SimconnectIds::FD_BANK:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit fd_bankChanged(newValue);
                break;
            }
            case SimconnectIds::FD_PITCH:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit fd_pitchChanged(newValue);
                break;
            }

            // bottombar
            case SimconnectIds::ZULU_SECONDS:
            {
                int32_t newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit zulu_secondsChanged(newValue);
                break;
            }
            case SimconnectIds::LOCAL_SECONDS:
            {
                int32_t newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit local_secondsChanged(newValue);
                break;
            }
            case SimconnectIds::GROUND_SPEED:
            {
                int32_t newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit ground_speedChanged(newValue);
                break;
            }
            case SimconnectIds::TOTAL_AIR_TEMP:
            {
                float newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit total_air_tempChanged(newValue);
                break;
            }

            // hsi
            case SimconnectIds::ROTATION:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit rotationChanged(newValue);
                break;
            }
            case SimconnectIds::HEADING:   // might be int
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit headingChanged(newValue);
                break;
            }
            case SimconnectIds::COURSE:   // might be int
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit courseChanged(newValue);
                break;
            }
            case SimconnectIds::COURSE_DEVIATION:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit course_deviationChanged(newValue);
                break;
            }
            case SimconnectIds::DISPLAY_DEVIATION:
            {
                bool newValue = false;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit display_deviationChanged(newValue);
                break;
            }
            case SimconnectIds::TURN_RATE:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit turn_rateChanged(newValue);
                break;
            }
            case SimconnectIds::NAV_SOURCE:
            {
                int32_t newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit nav_sourceChanged(newValue);
                break;
            }
            case SimconnectIds::CURRENT_TRACK:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit current_trackChanged(newValue);
                break;
            }
            case SimconnectIds::TO_FROM:
            {
                int32_t newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit to_fromChanged(newValue);
                break;
            }

            // hsi brg
            case SimconnectIds::NAV1_IDENT:
            {
                uint8_t size = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(size))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&size), sizeof(size));
                QString newValue = "";
                if (size == 0)
                {
                    tcpSocket.commitTransaction();
                    emit nav1_identChanged(newValue);
                    break;
                }
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < size)
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                newValue = tcpSocket.read(size);
                emit nav1_identChanged(newValue);
                tcpSocket.commitTransaction();
                break;
            }
            case SimconnectIds::NAV1_DME:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit nav1_dmeChanged(newValue);
                break;
            }
            case SimconnectIds::NAV1_BEARING:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit nav1_bearingChanged(newValue);
                break;
            }
            case SimconnectIds::NAV1_HAS_NAV:
            {
                bool newValue = false;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit nav1_has_navChanged(newValue);
                break;
            }
            case SimconnectIds::NAV1_HAS_SIGNAL:
            {
                bool newValue = false;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit nav1_has_signalChanged(newValue);
                break;
            }
            case SimconnectIds::NAV1_HAS_DME:
            {
                bool newValue = false;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit nav1_has_dmeChanged(newValue);
                break;
            }
            case SimconnectIds::NAV2_IDENT:
            {
                uint8_t size = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(size))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&size), sizeof(size));
                QString newValue = "";
                if (size == 0)
                {
                    tcpSocket.commitTransaction();
                    emit nav2_identChanged(newValue);
                    break;
                }
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < size)
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                newValue = tcpSocket.read(size);
                emit nav2_identChanged(newValue);
                tcpSocket.commitTransaction();
                break;
            }
            case SimconnectIds::NAV2_DME:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit nav2_dmeChanged(newValue);
                break;
            }
            case SimconnectIds::NAV2_BEARING:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit nav2_bearingChanged(newValue);
                break;
            }
            case SimconnectIds::NAV2_HAS_NAV:
            {
                bool newValue = false;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit nav2_has_navChanged(newValue);
                break;
            }
            case SimconnectIds::NAV2_HAS_SIGNAL:
            {
                bool newValue = false;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit nav2_has_signalChanged(newValue);
                break;
            }
            case SimconnectIds::NAV2_HAS_DME:
            {
                bool newValue = false;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit nav2_has_dmeChanged(newValue);
                break;
            }
            case SimconnectIds::GPS_DISTANCE:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit gps_distanceChanged(newValue);
                break;
            }
            case SimconnectIds::GPS_BEARING:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit gps_bearingChanged(newValue);
                break;
            }
            case SimconnectIds::ADF_HAS_SIGNAL:
            {
                bool newValue = false;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit adf_has_signalChanged(newValue);
                break;
            }
            case SimconnectIds::ADF_FREQ:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit adf_freqChanged(newValue);
                break;
            }
            case SimconnectIds::ADF_RADIAL:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit adf_radialChanged(newValue);
                break;
            }

            // nav info
            case SimconnectIds::GPS_IS_ACTIVE_FLIGHTPLAN:
            {
                bool newValue = false;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit gps_is_active_flightplanChanged(newValue);
                break;
            }
            case SimconnectIds::CURRENT_LEG_TO:
            {
                uint8_t size = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(size))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&size), sizeof(size));
                QString newValue = "";
                if (size == 0)
                {
                    tcpSocket.commitTransaction();
                    emit current_leg_toChanged(newValue);
                    break;
                }
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < size)
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                newValue = tcpSocket.read(size);
                emit current_leg_toChanged(newValue);
                tcpSocket.commitTransaction();
                break;
            }
            case SimconnectIds::CURRENT_LEG_FROM:
            {
                uint8_t size = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(size))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&size), sizeof(size));
                QString newValue = "";
                if (size == 0)
                {
                    tcpSocket.commitTransaction();
                    emit current_leg_fromChanged(newValue);
                    break;
                }
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < size)
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                newValue = tcpSocket.read(size);
                emit current_leg_fromChanged(newValue);
                tcpSocket.commitTransaction();
                break;
            }
            case SimconnectIds::LEG_IS_DIRECT_TO:
            {
                bool newValue = false;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit leg_is_direct_toChanged(newValue);
                break;
            }
            case SimconnectIds::CURRENT_LEG_DISTANCE:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit current_leg_distanceChanged(newValue);
                break;
            }
            case SimconnectIds::CURRENT_LEG_BEARING:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit current_leg_bearingChanged(newValue);
                break;
            }

            // radio info
            case SimconnectIds::HAS_COM1:
            {
                bool newValue = false;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit has_com1Changed(newValue);
                break;
            }
            case SimconnectIds::HAS_COM2:
            {
                bool newValue = false;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit has_com2Changed(newValue);
                break;
            }
            case SimconnectIds::HAS_NAV1:
            {
                bool newValue = false;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit has_nav1Changed(newValue);
                break;
            }
            case SimconnectIds::HAS_NAV2:
            {
                bool newValue = false;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit has_nav2Changed(newValue);
                break;
            }
            case SimconnectIds::COM1_FREQ:
            {
                float newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit com1_freqChanged(newValue);
                break;
            }
            case SimconnectIds::COM2_FREQ:
            {
                float newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit com2_freqChanged(newValue);
                break;
            }
            case SimconnectIds::NAV1_FREQ:
            {
                float newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit nav1_freqChanged(newValue);
                break;
            }
            case SimconnectIds::NAV2_FREQ:
            {
                float newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit nav2_freqChanged(newValue);
                break;
            }
            case SimconnectIds::COM1_STBY:
            {
                float newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit com1_stbyChanged(newValue);
                break;
            }
            case SimconnectIds::COM2_STBY:
            {
                float newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit com2_stbyChanged(newValue);
                break;
            }
            case SimconnectIds::NAV1_STBY:
            {
                float newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit nav1_stbyChanged(newValue);
                break;
            }
            case SimconnectIds::NAV2_STBY:
            {
                float newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit nav2_stbyChanged(newValue);
                break;
            }
            case SimconnectIds::XPDR_CODE:
            {
                int32_t newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit xpdr_codeChanged(newValue);
                break;
            }
            case SimconnectIds::XPDR_STATE:
            {
                int32_t newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit xpdr_stateChanged(newValue);
                break;
            }

            // wind
            case SimconnectIds::WIND_DIRECTION:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit wind_directionChanged(newValue);
                break;
            }
            case SimconnectIds::WIND_STRENGTH:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit wind_strengthChanged(newValue);
                break;
            }
            case SimconnectIds::WIND_TRUE_DIRECTION:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit wind_true_directionChanged(newValue);
                break;
            }

            // mfd
            case SimconnectIds::COORDINATES:
            {
                double newLat = 0;
                double newLon = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newLat) + sizeof(newLon))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newLat), sizeof(newLat));
                tcpSocket.read(reinterpret_cast<char *>(&newLon), sizeof(newLon));
                tcpSocket.commitTransaction();
                emit coordinates_Changed(QGeoCoordinate(newLat, newLon));
                break;
            }
            case SimconnectIds::TRUE_HEADING:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit true_headingChanged(newValue);
                break;
            }
            case SimconnectIds::GPS_WP_DTK:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit gps_wp_desired_trackChanged(newValue);
                break;
            }
            case SimconnectIds::GPS_WP_ETE:
            {
                int32_t newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit gps_wp_eteChanged(newValue);
                break;
            }
            case SimconnectIds::GPS_ETE:
            {
                int32_t newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit gps_eteChanged(newValue);
                break;
            }

            // flightplan
            case SimconnectIds::CLEAR_FLIGHTPLAN:
            {
                tcpSocket.commitTransaction();
                emit clear_flightplan_received();
                break;
            }
            case SimconnectIds::FLIGHTPLAN_LIST:
            {
                int64_t byteSize = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(byteSize))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&byteSize), sizeof(byteSize));
                if (tcpSocket.bytesAvailable() < byteSize)
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                QList<FlightPlanWaypoint> wpList = BinaryUtil::readFpList(tcpSocket);
                tcpSocket.commitTransaction();
                emit received_flightplan(wpList);
                break;
            }

            // simconnect server events
            case SimconnectIds::QUIT:
            {
                tcpSocket.commitTransaction();
                emit displayError("Sim closed");
                tcpSocket.disconnectFromHost();
                break;
            }
            case SimconnectIds::SIM_START_EVENT:
            {
                tcpSocket.commitTransaction();
                emit sim_start_received();
                break;
            }
            case SimconnectIds::SIM_STOP_EVENT:
            {
                tcpSocket.commitTransaction();
                emit sim_stop_received();
                break;
            }
            case SimconnectIds::SIM_CONNECTION_FAILED:
            {
                tcpSocket.commitTransaction();
                emit displayError("Failed to connect to sim");
                emit simConnectionFailed();
                break;
            }
            case SimconnectIds::ERROR_STRING:
            {
                uint8_t size = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(size))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&size), sizeof(size));
                QString newValue = "";
                if (size == 0)
                {
                    tcpSocket.commitTransaction();
                    break;
                }
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < size)
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                newValue = tcpSocket.read(size);
                tcpSocket.commitTransaction();
                emit displayError(newValue);
                break;
            }

            // engine data
            case SimconnectIds::ENGINE1_N1:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine1_n1Changed(newValue);
                break;
            }
            case SimconnectIds::ENGINE2_N1:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine2_n1Changed(newValue);
                break;
            }
            case SimconnectIds::ENGINE3_N1:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine3_n1Changed(newValue);
                break;
            }
            case SimconnectIds::ENGINE4_N1:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine4_n1Changed(newValue);
                break;
            }
            case SimconnectIds::ENGINE1_N2:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine1_n2Changed(newValue);
                break;
            }
            case SimconnectIds::ENGINE2_N2:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine2_n2Changed(newValue);
                break;
            }
            case SimconnectIds::ENGINE3_N2:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine3_n2Changed(newValue);
                break;
            }
            case SimconnectIds::ENGINE4_N2:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine4_n2Changed(newValue);
                break;
            }
            case SimconnectIds::ENGINE1_ITT:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine1_ittChanged(newValue);
                break;
            }
            case SimconnectIds::ENGINE2_ITT:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine2_ittChanged(newValue);
                break;
            }
            case SimconnectIds::ENGINE3_ITT:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine3_ittChanged(newValue);
                break;
            }
            case SimconnectIds::ENGINE4_ITT:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine4_ittChanged(newValue);
                break;
            }
            case SimconnectIds::ENGINE1_RPM:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine1_rpmChanged(newValue);
                break;
            }
            case SimconnectIds::ENGINE2_RPM:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine2_rpmChanged(newValue);
                break;
            }
            case SimconnectIds::ENGINE1_SECOND:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine1_secondChanged(newValue);
                break;
            }
            case SimconnectIds::ENGINE2_SECOND:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine2_secondChanged(newValue);
                break;
            }
            case SimconnectIds::ENGINE1_TRQ:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine1_trqChanged(newValue);
                break;
            }
            case SimconnectIds::ENGINE2_TRQ:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine2_trqChanged(newValue);
                break;
            }
            case SimconnectIds::ENGINE1_FUEL_QTY:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine1_fuel_qtyChanged(newValue);
                break;
            }
            case SimconnectIds::ENGINE2_FUEL_QTY:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine2_fuel_qtyChanged(newValue);
                break;
            }
            case SimconnectIds::ENGINE1_FUEL_FLOW:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine1_fuel_flowChanged(newValue);
                break;
            }
            case SimconnectIds::ENGINE2_FUEL_FLOW:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine2_fuel_flowChanged(newValue);
                break;
            }
            case SimconnectIds::ENGINE1_OIL_PRESS:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine1_oil_pressChanged(newValue);
                break;
            }
            case SimconnectIds::ENGINE2_OIL_PRESS:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine2_oil_pressChanged(newValue);
                break;
            }
            case SimconnectIds::ENGINE1_OIL_TEMP:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine1_oil_tempChanged(newValue);
                break;
            }
            case SimconnectIds::ENGINE2_OIL_TEMP:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine2_oil_tempChanged(newValue);
                break;
            }
            case SimconnectIds::ENGINE1_EGT:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine1_egtChanged(newValue);
                break;
            }
            case SimconnectIds::ENGINE2_EGT:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit engine2_egtChanged(newValue);
                break;
            }
            case SimconnectIds::APU_RPM_PCT:
            {
                int32_t newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit apu_rpmChanged(newValue);
                break;
            }
            case SimconnectIds::FUEL_TEXT_DATA:
            {
                // fueltextdata consists of 3 floats: qty, flow and gs so read those
                float fuelQty = 0;
                float fuelFlow = 0;
                float groundSpeed = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(fuelQty) + sizeof(fuelFlow) + sizeof(groundSpeed))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&fuelQty), sizeof(fuelQty));
                tcpSocket.read(reinterpret_cast<char *>(&fuelFlow), sizeof(fuelFlow));
                tcpSocket.read(reinterpret_cast<char *>(&groundSpeed), sizeof(groundSpeed));
                tcpSocket.commitTransaction();
                emit fuel_text_dataChanged(fuelFlow, fuelQty, groundSpeed);
                break;
            }
            case SimconnectIds::SPOILERS_PCT:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit spoilers_pctChanged(newValue);
                break;
            }
            case SimconnectIds::FLAPS_ANGLE:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit flaps_angleChanged(newValue);
                break;
            }
            case SimconnectIds::ELEV_TRIM_PCT:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit elev_trim_pctChanged(newValue);
                break;
            }
            case SimconnectIds::RUDD_TRIM_PCT:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit rudd_trim_pctChanged(newValue);
                break;
            }
            case SimconnectIds::AIL_TRIM_PCT:
            {
                double newValue = 0;
                if (static_cast<uint64_t>(tcpSocket.bytesAvailable()) < sizeof(newValue))
                {
                    tcpSocket.rollbackTransaction();
                    reading = false;
                    break;
                }
                tcpSocket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
                tcpSocket.commitTransaction();
                emit ail_trim_pctChanged(newValue);
                break;
            }
        }
    }
}
