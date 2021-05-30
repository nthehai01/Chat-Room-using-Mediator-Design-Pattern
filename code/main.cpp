#include <iostream>
#include <string>

using namespace std;

class ChatRoom;

class Participant
{
private:
  string name;
  ChatRoom *room;

public:
  Participant();
  Participant(string);
  bool join(ChatRoom *);
  void receive(string, Participant *);
  void send(string, Participant *);
  bool operator==(Participant &);
  bool operator!=(Participant &);
  ~Participant();
};
class ChatRoom
{
private:
  Participant *participants;
  int numParticipants;

public:
  ChatRoom();
  void registration(Participant &);
  void send(string, Participant *, Participant *);
  ~ChatRoom();
};

Participant::Participant()
{
  name = '\0';
}

Participant::Participant(string name)
{
  this->name = name;
  room = NULL;
}

bool Participant::join(ChatRoom *room)
{
  if (!room)
    return false;

  this->room = room;
  room->registration(*this);
  return true;
}

void Participant::receive(string message, Participant *from)
{
  cout << from->name << " to " << name << ": " << message << endl;
}

void Participant::send(string message, Participant *to = NULL)
{
  if (to && *this == *to)
  {
    cout << "Self sending!" << endl;
    return;
  }
  room->send(message, this, to);
}

bool Participant::operator==(Participant &src)
{
  bool res = name == src.name;
  res = res && room == src.room;
  return res;
}

bool Participant::operator!=(Participant &src)
{
  return !(*this == src);
}

Participant::~Participant()
{
  name = '\0';
  if (room)
    delete room;
  room = NULL;
}

ChatRoom::ChatRoom()
{
  participants = new Participant[100];
  numParticipants = 0;
}

void ChatRoom::registration(Participant &participant)
{
  participants[numParticipants] = participant;
  numParticipants++;
}

void ChatRoom::send(string message, Participant *from, Participant *to = NULL)
{
  if (to)
  {
    for (int i = 0; i < numParticipants; i++)
      if (participants[i] == *to)
      {
        participants[i].receive(message, from);
        return;
      }
    cout << "This one is not in the room!" << endl;
  }

  else
    for (int i = 0; i < numParticipants; i++)
      if (participants[i] != *from)
        participants[i].receive(message, from);
}

ChatRoom::~ChatRoom()
{
  numParticipants = 0;
  if (participants)
    delete participants;
  participants = NULL;
}

int main()
{
  ChatRoom chatroom;

  Participant beau("beau");
  Participant quincy("quincy");
  Participant rafael("rafael");
  Participant berkeley("berkeley");
  Participant evaristo("evaristo");

  beau.join(&chatroom);
  quincy.join(&chatroom);
  rafael.join(&chatroom);
  berkeley.join(&chatroom);

  quincy.send("How's it going?");
  cout << "--------------" << endl;
  berkeley.send("I'm good", &berkeley);

  return 0;
}