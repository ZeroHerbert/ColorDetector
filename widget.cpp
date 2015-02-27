#include "widget.h"
#include "ui_widget.h"
#include <QColorDialog>
#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui -> setupUi(this);
    // 关联信号与槽函数
    connect(ui -> openImage, SIGNAL(clicked()), this, SLOT(openImage()));
    connect(ui -> ImageProcess, SIGNAL(clicked()), this, SLOT(ImageProcess()));
    connect(ui -> colorButton, SIGNAL(clicked()), this, SLOT(colorSelect()));
    connect(ui -> verticalSlider, SIGNAL(valueChanged(int)), this, SLOT(changeDistance(int)));
    // 在未输入图像时，屏蔽图像处理的按钮
    ui -> ImageProcess -> setEnabled(false);
    ui -> colorButton -> setEnabled(false);
    ui -> verticalSlider -> setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::openImage()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                  tr("Open Image"), ".",
                tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));

    ColorDetector::getInstance()->setInputImage(fileName.toLatin1().data());
    cv::Mat input;
    input = ColorDetector::getInstance()->getInputImage();
    if (!input.data)
    {
        qDebug() << "No Input Image";
    }
    else
    {
        // 当检测到输入图像，可激活图像处理按键，并显示原图像
        ui->ImageProcess->setEnabled(true);
        ui->colorButton->setEnabled(true);
        ui->verticalSlider->setEnabled(true);
        cv::namedWindow("image");
        cv::imshow("image",ColorDetector::getInstance()->getInputImage());
    }
}

void Widget::ImageProcess()
{
    ColorDetector::getInstance()->process();
    cv::cvtColor(ColorDetector::getInstance()->getResult(),image,CV_GRAY2RGB);
    qimage = QImage((const unsigned char*)(image.data),image.cols,image.rows,QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(qimage).scaledToHeight(300));
    //ui->label->resize(ui->label->pixmap()->size());
}

void Widget::colorSelect()
{
    QColor color = QColorDialog::getColor(Qt::green,this);
    if(color.isValid())
    {
        ColorDetector::getInstance()->setTargetColor(
                    color.red(),color.green(),color.blue());
    }
}

void Widget::changeDistance(int value)
{
    ColorDetector::getInstance()->setColorDistanceThreshold(value);
}
