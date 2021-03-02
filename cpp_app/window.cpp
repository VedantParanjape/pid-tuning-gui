#include "window.h"

Window::Window(QWidget *parent) :
    QWidget(parent)
{
    QMainWindow window;
    // Set size of the window
    setFixedSize(600, 600);
    // Create and position the button
    m_button = new QPushButton("Hello World", this);
    m_button->setGeometry(200, 10, 280, 30);
    m_button->setCheckable(true);
    // NEW : Do the connection
    connect(m_button, SIGNAL (clicked(bool)), this, SLOT (slotButtonClicked(bool)));
    connect(this, SIGNAL (counterReached()), QApplication::instance(), SLOT (quit()));
    m_counter = 0;
    // Create a horizontal slider
    // with the range between 0 and 100, and a starting value of 0
    slider = new QSlider(this->window());
    slider->setOrientation(Qt::Horizontal);
    slider->setRange(0, 100);
    slider->setValue(0);
    slider->setGeometry(10, 40, 180, 30);
    // Create a progress bar
    // with the range between 0 and 100, and a starting value of 0
    progressBar = new QProgressBar(this->window());
    progressBar->setRange(0, 100);
    progressBar->setValue(0);
    progressBar->setGeometry(10, 10, 180, 30);
    // Connection
    // This connection set the value of the progress bar
    // while the slider's value changes
    QObject::connect(slider, SIGNAL (valueChanged(int)), progressBar, SLOT (setValue(int)));

}

void Window::slotButtonClicked(bool checked) {

    if (checked)
    {
        m_button->setText("Checked");
    }
    else
    {
        m_button->setText("Hello World");
    }
    m_counter++;
    if (m_counter == 10) {
    emit counterReached();
    }
}
