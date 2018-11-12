#include "dialogs.h"

/*
MessageDialog (
const Glib::ustring& message,
bool use_markup=false,
MessageType type=MESSAGE_INFO,
ButtonsType buttons=BUTTONS_OK,
bool modal=false)
*/


// A message is like cout, simply displaying information to the user
void Dialogs::message(std::string msg, std::string title) {
    Gtk::MessageDialog *dialog = new Gtk::MessageDialog(title,true);
    dialog->set_secondary_text(msg, true);
    dialog->run();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    delete dialog;
}

// A question is a message that allows the user to respond with a button
int Dialogs::question(std::string msg, std::string title,
             std::vector<std::string> buttons) {
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title(title);

    Gtk::Label *label = new Gtk::Label(msg);
    dialog->get_content_area()->pack_start(*label);
    label->show();

    for(int i=0; i<buttons.size(); ++i) dialog->add_button(buttons[i], i);

    int result = dialog->run();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    delete label;
    delete dialog;

    return result;
}

// A request for a line of text input
std::string Dialogs::input(std::string msg, std::string title,
    std::string default_text, std::string cancel_text) {
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title(title);

    Gtk::Label *label = new Gtk::Label(msg);
    dialog->get_content_area()->pack_start(*label);
    label->set_use_markup();
    label->show();

    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->set_default_response(1);

    Gtk::Entry *entry = new Gtk::Entry{};
    entry->set_text(default_text);
    entry->set_max_length(50);
    entry->show();
    dialog->get_vbox()->pack_start(*entry);

    int result = dialog->run();
    std::string text = entry->get_text();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    delete entry;
    delete label;
    delete dialog;

    if (result == 1)
        return text;
    else
        return cancel_text;
}


// Display an image from a disk file
void Dialogs::image(std::string filename, std::string title, std::string msg) {
    Gtk::Dialog *dialog = new Gtk::Dialog(title);
    dialog->set_title(title);

    Gtk::Label *label = new Gtk::Label(msg);
    dialog->get_content_area()->pack_start(*label);
    label->show();

    dialog->add_button("Close", 0);
    dialog->set_default_response(0);

    Gtk::Image *image = new Gtk::Image{filename};
    image->show();
    dialog->get_vbox()->pack_start(*image);

    int result = dialog->run();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    delete image;
    delete label;
    delete dialog;

    return;
}
/*
std::string Dialogs::donut(std::string msg, std::string title,
    std::string default_text, std::string cancel_text) {

      dialog->add_button("Cancel", 0);
      dialog->add_button("OK", 1);
      dialog->set_default_response(1);

    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("New Donut");

    Gtk::Label *label_name = new Gtk::Label("Name:");
    dialog->get_content_area()->pack_start(*label_name);
    label_name->show();

    Gtk::Entry *entry_name = new Gtk::Entry{};
    entry_name->set_max_length(50);
    entry_name->show();
    dialog->get_vbox()->pack_start(*entry_name);

    Gtk::Label *label_price = new Gtk::Label("Price:");
    dialog->get_content_area()->pack_start(*label_price);
    label_price->show();

    Gtk::Entry *entry_price = new Gtk::Entry{};
    entry_price->set_max_length(5);
    entry_price->show();
    dialog->get_vbox()->pack_start(*entry_price);

    Gtk::Label *label_cost = new Gtk::Label("Cost:");
    dialog->get_content_area()->pack_start(*label_cost);
    label_cost->show();

    Gtk::Entry *entry_cost = new Gtk::Entry{};
    entry_cost->set_max_length(5);
    entry_cost->show();
    dialog->get_vbox()->pack_start(*entry_cost);

    int result = dialog->run();
    std::string text = entry->get_text();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    delete entry;
    delete label;
    delete dialog;

    if (result == 1)
        return text;
    else
        return cancel_text;
}
*/
