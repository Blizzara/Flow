/********************************************************************************
** Form generated from reading UI file 'FlowUI.ui'
**
** Created: Tue May 29 11:47:52 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FLOWUI_H
#define FLOWUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "FlowGLWin.h"

QT_BEGIN_NAMESPACE

class Ui_FlowWin
{
public:
    QAction *action_Exit;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *Settings;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *layout_diff;
    QLabel *label_diff;
    QLabel *label_value_diff;
    QSlider *slider_diff;
    QHBoxLayout *layout_visc;
    QLabel *label_visc;
    QLabel *label_value_visc;
    QSlider *slider_visc;
    QHBoxLayout *layout_interval;
    QLabel *label_interval;
    QLabel *label_value_inter;
    QSlider *slider_interval;
    QHBoxLayout *layout_timestep;
    QLabel *label_timestep;
    QLabel *label_value_dt;
    QSlider *slider_timestep;
    QHBoxLayout *layout_k;
    QLabel *label_k;
    QLabel *label_value_k;
    QSlider *slider_k;
    QHBoxLayout *layout_op6;
    QLabel *label_6;
    QLabel *label_8;
    QSlider *slider_6;
    QHBoxLayout *layout_op7;
    QLabel *label_7;
    QLabel *label_9;
    QSlider *slider_7;
    QPushButton *button_step;
    QPushButton *button_reset;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGroupBox *select_insert;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *source;
    QRadioButton *force_u;
    QRadioButton *force_v;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_red;
    QComboBox *combo_red;
    QLabel *label_green;
    QComboBox *combo_green;
    QLabel *label_blue;
    QComboBox *combo_blue;
    QGroupBox *groupbox_time;
    QVBoxLayout *verticalLayout_3;
    QLabel *labe_time_val;
    QPushButton *button_start;
    QPushButton *button_pause;
    QGroupBox *groupbox_pixelinfo;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    FlowGLWin *GL_window;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FlowWin)
    {
        if (FlowWin->objectName().isEmpty())
            FlowWin->setObjectName(QString::fromUtf8("FlowWin"));
        FlowWin->resize(941, 613);
        action_Exit = new QAction(FlowWin);
        action_Exit->setObjectName(QString::fromUtf8("action_Exit"));
        centralwidget = new QWidget(FlowWin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        Settings = new QGroupBox(centralwidget);
        Settings->setObjectName(QString::fromUtf8("Settings"));
        verticalLayout_2 = new QVBoxLayout(Settings);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        layout_diff = new QHBoxLayout();
        layout_diff->setObjectName(QString::fromUtf8("layout_diff"));
        label_diff = new QLabel(Settings);
        label_diff->setObjectName(QString::fromUtf8("label_diff"));

        layout_diff->addWidget(label_diff);

        label_value_diff = new QLabel(Settings);
        label_value_diff->setObjectName(QString::fromUtf8("label_value_diff"));

        layout_diff->addWidget(label_value_diff);


        verticalLayout_2->addLayout(layout_diff);

        slider_diff = new QSlider(Settings);
        slider_diff->setObjectName(QString::fromUtf8("slider_diff"));
        slider_diff->setMinimum(1);
        slider_diff->setMaximum(60);
        slider_diff->setValue(20);
        slider_diff->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(slider_diff);

        layout_visc = new QHBoxLayout();
        layout_visc->setObjectName(QString::fromUtf8("layout_visc"));
        label_visc = new QLabel(Settings);
        label_visc->setObjectName(QString::fromUtf8("label_visc"));

        layout_visc->addWidget(label_visc);

        label_value_visc = new QLabel(Settings);
        label_value_visc->setObjectName(QString::fromUtf8("label_value_visc"));

        layout_visc->addWidget(label_value_visc);


        verticalLayout_2->addLayout(layout_visc);

        slider_visc = new QSlider(Settings);
        slider_visc->setObjectName(QString::fromUtf8("slider_visc"));
        slider_visc->setMinimum(1);
        slider_visc->setMaximum(50);
        slider_visc->setValue(10);
        slider_visc->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(slider_visc);

        layout_interval = new QHBoxLayout();
        layout_interval->setObjectName(QString::fromUtf8("layout_interval"));
        label_interval = new QLabel(Settings);
        label_interval->setObjectName(QString::fromUtf8("label_interval"));

        layout_interval->addWidget(label_interval);

        label_value_inter = new QLabel(Settings);
        label_value_inter->setObjectName(QString::fromUtf8("label_value_inter"));

        layout_interval->addWidget(label_value_inter);


        verticalLayout_2->addLayout(layout_interval);

        slider_interval = new QSlider(Settings);
        slider_interval->setObjectName(QString::fromUtf8("slider_interval"));
        slider_interval->setMinimum(1);
        slider_interval->setMaximum(1000);
        slider_interval->setSingleStep(10);
        slider_interval->setValue(500);
        slider_interval->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(slider_interval);

        layout_timestep = new QHBoxLayout();
        layout_timestep->setObjectName(QString::fromUtf8("layout_timestep"));
        label_timestep = new QLabel(Settings);
        label_timestep->setObjectName(QString::fromUtf8("label_timestep"));

        layout_timestep->addWidget(label_timestep);

        label_value_dt = new QLabel(Settings);
        label_value_dt->setObjectName(QString::fromUtf8("label_value_dt"));

        layout_timestep->addWidget(label_value_dt);


        verticalLayout_2->addLayout(layout_timestep);

        slider_timestep = new QSlider(Settings);
        slider_timestep->setObjectName(QString::fromUtf8("slider_timestep"));
        slider_timestep->setMinimum(1);
        slider_timestep->setValue(10);
        slider_timestep->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(slider_timestep);

        layout_k = new QHBoxLayout();
        layout_k->setObjectName(QString::fromUtf8("layout_k"));
        label_k = new QLabel(Settings);
        label_k->setObjectName(QString::fromUtf8("label_k"));

        layout_k->addWidget(label_k);

        label_value_k = new QLabel(Settings);
        label_value_k->setObjectName(QString::fromUtf8("label_value_k"));
        label_value_k->setLayoutDirection(Qt::LeftToRight);
        label_value_k->setScaledContents(false);
        label_value_k->setWordWrap(false);

        layout_k->addWidget(label_value_k);


        verticalLayout_2->addLayout(layout_k);

        slider_k = new QSlider(Settings);
        slider_k->setObjectName(QString::fromUtf8("slider_k"));
        slider_k->setMinimum(1);
        slider_k->setMaximum(40);
        slider_k->setValue(20);
        slider_k->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(slider_k);

        layout_op6 = new QHBoxLayout();
        layout_op6->setObjectName(QString::fromUtf8("layout_op6"));
        label_6 = new QLabel(Settings);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        layout_op6->addWidget(label_6);

        label_8 = new QLabel(Settings);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        layout_op6->addWidget(label_8);


        verticalLayout_2->addLayout(layout_op6);

        slider_6 = new QSlider(Settings);
        slider_6->setObjectName(QString::fromUtf8("slider_6"));
        slider_6->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(slider_6);

        layout_op7 = new QHBoxLayout();
        layout_op7->setObjectName(QString::fromUtf8("layout_op7"));
        label_7 = new QLabel(Settings);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        layout_op7->addWidget(label_7);

        label_9 = new QLabel(Settings);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        layout_op7->addWidget(label_9);


        verticalLayout_2->addLayout(layout_op7);

        slider_7 = new QSlider(Settings);
        slider_7->setObjectName(QString::fromUtf8("slider_7"));
        slider_7->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(slider_7);

        button_step = new QPushButton(Settings);
        button_step->setObjectName(QString::fromUtf8("button_step"));

        verticalLayout_2->addWidget(button_step);

        button_reset = new QPushButton(Settings);
        button_reset->setObjectName(QString::fromUtf8("button_reset"));

        verticalLayout_2->addWidget(button_reset);


        horizontalLayout_3->addWidget(Settings);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        select_insert = new QGroupBox(centralwidget);
        select_insert->setObjectName(QString::fromUtf8("select_insert"));
        horizontalLayout_2 = new QHBoxLayout(select_insert);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        source = new QRadioButton(select_insert);
        source->setObjectName(QString::fromUtf8("source"));
        source->setChecked(true);

        horizontalLayout_2->addWidget(source);

        force_u = new QRadioButton(select_insert);
        force_u->setObjectName(QString::fromUtf8("force_u"));

        horizontalLayout_2->addWidget(force_u);

        force_v = new QRadioButton(select_insert);
        force_v->setObjectName(QString::fromUtf8("force_v"));

        horizontalLayout_2->addWidget(force_v);


        verticalLayout->addWidget(select_insert);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_16 = new QHBoxLayout(groupBox);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_red = new QLabel(groupBox);
        label_red->setObjectName(QString::fromUtf8("label_red"));

        horizontalLayout_16->addWidget(label_red);

        combo_red = new QComboBox(groupBox);
        combo_red->setObjectName(QString::fromUtf8("combo_red"));

        horizontalLayout_16->addWidget(combo_red);

        label_green = new QLabel(groupBox);
        label_green->setObjectName(QString::fromUtf8("label_green"));

        horizontalLayout_16->addWidget(label_green);

        combo_green = new QComboBox(groupBox);
        combo_green->setObjectName(QString::fromUtf8("combo_green"));

        horizontalLayout_16->addWidget(combo_green);

        label_blue = new QLabel(groupBox);
        label_blue->setObjectName(QString::fromUtf8("label_blue"));

        horizontalLayout_16->addWidget(label_blue);

        combo_blue = new QComboBox(groupBox);
        combo_blue->setObjectName(QString::fromUtf8("combo_blue"));

        horizontalLayout_16->addWidget(combo_blue);


        verticalLayout->addWidget(groupBox);


        horizontalLayout->addLayout(verticalLayout);

        groupbox_time = new QGroupBox(centralwidget);
        groupbox_time->setObjectName(QString::fromUtf8("groupbox_time"));
        verticalLayout_3 = new QVBoxLayout(groupbox_time);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        labe_time_val = new QLabel(groupbox_time);
        labe_time_val->setObjectName(QString::fromUtf8("labe_time_val"));

        verticalLayout_3->addWidget(labe_time_val);

        button_start = new QPushButton(groupbox_time);
        button_start->setObjectName(QString::fromUtf8("button_start"));

        verticalLayout_3->addWidget(button_start);

        button_pause = new QPushButton(groupbox_time);
        button_pause->setObjectName(QString::fromUtf8("button_pause"));

        verticalLayout_3->addWidget(button_pause);


        horizontalLayout->addWidget(groupbox_time);

        groupbox_pixelinfo = new QGroupBox(centralwidget);
        groupbox_pixelinfo->setObjectName(QString::fromUtf8("groupbox_pixelinfo"));
        formLayout = new QFormLayout(groupbox_pixelinfo);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupbox_pixelinfo);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(groupbox_pixelinfo);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label_2);

        label_3 = new QLabel(groupbox_pixelinfo);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(groupbox_pixelinfo);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(1, QFormLayout::FieldRole, label_4);

        label_5 = new QLabel(groupbox_pixelinfo);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        label_14 = new QLabel(groupbox_pixelinfo);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout->setWidget(2, QFormLayout::FieldRole, label_14);

        label_15 = new QLabel(groupbox_pixelinfo);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_15);

        label_16 = new QLabel(groupbox_pixelinfo);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        formLayout->setWidget(3, QFormLayout::FieldRole, label_16);


        horizontalLayout->addWidget(groupbox_pixelinfo);


        verticalLayout_4->addLayout(horizontalLayout);

        GL_window = new FlowGLWin(centralwidget);
        GL_window->setObjectName(QString::fromUtf8("GL_window"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GL_window->sizePolicy().hasHeightForWidth());
        GL_window->setSizePolicy(sizePolicy);
        GL_window->setMinimumSize(QSize(800, 400));
        GL_window->setMaximumSize(QSize(800, 400));

        verticalLayout_4->addWidget(GL_window);


        horizontalLayout_3->addLayout(verticalLayout_4);

        FlowWin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FlowWin);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 941, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        FlowWin->setMenuBar(menubar);
        statusbar = new QStatusBar(FlowWin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FlowWin->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(action_Exit);

        retranslateUi(FlowWin);
        QObject::connect(slider_diff, SIGNAL(valueChanged(int)), GL_window, SLOT(changeDiffusion(int)));
        QObject::connect(slider_visc, SIGNAL(valueChanged(int)), GL_window, SLOT(changeViscosity(int)));
        QObject::connect(action_Exit, SIGNAL(triggered()), FlowWin, SLOT(close()));
        QObject::connect(button_step, SIGNAL(clicked()), GL_window, SLOT(step()));
        QObject::connect(source, SIGNAL(clicked()), GL_window, SLOT(selectInsertMode_source()));
        QObject::connect(force_u, SIGNAL(clicked()), GL_window, SLOT(selectInsertMode_force_u()));
        QObject::connect(force_v, SIGNAL(clicked()), GL_window, SLOT(selectInsertMode_force_v()));
        QObject::connect(slider_timestep, SIGNAL(valueChanged(int)), GL_window, SLOT(changeTimestep(int)));
        QObject::connect(slider_interval, SIGNAL(valueChanged(int)), GL_window, SLOT(changeUpdateInterval(int)));
        QObject::connect(slider_diff, SIGNAL(valueChanged(int)), label_value_diff, SLOT(setNum(int)));
        QObject::connect(slider_visc, SIGNAL(valueChanged(int)), label_value_visc, SLOT(setNum(int)));
        QObject::connect(slider_k, SIGNAL(valueChanged(int)), label_value_k, SLOT(setNum(int)));
        QObject::connect(slider_6, SIGNAL(valueChanged(int)), label_8, SLOT(setNum(int)));
        QObject::connect(slider_7, SIGNAL(valueChanged(int)), label_9, SLOT(setNum(int)));
        QObject::connect(slider_k, SIGNAL(valueChanged(int)), GL_window, SLOT(changeK(int)));
        QObject::connect(combo_red, SIGNAL(currentIndexChanged(int)), GL_window, SLOT(selectRed(int)));
        QObject::connect(combo_blue, SIGNAL(currentIndexChanged(int)), GL_window, SLOT(selectBlue(int)));
        QObject::connect(combo_green, SIGNAL(currentIndexChanged(int)), GL_window, SLOT(selectGreen(int)));
        QObject::connect(button_start, SIGNAL(clicked()), GL_window, SLOT(startSim()));
        QObject::connect(button_pause, SIGNAL(clicked()), GL_window, SLOT(pauseSim()));
        QObject::connect(button_reset, SIGNAL(clicked()), GL_window, SLOT(resetSim()));
        QObject::connect(slider_interval, SIGNAL(valueChanged(int)), label_value_inter, SLOT(setNum(int)));
        QObject::connect(slider_timestep, SIGNAL(valueChanged(int)), label_value_dt, SLOT(setNum(int)));
        QObject::connect(slider_7, SIGNAL(valueChanged(int)), label_9, SLOT(setNum(int)));

        combo_green->setCurrentIndex(0);
        combo_blue->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FlowWin);
    } // setupUi

    void retranslateUi(QMainWindow *FlowWin)
    {
        FlowWin->setWindowTitle(QApplication::translate("FlowWin", "MainWindow", 0, QApplication::UnicodeUTF8));
        action_Exit->setText(QApplication::translate("FlowWin", "&Exit", 0, QApplication::UnicodeUTF8));
        Settings->setTitle(QApplication::translate("FlowWin", "Settings", 0, QApplication::UnicodeUTF8));
        label_diff->setText(QApplication::translate("FlowWin", "Diffusion", 0, QApplication::UnicodeUTF8));
        label_value_diff->setText(QApplication::translate("FlowWin", "20", 0, QApplication::UnicodeUTF8));
        label_visc->setText(QApplication::translate("FlowWin", "Viscosity", 0, QApplication::UnicodeUTF8));
        label_value_visc->setText(QApplication::translate("FlowWin", "10", 0, QApplication::UnicodeUTF8));
        label_interval->setText(QApplication::translate("FlowWin", "Interval", 0, QApplication::UnicodeUTF8));
        label_value_inter->setText(QApplication::translate("FlowWin", "1000", 0, QApplication::UnicodeUTF8));
        label_timestep->setText(QApplication::translate("FlowWin", "Timestep", 0, QApplication::UnicodeUTF8));
        label_value_dt->setText(QApplication::translate("FlowWin", "10", 0, QApplication::UnicodeUTF8));
        label_k->setText(QApplication::translate("FlowWin", "K", 0, QApplication::UnicodeUTF8));
        label_value_k->setText(QApplication::translate("FlowWin", "20", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("FlowWin", "Option6", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("FlowWin", "TL", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("FlowWin", "Option7", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("FlowWin", "TL", 0, QApplication::UnicodeUTF8));
        button_step->setText(QApplication::translate("FlowWin", "Step", 0, QApplication::UnicodeUTF8));
        button_reset->setText(QApplication::translate("FlowWin", "Reset", 0, QApplication::UnicodeUTF8));
        select_insert->setTitle(QApplication::translate("FlowWin", "Insert mode", 0, QApplication::UnicodeUTF8));
        source->setText(QApplication::translate("FlowWin", "Source", 0, QApplication::UnicodeUTF8));
        force_u->setText(QApplication::translate("FlowWin", "u-force", 0, QApplication::UnicodeUTF8));
        force_v->setText(QApplication::translate("FlowWin", "v-force", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("FlowWin", "Components to view", 0, QApplication::UnicodeUTF8));
        label_red->setText(QApplication::translate("FlowWin", "Red", 0, QApplication::UnicodeUTF8));
        combo_red->clear();
        combo_red->insertItems(0, QStringList()
         << QApplication::translate("FlowWin", "Density", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FlowWin", "Source", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FlowWin", "U-force", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FlowWin", "V-force", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FlowWin", "Sum force", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FlowWin", "U-velocity", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FlowWin", "V-velocity", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FlowWin", "Sum velocity", 0, QApplication::UnicodeUTF8)
        );
        label_green->setText(QApplication::translate("FlowWin", "Green", 0, QApplication::UnicodeUTF8));
        combo_green->clear();
        combo_green->insertItems(0, QStringList()
         << QApplication::translate("FlowWin", "Density", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FlowWin", "Source", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FlowWin", "U-force", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FlowWin", "V-force", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FlowWin", "Sum force", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FlowWin", "U-velocity", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FlowWin", "V-velocity", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FlowWin", "Sum velocity", 0, QApplication::UnicodeUTF8)
        );
        label_blue->setText(QApplication::translate("FlowWin", "Blue", 0, QApplication::UnicodeUTF8));
        combo_blue->clear();
        combo_blue->insertItems(0, QStringList()
         << QApplication::translate("FlowWin", "Density", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FlowWin", "Source", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FlowWin", "U-force", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FlowWin", "V-force", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FlowWin", "Sum force", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FlowWin", "U-velocity", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FlowWin", "V-velocity", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FlowWin", "Sum velocity", 0, QApplication::UnicodeUTF8)
        );
        groupbox_time->setTitle(QApplication::translate("FlowWin", "Time", 0, QApplication::UnicodeUTF8));
        labe_time_val->setText(QApplication::translate("FlowWin", "0", 0, QApplication::UnicodeUTF8));
        button_start->setText(QApplication::translate("FlowWin", "Start", 0, QApplication::UnicodeUTF8));
        button_pause->setText(QApplication::translate("FlowWin", "Pause", 0, QApplication::UnicodeUTF8));
        groupbox_pixelinfo->setTitle(QApplication::translate("FlowWin", "Pixel info", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FlowWin", "X", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FlowWin", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("FlowWin", "Y", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("FlowWin", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("FlowWin", "Density", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("FlowWin", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("FlowWin", "U-force", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("FlowWin", "TextLabel", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("FlowWin", "&File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FlowWin: public Ui_FlowWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FLOWUI_H
