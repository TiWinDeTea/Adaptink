#include <QColorDialog>

#include <adaptink.hpp>
#include <ui_adaptink.h>

#include <QDebug>
Adaptink::Adaptink(QWidget *parent) :
	QMainWindow(parent),
	m_ui(new Ui::Adaptink)
{
	m_ui->setupUi(this);
}

Adaptink::~Adaptink() {
	delete m_ui;
}

void Adaptink::on_actionQuit_triggered() {
	QCoreApplication::quit();
}

void Adaptink::on_actionChangePen_triggered() {
	// TODO
}

void Adaptink::on_actionChangeColor_triggered() {
	QColor color = QColorDialog::getColor(Qt::white, nullptr, tr("Pick a color"), QColorDialog::ShowAlphaChannel);
	if (color != QColor::Invalid) {
		m_ui->canvas->setPenColor(color);
	}
}
