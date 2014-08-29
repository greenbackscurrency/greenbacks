/*Copyright (C) 2009 Cleriot Simon
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2.1 of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA*/

#include "chatwindow.h"
#include "ui_chatwindow.h"

ChatWindow::ChatWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::ChatWindowClass)
{
    ui->setupUi(this);
    setFixedSize(1280,720);
    

	//connect(ui->buttonConnect, SIGNAL(clicked()), this, SLOT(connecte()));

	connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(close()));
	connect(ui->actionCloseTab, SIGNAL(triggered()), this, SLOT(closeTab()));

	





    //connect(ui->disconnect, SIGNAL(clicked()), this, SLOT(disconnectFromServer()));


}



void ChatWindow::tabChanged(int index)
{
	
		
}

void ChatWindow::tabClosing(int index)
{
	
}
/*void ChatWindow::tabRemoved(int index)
{
	
}*/

void ChatWindow::disconnectFromServer() {

    

   


   

}



void ChatWindow::closeTab()
{
	}

void ChatWindow::sendCommande()
{
	
}

void ChatWindow::tabJoined()
{
	joining=true;
}
void ChatWindow::tabJoining()
{
	joining=false;
}

void ChatWindow::connecte()
{

 
 

     






}

void ChatWindow::closeEvent(QCloseEvent *event)
{
	
}
void ChatWindow ::setModel(ClientModel *model)
{
    this->model = model;
}


ChatWindow::~ChatWindow()
{

}
