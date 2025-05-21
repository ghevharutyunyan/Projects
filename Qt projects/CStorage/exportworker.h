#ifndef EXPORTWORKER_H
#define EXPORTWORKER_H
#include "qthread.h"
#include <QList>

enum class ExportFormat{
    CSV,
    XLSX
};

class ExportWorker:public QThread
{
    Q_OBJECT
public:
    ExportWorker(const QString& path,ExportFormat format);
protected:
    void run()override;

signals:
    void exportFinished(const QString& message);

private:
    QString escapeForCSV(const QString& str);
    void exportToCSV();
    void exportToXLSX();
private:
    QString m_filePath;
    ExportFormat m_format;
};

#endif // EXPORTWORKER_H
