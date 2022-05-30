#include "apinfobackend.h"


ApInfoBackend::ApInfoBackend(QObject *parent) : QObject(parent)
{
}

bool ApInfoBackend::has_ap() const
{
    return d_has_ap;
}
QString ApInfoBackend::ap_lateralActive() const
{
    return d_ap_lateralActive;
}
QString ApInfoBackend::ap_lateralArmed() const
{
    return d_ap_lateralArmed;
}
bool ApInfoBackend::ap_status() const
{
    return d_ap_status;
}
bool ApInfoBackend::ap_ydStatus() const
{
    return d_ap_ydStatus;
}
bool ApInfoBackend::ap_fdActive() const
{
    return d_ap_fdActive;
}
QString ApInfoBackend::ap_verticalActive() const
{
    return d_ap_verticalActive;
}
QString ApInfoBackend::ap_modeReference() const
{
    return d_ap_modeReference;
}
QString ApInfoBackend::ap_armed() const
{
    return d_ap_armed;
}
QString ApInfoBackend::ap_armedReference() const
{
    return d_ap_armedReference;
}


void ApInfoBackend::updateHas_ap(bool newValue)
{
    d_has_ap = newValue;
    emit has_apChanged();
}

void ApInfoBackend::updateAp_lateralActive(const QString &newValue)
{
    d_ap_lateralActive = newValue;
    emit ap_lateralActiveChanged();
}

void ApInfoBackend::updateAp_lateralArmed(QString const &newValue)
{
    d_ap_lateralArmed = newValue;
    emit ap_lateralArmedChanged();
}
void ApInfoBackend::updateAp_status(bool newValue)
{
    d_ap_status = newValue;
    emit ap_statusChanged();
}
void ApInfoBackend::updateAp_ydStatus(bool newValue)
{
    d_ap_ydStatus = newValue;
    emit ap_ydStatusChanged();
}
void ApInfoBackend::updateAp_fdActive(bool newValue)
{
    d_ap_fdActive = newValue;
    emit ap_fdActiveChanged();
}
void ApInfoBackend::updateAp_verticalActive(QString const &newValue)
{
    d_ap_verticalActive = newValue;
    emit ap_verticalActiveChanged();
}
void ApInfoBackend::updateAp_modeReference(QString const &newValue)
{
    d_ap_modeReference = newValue;
    emit ap_modeReferenceChanged();
}
void ApInfoBackend::updateAp_armed(QString const &newValue)
{
    d_ap_armed = newValue;
    emit ap_armedChanged();
}
void ApInfoBackend::updateAp_armedReference(QString const &newValue)
{
    d_ap_armedReference = newValue;
    emit ap_armedReferenceChanged();
}
