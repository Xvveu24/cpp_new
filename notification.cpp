#include <iostream>
#include <string>
using namespace std;

class Notification
{
protected:
    string message;
    string timestamp;

public:
    Notification(const string& notificationMessage, const string& time)
        : message(notificationMessage), timestamp(time)
    {
    }
};

class EmailNotification : public Notification
{
private:
    string emailAddress;

public:
    EmailNotification(const string& notificationMessage,
        const string& time, const string& address)
        : Notification(notificationMessage, time), emailAddress(address)
    {
    }

    void send() const
    {
        cout << "Відправка email на " << emailAddress
             << ": " << message << '\n';
    }
};

class PushNotification : public Notification
{
private:
    string deviceId;

public:
    PushNotification(const string& notificationMessage,
        const string& time, const string& id)
        : Notification(notificationMessage, time), deviceId(id)
    {
    }

    void send() const
    {
        cout << "Відправка пуша на пристрій " << deviceId
             << ": " << message << '\n';
    }
};

int main()
{
    EmailNotification email("Ваше замовлення відправлено", "10:30", "user@example.com");
    PushNotification push("Нове повідомлення", "10:31", "device-123");

    email.send();
    push.send();
}
