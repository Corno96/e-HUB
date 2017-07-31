#include "platform_button.h"

PButton::PButton(QWidget *parent, MainWindow *main_window, Platform* platform) : QPushButton(parent) {
    this->main_window = main_window;
    this->platform = platform;

    qDebug() << "Dopo : " << platform;
}

void PButton::choosePlatform() {
    if (platform != nullptr) {
        main_window->getUI()->stackedWidget->setCurrentIndex(MainWindow::GAME);

        drawGrid(platform->getGames());
    }
}

void PButton::drawGrid(QVector<Game> vec)
{
    QHBoxLayout* layout = new QHBoxLayout;
    QWidget* widget = new QWidget(this);

    for (auto widget: main_window->getUI()->games->findChildren<QWidget*>(QString(), Qt::FindDirectChildrenOnly))
      delete widget;

    for (int i=0;i<=(vec.size()/main_window->getColumns());++i){

        for (int k=0;k<main_window->getColumns();++k) {
            if (i*main_window->getColumns() + k >= vec.size())
                break;

            Game* g = platform->getGame(i*main_window->getColumns()+k);

            // create button and add it to layout
            GButton* button = new GButton(this, platform, g);
            QObject::connect(button, SIGNAL(clicked(bool)), button, SLOT(launchGame()));
            button->setText(vec[i*main_window->getColumns()+k].getName());

            layout->addWidget(button);
        }

        // set widget layout and add it to main layout
        //layout->setAlignment(Qt::AlignLeft);
        widget->setLayout(layout);

        main_window->getUI()->games->layout()->addWidget(widget);
        widget->show();

        widget = new QWidget(this);
        layout = new QHBoxLayout;
    }
}

