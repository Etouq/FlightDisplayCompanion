#include "MfdPage.hpp"
#include "common/typeEnums.hpp"
#include "io/NetworkClient/NetworkClient.hpp"
#include "common/definitions/AircraftDefinition/AircraftDefinition.hpp"
#include "common/definitions/PropDefinition/PropDefinition.hpp"
#include "pages/MfdPage/GaugeElement/GaugeElement.hpp"


using io::network::NetworkClient;

namespace pages::mfd
{

void MfdPage::updateChangingGaugeConnections(const definitions::AircraftDefinition &definition)
{
    // first disconnect all signals
    disconnect(d_networkClient, nullptr, &d_gauge1, nullptr);
    disconnect(d_networkClient, nullptr, &d_gauge2, nullptr);
    disconnect(d_networkClient, nullptr, &d_gauge3, nullptr);
    disconnect(d_networkClient, nullptr, &d_gauge4, nullptr);

    switch (definition.type)
    {
        case AircraftType::JET:  // always N1, N2, ITT
        {
            connect(d_networkClient, &NetworkClient::engineN1Changed, &d_gauge1, &GaugeElement::update);
            connect(d_networkClient, &NetworkClient::engineN2Changed, &d_gauge2, &GaugeElement::update);
            connect(d_networkClient, &NetworkClient::engineIttChanged, &d_gauge3, &GaugeElement::update);
            break;
        }
        case AircraftType::PROP:  // changing RPM, Power, Manifold Pressure, Cht (no change in order though)
        {
            const definitions::PropDefinition &propDef = static_cast<const definitions::PropDefinition &>(definition);

            int precedingGaugeCount = 0;
            if (propDef.hasRpm)
            {
                connect(d_networkClient, &NetworkClient::engineRpmChanged, &d_gauge1, &GaugeElement::update);
                ++precedingGaugeCount;
            }
            if (propDef.hasPower)
            {
                if (precedingGaugeCount == 0)
                    connect(d_networkClient, &NetworkClient::enginePowerChanged, &d_gauge1, &GaugeElement::update);
                else
                    connect(d_networkClient, &NetworkClient::enginePowerChanged, &d_gauge2, &GaugeElement::update);

                ++precedingGaugeCount;
            }
            if (propDef.hasManPress || precedingGaugeCount == 0)
            {
                if (precedingGaugeCount == 0)
                    connect(d_networkClient, &NetworkClient::engineManPressChanged, &d_gauge1, &GaugeElement::update);
                else if (precedingGaugeCount == 1)
                    connect(d_networkClient, &NetworkClient::engineManPressChanged, &d_gauge2, &GaugeElement::update);
                else
                    connect(d_networkClient, &NetworkClient::engineManPressChanged, &d_gauge3, &GaugeElement::update);

                ++precedingGaugeCount;
            }
            if (propDef.hasCht || precedingGaugeCount == 1)
            {
                if (precedingGaugeCount == 1)
                    connect(d_networkClient, &NetworkClient::engineChtChanged, &d_gauge2, &GaugeElement::update);
                else if (precedingGaugeCount == 2)
                    connect(d_networkClient, &NetworkClient::engineChtChanged, &d_gauge3, &GaugeElement::update);
                else
                    connect(d_networkClient, &NetworkClient::engineChtChanged, &d_gauge4, &GaugeElement::update);
            }

            break;
        }
        case AircraftType::TURBOPROP:  // always N1, TRQ, ITT, RPM
        {
            connect(d_networkClient, &NetworkClient::engineN1Changed, &d_gauge1, &GaugeElement::update);
            connect(d_networkClient, &NetworkClient::engineTrqChanged, &d_gauge2, &GaugeElement::update);
            connect(d_networkClient, &NetworkClient::engineIttChanged, &d_gauge3, &GaugeElement::update);
            connect(d_networkClient, &NetworkClient::engineRpmChanged, &d_gauge4, &GaugeElement::update);
            break;
        }
        case AircraftType::INVALID:
            break;
    }
}

}  // namespace pages::mfd
