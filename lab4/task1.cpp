#include <iostream>
#include <string>
using namespace std;

struct Song
{
    int songID;
    string songName;
    string duration;

    Song* prev;
    Song* next;
};

class Playlist
{
private:
    Song* head;
    Song* tail;
    Song* current;

public:
    Playlist()
    {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
    }

    // 1. Add Song
    void addSong(int id, string name, string duration)
    {
        Song* newSong = new Song;

        newSong->songID = id;
        newSong->songName = name;
        newSong->duration = duration;
        newSong->prev = nullptr;
        newSong->next = nullptr;

        if (head == nullptr)
        {
            head = tail = newSong;
            current = head;
        }
        else
        {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }

        cout << "Song added successfully.\n";
    }

    // 2. Delete Song
    void deleteSong(int id)
    {
        Song* temp = head;

        while (temp != nullptr && temp->songID != id)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Song not found.\n";
            return;
        }

        if (temp->prev != nullptr)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next != nullptr)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev;

        if (current == temp)
        {
            if (temp->next != nullptr)
                current = temp->next;
            else
                current = temp->prev;
        }

        delete temp;

        cout << "Song deleted successfully.\n";
    }

    // 3. Display Playlist Forward
    void displayForward()
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        Song* temp = head;

        cout << "\nPlaylist Forward:\n";

        while (temp != nullptr)
        {
            cout << "ID: " << temp->songID
                 << " | Name: " << temp->songName
                 << " | Duration: " << temp->duration << endl;

            temp = temp->next;
        }
    }

    // 4. Display Playlist Backward
    void displayBackward()
    {
        if (tail == nullptr)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        Song* temp = tail;

        cout << "\nPlaylist Backward:\n";

        while (temp != nullptr)
        {
            cout << "ID: " << temp->songID
                 << " | Name: " << temp->songName
                 << " | Duration: " << temp->duration << endl;

            temp = temp->prev;
        }
    }

    // 5. Search Song
    void searchSong(int id)
    {
        Song* temp = head;

        while (temp != nullptr)
        {
            if (temp->songID == id)
            {
                cout << "\nSong Found:\n";
                cout << "ID: " << temp->songID << endl;
                cout << "Name: " << temp->songName << endl;
                cout << "Duration: " << temp->duration << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Song not found.\n";
    }

    // 6. Play Next Song
    void playNext()
    {
        if (current == nullptr)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        if (current->next != nullptr)
        {
            current = current->next;

            cout << "Now Playing: "
                 << current->songName << endl;
        }
        else
        {
            cout << "Already at the last song.\n";
        }
    }

    // 6. Play Previous Song
    void playPrevious()
    {
        if (current == nullptr)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        if (current->prev != nullptr)
        {
            current = current->prev;

            cout << "Now Playing: "
                 << current->songName << endl;
        }
        else
        {
            cout << "Already at the first song.\n";
        }
    }

    // 7. Reverse Playlist
    void reversePlaylist()
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        Song* temp = head;

        while (temp != nullptr)
        {
            Song* nextNode = temp->next;

            temp->next = temp->prev;
            temp->prev = nextNode;

            temp = nextNode;
        }

        Song* oldHead = head;
        head = tail;
        tail = oldHead;

        current = head;

        cout << "Playlist reversed successfully.\n";
    }
};

int main()
{
    Playlist playlist;

    int choice;
    int id;
    string name;
    string duration;

    do
    {
        cout << "\n===== PLAYLIST MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Display Playlist Forward\n";
        cout << "4. Display Playlist Backward\n";
        cout << "5. Search Song\n";
        cout << "6. Play Next Song\n";
        cout << "7. Play Previous Song\n";
        cout << "8. Reverse Playlist\n";
        cout << "9. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Song ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Song Name: ";
            getline(cin, name);

            cout << "Enter Duration (minutes:seconds): ";
            getline(cin, duration);

            playlist.addSong(id, name, duration);
            break;

        case 2:
            cout << "Enter Song ID to delete: ";
            cin >> id;

            playlist.deleteSong(id);
            break;

        case 3:
            playlist.displayForward();
            break;

        case 4:
            playlist.displayBackward();
            break;

        case 5:
            cout << "Enter Song ID to search: ";
            cin >> id;

            playlist.searchSong(id);
            break;

        case 6:
            playlist.playNext();
            break;

        case 7:
            playlist.playPrevious();
            break;

        case 8:
            playlist.reversePlaylist();
            break;

        case 9:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 9);

    return 0;
}
