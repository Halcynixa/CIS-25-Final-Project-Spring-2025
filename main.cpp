#include <iostream>
#include <vector> // for flexible arrays
using namespace std;

class Template {
    public:
       string Tname = "Empty Slot"; // technical reasons
       string content = "";
       vector<int> variables = {}; // stores where the # (variables) are in the string
       void assignName(string n) { // create template function
            Tname = n; // assign display name
            cout << "Start typing your code below.\nPress Enter for new line\nPress # to put a variable\nPress $ to save and exit\n";
            string in = "";
            while (in != "$") { // keep looping until user inputs $ (save and exit)
                cin >> in;
                if (in != "$") { // don't add $ to content
                    content = content + "\n" + in; // add new stuff to content after every line
                }
            }
            cout << "Saving an exiting...\n";
        }
       void selectTemplate() { // select template function
           for (int i = 0; i < content.length(); i++) {
               if (content[i] == '#') {
                   variables.push_back(i); // store positions of # in the string to the arrays
               }
           }
           string output = content;
           for (int i = 0; i < variables.size(); i++) { // variables.size() = # of # (eh?), which is how many times this will loop
               char q;
               cout << "What should template " << i + 1 << " be?\n"; // ask user for what to replace # with
               cin >> q;
               output[variables[i]] = q; // actually replace it

           }
           cout << "<><><><><><><><><><>" << output << "\n<><><><><><><><><><>\n"; // output final result
           for (int i = 0; i < variables.size(); i++) { // v = 1 -> i = 0, total 1 || v = 2 -> i = 0, 1, total 2
               variables.pop_back(); //clear variables array once done, allowing for reuse   
           }
       }
       ~Template() {
           cout << "\nSaving...\n----\n----\n----\n"; // exit
       }
};

bool checkTemplates(string A, string B, string C, string D, string E) { // checks if all the slots aren't filled yet
    if (A == "" || B == "" || C == "" || D == "" || E == "") {
        return true; // they aren't
    }
    else {
        return false; // they are
    }
}

int main()
{
    Template a; // initialize all 5 slots
    Template b;
    Template c;
    Template d;
    Template e;
    int x = 0;
    while (x != 3) { // 3 = exit
        int x = 0;
        cout << "--------\nWelcome to Template Code Generator!\n--------\nSelect or create a new template below\n1). Select Template\n2). Create New Template\n3). Exit\n";
        cin >> x;
        if (x == 1) { // select template
            int y = 0;
            cout << "Select template: \n1). " << a.Tname << "\n2). " << b.Tname << "\n3). " << c.Tname << "\n4). " << d.Tname << "\n5). " << e.Tname << "\n\n\n\nSelect with cooresponidng number. Hit any other button to go back\n";
            cin >> y;
            // call the class
            if (y == 1 && a.Tname != "Empty Slot") {
                a.selectTemplate();
            }
            else if (y == 2 && b.Tname != "Empty Slot") {
                b.selectTemplate();
            }
            else if (y == 3 && c.Tname != "Empty Slot") {
                c.selectTemplate();
            }
            else if (y == 4 && d.Tname != "Empty Slot") {
                d.selectTemplate();
            }
            else if (y == 5 && e.Tname != "Empty Slot") {
                e.selectTemplate();
            }
          
        }
        else if (x == 2) { // create new template
                if (checkTemplates(a.content, b.content, c.content, d.content, e.content)) { // see if slots are filled yet
                    string name;
                    cout << "Enter the name for your template: \n";
                    cin >> name;
                    // call the class
                    if (a.Tname == "Empty Slot") {
                        a.assignName(name);
                    }
                    else if (b.Tname == "Empty Slot") {
                        b.assignName(name);
                    }
                    else if (c.Tname == "Empty Slot") {
                        c.assignName(name);
                    }
                    else if (d.Tname == "Empty Slot") {
                        d.assignName(name);
                    }
                    else if (e.Tname == "Empty Slot") {
                        e.assignName(name);
                    }
                     
                }
                else {
                    cout << "No more space.\n"; //slots are full, don't create any more classes
                }

            }
        }
        cout << "Exiting...";
        return 0;
    }
