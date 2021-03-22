#include <iostream>
#include "dictionary.hxx"
#include "finder.hxx"

using namespace std;

int main()
{
    auto dict_list = vector<pair<string, string>>();
    nuspell::search_default_dirs_for_dicts(dict_list);
    auto dict_name_and_path = nuspell::find_dictionary(dict_list, "en_US");
    if (dict_name_and_path == end(dict_list))
        return 1; // Return error because we can not find the requested
                  // dictionary in the list.
    auto& dict_path = dict_name_and_path->second;

    auto dict = nuspell::Dictionary::load_from_path(dict_path);

    auto word = string();
    auto sugs = vector<string>();
    while (cin >> word) {
        if (dict.spell(word)) {
            cout << "Word \"" << word << "\" is ok.\n";
            continue;
        }

        cout << "Word \"" << word << "\" is incorrect.\n";
        dict.suggest(word, sugs);
        if (sugs.empty())
            continue;
        cout << "  Suggestions are: ";
        for (auto& sug : sugs)
            cout << sug << ' ';
        cout << '\n';
    }
}