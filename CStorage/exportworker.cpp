#include "exportworker.h"
#include "xlsxdocument.h"
#include <QTextStream>
#include "qfile.h"
#include "productdatabasemanager.h"


ExportWorker::ExportWorker(const QString &path,ExportFormat format):
    m_filePath{path},m_format{format}{}

void ExportWorker::run(){

    if(m_format == ExportFormat::CSV){
        exportToCSV();
    }else if(m_format == ExportFormat::XLSX){
        exportToXLSX();
    }

    emit exportFinished(QString("Export ended: %1").arg(m_filePath));
}
QString ExportWorker::escapeForCSV(const QString& str) {
    QString escaped = str;
    escaped.replace("\"", "\"\"");
    return "\"" + escaped + "\"";
}
void ExportWorker::exportToCSV() {
    QList<Product> products = ProductDatabaseManager::instance().getAllProducts();
    QFile file(m_filePath);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out.setEncoding(QStringConverter::Encoding::Utf8);
        out << "ID,Name,Price\n";

        for (const Product& p : products) {
            out << p.id << "," << escapeForCSV(p.name) << "," << QString::number(p.price, 'f', 2) << "\n";
        }

        if (out.status() != QTextStream::Ok) {
            emit exportFinished("Error occurred during writing to file.");
        } else {
            emit exportFinished("Export successful: " + m_filePath);
        }

        file.close();
    } else {
        emit exportFinished("Failed to open file for writing: " + m_filePath);
    }
}

void ExportWorker::exportToXLSX(){
    QList<Product> products = ProductDatabaseManager::instance().getAllProducts();
    QXlsx::Document xlsx;

    xlsx.write("A1", "ID");
    xlsx.write("B1", "Name");
    xlsx.write("C1", "Price");

    int row = 2;
    for (const Product& p : products) {
        xlsx.write(row, 1, p.id);
        xlsx.write(row, 2, p.name);
        xlsx.write(row, 3, p.price);
        row++;
    }

    xlsx.saveAs(m_filePath);
}
