#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream> 
#include <sstream>
using namespace std;
// class person section ------------------------------
class Person {
protected:
    string name;
    int id;
public:
    Person();
    Person(string, int);
    void setName(string);
    void setId(int);
    virtual void display() const; 
    string getName() const;
    int getId() const;
};

Person::Person() {
    name = "";
    id = 0;
}
Person::Person(string n, int i) {
    setName(n);
    setId(i);
}

void Person::setName(string n) {
    if (n.length() >= 3)
        name = n;
    else
        cout << "Error! Name must be least 3 characters." << endl;
}

void Person::setId(int i) {
    if (i >= 0)
        id = i;
    else
        cout << "Error! ID must be non-negative." << endl;
}

string Person::getName() const {
    return name;
}

int Person::getId() const {
    return id;
}

void Person::display() const {
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
}
// Member section class ---------------------------------
class Member : public Person {
private:
    vector<int> borrowedItemId;
public:
    Member();
    Member(string, int);
    void borrowItem(int);
    void returnItem(int);
    void display() const override; 
    const vector<int>& getBorrowedItemId() const;
};

Member::Member() = default;

Member::Member(string n, int i) : Person(n, i) {}

void Member::borrowItem(int itemId) {
    borrowedItemId.push_back(itemId);
}

void Member::returnItem(int itemId) {
    borrowedItemId.erase(remove(borrowedItemId.begin(), borrowedItemId.end(), itemId), borrowedItemId.end());
}

void Member::display() const {
    Person::display();
    cout << "Borrowed items: ";
    if (borrowedItemId.empty()) {
        cout << "None";
    } else {
        for (int id : borrowedItemId) {
            cout << id << " ";
        }
    }
    cout << endl;
}

const vector<int>& Member::getBorrowedItemId() const {
    return borrowedItemId;
}
// class librarian section -----------------------
class Librarian : public Person {
    private:
        string username;
        string password;
    
    public:
        Librarian();
        Librarian(string name, int id, string u, string p);
    
        void setUsername(string u);
        void setPassword(string p);
    
        string getUsername() const;
        string getPassword() const;
    
        void displayLibrarianInfo() const;
    };
    Librarian::Librarian() : Person() {
        username = "";
        password = "";
    }
    
    Librarian::Librarian(string name, int id, string u, string p) : Person(name, id) {
        setUsername(u);
        setPassword(p);
    }
    
    void Librarian::setUsername(string u) {
        if (u.length() >= 3)
            username = u;
        else
            cout << "Error! Username must be at least 3 characters." << endl;
    }
    
    void Librarian::setPassword(string p) {
        if (p.length() >= 6)
            password = p;
        else
            cout << "Error! Password must be at least 6 characters." << endl;
    }
    
    string Librarian::getUsername() const {
        return username;
    }
    
    string Librarian::getPassword() const {
        return password;
    }
    
    void Librarian::displayLibrarianInfo() const {
        display();
        cout << "Username: " << username << endl;
    }
        
    
// class item section ---------------------------
class Item {
    protected:
        string title;
        int itemID;
        bool isAvailable;
    
    public:
        Item();
        Item(string, int, bool);
        
        void setTitle(string);
        void setItemID(int);
        void setIsAvailable(bool);
        
        string getTitle() const;
        int getItemID() const;
        bool getIsAvailable() const;
    
        virtual void displayInfo() const;
    };
    Item::Item() {
        title = "";
        itemID = 0;
        isAvailable = true;
    }
    
    Item::Item(string t, int id, bool avail) {
        setTitle(t);
        setItemID(id);
        setIsAvailable(avail);
    }
    
    void Item::setTitle(string t) {
        if (t.length() >= 3)
            title = t;
        else
            cout << "Error! must be at least 3 characters." << endl;
    }
    
    void Item::setItemID(int id) {
        if (id >= 0)
            itemID = id;
        else
            cout << "Error! ID must be Positive." << endl;
    }
    
    void Item::setIsAvailable(bool avail) {
        isAvailable = avail;
    }
    
    string Item::getTitle() const {
        return title;
    }
    
    int Item::getItemID() const {
        return itemID;
    }
    
    bool Item::getIsAvailable() const {
        return isAvailable;
    }
    
    void Item::displayInfo() const {
        cout << "Title: " << title << endl;
        cout << "Item ID: " << itemID << endl;
        cout << "Availability: " << (isAvailable ? "Available" : "Borrowed") << endl;
    }
//class Book section ----------------------
class Book : public Item {
    private:
        string author;
        string ISBN;
    
    public:
        Book();
        Book(string, int, bool, string, string);
        
        void setAuthor(string);
        void setISBN(string);
    
        string getAuthor() const;
        string getISBN() const;
    
        void displayInfo() const override;
    };
    Book::Book() : Item() {
        author = "";
        ISBN = "";
    }
    
    Book::Book(string t, int id, bool avail, string a, string isbn) : Item(t, id, avail) {
        setAuthor(a);
        setISBN(isbn);
    }
    
    void Book::setAuthor(string a) {
        if (a.length() >= 3)
            author = a;
        else
            cout << "Error! must be at least 3 characters." << endl;
    }
    
    void Book::setISBN(string isbn) {
        if (isbn.length() == 13)
            ISBN = isbn;
        else
            cout << "Error! must be 13 characters." << endl;
    }
    
    string Book::getAuthor() const {
        return author;
    }
    
    string Book::getISBN() const {
        return ISBN;
    }
    
    void Book::displayInfo() const {
        Item::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
    }
// class magazin section -----------------
class Magazine : public Item {
    private:
        int issueNumber;
        string publisher;
    
    public:
        Magazine();
        Magazine(string, int, bool, int, string);
    
        void setIssueNumber(int);
        void setPublisher(string);
    
        int getIssueNumber() const;
        string getPublisher() const;
    
        void displayInfo() const override;
    };
    Magazine::Magazine() : Item() {
        issueNumber = 0;
        publisher = "";
    }
    
    Magazine::Magazine(string t, int id, bool avail, int issue, string pub) : Item(t, id, avail) {
        setIssueNumber(issue);
        setPublisher(pub);
    }
    
    void Magazine::setIssueNumber(int issue) {
        if (issue > 0)
            issueNumber = issue;
        else
            cout << "Error! must be positive." << endl;
    }
    
    void Magazine::setPublisher(string pub) {
        if (pub.length() >= 3)
            publisher = pub;
        else
            cout << "Error! must be at least 3 characters." << endl;
    }
    
    int Magazine::getIssueNumber() const {
        return issueNumber;
    }
    
    string Magazine::getPublisher() const {
        return publisher;
    }
    
    void Magazine::displayInfo() const {
        Item::displayInfo();
        cout << "Issue Number: " << issueNumber << endl;
        cout << "Publisher: " << publisher << endl;
    }
//class DVD section --------------------------------
class DVD : public Item {
    private:
        string director;
        float duration;  
    
    public:
        DVD();
        DVD(string, int, bool, string, float);
    
        void setDirector(string);
        void setDuration(float);
    
        string getDirector() const;
        float getDuration() const;
    
        void displayInfo() const override;
    };
    DVD::DVD() : Item() {
        director = "";
        duration = 0.0;
    }
    
    DVD::DVD(string t, int id, bool avail, string dir, float dur) : Item(t, id, avail) {
        setDirector(dir);
        setDuration(dur);
    }
    
    void DVD::setDirector(string dir) {
        if (dir.length() >= 3)
            director = dir;
        else
            cout << "Error! must be at least 3 characters." << endl;
    }
    
    void DVD::setDuration(float dur) {
        if (dur > 0)
            duration = dur;
        else
            cout << "Error! must be greater than 0." << endl;
    }
    
    string DVD::getDirector() const {
        return director;
    }
    
    float DVD::getDuration() const {
        return duration;
    }
    
    void DVD::displayInfo() const {
        Item::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " minutes" << endl;
    }
// class transaction section --------------------------
class Transaction {
    private:
        int memberID;
        int itemID;
        string borrowDate;
        string returnDate;
        bool isReturned;
    
    public:
        Transaction();
        Transaction(int, int, string);
    
        void setMemberID(int);
        void setItemID(int);
        void setBorrowDate(string);
        void setReturnDate(string);
        void setIsReturned(bool);
    
        int getMemberID() const;
        int getItemID() const;
        string getBorrowDate() const;
        string getReturnDate() const;
        bool getIsReturned() const;
        
    
        void markReturned(string returnDate);
        void display() const;
    };
    Transaction::Transaction() {
        memberID = 0;
        itemID = 0;
        borrowDate = "";
        returnDate = "";
        isReturned = false;
    }
    
    Transaction::Transaction(int mID, int iID, string bDate) {
        setMemberID(mID);
        setItemID(iID);
        setBorrowDate(bDate);
        isReturned = false;
        returnDate = "";
    }
    
    void Transaction::setMemberID(int id) {
        if (id >= 0)
            memberID = id;
        else
            cout << "Error! must be positive." << endl;
    }
    
    void Transaction::setItemID(int id) {
        if (id >= 0)
            itemID = id;
        else
            cout << "Error! Item ID must be positive." << endl;
    }
    
    void Transaction::setBorrowDate(string date) {
        if (date.length() >= 6)
            borrowDate = date;
        else
            cout << "Error! Invalid borrow date format." << endl;
    }
    
    void Transaction::setReturnDate(string date) {
        if (date.length() >= 6)
            returnDate = date;
        else
            cout << "Error! Invalid return date format." << endl;
    }
    
    void Transaction::setIsReturned(bool status) {
        isReturned = status;
    }
    
    int Transaction::getMemberID() const {
        return memberID;
    }
    
    int Transaction::getItemID() const {
        return itemID;
    }
    
    string Transaction::getBorrowDate() const {
        return borrowDate;
    }
    
    string Transaction::getReturnDate() const {
        return returnDate;
    }
    
    bool Transaction::getIsReturned() const {
        return isReturned;
    }
    
    void Transaction::markReturned(string rDate) {
        setReturnDate(rDate);
        setIsReturned(true);
    }
    
    void Transaction::display() const {
        cout << "Transaction Info:" << endl;
        cout << "Member ID: " << memberID << endl;
        cout << "Item ID: " << itemID << endl;
        cout << "Borrow Date: " << borrowDate << endl;
        cout << "Return Date: " << (isReturned ? returnDate : "Not returned yet") << endl;
        cout << "Status: " << (isReturned ? "Returned" : "Borrowed") << endl;
    }
// class library section -----------------------------------
class Library {
    private:
        vector<Member> members;
        vector<Item*> items; 
        vector<Transaction> transactions;
    
    public:
        void addMember(const Member&);
        void addItem(Item*);
        void issueItem(int memberID, int itemID, const string& date);
        void returnItem(int itemID, const string& returnDate);
        
        Member* findMember(int memberID);
        Item* findItem(int itemID);
        void deleteMember(int);
        void deleteItem(int );
        void displayAllMembers() const;
        void displayAllItems() const;
        void displayAllTransactions() const;
    
        void loadFromFiles();
        void saveToFiles();
    };
    void Library::addMember(const Member& m) {
        members.push_back(m);
        cout << "Member added successfully." << endl;
    }
    void Library::addItem(Item* item) {
        items.push_back(item);
        cout << "Item added successfully." << endl;
    }
    Member* Library::findMember(int memberID) {
        for (auto& m : members) {
            if (m.getId() == memberID)
                return &m;
        }
        return nullptr;
    }
    
    Item* Library::findItem(int itemID) {
        for (auto& i : items) {
            if (i->getItemID() == itemID)
                return i;
        }
        return nullptr;
    }
    void Library::issueItem(int memberID, int itemID, const string& date) {
        Member* member = findMember(memberID);
        Item* item = findItem(itemID);
    
        if (!member) {
            cout << "Member not found!" << endl;
            return;
        }
    
        if (!item) {
            cout << "Item not found!" << endl;
            return;
        }
    
        if (!item->getIsAvailable()) {
            cout << "Item is already borrowed." << endl;
            return;
        }
    
        item->setIsAvailable(false);
        member->borrowItem(itemID); 
    
        Transaction t(memberID, itemID, date);
        transactions.push_back(t);
    
        cout << "Item issued successfully." << endl;
    }
    
    void Library::returnItem(int itemID, const string& returnDate) {
        Item* item = findItem(itemID);
    
        if (!item) {
            cout << "Item not found!" << endl;
            return;
        }
    
        if (item->getIsAvailable()) {
            cout << "Item is not currently borrowed." << endl;
            return;
        }
    
        for (auto& t : transactions) {
            if (t.getItemID() == itemID && !t.getIsReturned()) {
                t.markReturned(returnDate);
                break;
            }
        }
    
        item->setIsAvailable(true); 
    
        for (auto& m : members) {
            auto borrowed = m.getBorrowedItemId();
            if (find(borrowed.begin(), borrowed.end(), itemID) != borrowed.end()) {
                m.returnItem(itemID);
                break;
            }
        }
    
        cout << "Item returned successfully." << endl;
    }
    
    void Library::displayAllMembers() const {
        for (const auto& m : members) {
            m.display();
            cout << "---------------------" << endl;
        }
    }
    
    void Library::displayAllItems() const {
        for (const auto& i : items) {
            i->displayInfo();
            cout << "---------------------" << endl;
        }
    }
    
    void Library::displayAllTransactions() const {
        for (const auto& t : transactions) {
            t.display();
            cout << "---------------------" << endl;
        }
    }
    void Library::deleteMember(int memberID) {
        auto it = remove_if(members.begin(), members.end(), [memberID](const Member& m) {
            return m.getId() == memberID;
        });
        if (it != members.end()) {
            members.erase(it, members.end());
            cout << "Member deleted successfully." << endl;
        } else {
            cout << "Member not found." << endl;
        }
    }
    
    void Library::deleteItem(int itemID) {
        for (auto i = items.begin(); i != items.end(); ) {
            if ((*i)->getItemID() == itemID) {
                delete *i;
                i = items.erase(i);
                cout << "Item deleted successfully." << endl;
            } else {
                ++i;
            }
        }        
    }
// saveToFile section ----------------------
void Library::saveToFiles() {
    ofstream memberFile("members.txt");
    for (const auto& m : members) {
        memberFile << m.getId() << ',' << m.getName();
        for (int itemId : m.getBorrowedItemId()) {
            memberFile << ',' << itemId;
        }
        memberFile << endl;
    }
    memberFile.close();

    ofstream itemFile("items.txt");
    for (const auto& item : items) {
        Book* b = dynamic_cast<Book*>(item);
        if (b) {
            itemFile << "Book," << b->getItemID() << ',' << b->getTitle() << ',' << b->getIsAvailable()
                     << ',' << b->getAuthor() << ',' << b->getISBN() << endl;
            continue;
        }

        Magazine* m = dynamic_cast<Magazine*>(item);
        if (m) {
            itemFile << "Magazine," << m->getItemID() << ',' << m->getTitle() << ',' << m->getIsAvailable()
                     << ',' << m->getIssueNumber() << ',' << m->getPublisher() << endl;
            continue;
        }

        DVD* d = dynamic_cast<DVD*>(item);
        if (d) {
            itemFile << "DVD," << d->getItemID() << ',' << d->getTitle() << ',' << d->getIsAvailable()
                     << ',' << d->getDirector() << ',' << d->getDuration() << endl;
        }
    }
    itemFile.close();

    ofstream transFile("transactions.txt");
    for (const auto& t : transactions) {
        transFile << t.getMemberID() << ',' << t.getItemID() << ',' << t.getBorrowDate()
                  << ',' << t.getIsReturned() << ',' << t.getReturnDate() << endl;
    }
    transFile.close();

    cout << "Data saved successfully." << endl;
}
// loadFromFile section --------------------
void Library::loadFromFiles() {
    ifstream memberFile("members.txt");
    string line;
    while (getline(memberFile, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, ',')) tokens.push_back(token);

        if (tokens.size() >= 2) {
            Member m(tokens[1], stoi(tokens[0]));
            for (size_t i = 2; i < tokens.size(); ++i)
                m.borrowItem(stoi(tokens[i]));
            members.push_back(m);
        }
    }
    memberFile.close();

    ifstream itemFile("items.txt");
    while (getline(itemFile, line)) {
        stringstream ss(line);
        string type, title, extra1, extra2;
        int id;
        bool available;

        getline(ss, type, ',');
        ss >> id;
        ss.ignore();
        getline(ss, title, ',');
        ss >> available;
        ss.ignore();

        if (type == "Book") {
            getline(ss, extra1, ','); 
            getline(ss, extra2);
            items.push_back(new Book(title, id, available, extra1, extra2));
        } else if (type == "Magazine") {
            int issue;
            ss >> issue;
            ss.ignore();
            getline(ss, extra1);
            items.push_back(new Magazine(title, id, available, issue, extra1));
        } else if (type == "DVD") {
            getline(ss, extra1, ','); // director
            float dur;
            ss >> dur;
            items.push_back(new DVD(title, id, available, extra1, dur));
        }
    }
    itemFile.close();

    ifstream transFile("transactions.txt");
    while (getline(transFile, line)) {
        stringstream ss(line);
        string mID, iID, bDate, retFlag, rDate;
        getline(ss, mID, ',');
        getline(ss, iID, ',');
        getline(ss, bDate, ',');
        getline(ss, retFlag, ',');
        getline(ss, rDate);

        Transaction t(stoi(mID), stoi(iID), bDate);
        if (retFlag == "1") t.markReturned(rDate);
        transactions.push_back(t);
    }
    transFile.close();

    cout << "Data loaded successfully.\n";
}



// Menu -------------------------------
void showMenu() {
    cout << "\n--- Library Menu ---" << endl;
    cout << "1. Add Member" << endl;
    cout << "2. Add Item" << endl;
    cout << "3. Issue Item" << endl;
    cout << "4. Return Item" << endl;
    cout << "5. Display All Members" << endl;
    cout << "6. Display All Items" << endl;
    cout << "7. Display All Transactions" << endl;
    cout << "8. Delete Member" << endl;
    cout << "9. Delete Item" << endl;
    cout << "10. Add Librarian" << endl;        
    cout << "11. Display Librarian Info" << endl; 
    cout << "12. Save Data to Files" << endl;   
    cout << "13. Load Data from Files" << endl; 
    cout << "14. Exit" << endl;
    cout << "Choose an option: ";
}

int main() {
    Library lib;
    Librarian librarian;

    int choice;

    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string name;
                int id;
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter ID: ";
                cin >> id;
                lib.addMember(Member(name, id));
                break;
            }
            case 2: {
                int itemType;
                cout << "Select Item Type:\n1. Book\n2. Magazine\n3. DVD\nChoice: ";
                cin >> itemType;
                cin.ignore();

                string title;
                int id;
                bool avail = true;

                cout << "Enter title: ";
                getline(cin, title);
                cout << "Enter item ID: ";
                cin >> id;

                if (itemType == 1) {
                    string author, isbn;
                    cout << "Enter author: ";
                    cin.ignore();
                    getline(cin, author);
                    cout << "Enter ISBN (13 characters): ";
                    getline(cin, isbn);
                    lib.addItem(new Book(title, id, avail, author, isbn));
                } else if (itemType == 2) {
                    int issue;
                    string publisher;
                    cout << "Enter issue number: ";
                    cin >> issue;
                    cin.ignore();
                    cout << "Enter publisher: ";
                    getline(cin, publisher);
                    lib.addItem(new Magazine(title, id, avail, issue, publisher));
                } else if (itemType == 3) {
                    string director;
                    float duration;
                    cout << "Enter director: ";
                    cin.ignore();
                    getline(cin, director);
                    cout << "Enter duration (minutes): ";
                    cin >> duration;
                    lib.addItem(new DVD(title, id, avail, director, duration));
                } else {
                    cout << "Invalid item type." << endl;
                }
                break;
            }
            case 3: {
                int memberID, itemID;
                string date;
                cout << "Enter Member ID: ";
                cin >> memberID;
                cout << "Enter Item ID: ";
                cin >> itemID;
                cin.ignore();
                cout << "Enter Borrow Date: ";
                getline(cin, date);
                lib.issueItem(memberID, itemID, date);
                break;
            }
            case 4: {
                int itemID;
                string returnDate;
                cout << "Enter Item ID: ";
                cin >> itemID;
                cin.ignore();
                cout << "Enter Return Date: ";
                getline(cin, returnDate);
                lib.returnItem(itemID, returnDate);
                break;
            }
            case 5:
                lib.displayAllMembers();
                break;
            case 6:
                lib.displayAllItems();
                break;
            case 7:
                lib.displayAllTransactions();
                break;
            case 8: {
                int id;
                cout << "Enter Member ID to delete: ";
                cin >> id;
                lib.deleteMember(id);
                break;
            }
            case 9: {
                int id;
                cout << "Enter Item ID to delete: ";
                cin >> id;
                lib.deleteItem(id);
                break;
            }
            case 10: {
                string name, username, password;
                int id;
                cout << "Enter Librarian Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Librarian ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Username: ";
                getline(cin, username);
                cout << "Enter Password: ";
                getline(cin, password);
                librarian = Librarian(name, id, username, password);
                cout << "Librarian added successfully." << endl;
                break;
            }
            case 11:
                librarian.displayLibrarianInfo();
                break;
            case 12:
                lib.saveToFiles();
                break;
            case 13:
                lib.loadFromFiles();
                break;
            case 14:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 14);

    return 0;
}
