#include "exchangepage.h"
#include "ui_exchangepage.h"

#include "clientmodel.h"
#include "walletmodel.h"
#include "bitcoinunits.h"
#include "optionsmodel.h"
#include "transactiontablemodel.h"
#include "transactionfilterproxy.h"
#include "guiutil.h"
#include "guiconstants.h"

#include <QAbstractItemDelegate>
#include <QPainter>

#define DECORATION_SIZE 64


#include "exchangepage.moc"

ExchangePage::ExchangePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExchangePage),
    walletModel(0),
    clientModel(0)

{
    ui->setupUi(this);        
    ui->webViewExchange->setHidden(true);
    ui->frameExchangesBottom->setHidden(true);  
       
    connect(ui->pushButtonBittrex,SIGNAL(clicked()),this,SLOT(LoadBittrexWebview()));
    connect(ui->pushButtonCryptsy,SIGNAL(clicked()),this,SLOT(LoadCryptsyWebview()));
}

ExchangePage::~ExchangePage()
{
    delete ui;
}

void ExchangePage::setClientModel(ClientModel *model)
{
    this->clientModel = model;
    if(model)
    {
    }
}

void ExchangePage::setWalletModel(WalletModel *model)
{
    this->walletModel = model;
}

void ExchangePage::LoadBittrexWebview() {
  ui->webViewExchange->setHidden(false);
  ui->frameExchangesCenter->setHidden(true);
  ui->frameExchangesBottom->setHidden(false);
  QString url = "https://bittrex.com/Market/Index?MarketName=BTC-GB";            
  ui->webViewExchange->load(QNetworkRequest(url));
  connect(ui->pushButtonBittrex_bottom,SIGNAL(clicked()),this,SLOT(LoadBittrexWebviewBottom()));
  connect(ui->pushButtonCryptsy_bottom,SIGNAL(clicked()),this,SLOT(LoadCryptsyWebviewBottom()));
}

void ExchangePage::LoadCryptsyWebview() {
  ui->webViewExchange->setHidden(false);
  ui->frameExchangesCenter->setHidden(true);
  ui->frameExchangesBottom->setHidden(false);
  QString url = "https://www.cryptsy.com/markets/view/283";            
  ui->webViewExchange->load(QNetworkRequest(url));
  connect(ui->pushButtonBittrex_bottom,SIGNAL(clicked()),this,SLOT(LoadBittrexWebviewBottom()));
  connect(ui->pushButtonCryptsy_bottom,SIGNAL(clicked()),this,SLOT(LoadCryptsyWebviewBottom()));
}


void ExchangePage::LoadBittrexWebviewBottom() {
  ui->webViewExchange->setHidden(false);
  ui->frameExchangesCenter->setHidden(true);
  ui->frameExchangesBottom->setHidden(false);
  QString url = "https://bittrex.com/Market/Index?MarketName=BTC-GB";            
  ui->webViewExchange->load(QNetworkRequest(url));
}

void ExchangePage::LoadCryptsyWebviewBottom() {
  ui->webViewExchange->setHidden(false);
  ui->frameExchangesCenter->setHidden(true);
  ui->frameExchangesBottom->setHidden(false);
  QString url = "https://www.cryptsy.com/markets/view/283";            
  ui->webViewExchange->load(QNetworkRequest(url));
}


