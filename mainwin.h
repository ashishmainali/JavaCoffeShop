#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include "store.h"
#include "dialogs.h"
#include <regex>
#include <exception>
#include <stdexcept>

class Mainwin : public Gtk::Window
{
  public:
    Mainwin();
    virtual ~Mainwin();
  protected:
    void on_quit_click();
    void on_view_all_click();
    void on_create_coffee_click();
    void on_create_donut_click();
    void on_new_customer_click();
    void on_list_customers_click();
    void on_about_click();

  private:
    Store _store;
    Gtk::Label* msg = new Gtk::Label;
    Gtk::MenuItem* menuitem_new_coffee = Gtk::manage(new Gtk::MenuItem("_Coffee",true));
    Gtk::MenuItem* menuitem_new_donut = Gtk::manage(new Gtk::MenuItem("_Donut",true));

};

#endif
