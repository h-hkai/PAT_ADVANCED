#include <bits/stdc++.h>

using namespace std;

struct Book {
    string id;
    string title;
    string author;
    set<string> keywords;
    string publisher;
    string published_year;
};

bool cmp(Book a, Book b) { return a.id < b.id; }

int main() {
    int n;
    cin >> n;
    getchar();
    string temp;
    vector<Book> books(n);
    for (int i = 0; i < n; ++i) {
        getline(cin, books[i].id);
        getline(cin, books[i].title);
        getline(cin, books[i].author);
        getline(cin, temp);
        getline(cin, books[i].publisher);
        getline(cin, books[i].published_year);
        int last = 0, pos;
        set<string> keywords;
        while (temp.find(' ', last) != string::npos) {
            pos = temp.find(' ', last);
            string keyword = temp.substr(last, pos - last);
            books[i].keywords.insert(keyword);
            last = pos + 1;
        }
        books[i].keywords.insert(temp.substr(last));
    }
    sort(books.begin(), books.end(), cmp);
    int m;
    cin >> m;
    getchar();
    string query;
    for (int i = 0; i < m; ++i) {
        getline(cin, query);
        cout << query << endl;
        int flag = 0;
        switch (query[0] - '0') {
            case 1:
                temp = query.substr(3);
                for (int j = 0; j < n; ++j) {
                    if (books[j].title == temp) {
                        cout << books[j].id << endl;
                        flag = 1;
                    }
                }
                break;
            case 2:
                temp = query.substr(3);
                for (int j = 0; j < n; ++j) {
                    if (books[j].author == temp) {
                        cout << books[j].id << endl;
                        flag = 1;
                    }
                }
                break;
            case 3:
                temp = query.substr(3);
                for (int j = 0; j < n; ++j) {
                    for (string s : books[j].keywords) {
                        if (s == temp) {
                            cout << books[j].id << endl;
                            flag = 1;
                            break;
                        }
                    }
                }
                break;
            case 4:
                temp = query.substr(3);
                for (int j = 0; j < n; ++j) {
                    if (books[j].publisher == temp) {
                        cout << books[j].id << endl;
                        flag = 1;
                    }
                }
                break;
            case 5:
                temp = query.substr(3);
                for (int j = 0; j < n; ++j) {
                    if (books[j].published_year == temp) {
                        cout << books[j].id << endl;
                        flag = 1;
                    }
                }
                break;
            default:
                break;
        }
        if (flag == 0) cout << "Not Found" << endl;
    }

    return 0;
}