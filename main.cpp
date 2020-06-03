#include "mainwin.h"

int main(int argc, char *argv[]) {

    Gtk::Main kit(argc, argv);
    auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.vehicle");

  // Instance a Window
  Mainwin win;

  // Set the window title
  win.set_title("JAVA and DONUT");

  //Show the window and returns when it is closed or hidden
  return app->run(win);


}
