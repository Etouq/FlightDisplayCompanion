#ifndef __AIRCRAFT_LOADER_HPP__
#define __AIRCRAFT_LOADER_HPP__

#include <QObject>

namespace pages
{
namespace mfd
{
class MfdPage;
}

namespace pfd
{
class PfdPage;
}

namespace tsc
{
class TscPage;
}
}  // namespace pages

namespace definitions
{
struct AircraftDefinition;
}

class AircraftLoader : public QObject
{
    Q_OBJECT

public:

    AircraftLoader(pages::mfd::MfdPage &mfdPage,
                   pages::pfd::PfdPage &pfdPage,
                   pages::tsc::TscPage &tscPage,
                   QObject *parent = nullptr);

signals:

    void aircraftLoaded();

public slots:

    void loadAircraft(const definitions::AircraftDefinition &aircraft);

private:

    pages::mfd::MfdPage &d_mfdPage;
    pages::pfd::PfdPage &d_pfdPage;
    pages::tsc::TscPage &d_tscPage;
};

#endif  // __AIRCRAFT_LOADER_HPP__