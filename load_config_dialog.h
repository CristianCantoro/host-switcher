#ifndef LOAD_CONFIG_DIALOG_H
#define LOAD_CONFIG_DIALOG_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QUrl>
#include "host_switcher.h"

namespace Ui {
    class LoadConfigDialog;
}

class HostSwitcher;

class LoadConfigDialog : public QDialog {
    Q_OBJECT
public:
    LoadConfigDialog(QWidget *parent = 0);
    ~LoadConfigDialog();

	void show_myself();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::LoadConfigDialog *ui;

	HostSwitcher *parent_;

	QUrl url_;
	QNetworkAccessManager qnam_;
	QNetworkReply *reply_;
	QString result_;

	bool lock;

public slots:
	void start_request();
	void http_finished();
	void http_ready_read();
	void cancel();
	void refreshClients();

	void on_searchButton_clicked();
	void on_clientsTableWidget_itemSelectionChanged();
};

#endif // LOAD_CONFIG_DIALOG_H
