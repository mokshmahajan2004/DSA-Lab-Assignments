#include <iostream>
using namespace std;

struct Player
{
    int id;
    string name;
    Player *next;
    Player(int i, string n) : id(i), name(n), next(nullptr) {}
};

class Game
{
private:
    Player *head = nullptr;

public:
    void addPlayer(int id, string name)
    {
        Player *newPlayer = new Player(id, name);
        if (!head)
        {
            head = newPlayer;
            head->next = head;
        }
        else
        {
            Player *temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newPlayer;
            newPlayer->next = head;
        }
    }

    void displayPlayers()
    {
        if (!head)
            return;
        Player *temp = head;
        do
        {
            cout << "ID: " << temp->id << ", Name: " << temp->name << endl;
            temp = temp->next;
        } while (temp != head);
    }

    int countPlayers()
    {
        if (!head)
            return 0;
        int count = 0;
        Player *temp = head;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }

    void searchPlayer(int id)
    {
        Player *temp = head;
        if (!head)
            return;
        do
        {
            if (temp->id == id)
            {
                cout << "Found: " << temp->name << " (ID: " << temp->id << ")\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Player not found.\n";
    }

    void removePlayer(int id)
    {
        if (!head)
            return;
        Player *temp = head, *prev = nullptr;
        if (head->id == id)
        {
            while (temp->next != head)
                temp = temp->next;
            if (head == head->next)
            {
                delete head;
                head = nullptr;
            }
            else
            {
                temp->next = head->next;
                delete head;
                head = temp->next;
            }
            return;
        }
        do
        {
            prev = temp;
            temp = temp->next;
        } while (temp != head && temp->id != id);
        if (temp->id == id)
        {
            prev->next = temp->next;
            delete temp;
        }
    }

    ~Game()
    {
        if (!head)
            return;
        Player *temp = head;
        do
        {
            Player *next = temp->next;
            delete temp;
            temp = next;
        } while (temp != head);
    }
};

int main()
{
    Game game;
    game.addPlayer(1, "Rahul");
    game.addPlayer(2, "Priya");
    game.addPlayer(3, "Arjun");
    game.addPlayer(4, "Neha");

    cout << "Players:\n";
    game.displayPlayers();
    cout << "Total Players: " << game.countPlayers() << endl;

    game.searchPlayer(3);
    game.removePlayer(2);
    cout << "After removal:\n";
    game.displayPlayers();

    return 0;
}
