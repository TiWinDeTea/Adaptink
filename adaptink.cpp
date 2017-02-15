#include "adaptink.hpp"
#include "ui_adaptink.h"

Adaptink::Adaptink(QWidget *parent) : QMainWindow(parent), ui(new Ui::Adaptink) {
	ui->setupUi(this);
}

Adaptink::~Adaptink() {
	delete ui;
}

void Adaptink::on_actionChangePen_triggered() {
	// TODO
}

void Adaptink::on_actionQuit_triggered() {
	QCoreApplication::quit();
}
