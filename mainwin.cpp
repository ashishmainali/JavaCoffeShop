#include "mainwin.h"
Mainwin::~Mainwin() { }
Mainwin::Mainwin()
{
  set_default_size(700, 400);
  Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);
    //CRETING MENU BAR "menubar"
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //F I L E       M E N U

    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);

    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_quit_click));
    filemenu->append(*menuitem_quit);
//  V I E W       M E N U

    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menubar->append (*menuitem_view);

    Gtk::Menu *viewmenu = Gtk::manage (new Gtk::Menu());
    menuitem_view ->set_submenu (*viewmenu);

    Gtk::MenuItem *menuitem_view_all = Gtk::manage(new Gtk::MenuItem("_View All",true));
    menuitem_view_all->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_view_all_click));
    viewmenu->append (*menuitem_view_all);

    //  C R E A T E       M E N U
  Gtk::MenuItem *menuitem_create = Gtk::manage (new Gtk::MenuItem("_Create",true));
  menubar->append (*menuitem_create);

  Gtk::Menu *createmenu = Gtk::manage(new Gtk::Menu());
  menuitem_create ->set_submenu (*createmenu);

 createmenu->append(*menuitem_new_coffee);
  menuitem_new_donut->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_donut_click));
  

  createmenu->append(*menuitem_new_donut);
    menuitem_new_coffee->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_coffee_click));
  





    vbox->show_all();
}

void Mainwin::on_quit_click()
{
 _store.free_products();
  hide();
}
void Mainwin::on_view_all_click()
{
  std::ostringstream strs;
  std::string msg;
  std::string title = " All Products";
    for (int i = 0 ; i < _store.number_of_products() ; i++)
        strs <<std::to_string(i+1)<<". " << _store.product_to_string(i) << "\n";
    msg = strs.str();
    std::cout << msg;

    Gtk::MessageDialog *dialog = new Gtk::MessageDialog(title);
    
    dialog->set_secondary_text(msg, true);
    dialog->run();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    delete dialog;


}
void Mainwin::on_create_coffee_click()
{
  Java *p0 = new Java("Frappe",3,1,3);
  _store.add_product(p0);

}
void Mainwin::on_create_donut_click()
{
  
  Product *p1 = new Donut("Donut",3.5,1.5,Frosting::CHOCLATE_TOP,true,Filling::STRAWBERRY);
  _store.add_product(p1);


}
