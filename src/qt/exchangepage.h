#ifndef EXCHANGEPAGE_H
#define EXCHANGEPAGE_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QByteArray>
#include <QTimer>

namespace Ui {
    class ExchangePage;
}
class ClientModel;
class WalletModel;

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** Exchange page widget */
class ExchangePage : public QWidget
{
    Q_OBJECT

public:
    explicit ExchangePage(QWidget *parent = 0);
    ~ExchangePage();

    void setClientModel(ClientModel *clientModel);
    void setWalletModel(WalletModel *walletModel);

public slots:

signals:

private:
    Ui::ExchangePage *ui;
    ClientModel *clientModel;
    WalletModel *walletModel;

private slots:
    void LoadBittrexWebview();
    void LoadCryptsyWebview();
    void LoadBittrexWebviewBottom();
    void LoadCryptsyWebviewBottom();
};

#endif // EXCHANGEPAGE_H
