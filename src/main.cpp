#include <QApplication> //подключаем библиотеки QApplication	
#include <QTranslator> //Подключение библитеки QTranslator

#include <signal.h>  //Подключение библиотеки signal.h 

#include "mainwindow.h" // Подключаем файл mainwindow.h, он становится дочерним к main 

//static void sigHandler(int sig) {} //в переменную sig записывается значение, которое выдает sigHandler при выполнение функции signal

int main(int argc, char *argv[]) //головная программа
{
	/**блок обработки процессором в зависимости от signal**/
    struct sigaction sa;  
    sa.sa_flags = 0; // устанавливаем флаг в значение 0
   // sa.sa_handler = sigHandler; // определение на какой сигнал необходимо установить обработчик
    sigaction(SIGPIPE, &sa, NULL); // один процесс пересылает данные другому , без не обходимости создавать файлы на дисе при нарушении соединения процесс допередает и заверешается
    sigaction(SIGSEGV, &sa, NULL);//при нарушении работы памяти прекратить работу программы

    QApplication app(argc, argv);  // создание объекта для управления всеми ресурсами проекта

/**Блок для перевода с одного языка на другой **/
    QTranslator translator;  
    if (translator.load(":/res/l10n/mbdu_ru.qm")) //указываем путь к переведенному ресурсу, если он есть, то
        app.installTranslator(&translator); // перевод

    MainWindow lMainWindow; //результат из MainWindow записывается в lMainWindow
    lMainWindow.show(); // выводим на экран резльтат из lMainWindow
    lMainWindow.setWindowState(Qt::WindowFullScreen);  // приложение переходит в полноэкранный режим

    return app.exec(); // передача управления переходит к QT приложение ожидает действия со стороны пользователя аналог readln
}
