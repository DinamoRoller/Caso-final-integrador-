#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct ColorConsole
        {
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
};

struct ConsoleBox
        {
    void new_text() { /*...*/}
    static void set_text(const string &text) { cout << text << endl; }
};

ConsoleBox *consoleBox = new ConsoleBox; // suponiendo que ya esta inicializado

void load_script(const char *filename, bool show_script = false)
{
    string script;
    ifstream file(filename);

    try
    {
     if (!file.is_open())
     {
      cerr << "Error de apertura de " << filename << endl;
      return;
     }

     string line;
     while (getline(file, line))
     {
     script += line + "\n";
     }

     if (show_script)
     {
     cout << ColorConsole::fg_blue << ColorConsole::bg_white;
     cout << script << endl;
     }

     consoleBox->new_text();
     ConsoleBox::set_text(script);
    }
    catch (const std::exception &e)
    {
        cerr << "Error durante la lectura del archivo: " << e.what() << endl;
    }
}

void load_script()
{
    char filename[500];
    cout << "Archivo: ";
    cin.getline(filename, sizeof(filename));
    load_script(filename, true);
}

int main(){
    //ejemplo de uso
    load_script(); //pide al usuario que ponga el nombre de un archivo

    return 0;
}