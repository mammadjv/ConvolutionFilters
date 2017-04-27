/********************************************************************************
** Form generated from reading UI file 'viewframe.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWFRAME_H
#define UI_VIEWFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ViewFrame
{
public:
    QVBoxLayout *verticalLayout_3;
    QFrame *options;
    QGridLayout *gridLayout;
    QCheckBox *north;
    QCheckBox *east;
    QCheckBox *north_west;
    QCheckBox *LP2;
    QCheckBox *HP1;
    QCheckBox *south_west;
    QCheckBox *HP3;
    QCheckBox *LP1;
    QCheckBox *HP2;
    QCheckBox *LP3;
    QCheckBox *LAP2;
    QCheckBox *hor_edges;
    QCheckBox *sec_ver_edges;
    QCheckBox *west;
    QSpacerItem *verticalSpacer;
    QCheckBox *LAP1;
    QCheckBox *horver_edges;
    QCheckBox *sec_hor_edges;
    QCheckBox *ver_edges;
    QCheckBox *LAP4;
    QCheckBox *LAP3;
    QCheckBox *south;
    QCheckBox *blur;
    QCheckBox *north_east;
    QCheckBox *south_east;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLineEdit *path;
    QPushButton *files;
    QFrame *images;
    QVBoxLayout *verticalLayout;
    QGraphicsView *mainImg;
    QGraphicsView *convedimg;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *ViewFrame)
    {
        if (ViewFrame->objectName().isEmpty())
            ViewFrame->setObjectName(QStringLiteral("ViewFrame"));
        ViewFrame->resize(661, 738);
        verticalLayout_3 = new QVBoxLayout(ViewFrame);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        options = new QFrame(ViewFrame);
        options->setObjectName(QStringLiteral("options"));
        options->setFrameShape(QFrame::StyledPanel);
        options->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(options);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        north = new QCheckBox(options);
        buttonGroup = new QButtonGroup(ViewFrame);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(north);
        north->setObjectName(QStringLiteral("north"));

        gridLayout->addWidget(north, 13, 0, 1, 1);

        east = new QCheckBox(options);
        buttonGroup->addButton(east);
        east->setObjectName(QStringLiteral("east"));

        gridLayout->addWidget(east, 13, 2, 1, 1);

        north_west = new QCheckBox(options);
        buttonGroup->addButton(north_west);
        north_west->setObjectName(QStringLiteral("north_west"));

        gridLayout->addWidget(north_west, 10, 3, 1, 1);

        LP2 = new QCheckBox(options);
        buttonGroup->addButton(LP2);
        LP2->setObjectName(QStringLiteral("LP2"));

        gridLayout->addWidget(LP2, 0, 1, 1, 1);

        HP1 = new QCheckBox(options);
        buttonGroup->addButton(HP1);
        HP1->setObjectName(QStringLiteral("HP1"));

        gridLayout->addWidget(HP1, 4, 1, 1, 1);

        south_west = new QCheckBox(options);
        buttonGroup->addButton(south_west);
        south_west->setObjectName(QStringLiteral("south_west"));

        gridLayout->addWidget(south_west, 0, 3, 1, 1);

        HP3 = new QCheckBox(options);
        buttonGroup->addButton(HP3);
        HP3->setObjectName(QStringLiteral("HP3"));

        gridLayout->addWidget(HP3, 7, 0, 1, 1);

        LP1 = new QCheckBox(options);
        buttonGroup->addButton(LP1);
        LP1->setObjectName(QStringLiteral("LP1"));
        LP1->setTristate(false);

        gridLayout->addWidget(LP1, 0, 0, 1, 1);

        HP2 = new QCheckBox(options);
        buttonGroup->addButton(HP2);
        HP2->setObjectName(QStringLiteral("HP2"));

        gridLayout->addWidget(HP2, 4, 2, 1, 1);

        LP3 = new QCheckBox(options);
        buttonGroup->addButton(LP3);
        LP3->setObjectName(QStringLiteral("LP3"));

        gridLayout->addWidget(LP3, 0, 2, 1, 1);

        LAP2 = new QCheckBox(options);
        buttonGroup->addButton(LAP2);
        LAP2->setObjectName(QStringLiteral("LAP2"));

        gridLayout->addWidget(LAP2, 13, 3, 1, 1);

        hor_edges = new QCheckBox(options);
        buttonGroup->addButton(hor_edges);
        hor_edges->setObjectName(QStringLiteral("hor_edges"));

        gridLayout->addWidget(hor_edges, 7, 2, 1, 1);

        sec_ver_edges = new QCheckBox(options);
        buttonGroup->addButton(sec_ver_edges);
        sec_ver_edges->setObjectName(QStringLiteral("sec_ver_edges"));

        gridLayout->addWidget(sec_ver_edges, 10, 1, 1, 1);

        west = new QCheckBox(options);
        buttonGroup->addButton(west);
        west->setObjectName(QStringLiteral("west"));

        gridLayout->addWidget(west, 4, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 26, 0, 1, 1);

        LAP1 = new QCheckBox(options);
        buttonGroup->addButton(LAP1);
        LAP1->setObjectName(QStringLiteral("LAP1"));

        gridLayout->addWidget(LAP1, 7, 3, 1, 1);

        horver_edges = new QCheckBox(options);
        buttonGroup->addButton(horver_edges);
        horver_edges->setObjectName(QStringLiteral("horver_edges"));

        gridLayout->addWidget(horver_edges, 10, 0, 1, 1);

        sec_hor_edges = new QCheckBox(options);
        buttonGroup->addButton(sec_hor_edges);
        sec_hor_edges->setObjectName(QStringLiteral("sec_hor_edges"));

        gridLayout->addWidget(sec_hor_edges, 10, 2, 1, 1);

        ver_edges = new QCheckBox(options);
        buttonGroup->addButton(ver_edges);
        ver_edges->setObjectName(QStringLiteral("ver_edges"));

        gridLayout->addWidget(ver_edges, 7, 1, 1, 1);

        LAP4 = new QCheckBox(options);
        buttonGroup->addButton(LAP4);
        LAP4->setObjectName(QStringLiteral("LAP4"));

        gridLayout->addWidget(LAP4, 0, 4, 1, 1);

        LAP3 = new QCheckBox(options);
        buttonGroup->addButton(LAP3);
        LAP3->setObjectName(QStringLiteral("LAP3"));

        gridLayout->addWidget(LAP3, 4, 4, 1, 1);

        south = new QCheckBox(options);
        buttonGroup->addButton(south);
        south->setObjectName(QStringLiteral("south"));

        gridLayout->addWidget(south, 7, 4, 1, 1);

        blur = new QCheckBox(options);
        buttonGroup->addButton(blur);
        blur->setObjectName(QStringLiteral("blur"));

        gridLayout->addWidget(blur, 10, 4, 1, 1);

        north_east = new QCheckBox(options);
        buttonGroup->addButton(north_east);
        north_east->setObjectName(QStringLiteral("north_east"));

        gridLayout->addWidget(north_east, 13, 1, 1, 1);

        south_east = new QCheckBox(options);
        buttonGroup->addButton(south_east);
        south_east->setObjectName(QStringLiteral("south_east"));

        gridLayout->addWidget(south_east, 4, 0, 1, 1);


        verticalLayout_3->addWidget(options);

        frame = new QFrame(ViewFrame);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        path = new QLineEdit(frame);
        path->setObjectName(QStringLiteral("path"));

        horizontalLayout->addWidget(path);

        files = new QPushButton(frame);
        files->setObjectName(QStringLiteral("files"));

        horizontalLayout->addWidget(files);


        verticalLayout_3->addWidget(frame);

        images = new QFrame(ViewFrame);
        images->setObjectName(QStringLiteral("images"));
        images->setFrameShape(QFrame::StyledPanel);
        images->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(images);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        mainImg = new QGraphicsView(images);
        mainImg->setObjectName(QStringLiteral("mainImg"));

        verticalLayout->addWidget(mainImg);

        convedimg = new QGraphicsView(images);
        convedimg->setObjectName(QStringLiteral("convedimg"));

        verticalLayout->addWidget(convedimg);


        verticalLayout_3->addWidget(images);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 1);
        verticalLayout_3->setStretch(2, 8);

        retranslateUi(ViewFrame);

        QMetaObject::connectSlotsByName(ViewFrame);
    } // setupUi

    void retranslateUi(QDialog *ViewFrame)
    {
        ViewFrame->setWindowTitle(QApplication::translate("ViewFrame", "Dialog", 0));
        north->setText(QApplication::translate("ViewFrame", "north", 0));
        east->setText(QApplication::translate("ViewFrame", "east", 0));
        north_west->setText(QApplication::translate("ViewFrame", "north_west", 0));
        LP2->setText(QApplication::translate("ViewFrame", "LP2", 0));
        HP1->setText(QApplication::translate("ViewFrame", "HP1", 0));
        south_west->setText(QApplication::translate("ViewFrame", "south_west", 0));
        HP3->setText(QApplication::translate("ViewFrame", "HP3", 0));
        LP1->setText(QApplication::translate("ViewFrame", "LP1", 0));
        HP2->setText(QApplication::translate("ViewFrame", "HP2", 0));
        LP3->setText(QApplication::translate("ViewFrame", "LP3", 0));
        LAP2->setText(QApplication::translate("ViewFrame", "LAP2", 0));
        hor_edges->setText(QApplication::translate("ViewFrame", "hor_edges", 0));
        sec_ver_edges->setText(QApplication::translate("ViewFrame", "sec_ver_edges", 0));
        west->setText(QApplication::translate("ViewFrame", "west", 0));
        LAP1->setText(QApplication::translate("ViewFrame", "LAP1", 0));
        horver_edges->setText(QApplication::translate("ViewFrame", "horver_edges", 0));
        sec_hor_edges->setText(QApplication::translate("ViewFrame", "sec_hor_edges", 0));
        ver_edges->setText(QApplication::translate("ViewFrame", "ver_edges", 0));
        LAP4->setText(QApplication::translate("ViewFrame", "LAP4", 0));
        LAP3->setText(QApplication::translate("ViewFrame", "LAP3", 0));
        south->setText(QApplication::translate("ViewFrame", "south", 0));
        blur->setText(QApplication::translate("ViewFrame", "blur", 0));
        north_east->setText(QApplication::translate("ViewFrame", "north_east", 0));
        south_east->setText(QApplication::translate("ViewFrame", "south_east", 0));
        files->setText(QApplication::translate("ViewFrame", "Files", 0));
    } // retranslateUi

};

namespace Ui {
    class ViewFrame: public Ui_ViewFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWFRAME_H
