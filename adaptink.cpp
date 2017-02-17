#include <QColorDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QSpinBox>
#include <QAction>

#include <adaptink.hpp>
#include <ui_adaptink.h>
#include <dcanvas.hpp>

Adaptink::Adaptink(QWidget *parent) :
	QMainWindow(parent),
	m_ui(new Ui::Adaptink),
	m_current_file_name()
{
	m_ui->setupUi(this);

	QSpinBox* tool_size_spin_box = new QSpinBox();
	tool_size_spin_box->setValue(5);
	m_ui->dcanvas->front->setToolSize(5);
	m_ui->toolBarContextual->insertWidget(new QAction, tool_size_spin_box);
	connect(tool_size_spin_box, SIGNAL(valueChanged(int)), m_ui->dcanvas->front, SLOT(setToolSize(int)));
}

Adaptink::~Adaptink() {
	delete m_ui;
}

void Adaptink::on_actionQuit_triggered() {
	QCoreApplication::quit();
}

void Adaptink::on_actionNew_triggered() {
	QApplication::instance()->exit(RESTART_EXIT_STATUS);
}

void Adaptink::on_actionOpen_triggered() {
	QString fileName = QFileDialog::getOpenFileName(this,
													tr("Open file"),
													QString(),
													tr("All files (*);;JPEG image (*.jpg *.jpeg *.jpe);;PNG image (*.png);;Windows BMP image (*.bmp)"));

	if (!fileName.isEmpty()) {
		QPixmap pixmap;
		if (!pixmap.load(fileName)) {
			QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
			return;
		}

		m_ui->dcanvas->front->setPixmap(pixmap);
		m_ui->dcanvas->front->repaint();

		m_current_file_name = fileName;
	}
}

void Adaptink::on_actionExport_triggered() {
	if (m_current_file_name.isEmpty()) {
		on_actionExportAs_triggered();
	} else {
		exportCanvas();
	}
}

void Adaptink::on_actionExportAs_triggered() {
	QString fileName = QFileDialog::getSaveFileName(this,
													tr("Save file as"),
													QString(),
													tr("All files (*);;JPEG image (*.jpg *.jpeg *.jpe);;PNG image (*.png);;Windows BMP image (*.bmp)"));

	if (!fileName.isEmpty()) {
		m_current_file_name = fileName;
		exportCanvas();
	}
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

// === private ===

void Adaptink::exportCanvas() {
	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(this, tr("Save with background?"), tr("Save with background?"), QMessageBox::Yes | QMessageBox::No);

	bool success;
	if (reply == QMessageBox::Yes) {
		success = m_ui->dcanvas->grab().save(m_current_file_name);
	} else {
		success = m_ui->dcanvas->front->grab().save(m_current_file_name);
	}

	if (!success) {
		QMessageBox::critical(this, tr("Error"), tr("Could not save file"));
	}
}
