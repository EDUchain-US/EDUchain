#include "addeditEDCnode.h"
#include "ui_addeditEDCnode.h"

#include "walletdb.h"
#include "wallet.h"
#include "ui_interface.h"
#include "util.h"
#include "key.h"
#include "script/script.h"
#include "init.h"
#include "base58.h"
#include <QMessageBox>

AddEditEdcNode::AddEditEdcNode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditEdcNode)
{
    ui->setupUi(this);

}

AddEditEdcNode::~AddEditEdcNode()
{
    delete ui;
}


void AddEditEdcNode::on_okButton_clicked()
{
    if(ui->aliasLineEdit->text() == "")
    {
	QMessageBox msg;
        msg.setText("Please enter an alias.");
	msg.exec();
	return;
    }
    else if(ui->addressLineEdit->text() == "")
    {
	QMessageBox msg;
        msg.setText("Please enter an address.");
	msg.exec();
	return;
    }
    else
    {
	CEdcNodeConfig c;
        c.sAlias = ui->aliasLineEdit->text().toStdString();
	c.sAddress = ui->addressLineEdit->text().toStdString();
        CKey secret;
        secret.MakeNewKey(false);
        c.sMasternodePrivKey = CBitcoinSecret(secret).ToString();
	
        CWalletDB walletdb(pwalletMain->strWalletFile);
        CAccount account;
        walletdb.ReadAccount(c.sAlias, account);
        bool bKeyUsed = false;
	bool bForceNew = false;

        // Check if the current key has been used
        if (account.vchPubKey.IsValid())
        {
            CScript scriptPubKey = GetScriptForDestination(account.vchPubKey.GetID());
            for (map<uint256, CWalletTx>::iterator it = pwalletMain->mapWallet.begin();
                 it != pwalletMain->mapWallet.end() && account.vchPubKey.IsValid();
                 ++it)
            {
                const CWalletTx& wtx = (*it).second;
                BOOST_FOREACH(const CTxOut& txout, wtx.vout)
                    if (txout.scriptPubKey == scriptPubKey)
                        bKeyUsed = true;
            }
        }

        // Generate a new key
        if (!account.vchPubKey.IsValid() || bForceNew || bKeyUsed)
        {
            if (!pwalletMain->GetKeyFromPool(account.vchPubKey))
            {
		QMessageBox msg;
                msg.setText("Keypool ran out, please call keypoolrefill first.");
		msg.exec();
		return;
	    }
            pwalletMain->SetAddressBook(account.vchPubKey.GetID(), c.sAlias, "");
            walletdb.WriteAccount(c.sAlias, account);
        }

        c.sCollateralAddress = EncodeDestination(account.vchPubKey.GetID());

        pwalletMain->mapMyEdcNodes.insert(make_pair(c.sAddress, c));
	walletdb.WriteEdcNodeConfig(c.sAddress, c);
        uiInterface.NotifyEdcNodeChanged(c);

        accept();
    }
}

void AddEditEdcNode::on_cancelButton_clicked()
{
    reject();
}

