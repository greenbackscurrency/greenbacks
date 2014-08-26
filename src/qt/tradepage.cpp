#include "tradepage.h"
#include "ui_tradepage.h"

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


#include "tradepage.moc"

TradePage::TradePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TradePage),
    walletModel(0),
    clientModel(0)
{
    ui->setupUi(this);        
    ui->webViewTrade->setHidden(true);
    ui->frameExchangesBottom->setHidden(true);         
    connect(ui->pushButtonTicket,SIGNAL(clicked()),this,SLOT(LoadTicketWebview()));
    connect(ui->pushButtonIRC,SIGNAL(clicked()),this,SLOT(LoadIRCWebview()));
}

TradePage::~TradePage()
{
    delete ui;
}

void TradePage::setClientModel(ClientModel *model)
{
    this->clientModel = model;
    if(model)
    {
    }
}

void TradePage::setWalletModel(WalletModel *model)
{
    this->walletModel = model;
}

void TradePage::LoadTicketWebview() {
  ui->webViewTrade->setHidden(false);
  ui->frameExchangesCenter->setHidden(true);
  ui->frameExchangesBottom->setHidden(false);
  QString url = "http://www.greenbackscurrency.com/site/submit-ticket/";            
  ui->webViewTrade->load(QNetworkRequest(url));
  connect(ui->pushButtonTicket_bottom,SIGNAL(clicked()),this,SLOT(LoadTicketWebviewBottom()));
  connect(ui->pushButtonIRC_bottom,SIGNAL(clicked()),this,SLOT(LoadIRCWebviewBottom()));
}

void TradePage::LoadIRCWebview() {
  ui->webViewTrade->setHidden(false);
  ui->frameExchangesCenter->setHidden(true);
  ui->frameExchangesBottom->setHidden(false);
  QString url = "http://webchat.freenode.net/?channels=greenbacks&uio=MT1mYWxzZSY5PXRydWUmMTE9ODI72";            
  ui->webViewTrade->load(QNetworkRequest(url));
  connect(ui->pushButtonTicket_bottom,SIGNAL(clicked()),this,SLOT(LoadTicketWebviewBottom()));
  connect(ui->pushButtonIRC_bottom,SIGNAL(clicked()),this,SLOT(LoadIRCWebviewBottom()));
}


void TradePage::LoadTicketWebviewBottom() {
  ui->webViewTrade->setHidden(false);
  ui->frameExchangesCenter->setHidden(true);
  ui->frameExchangesBottom->setHidden(false);
  QString url = "http://www.greenbackscurrency.com/site/submit-ticket/";            
  ui->webViewTrade->load(QNetworkRequest(url));
}

void TradePage::LoadIRCWebviewBottom() {
  ui->webViewTrade->setHidden(false);
  ui->frameExchangesCenter->setHidden(true);
  ui->frameExchangesBottom->setHidden(false);
  QString url = "http://webchat.freenode.net/?channels=greenbacks&uio=MT1mYWxzZSY5PXRydWUmMTE9ODI72";            
  ui->webViewTrade->load(QNetworkRequest(url));
}


