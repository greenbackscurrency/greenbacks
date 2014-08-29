#include "newspage.h"
#include "ui_newspage.h"

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


#include "newspage.moc"

NewsPage::NewsPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewsPage),
    walletModel(0),
    clientModel(0)
{
    ui->setupUi(this);
    nam = new QNetworkAccessManager(this);           
    ui->webViewNews->setHidden(true);
    connect(nam,SIGNAL(finished(QNetworkReply*)),this,SLOT(finished(QNetworkReply*)));          
    connect(ui->submitButton,SIGNAL(clicked()),this,SLOT(GetHttpContent()));
}

NewsPage::~NewsPage()
{
    delete ui;
}

void NewsPage::setClientModel(ClientModel *model)
{
    this->clientModel = model;
    if(model)
    {
    }
}

void NewsPage::setWalletModel(WalletModel *model)
{
    this->walletModel = model;
}

void NewsPage::finished(QNetworkReply *reply) {
  ui->webViewNews->setHidden(false);
  
}

void NewsPage::GetHttpContent() {
  ui->webViewNews->setHidden(false);
  ui->submitButton->setHidden(true);

  //QUrl url;
  //QNetworkRequest request;
  //url.setUrl("http://news.com/search?q=");
  //request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/x-www-form-urlencoded"));
  QString url = "http://news.greenbackscurrency.com/";            
  //QString data = ui->searchData->text();
  //QString final = url + data;
  //QByteArray postData;
  //postData.append(data.toLatin1());
 //nam->get(QNetworkRequest(QUrl(final)));
  //ui->webViewNews->load(QNetworkRequest(final), QNetworkAccessManager::PostOperation, postData);
  ui->webViewNews->load(QNetworkRequest(url));

}
