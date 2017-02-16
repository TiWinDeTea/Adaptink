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

void Adaptink::on_actionChangeColor_triggered() {
	QColor color = QColorDialog::getColor(Qt::white, nullptr, tr("Pick a color"), QColorDialog::ShowAlphaChannel);
	if (color != QColor::Invalid) {
		m_ui->dcanvas->front->setPaintColor(color);
	}
}

void Adaptink::on_actionToolPencil_triggered() {
	m_ui->dcanvas->front->setTool(Pencil);
}

void Adaptink::on_actionToolBrush_triggered() {
	m_ui->dcanvas->front->setTool(Paintbrush);
}

void Adaptink::on_actionToolLabel_triggered() {
	m_ui->dcanvas->front->setTool(Label);
}


void Adaptink::on_actionRubber_triggered() {
	m_ui->dcanvas->front->setTool(Rubber);
}

void Adaptink::on_actionSet_Background_color_triggered() {
	QColor color = QColorDialog::getColor(Qt::white, nullptr, tr("Pick a color"), QColorDialog::ShowAlphaChannel);
	if (color != QColor::Invalid) {
		m_ui->dcanvas->background->setPalette(QPalette(color));
	}
}
