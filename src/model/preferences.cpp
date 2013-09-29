#include "preferences.h"
#include <QDebug>
#include <QString>
#include <QDir>

Preferences::Preferences() :
    m_cSettings(QSettings::IniFormat, QSettings::UserScope, "GITL", "Gitl_HEVC_Analyzer_Preferences")
{
    if(!m_cSettings.contains("cache_path")) {
        QDir cCacheFolder(".");
        QString strCacheFolder = cCacheFolder.absoluteFilePath("cache");
        m_cSettings.setValue("cache_path", strCacheFolder);
        m_cSettings.sync();
    }

    if(!m_cSettings.contains("decoder_path")) {
        QDir cCacheFolder(".");
        QString strDecoderFolder = cCacheFolder.absoluteFilePath("decoders");
        m_cSettings.setValue("decoder_path", strDecoderFolder);
        m_cSettings.sync();
    }

    m_strCacheFolder   = m_cSettings.value("cache_path").toString();
    m_strDecoderFolder = m_cSettings.value("decoder_path").toString();


}


void Preferences::setCacheFolder(const QString& strCacheFolder)
{
    m_strCacheFolder = strCacheFolder;
    m_cSettings.setValue("cache_path", m_strCacheFolder);
    m_cSettings.sync();
}

void Preferences::setDecoderFolder(const QString& strDecoderFolder)
{
    m_strDecoderFolder = strDecoderFolder;
    m_cSettings.setValue("decoder_path", m_strDecoderFolder);
    m_cSettings.sync();
}
