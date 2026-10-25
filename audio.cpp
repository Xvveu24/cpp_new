#include <iostream>
#include <string>
using namespace std;

class Audio
{
public:
    virtual void Play() const = 0;
    virtual ~Audio() = default;
};

class Song : public Audio
{
private:
    string title;
    string artist;

public:
    Song(const string& songTitle, const string& songArtist)
        : title(songTitle), artist(songArtist)
    {
    }

    void Play() const override
    {
        cout << "Playing song: " << title << " by " << artist << '\n';
    }
};

class Podcast : public Audio
{
private:
    string host;
    string topic;

public:
    Podcast(const string& podcastHost, const string& podcastTopic)
        : host(podcastHost), topic(podcastTopic)
    {
    }

    void Play() const override
    {
        cout << "Podcast on " << topic << " hosted by " << host << '\n';
    }
};

class Audiobook : public Audio
{
private:
    string bookTitle;
    string author;
    string voice;

public:
    Audiobook(const string& title, const string& bookAuthor, const string& reader)
        : bookTitle(title), author(bookAuthor), voice(reader)
    {
    }

    void Play() const override
    {
        cout << "Listening to audiobook: " << bookTitle << " by " << author
             << ". Read by " << voice << ".\n";
    }
};

int main()
{
    cout << "Choose audio type:\n";
    cout << "1. Song\n2. Podcast\n3. Audiobook\n";

    int choice;
    cin >> choice;
    cin.ignore(10000, '\n');

    Audio* audio = nullptr;
    string first;
    string second;
    string third;

    if (choice == 1)
    {
        cout << "Enter title: ";
        getline(cin, first);
        cout << "Enter artist: ";
        getline(cin, second);
        audio = new Song(first, second);
    }
    else if (choice == 2)
    {
        cout << "Enter host: ";
        getline(cin, first);
        cout << "Enter topic: ";
        getline(cin, second);
        audio = new Podcast(first, second);
    }
    else if (choice == 3)
    {
        cout << "Enter book title: ";
        getline(cin, first);
        cout << "Enter author: ";
        getline(cin, second);
        cout << "Enter voice: ";
        getline(cin, third);
        audio = new Audiobook(first, second, third);
    }
    else
    {
        cout << "Wrong choice.\n";
        return 0;
    }

    audio->Play();
    delete audio;
}
