#include <QTextEdit>
#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>

class HistoryDialog : public QDialog {
    Q_OBJECT

public:
    HistoryDialog(const QList<QPair<QString, QString>>& history, QWidget *parent = nullptr)
        : QDialog(parent)
    {
        setWindowTitle("History");
        setFixedSize(600, 400);

        QVBoxLayout *layout = new QVBoxLayout(this);

        QTextEdit *historyTextEdit = new QTextEdit(this);
        historyTextEdit->setReadOnly(true);
        historyTextEdit->setTextInteractionFlags(Qt::TextBrowserInteraction);
        historyTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        // Формирование текста истории
        QString historyText;
        for (const auto& entry : history) {
            historyText += QString("[%1] %2\n").arg(entry.second).arg(entry.first);
        }

        historyTextEdit->setPlainText(historyText);

        layout->addWidget(historyTextEdit);

        QPushButton *closeButton = new QPushButton("Close", this);
        connect(closeButton, &QPushButton::clicked, this, &HistoryDialog::accept);
        layout->addWidget(closeButton);
    }
};
